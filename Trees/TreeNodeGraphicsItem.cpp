#include <QFont>
#include <QPainter>

#include "TreeNodeGraphicsItem.h"

TreeNodeGraphicsItem::TreeNodeGraphicsItem(int key, QGraphicsItem *parent)
    : QGraphicsTextItem(QString::number(key), parent)
    , m_key(key)
{
    QFont font = this->font();
    font.setPixelSize(40);
    setFont(font);
}

void TreeNodeGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    this->QGraphicsTextItem::paint(painter, option, widget);
    painter->setPen(Qt::magenta);
    painter->drawRect(QGraphicsTextItem::boundingRect());

    painter->setPen(Qt::black);
    painter->drawEllipse(0, 0, boundingRect().width(), boundingRect().height());
}
