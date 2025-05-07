#pragma once

#include <QGraphicsTextItem>

class TreeNodeGraphicsItem : public QGraphicsTextItem
{
public:
    TreeNodeGraphicsItem(int key = 0, QGraphicsItem *parent = nullptr);

    void setBackgroundColor(const QColor &color);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int m_key = 0;
    QColor m_backgroundColor = Qt::transparent;
};

