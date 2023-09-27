#ifndef Viewer_H
#define Viewer_H
#include <QObject>
#include <QDateTime>
#include "object.h"
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

    PointView()
    {
        pointsPtr = std::make_shared<PointCloud<PointXYZI> >();
        //sPointsLeft = std::make_shared<PointCloud<PointXYZI>>();
        //sPointsRight = std::make_shared<PointCloud<PointXYZI>>();
    }

    //    PointView(QDateTime time, PointCloud<PointXYZ>::Ptr vehCloud, PointCloud<PointXYZ>::Ptr groundCloud,
    //        QVector<shared_ptr<TrackerBase>> trackers, QVector<PointCloudCluster> clusters)
    //    {
    //        FrameTime = time;
    //        List_VehPoints = vehCloud;
    //        List_GroundPoints = groundCloud;
    //        Vec_Trackers = trackers;
    //        Vec_Cluster = clusters;
    //    }
};

/*
class Particle {
public:
    Particle();

    void init();
    void draw();
    void animate();
    void getData();
    void getDataV();
    void drawV();

    int n_datax[640];
    int n_datay[640];
    int n_dataz[10];
    int cnt;
private:
    qglviewer::Vec speed_, pos_;
    int age_, ageMax_;

};
*/
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
    void setview(ENUM_VIEW view);
    void draGridAndCircular();
    
protected:
    virtual void draw();
    virtual void init();
    virtual void animate();
    virtual QString helpString() const;


    //// Mouse events functions
    virtual void mousePressEvent(QMouseEvent* e);
    virtual void mouseMoveEvent(QMouseEvent* e);
    virtual void mouseReleaseEvent(QMouseEvent* e);
    virtual void mouseDoubleClickEvent(QMouseEvent* event);
    void reSize();
    virtual void resizeGL(int w, int h);
    virtual bool eventFilter(QObject* watched, QEvent* event);

    //function
    void displayText();

private:

    void paintControl();

    void drawSelectionRectangle() const;

    // Current rectangular selection
    QRect _rectangle;

    QList<Object> _objects;
    QList<int> _selection;
    bool _isSelect;

    st_point _findP;
    bool _find;

    int _nGrid = 10;
    float _gridR = 10.f;

    QDateTime _frameTime;
    PointCloud<PointXYZI>::Ptr _mPointsPtr;

    bool m_fullScreen;
    Qt::WindowFlags m_lastWindowFlags;
    QRect m_lastGeometry;
    QPushButton* m_btnPlay;
    QPushButton* m_btnRecord;
    QPushButton* m_btnShot;


    bool m_hasPlayed = false;
    bool m_hasRecorded = false;
    bool m_hasReplayed = false;

    int nGrid = 10;//圆圈数以及网格数/2
    float gridR = 10.0f;//网格最小圆半径以及网格单位长度
    float axisR = 10.0f;//坐标系长度

    VVAssistant* m_assistant;
signals:
    //    void signal_select_done(PointCloud<PointXYZ>::Ptr);
    bool signal_play_radar(bool doPlay);
    bool signal_record_radar(bool doRecord);
public slots:
    //void updateView(QList<PointXYZ> plistPoints, QVector<PointCloudCluster> pvecCluster);
    void updateViewMaster(PointView);
    void updateViewMasterX();
    void drawGridAndCircular();
    void convertRgbByIntensity(float intensity, float& r, float& g, float& b);
    void videoControl(QWidget* type);
    void showOneFrame(PointView pv);
    void slot_hide_icon(bool state);
};
#endif // Viewer_H