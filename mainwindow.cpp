#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingswindow.h"
#include "ui_settingswindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settings = new SettingsWindow();
    QTimer *timer = new QTimer();
    current = 0;
    counter = 60;
    timer->setInterval(1000);

    connect(ui->startButton,SIGNAL(clicked()),timer,SLOT(start()));
    connect(ui->pauseButton,SIGNAL(clicked()),timer,SLOT(stop()));
    connect(ui->stopButton,SIGNAL(clicked()),timer,SLOT(stop()));
    connect(timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(ui->actionConfigure, SIGNAL(triggered()), settings, SLOT(show()));
    connect(settings,SIGNAL(sendSettings(int, bool)),this,SLOT(receiveSettings(int, bool)));
    connect(settings,SIGNAL(sendSettings(int,bool)),timer,SLOT(stop()));
}

MainWindow::~MainWindow()
{
    disconnect(this,SLOT(tick()));
    delete ui;
    //delete timer;
    delete settings;
}

void MainWindow::tick()
{
    if (current>9)
    {
        ui->label->setText("00:"+QString::number(current));
    }
    else ui->label->setText("00:0"+QString::number(current));

    if(counter == 0)
    {
        if(current>counter)
            current--;
    }

    else
    {
        if(current<counter)
            current++;
    }
}

void MainWindow::receiveSettings(int sec, bool check)
{
    counter = sec;
    current = 0;
    ui->label->setText("00:00");
    if(check == true)
    {
        current = sec;
        counter = 0;
        ui->label->setText("00:"+QString::number(current));
    }
}

void MainWindow::on_startButton_clicked()
{
    ui->actionStart->setEnabled(true);
    ui->actionPause->setEnabled(true);
    ui->actionStop->setEnabled(true);

    ui->startButton->setEnabled(true);
    ui->pauseButton->setEnabled(true);
    ui->stopButton->setEnabled(true);
}

void MainWindow::on_stopButton_clicked()
{
    ui->actionStart->setEnabled(true);
    ui->actionPause->setEnabled(false);
    ui->actionStop->setEnabled(false);

    ui->startButton->setEnabled(true);
    ui->pauseButton->setEnabled(false);
    ui->stopButton->setEnabled(false);

    current=1;
    ui->label->setText("00:00");
}
