#ifndef SHIPGRAPHICITEM_H
#define SHIPGRAPHICITEM_H

#include <QObject>
#include <QWidget>
#include <QGraphicsItem>

class ShipGraphicItem : public QGraphicsItem
{
public:
    ShipGraphicItem();
    ShipGraphicItem(float size);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setSize(float size);
private:
    float size;
};

#endif // SHIPGRAPHICITEM_H
