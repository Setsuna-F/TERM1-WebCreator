#include "pagewidget.h"
#include "rectangleitem.h"
#include <QtWidgets>
#include <stdio.h>
#include <iostream>
#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>
#include <QMainWindow>
#include <QtWidgets>
#include <QGraphicsItem>
QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QParallelAnimationGroup;
class Robot;
QT_END_NAMESPACE


PageWidget::PageWidget(QWidget *parent): QWidget(parent){
    setAcceptDrops(true);
    setMinimumSize(200,200);
}

void PageWidget::dragEnterEvent(QDragEnterEvent *event){
    std::cout << "dragEnterEventDeb" << std::endl;
    if (event->mimeData()->hasColor()) {
        event->setAccepted(true);
        update();
    } else {
        event->setAccepted(false);
    }
    std::cout << "dragEnterEventFin" << std::endl;
}


void PageWidget::dragLeaveEvent(QDragLeaveEvent *event){
    std::cout << "dragLeaveEventDeb" << std::endl;
    QRect updateRect = highlightedRect;
    highlightedRect = QRect();
    update(updateRect);
    event->accept();
    std::cout << "dragLeaveEventFin" << std::endl;
}


void PageWidget::dragMoveEvent(QDragMoveEvent *event){
    std::cout << "dragMoveEventDeb" << std::endl;
    QPoint pt = event->pos();
    pt.setX(pt.x());
    pt.setY(pt.y());

    //QRect updateRect = highlightedRect.united(targetSquare(pt));
    //QRect updateRect = highlightedRect.united(item->sceneBoundingRect().toAlignedRect());

    RectangleItem *item = new RectangleItem;
    item->setPos(pt.x(), pt.y());
    QRect updateRect = highlightedRect.united(item->sceneBoundingRect().toAlignedRect());
    highlightedRect=item->sceneBoundingRect().toAlignedRect();

    //highlightedRect = targetSquare(pt);
    event->setDropAction(Qt::MoveAction);
    event->accept();

    update(updateRect);
    std::cout << "dragMoveEventFin" << std::endl;
}


void PageWidget::dropEvent(QDropEvent *event){
 /*   //dragOver = false;
    if (event->mimeData()->hasColor()){
        //color = qvariant_cast<QColor>(event->mimeData()->colorData());
        setBackgroundRole(qvariant_cast<QPalette::ColorRole>(event->mimeData()->colorData()));
        if(event->mimeData()->colorData().toString().toStdString()=="#a7f1d9"){
            //RectangleItem rect;

            //QGraphicsScene scene(-200, -200, 400, 400);
            RobotHead *robot = new RobotHead;
           // RobotHead->setPos(0, -20);
           // scene.addItem(RobotHead);
        //! [1]
        //! [2]
//            QGraphicsView view(&scene);
//            view.setRenderHint(QPainter::Antialiasing);
//            view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
//            view.setBackgroundBrush(QColor(230, 200, 167));
//            view.setWindowTitle("Drag and Drop Robot");
//             view.show();

//             QGraphicsObject *robotItem = new RobotHead();
//             robotItem->setPos(0, -20);





             QFrame *frame = new QFrame;
             QHBoxLayout *frameLayout = new QHBoxLayout(frame);

             scene = new QGraphicsScene(-200, -200, 400, 400);
             RectangleItem *item = new RectangleItem;

             scene->addItem(item);

             ///Partie Gauche
             view=new QGraphicsView(scene);
             view->setRenderHint(QPainter::Antialiasing);
             view->setBackgroundBrush(QColor(230, 200, 167));

             //widget = new QWidget;
             //QVBoxLayout* vlayout = new QVBoxLayout(widget);
             frameLayout->addWidget(view);



             //setCentralWidget(frame);



             std::cout<<"La couleur est: "<<event->mimeData()->colorData().toString().toStdString()<<std::endl;
             std::cout<<"Le html est: "<<event->mimeData()->html().toStdString()<<std::endl;
        }
    }
    update();*/








    QPoint pt = event->pos();
    pt.setX(pt.x());
    pt.setY(pt.y());
    if (event->mimeData()->hasHtml()) {

        //QByteArray pieceData = event->mimeData()->data("image/x-puzzle-piece");
        //QDataStream dataStream(&pieceData, QIODevice::ReadOnly);

        QRect square = targetSquare(event->pos());
        //QPixmap pixmap;
        QPoint location=event->pos();
        //dataStream >> pixmap >> location;

        pieceLocations.append(location);
        //piecePixmaps.append(pixmap);
        pieceRects.append(square);

        //highlightedRect = QRect();
        RectangleItem *item = new RectangleItem;
        item->setPos(pt.x(), pt.y());
        highlightedRect=item->sceneBoundingRect().toAlignedRect();

        update(square);

        event->setDropAction(Qt::MoveAction);
        event->accept();

        //if (location == QPoint(square.x()/pieceSize(), square.y()/pieceSize())) {
        //    inPlace++;
        //    if (inPlace == 25)
        //        emit puzzleCompleted();
        //}
    } else {
        RectangleItem *item = new RectangleItem;
        item->setPos(pt.x(), pt.y());
        highlightedRect=item->sceneBoundingRect().toAlignedRect();
        //highlightedRect = QRect();
        event->ignore();
    }

    std::cout<<"La couleur est: "<<event->mimeData()->colorData().toString().toStdString()<<std::endl;
    std::cout<<"Le html est: "<<event->mimeData()->html().toStdString()<<std::endl;


}

void PageWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);
    std::cout<<"je suis dans le paint"<<std::endl;

    //Ici c'est l'ombre des ronds
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawRect(-12, -12, 30, 30);

    //Ici c'est les ronds
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush("#a7f1d9"));
    painter->drawRect(-15, -15, 30, 30);

    RectangleItem *item = new RectangleItem;
    item->setPos(0, 20);
}


/*
    Faire une classe qui herite de la classe QRect pour avoir mon propre Rectangle.
*/


void PageWidget::paintEvent(QPaintEvent *event){
    QPainter painter;
    //Ici on active l'affichage des pieces sur le tableau blanc
    painter.begin(this);
    //Ici on a notre page planche pour coler les puzzles.
    painter.fillRect(event->rect(), Qt::white);


    //
    if (highlightedRect.isValid()) {
        std::cout<<"je suis dans le paintEvent"<<std::endl;
        //Couleur du carre.
        painter.setBrush(QColor("#12aa92"));
        //ici on enleve les contours.
        painter.setPen(Qt::NoPen);
        //La on donne une taille au rectangle qui va predir la position de la piece.
        painter.drawRect(highlightedRect.adjusted(0, 0, 0, 0));
    }
    // La on va afficher dans le tableau blanc les peices du puzzle
    //for (int i = #a7f1d90; i < pieceRects.size(); ++i)
    //    painter.drawPixmap(pieceRects[i], piecePixmaps[i]);
    painter.end();
}


const QRect PageWidget::targetSquare(const QPoint &position) const{
    return QRect(position.x()-pieceSize()/2, position.y()-pieceSize()/2 , pieceSize(), pieceSize());
}

/*ICI c'est pour avoir la taille d'une peice*/
int PageWidget::pieceSize() const{
    return tailleElement;
}

int PageWidget::imageSize() const{
    return 200;
}

void PageWidget::mousePressEvent(QMouseEvent *){
    setCursor(Qt::ClosedHandCursor);
}

void PageWidget::mouseReleaseEvent(QMouseEvent *){
    setCursor(Qt::OpenHandCursor);
}




/*


MyRect::MyRect(int x, int y): QRect(0, 0, x, y){
    //setCursor(Qt::OpenHandCursor);
    //setAcceptedMouseButtons(Qt::LeftButton);
}

void MyRect::dragEnterEvent(QDragEnterEvent *event){
    std::cout << "dragEnterEventDeb" << std::endl;
    if (event->mimeData()->hasHtml()) {
        event->setAccepted(true);
       // update();
    } else {
        event->setAccepted(false);
    }
    std::cout << "dragEnterEventFin" << std::endl;
}


void MyRect::dragLeaveEvent(QDragLeaveEvent *event){
    std::cout << "dragLeaveEventDeb" << std::endl;
    QRect updateRect = highlightedRect;
    highlightedRect = QRect();
    //update(updateRect);
    event->accept();
    std::cout << "dragLeaveEventFin" << std::endl;

}
/ *ICI c'est pour avoir la taille d'une peice* /
int pieceSize2(){
    return 30;
}
const QRect targetSquare2(const QPoint &position) {
    return QRect(position.x()-pieceSize2()/2, position.y()-pieceSize2()/2 , pieceSize2(), pieceSize2());
}



void MyRect::dragMoveEvent(QDragMoveEvent *event){
    std::cout << "dragMoveEventDeb" << std::endl;
    QPoint pt = event->pos();
    pt.setX(pt.x());
    pt.setY(pt.y());


    QRect updateRect = highlightedRect.united(targetSquare2(pt));

    if (event->mimeData()->hasHtml()) {
        highlightedRect = targetSquare2(event->pos());
        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        highlightedRect = QRect();
        event->ignore();
    }

    //update(updateRect);
    std::cout << "dragMoveEventFin" << std::endl;
}


void MyRect::dropEvent(QDropEvent *event){
    if (event->mimeData()->hasHtml()) {

        QString pieceData = event->mimeData()->html();
        std::cout<<pieceData.toStdString()<<std::endl;
        QRect square = targetSquare2(event->pos());
        QPoint location;

        pieceLocations.append(location);
        //piecePixmaps.append(pixmap);
        pieceRects.append(square);

        highlightedRect = QRect();
        //update(square);

        event->setDropAction(Qt::MoveAction);
        event->accept();

        //if (location == QPoint(square.x()/pieceSize(), square.y()/pieceSize())) {
        //    inPlace++;
        //    if (inPlace == 25)
        //        emit puzzleCompleted();
        //}
    } else {
        highlightedRect = QRect();
        event->ignore();
    }
}


void MyRect::mousePressEvent(QMouseEvent *event)
{
 / *   QRect square = targetSquare2(event->pos());
    int found = findPiece(square);

    //if (found == -1)
    //    return;

    QPoint location = pieceLocations[found];
    //QPixmap pixmap = piecePixmaps[found];
    pieceLocations.removeAt(found);
    //piecePixmaps.removeAt(found);
    pieceRects.removeAt(found);

    //if (location == QPoint(square.x()/pieceSize(), square.y()/pieceSize()))
    //    inPlace--;

    update(square);

    //QByteArray itemData;
    //QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    //dataStream << pixmap << location;

    QMimeData *mimeData = new QMimeData;
    mimeData->setHtml("<p>soka</p>");

    QDrag *drag = new QDrag();
    drag->setMimeData(mimeData);
    drag->setHotSpot(event->pos() - square.topLeft());
   // drag->setPixmap(pixmap);

    if (!(drag->exec(Qt::MoveAction) == Qt::MoveAction)) {
        pieceLocations.insert(found, location);
        //piecePixmaps.insert(found, pixmap);
        pieceRects.insert(found, square);
        update(targetSquare(event->pos()));

        //if (location == QPoint(square.x()/pieceSize(), square.y()/pieceSize()))
        //    inPlace++;
    }* /
}
int MyRect::findPiece(const QRect &pieceRect) const
{
    for (int i = 0; i < pieceRects.size(); ++i) {
        if (pieceRect == pieceRects[i])
            return i;
    }
    return -1;
}
*/
