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
#include <QtWidgets/QLayout>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LidarViewerWidgetClass
{
public:
    QToolBox *toolBox;
    QWidget *page_1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton;
    QWidget *page_2;

    void setupUi(QWidget *LidarViewerWidgetClass)
    {
        if (LidarViewerWidgetClass->objectName().isEmpty())
            LidarViewerWidgetClass->setObjectName(QString::fromUtf8("LidarViewerWidgetClass"));
        LidarViewerWidgetClass->resize(858, 668);
        LidarViewerWidgetClass->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border:none\n"
"}"));
        toolBox = new QToolBox(LidarViewerWidgetClass);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(20, 30, 61, 271));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        page_1->setGeometry(QRect(0, 0, 61, 219));
        verticalLayoutWidget = new QWidget(page_1);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 51, 128));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton_2 = new QToolButton(verticalLayoutWidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setLayoutDirection(Qt::LeftToRight);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Image/front.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon);
        toolButton_2->setIconSize(QSize(35, 35));
        toolButton_2->setCheckable(false);
        toolButton_2->setAutoRepeat(false);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(verticalLayoutWidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setLayoutDirection(Qt::LeftToRight);
        toolButton_3->setIcon(icon);
        toolButton_3->setIconSize(QSize(35, 35));
        toolButton_3->setCheckable(false);
        toolButton_3->setAutoRepeat(false);
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton_3);

        toolButton = new QToolButton(verticalLayoutWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setLayoutDirection(Qt::LeftToRight);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(35, 35));
        toolButton->setCheckable(false);
        toolButton->setAutoRepeat(false);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout->addWidget(toolButton);

        toolBox->addItem(page_1, QString::fromUtf8("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 71, 219));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));

        retranslateUi(LidarViewerWidgetClass);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LidarViewerWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *LidarViewerWidgetClass)
    {
        LidarViewerWidgetClass->setWindowTitle(QCoreApplication::translate("LidarViewerWidgetClass", "LidarViewerWidget", nullptr));
#if QT_CONFIG(tooltip)
        toolButton_2->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600;\">set front view</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_2->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton_3->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600;\">set front view</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton_3->setText(QString());
#if QT_CONFIG(tooltip)
        toolButton->setToolTip(QCoreApplication::translate("LidarViewerWidgetClass", "<html><head/><body><p><span style=\" font-weight:600;\">set front view</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        toolButton->setText(QString());
        toolBox->setItemText(toolBox->indexOf(page_1), QCoreApplication::translate("LidarViewerWidgetClass", "Page 1", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("LidarViewerWidgetClass", "Page 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LidarViewerWidgetClass: public Ui_LidarViewerWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIDARVIEWERWIDGET_H
