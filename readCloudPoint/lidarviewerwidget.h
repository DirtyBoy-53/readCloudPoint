#pragma once

#include <QWidget>
#include "ui_lidarviewerwidget.h"
#include <qvector4d.h>
class LidarViewerWidget : public QWidget
{
	Q_OBJECT

public:
	LidarViewerWidget(QWidget *parent = nullptr);
	~LidarViewerWidget();
	void readPcdFile(const std::string& file_path, std::vector<QVector4D>& cloud);
	void LoadPcdFolder();

signals:
	void sig_set_camera_view(ENUM_VIEW view);
	void sig_set_projection_mode(Camera::Type model);
	void sig_set_isShow_grid(bool);
	void sig_set_isShow_polar(bool);
	void sig_set_isShow_coordinate(bool);
	void sig_update_lidar_data(PointView);

public slots:
	void slot_btn_clicked_tools();
	void slot_btn_clicked_playCtrl();
private:
	Ui::LidarViewerWidgetClass ui;

	QStringList m_pcdFileList;
	bool m_isShow_local_lidar_data{ false };
	bool m_isRun{ false };

	void doWork();
};
