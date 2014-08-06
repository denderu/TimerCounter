#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
 
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
 
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int counter;
    int current;
 
private slots:
    void tick();
	
    void on_startButton_clicked();
    void on_stopButton_clicked();
};

#endif // MAINWINDOW_H


