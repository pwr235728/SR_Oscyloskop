#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "display.h"
#include "trigger.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void update_data();

private:
    Ui::MainWindow *ui;

    QGridLayout *layout = nullptr;
    Display *display = nullptr;
    QTimer *timer = nullptr;
    int counter = 0;
    trigger trigger;
};

#endif // MAINWINDOW_H
