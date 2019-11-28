#include "shipgraphicitem.h"
#include <QRectF>
#include <QPainterPath>


ShipGraphicItem::ShipGraphicItem(){
    size = 0;
}

ShipGraphicItem::ShipGraphicItem(float size)
{
    this->size=size;
}

QRectF ShipGraphicItem::boundingRect() const{
    //return QRectF(-0.6*size, -0.6*size,1.2*size, 1.2*size);
    return QRectF(-0.25*size, -0.5*size, 0.5*size, 1*size);
}

QPainterPath ShipGraphicItem::shape() const{
    QPainterPath path;
    path.addRect(-0.25*size, -0.5*size, 0.5*size, 1*size);
    return path;
}

void ShipGraphicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    return;
}

void ShipGraphicItem::setSize(float size){
    this->size=size;
}

