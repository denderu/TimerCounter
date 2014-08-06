#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "settingswindow.h"

namespace Ui {
class MainWindow;
}

class SettingsWindow;
class MainWindow : public QMainWindow
{
    Q_OBJECT
 
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
 
private:
    Ui::MainWindow *ui;
    SettingsWindow *settings;
    QTimer *timer;
    int counter;
    int current;
 
private slots:
    void tick();
	
    void on_startButton_clicked();
    void on_stopButton_clicked();

    //friend void SettingsWindow::saveSettings();
};

#endif // MAINWINDOW_H


