#include "settingswindow.h"
#include "ui_settingswindow.h"

#include <QtCore>

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);
    connect(ui->applyButton,SIGNAL(clicked()),this,SLOT(saveSettings()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::saveSettings()
{
    int seconds = ui->comboBox->currentIndex();
    switch(seconds)
    {
        case 0: seconds=10; break;
        case 1: seconds=20; break;
        case 2: seconds=30; break;
        case 3: seconds=40; break;
        case 4: seconds=50; break;
        case 5: seconds=60; break;
        default: break;
    }
    qDebug()<<seconds;
    //counter = seconds;
    qDebug()<<ui->checkBox->isChecked();
}

