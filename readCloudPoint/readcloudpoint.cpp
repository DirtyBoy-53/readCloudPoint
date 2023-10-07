#include "readcloudpoint.h"
#include "qfiledialog.h"
#include "viewer.h"


readCloudPoint::readCloudPoint(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    init();

}

readCloudPoint::~readCloudPoint()
{}

void readCloudPoint::init()
{
    connect(ui.btn_chosefile, &QPushButton::clicked, this, &readCloudPoint::slot_btn_clicked);
    connect(ui.btn_chosefile_2, &QPushButton::clicked, this, &readCloudPoint::slot_btn_clicked);
}

void readCloudPoint::readfile(const std::string& file_path, std::vector<QVector4D> &cloud)
{
    std::ifstream infile;
    infile.open(file_path);
    assert(infile.is_open());
    std::string s;
    float x, y, z, i;
    while (std::getline(infile, s)) {
        std::stringstream ss(s);
        ss >> x;
        ss >> y;
        ss >> z;
        ss >> i;
        //qDebug() << QString("point_data:%1,%2,%3").arg(_pointData.x).arg(_pointData.y).arg(_pointData.z);
        
        cloud.emplace_back(QVector4D(x,y,z,i));
    }
    
    infile.close();
}


void readCloudPoint::slot_btn_clicked()
{

    //std::vector<QVector3D> vecPoints;
    //vecPoints.push_back(QVector3D(0.5f, 0.5f, 0.0f));
    //vecPoints.push_back(QVector3D(0.1f, 0.5f, 0.0f));
    //ui.openGLWidget->showPointCloud(vecPoints);
    //return;



    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("open a file."),
        "D:/",
        tr("cloudpoint(*.pcd);;All files(*.*)"));
    if (fileName.isEmpty()) return;
    //std::shared_ptr<pcl::PointCloud<pcl::PointXYZ>> _pointPtr = std::make_shared<pcl::PointCloud<pcl::PointXYZ>>();
    std::vector<QVector4D> _vecPoints;

    readfile(fileName.toStdString(), _vecPoints);
    //auto cnt = 0;
    //for (auto data : _vecPoints) {
    //    cnt++;
    //    qDebug() << QString("point%4:[%1,%2,%3]").arg(data.x()).arg(data.y()).arg(data.z()).arg(cnt);
    //}

    qDebug() << "point_size:" << _vecPoints.size();
    float x{0.0f}, y{ 0.0f }, z{ 0.0f }, intensity{ 0.0f };
    std::shared_ptr<pcl::PointCloud<PointXYZI>> m_PointsPtr = std::make_shared<PointCloud<PointXYZI>>();
    std::vector<QVector3D> _pt;
    for (auto i = 0; i < _vecPoints.size(); i++) {
        QVector3D _vecPt(x, y, z);
        _pt.emplace_back(_vecPt);
        x = _vecPoints.at(i).x();
        y = _vecPoints.at(i).y();
        z = _vecPoints.at(i).z();
        intensity = _vecPoints.at(i).w();
        //intensity = cld->points[i].intensity;
        m_PointsPtr->emplace_back(PointXYZI(x, y, z, intensity));
    }
    PointView pv;
    pv.pointsPtr = m_PointsPtr;
    
    //ui.openGLWidget->showPointCloud(_pt);
    ui.openGLWidget_2->updateViewMaster(pv);
}