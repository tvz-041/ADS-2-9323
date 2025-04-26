#pragma once

#include <QGraphicsTextItem>

class TreeNodeGraphicsItem : public QGraphicsTextItem
{
public:
    TreeNodeGraphicsItem(int key = 0, QGraphicsItem *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int m_key = 0;
};

