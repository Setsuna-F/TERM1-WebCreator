#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rectangleitem.h"
#include <QtWidgets>

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
    void setupMenus();
    void setupWidgets();
    RectangleItem *rectItem;
    QWidget *widget;
    QGraphicsView *view;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
