/********************************************************************************
** Form generated from reading UI file 'lidarviewerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIDARVIEWERWIDGET_H
#define UI_LIDARVIEWERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "viewer.h"

QT_BEGIN_NAMESPACE

class Ui_LidarViewerWidgetClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_connect;
    QPushButton *btn_opendir;
    QPushButton *btn_front;
    QPushButton *btn_right;
    QPushButton *btn_top;
    QPushButton *btn_projection;
    QPushButton *btn_grid;
    QPushButton *btn_polar;
    QPushButton *btn_isShow_coordinate;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    Viewer *pointViewerWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_last_file;
    QPushButton *btn_last_frame;
    QPushButton *btn_play_stop;
    QPushButton *btn_next_frame;
    QPushButton *btn_next_file;
    QPushButton *btn_record;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *LidarViewerWidgetClass)
    {
        if (LidarViewerWidgetClass->objectName().isEmpty())
            LidarViewerWidgetClass->setObjectName(QString::fromUtf8("LidarViewerWidgetClass"));
        LidarViewerWidgetClass->resize(858, 668);
        LidarViewerWidgetClass->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:none\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(LidarViewerWidgetClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(-1, -1, 0, -1);
        btn_connect = new QPushButton(LidarViewerWidgetClass);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));
        btn_connect->setMaximumSize(QSize(35, 35));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/web.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_connect->setIcon(icon);
        btn_connect->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(btn_connect);

        btn_opendir = new QPushButton(LidarViewerWidgetClass);
        btn_opendir->setObjectName(QString::fromUtf8("btn_opendir"));
        btn_opendir->setMaximumSize(QSize(35, 35));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Image/3735134.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_opendir->setIcon(icon1);
        btn_opendir->setIconSize(QSize(35, 35));

        verticalLayout->addWidget(btn_opendir);

        btn_front = new QPushButton(LidarViewerWidgetClass);
        btn_front->setObjectName(QString::fromUtf8("btn_front"));
        btn_front->setMaximumSize(QSize(35, 35));
        btn_front->setLayoutDirection(Qt::LeftToRight);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Image/front.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_front->setIcon(icon2);
        btn_front->setIconSize(QSize(35, 35));
        btn_front->setCheckable(false);
        btn_front->setAutoRepeat(false);

        verticalLayout->addWidget(btn_front);

        btn_right = new QPushButton(LidarViewerWidgetClass);
        btn_right->setObjectName(QString::fromUtf8("btn_right"));
        btn_right->setMaximumSize(QSize(35, 35));
        btn_right->setLayoutDirection(Qt::LeftToRight);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Image/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_right->setIcon(icon3);
        btn_right->setIconSize(QSize(35, 35));
        btn_right->setCheckable(false);
        btn_right->setAutoRepeat(false);

        verticalLayout->addWidget(btn_right);

        btn_top = new QPushButton(LidarViewerWidgetClass);
        btn_top->setObjectName(QString::fromUtf8("btn_top"));
        btn_top->setMaximumSize(QSize(35, 35));
        btn_top->setLayoutDirection(Qt::LeftToRight);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Image/top.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_top->setIcon(icon4);
        btn_top->setIconSize(QSize(35, 35));
        btn_top->setCheckable(false);
        btn_top->setAutoRepeat(false);

        verticalLayout->addWidget(btn_top);

        btn_projection = new QPushButton(LidarViewerWidgetClass);
        btn_projection->setObjectName(QString::fromUtf8("btn_projection"));
        btn_projection->setMaximumSize(QSize(35, 35));
        btn_projection->setLayoutDirection(Qt::LeftToRight);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Image/orthographic.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_projection->setIcon(icon5);
        btn_projection->setIconSize(QSize(35, 35));
        btn_projection->setCheckable(false);
        btn_projection->setAutoRepeat(false);

        verticalLayout->addWidget(btn_projection);

        btn_grid = new QPushButton(LidarViewerWidgetClass);
        btn_grid->setObjectName(QString::fromUtf8("btn_grid"));
        btn_grid->setMaximumSize(QSize(35, 35));
        btn_grid->setLayoutDirection(Qt::LeftToRight);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Image/grid.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_grid->setIcon(icon6);
        btn_grid->setIconSize(QSize(35, 35));
        btn_grid->setCheckable(false);
        btn_grid->setAutoRepeat(false);

        verticalLayout->addWidget(btn_grid);

        btn_polar = new QPushButton(LidarViewerWidgetClass);
        btn_polar->setObjectName(QString::fromUtf8("btn_polar"));
        btn_polar->setMaximumSize(QSize(35, 35));
        btn_polar->setLayoutDirection(Qt::LeftToRight);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Image/polar.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_polar->setIcon(icon7);
        btn_polar->setIconSize(QSize(35, 35));
        btn_polar->setCheckable(false);
        btn_polar->setAutoRepeat(false);

        verticalLayout->addWidget(btn_polar);

        btn_isShow_coordinate = new QPushButton(LidarViewerWidgetClass);
        btn_isShow_coordinate->setObjectName(QString::fromUtf8("btn_isShow_coordinate"));
        btn_isShow_coordinate->setMaximumSize(QSize(35, 35));
        btn_isShow_coordinate->setLayoutDirection(Qt::LeftToRight);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Image/showaxis.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_isShow_coordinate->setIcon(icon8);
        btn_isShow_coordinate->setIconSize(QSize(35, 35));
        btn_isShow_coordinate->setCheckable(false);
        btn_isShow_coordinate->setAutoRepeat(false);

        verticalLayout->addWidget(btn_isShow_coordinate);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pointViewerWidget = new Viewer(LidarViewerWidgetClass);
        pointViewerWidget->setObjectName(QString::fromUtf8("pointViewerWidget"));
        pointViewerWidget->setMinimumSize(QSize(300, 200));

        verticalLayout_2->addWidget(pointViewerWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        btn_last_file = new QPushButton(LidarViewerWidgetClass);
        btn_last_file->setObjectName(QString::fromUtf8("btn_last_file"));
        btn_last_file->setMaximumSize(QSize(16777215, 35));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Image/play_seekbackward.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_last_file->setIcon(icon9);
        btn_last_file->setIconSize(QSize(35, 35));

        horizontalLayout->addWidget(btn_last_file);

        btn_last_frame = new QPushButton(LidarViewerWidgetClass);
        btn_last_frame->setObjectName(QString::fromUtf8("btn_last_frame"));
        btn_last_frame->setMaximumSize(QSize(16777215, 35));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Image/play_gotostart.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_last_frame->setIcon(icon10);
        btn_last_frame->setIconSize(QSize(35, 35));

        horizontalLayout->addWidget(btn_last_frame);

        btn_play_stop = new QPushButton(LidarViewerWidgetClass);
        btn_play_stop->setObjectName(QString::fromUtf8("btn_play_stop"));
        btn_play_stop->setMaximumSize(QSize(16777215, 35));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Image/play_play.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_play_stop->setIcon(icon11);
        btn_play_stop->setIconSize(QSize(35, 35));

        horizontalLayout->addWidget(btn_play_stop);

        btn_next_frame = new QPushButton(LidarViewerWidgetClass);
        btn_next_frame->setObjectName(QString::fromUtf8("btn_next_frame"));
        btn_next_frame->setMaximumSize(QSize(16777215, 35));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Image/play_gotoend.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next_frame->setIcon(icon12);
        btn_next_frame->setIconSize(QSize(35, 35));

        horizontalLayout->addWidget(btn_next_frame);

        btn_next_file = new QPushButton(LidarViewerWidgetClass);
        btn_next_file->setObjectName(QString::fromUtf8("btn_next_file"));
        btn_next_file->setMaximumSize(QSize(16777215, 35));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Image/play_seekforward.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_next_file->setIcon(icon13);
        btn_next_file->setIconSize(QSize(35, 35));

        horizontalLayout->addWidget(btn_next_file);

        btn_record = new QPushButton(LidarViewerWidgetClass);
        btn_record->setObjectName(QString::fromUtf8("btn_record"));
        btn_record->setMaximumSize(QSize(16777215, 35));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Image/4186876.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_record->setIcon(icon14);
        btn_record->setIconSize(QSize(35, 35));

        horizontalLayout->addWidget(btn_record);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(LidarViewerWidgetClass);
        QObject::connect(btn_connect, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_tools()));
        QObject::connect(btn_opendir, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_tools()));
        QObject::connect(btn_front, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_tools()));
        QObject::connect(btn_right, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_tools()));
        QObject::connect(btn_top, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_tools()));
        QObject::connect(btn_projection, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_tools()));
        QObject::connect(btn_play_stop, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_playCtrl()));
        QObject::connect(btn_last_frame, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_playCtrl()));
        QObject::connect(btn_last_file, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_playCtrl()));
        QObject::connect(btn_next_frame, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_playCtrl()));
        QObject::connect(btn_next_file, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_playCtrl()));
        QObject::connect(btn_record, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_playCtrl()));
        QObject::connect(LidarViewerWidgetClass, SIGNAL(sig_set_camera_view(ENUM_VIEW)), pointViewerWidget, SLOT(set_camera_view(ENUM_VIEW)));
        QObject::connect(LidarViewerWidgetClass, SIGNAL(sig_set_projection_mode(Camera::Type)), pointViewerWidget, SLOT(set_projection_mode(Camera::Type)));
        QObject::connect(btn_grid, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_tools()));
        QObject::connect(btn_polar, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_tools()));
        QObject::connect(btn_isShow_coordinate, SIGNAL(clicked()), LidarViewerWidgetClass, SLOT(slot_btn_clicked_tools()));
        QObject::connect(LidarViewerWidgetClass, SIGNAL(sig_set_isShow_coordinate(bool)), pointViewerWidget, SLOT(set_is_show_coordinate(bool)));
        QObject::connect(LidarViewerWidgetClass, SIGNAL(sig_set_isShow_polar(bool)), pointViewerWidget, SLOT(set_is_show_polar(bool)));
        QObject::connect(LidarViewerWidgetClass, SIGNAL(sig_set_isShow_grid(bool)), pointViewerWidget, SLOT(set_is_show_grid(bool)));
        QObject::connect(LidarViewerWidgetClass, SIGNAL(sig_update_lidar_data(PointView)), pointViewerWidget, SLOT(updateViewMaster(PointView)));

        QMetaObject::connectSlotsByName(LidarViewerWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *LidarViewerWidgetClass)
    {
        LidarViewerWidgetClass->setWindowTitle(QCoreApplication::translate("LidarViewerWidgetClass", "LidarViewerWidget", nullptr));
#if QT_CONFIG(tooltip)
        btn_connect->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600;\">choose device</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_connect->setText(QString());
#if QT_CONFIG(tooltip)
        btn_opendir->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600;\">choose folder</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_opendir->setText(QString());
#if QT_CONFIG(tooltip)
        btn_front->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600;\">set front view</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_front->setText(QString());
#if QT_CONFIG(tooltip)
        btn_right->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600;\">set right view</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_right->setText(QString());
#if QT_CONFIG(tooltip)
        btn_top->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600;\">set top view</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_top->setText(QString());
#if QT_CONFIG(tooltip)
        btn_projection->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600;\">Orthographic/Perspective projection</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_projection->setText(QString());
#if QT_CONFIG(tooltip)
        btn_grid->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600;\">Orthographic/Perspective projection</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_grid->setText(QString());
#if QT_CONFIG(tooltip)
        btn_polar->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600;\">Orthographic/Perspective projection</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_polar->setText(QString());
#if QT_CONFIG(tooltip)
        btn_isShow_coordinate->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600;\">Orthographic/Perspective projection</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_isShow_coordinate->setText(QString());
#if QT_CONFIG(tooltip)
        btn_last_file->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600; color:#000000;\">last file</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_last_file->setText(QString());
#if QT_CONFIG(tooltip)
        btn_last_frame->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600; color:#000000;\">last frame</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_last_frame->setText(QString());
#if QT_CONFIG(tooltip)
        btn_play_stop->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600; color:#000000;\">play/stop</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_play_stop->setText(QString());
#if QT_CONFIG(tooltip)
        btn_next_frame->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600; color:#000000;\">next frame</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_next_frame->setText(QString());
#if QT_CONFIG(tooltip)
        btn_next_file->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600; color:#000000;\">next file</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_next_file->setText(QString());
#if QT_CONFIG(tooltip)
        btn_record->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600; color:#000000;\">next file</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_record->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LidarViewerWidgetClass: public Ui_LidarViewerWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIDARVIEWERWIDGET_H
