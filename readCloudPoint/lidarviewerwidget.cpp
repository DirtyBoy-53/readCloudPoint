#include "lidarviewerwidget.h"
#include <QFileDialog>
LidarViewerWidget::LidarViewerWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	qRegisterMetaType<PointView>("PointView");
	connect(this, &LidarViewerWidget::sig_update_lidar_data, ui.pointViewerWidget, &Viewer::updateViewMaster);
}

LidarViewerWidget::~LidarViewerWidget()
{
	m_isRun = false;
}

void LidarViewerWidget::readPcdFile(const std::string& file_path, std::vector<QVector4D>& cloud)
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
		cloud.emplace_back(QVector4D(x, y, z, i));
	}
	infile.close();
}

void LidarViewerWidget::LoadPcdFolder()
{
	QString fileName = QFileDialog::getExistingDirectory(
		this, tr("select the lidar data folder."), "./");
	if (fileName.isEmpty()) return;
	m_isShow_local_lidar_data = false;
	m_pcdFileList.clear();

	QDir dir(fileName);
	QStringList _allfile = dir.entryList(QStringList() << "*.pcd");
	for (auto data : _allfile) {
		m_pcdFileList.append(fileName + "/" + data);
	}
	if (m_pcdFileList.size() > 0) {
		m_isShow_local_lidar_data = true;
	}
	if (m_isRun == false) {
		m_isRun = true;
		new std::thread(&LidarViewerWidget::doWork, this);
	}
}

void LidarViewerWidget::slot_btn_clicked_tools() {
	QString _Objname = ((QPushButton*)sender())->objectName();
	if (_Objname == "btn_connect") {

	} else if(_Objname == "btn_opendir") {
		LoadPcdFolder();
	} else if (_Objname == "btn_front") {
		emit sig_set_camera_view(ENUM_VIEW::Enum_front);
	} else if (_Objname == "btn_right") {
		emit sig_set_camera_view(ENUM_VIEW::Enum_right);
	} else if(_Objname == "btn_top") {
		emit sig_set_camera_view(ENUM_VIEW::Enum_top);
	} else if (_Objname == "btn_projection") {
		static bool _isShowPro{ false };
		if (_isShowPro == false) {
			_isShowPro = true;
			emit sig_set_projection_mode(Camera::PERSPECTIVE);
			ui.btn_projection->setIcon(QIcon(":/Image/perspective.png"));
		} else {
			_isShowPro = false;
			emit sig_set_projection_mode(Camera::ORTHOGRAPHIC);
			ui.btn_projection->setIcon(QIcon(":/Image/orthographic.png"));
		}
	} else if (_Objname == "btn_grid") {
		static bool _isShowGrid{ false };
		_isShowGrid = !_isShowGrid;
		emit sig_set_isShow_grid(_isShowGrid);
	} else if (_Objname == "btn_polar") {
		static bool _isShowPolar{ false };
		_isShowPolar = !_isShowPolar;
		emit sig_set_isShow_polar(_isShowPolar);
	} else if (_Objname == "btn_isShow_coordinate") {
		static bool _isShowCoord{ false };
		_isShowCoord = !_isShowCoord;
		emit sig_set_isShow_coordinate(_isShowCoord);
	} else {}
 

	
}

void LidarViewerWidget::slot_btn_clicked_playCtrl()
{
}

void LidarViewerWidget::doWork()
{
	QStringList _pcdfilelist;
	std::vector<QVector4D> _vecPoints;
	float x{ 0.0f }, y{ 0.0f }, z{ 0.0f }, intensity{ 0.0f };
	while (m_isRun) {
		if (m_isShow_local_lidar_data) {
			for (auto path : m_pcdFileList) {
				readPcdFile(path.toStdString(), _vecPoints);

				std::shared_ptr<pcl::PointCloud<PointXYZI>> m_PointsPtr = std::make_shared<PointCloud<PointXYZI>>();
				for (auto i = 0; i < _vecPoints.size(); i++) {
					x = _vecPoints.at(i).x();
					y = _vecPoints.at(i).y();
					z = _vecPoints.at(i).z();
					intensity = _vecPoints.at(i).w();
					m_PointsPtr->emplace_back(PointXYZI(x, y, z, intensity));
				}
				PointView pv;
				pv.pointsPtr = m_PointsPtr;

				emit sig_update_lidar_data(pv);
			}
			m_isShow_local_lidar_data = false;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		
	}
}
