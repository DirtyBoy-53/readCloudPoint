#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_readcloudpoint.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

class readCloudPoint : public QMainWindow
{
    Q_OBJECT

public:
    readCloudPoint(QWidget *parent = nullptr);
    ~readCloudPoint();
    void init();
    void readfile(const std::string& file_path, std::vector<QVector4D>& cloud);
public slots:
    void slot_btn_clicked();
private:
    Ui::readCloudPointClass ui;
};
