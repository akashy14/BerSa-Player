#include "settingdialog.h"
#include "ui_settingdialog.h"
#include <QSettings>

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    ui->genreComboBox->addItems(QStringList() << "Afro" << "Gospel" << "Rap" << "Jazz" << "Classique" << "Electro");
    loadSettings();
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::on_saveButton_clicked()
{
    QSettings settings("BerSa-Entrepise", "BS-Player");
    settings.setValue("genre", ui->genreComboBox->currentText());
    settings.setValue("filtrage", ui->filterSlider->value());
    settings.setValue("mix", ui->mixSlider->value());
    accept();
}

void SettingDialog::loadSettings()
{
    QSettings settings("BerSa", "BS-Player");
    ui->genreComboBox->setCurrentText(settings.value("genre", "Afro").toString());
    ui->filterSlider->setValue(settings.value("filtrage", 5).toInt());
    ui->mixSlider->setValue(settings.value("mix", 5).toInt());
}
