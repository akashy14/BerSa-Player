/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QComboBox *genreComboBox;
    QPushButton *saveButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSlider *mixSlider;
    QSlider *filterSlider;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName("SettingDialog");
        SettingDialog->resize(310, 181);
        genreComboBox = new QComboBox(SettingDialog);
        genreComboBox->setObjectName("genreComboBox");
        genreComboBox->setGeometry(QRect(0, 0, 55, 22));
        saveButton = new QPushButton(SettingDialog);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(210, 150, 80, 18));
        horizontalLayoutWidget = new QWidget(SettingDialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(9, 29, 291, 81));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        mixSlider = new QSlider(horizontalLayoutWidget);
        mixSlider->setObjectName("mixSlider");
        mixSlider->setOrientation(Qt::Orientation::Vertical);

        horizontalLayout->addWidget(mixSlider);

        filterSlider = new QSlider(horizontalLayoutWidget);
        filterSlider->setObjectName("filterSlider");
        filterSlider->setOrientation(Qt::Orientation::Vertical);

        horizontalLayout->addWidget(filterSlider);


        retranslateUi(SettingDialog);

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QCoreApplication::translate("SettingDialog", "Dialog", nullptr));
        saveButton->setText(QCoreApplication::translate("SettingDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
