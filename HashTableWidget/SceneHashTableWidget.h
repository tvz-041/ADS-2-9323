#pragma once

#include <QGraphicsScene>
#include <QGraphicsView>

#include "TableElementWidget.h"

#include "BaseHashTableWidget.h"

class SceneHashTableWidget : public BaseHashTableWidget
{
public:
    SceneHashTableWidget(QWidget *parent = nullptr);

protected slots:
    void addKeyValue() override;
    void resizeTable() override;

private:
    QGraphicsScene *m_scene = nullptr;
    QGraphicsView *m_view = nullptr;

    QVector<QVector<TableElementWidget*>> m_rows;
};
