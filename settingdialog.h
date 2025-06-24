#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QtCore/qglobal.h>

#include <QDialog>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = nullptr);
    ~SettingDialog();

private slots:
    void on_saveButton_clicked();

private:
    Ui::SettingDialog *ui;
    void loadSettings();
};

#endif // SETTINGDIALOG_H
