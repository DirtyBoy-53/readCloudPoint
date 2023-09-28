#ifndef Viewer_H
#define Viewer_H
#include <QObject>
#include <QDateTime>
#include "QGLViewer/qglviewer.h"
#include <QWidget>
#include <QPushButton>
#include <QSignalMapper>
#include <QThread>
#include <QDebug>

//pcl
#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/octree/octree.h>
#include <boost/thread/thread.hpp>
#include <pcl/common/transforms.h>
#include <pcl/search/kdtree.h>
#include <pcl/common/time.h>
#include <Eigen/Dense>
#include <Eigen/Geometry>
using namespace pcl;

using namespace qglviewer;
using namespace std;


struct st_point {
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    st_point() {}

    st_point(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
};

struct PointInfo
{
    double X;
    double Y;
    double Z;
    float Intensity;
    int ring;
    double time;

    PointInfo() : X(0), Y(0), Z(0), Intensity(0), ring(0), time(0) {}
};
#define AT128_DATASIZE_MAX  384000  //AT128单帧点云大小
#define PI              3.141592654
struct StructPointData {
    PointInfo point[AT128_DATASIZE_MAX];
    // PPointCloud point;
    uint64_t pointsize;
    std::string time;
};
// typedef std::shared_ptr<StructPointData> StructPointDataPtr;
typedef std::shared_ptr<uchar> uchar_ptr;

enum class ENUM_VIEW {
    Enum_front,
    Enum_right,
    Enum_top,
};


struct PointView
{
    QDateTime frameTime;
    pcl::PointCloud<PointXYZI>::Ptr pointsPtr;

    PointView() {
        pointsPtr = std::make_shared<PointCloud<PointXYZI> >();
    }
};

class VVAssistant : public QObject
{
    Q_OBJECT
public:
    VVAssistant(QObject* parent = nullptr, int slotId = 0) : QObject(parent),
        m_videoId(slotId),
        m_showCount(0)
    {
        m_astThread = new QThread;
        moveToThread(m_astThread);
        m_astThread->start();

        m_shotSwitch = false;
    }

    ~VVAssistant()
    {
        if (m_astThread) {
            delete m_astThread;
            m_astThread = nullptr;
        }
    }

private:
    int m_videoId;
    int m_showCount;
    int m_showType;
    PointCloud<PointXYZI>::Ptr m_PointsPtr;
signals:
    void signalSetXy(PointView pv);

public slots:
    void slotShotOne(bool shotOne = true)
    {
        m_shotSwitch = shotOne;
    }
    void slotRidarDataSetting(int slot, StructPointData* data)
    {
        if (slot != m_videoId) return;
        if (m_showCount++ == 3) {
            // qDebug() << "Viewer::slotRidarDataSetting " << QThread::currentThreadId();
            m_PointsPtr = std::make_shared<PointCloud<PointXYZI>>();
            for (int i = 0; i < data->pointsize; i++) {
                m_PointsPtr->emplace_back(PointXYZI(data->point[i].X, data->point[i].Y, data->point[i].Z, data->point[i].Intensity));
            }

            PointView pv;
            pv.pointsPtr = m_PointsPtr;
            emit signalSetXy(pv);
            m_showCount = 0;
        }
    }

private:
    QThread* m_astThread;

    bool m_shotSwitch = false;
};

class Viewer : public QGLViewer
{
    Q_OBJECT
public:
    Viewer(QWidget* parent = 0, int slot = 0, bool needAssitant = false);

    QList<int> QL_ViewerSelectIds;
    void setView(ENUM_VIEW view);
    void drawCoordinates();
    void set_projection_mode(Camera::Type model);
    
protected:
    //must overload
    virtual void init();
    virtual void draw();
    virtual void resizeGL(int w, int h);

    // Mouse events functions
    virtual void mousePressEvent(QMouseEvent* e);
    virtual void mouseMoveEvent(QMouseEvent* e);
    virtual void mouseReleaseEvent(QMouseEvent* e);

    virtual void postSelection(const QPoint& point);

private:
    int _nGrid = 10;//圆圈数以及网格数/2
    float _gridR = 10.0f;//网格最小圆半径以及网格单位长度

    st_point _findP;
    bool _find{ false };

    QDateTime _frameTime;
    PointCloud<PointXYZI>::Ptr _mPointsPtr;
    VVAssistant* m_assistant;

    void set_display_text(QVector2D& pos, QString& content);

    void drawSelectionRectangle() const;

signals:


public slots:
    //void updateView(QList<PointXYZ> plistPoints, QVector<PointCloudCluster> pvecCluster);
    void updateViewMaster(PointView);
    void drawGridAndCircular();
    void convertRgbByIntensity(float intensity, float& r, float& g, float& b);

};
#endif // Viewer_H