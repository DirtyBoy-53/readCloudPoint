/********************************************************************************
** Form generated from reading UI file 'readcloudpoint.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READCLOUDPOINT_H
#define UI_READCLOUDPOINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cpointviewer.h"
#include "viewer.h"

QT_BEGIN_NAMESPACE

class Ui_readCloudPointClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    CPointViewer *openGLWidget;
    QPushButton *btn_chosefile;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    Viewer *openGLWidget_2;
    QPushButton *btn_chosefile_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *readCloudPointClass)
    {
        if (readCloudPointClass->objectName().isEmpty())
            readCloudPointClass->setObjectName(QString::fromUtf8("readCloudPointClass"));
        readCloudPointClass->resize(919, 765);
        centralWidget = new QWidget(readCloudPointClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        openGLWidget = new CPointViewer(tab);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        verticalLayout->addWidget(openGLWidget);

        btn_chosefile = new QPushButton(tab);
        btn_chosefile->setObjectName(QString::fromUtf8("btn_chosefile"));

        verticalLayout->addWidget(btn_chosefile);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        openGLWidget_2 = new Viewer(tab_2);
        openGLWidget_2->setObjectName(QString::fromUtf8("openGLWidget_2"));

        verticalLayout_2->addWidget(openGLWidget_2);

        btn_chosefile_2 = new QPushButton(tab_2);
        btn_chosefile_2->setObjectName(QString::fromUtf8("btn_chosefile_2"));

        verticalLayout_2->addWidget(btn_chosefile_2);

        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        readCloudPointClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(readCloudPointClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 919, 23));
        readCloudPointClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(readCloudPointClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        readCloudPointClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(readCloudPointClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        readCloudPointClass->setStatusBar(statusBar);

        retranslateUi(readCloudPointClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(readCloudPointClass);
    } // setupUi

    void retranslateUi(QMainWindow *readCloudPointClass)
    {
        readCloudPointClass->setWindowTitle(QCoreApplication::translate("readCloudPointClass", "readCloudPoint", nullptr));
        btn_chosefile->setText(QCoreApplication::translate("readCloudPointClass", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("readCloudPointClass", "Tab 1", nullptr));
        btn_chosefile_2->setText(QCoreApplication::translate("readCloudPointClass", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("readCloudPointClass", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class readCloudPointClass: public Ui_readCloudPointClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READCLOUDPOINT_H
