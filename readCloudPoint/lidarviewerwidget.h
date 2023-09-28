#pragma once

#include <QWidget>
#include "ui_lidarviewerwidget.h"

class LidarViewerWidget : public QWidget
{
	Q_OBJECT

public:
	LidarViewerWidget(QWidget *parent = nullptr);
	~LidarViewerWidget();

private:
	Ui::LidarViewerWidgetClass ui;
};
