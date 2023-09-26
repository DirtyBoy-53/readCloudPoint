#include "readcloudpoint.h"
#include "qfiledialog.h"



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
}

void readCloudPoint::readfile(const std::string& file_path, std::vector<QVector3D> &cloud)
{
    std::ifstream infile;
    infile.open(file_path);
    assert(infile.is_open());
    std::string s;
    float x, y, z;
    while (std::getline(infile, s)) {
        std::stringstream ss(s);
        ss >> x;
        ss >> y;
        ss >> z;
        //qDebug() << QString("point_data:%1,%2,%3").arg(_pointData.x).arg(_pointData.y).arg(_pointData.z);
        
        cloud.emplace_back(QVector3D(x,y,z));
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
    std::vector<QVector3D> _vecPoints;

    readfile(fileName.toStdString(), _vecPoints);
    
    qDebug() << "point_size:" << _vecPoints.size();
    
    ui.openGLWidget->showPointCloud(_vecPoints);
}