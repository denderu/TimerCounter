#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);

    timer->setInterval(5000);
    QObject::connect(timer,SIGNAL(timeout()), this, SLOT(close()));
    //QAbstractButton::connect(ui->startButton,SIGNAL(clicked()), timer, SLOT(start(1000)));
    QObject::connect(ui->startButton,SIGNAL(clicked()), timer, SLOT(start()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    ui->actionStart->setEnabled(true);
    ui->actionPause->setEnabled(true);
    ui->actionStop->setEnabled(true);

    ui->startButton->setEnabled(true);
    ui->pauseButton->setEnabled(true);
    ui->stopButton->setEnabled(true);

    ui->label->setText(QString::number(timer->remainingTime()));
}

void MainWindow::on_stopButton_clicked()
{
    ui->actionStart->setEnabled(true);
    ui->actionPause->setEnabled(false);
    ui->actionStop->setEnabled(false);

    ui->startButton->setEnabled(true);
    ui->pauseButton->setEnabled(false);
    ui->stopButton->setEnabled(false);

    ui->label->setText("00:00");
}
