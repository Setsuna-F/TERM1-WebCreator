#include "mainwindow.h"

#include <QtWidgets>
#include <stdlib.h>
#include "pagewidget.h"
#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtWidgets>
#include <stdlib.h>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setupMenus();
    setupWidgets();

    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    setWindowTitle(tr("Test Drag and Drop"));
}

MainWindow::~MainWindow(){

}

void MainWindow::setupMenus(){
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *exitAction = fileMenu->addAction(tr("E&xit"));
    exitAction->setShortcuts(QKeySequence::Quit);
    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
}

void MainWindow::setupWidgets(){
    QFrame *frame = new QFrame;
    QHBoxLayout *frameLayout = new QHBoxLayout(frame);

    scene = new QGraphicsScene(-200, -200, 400, 400);
    RectangleItem *item = new RectangleItem;
    scene->addItem(item);

    /*Partie Gauche*/
    view=new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QColor(230, 200, 167));

    /*Partie Droite*/
    PageWidget *pageW = new PageWidget();


    frameLayout->addWidget(view);
    frameLayout->addWidget(pageW);

    setCentralWidget(frame);
}
