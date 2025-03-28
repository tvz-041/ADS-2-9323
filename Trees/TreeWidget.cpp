#include <QGraphicsScene>
#include <QCheckBox>
#include <QPushButton>

#include "TreeWidget.h"
#include "ui_TreeWidget.h"

TreeWidget::TreeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TreeWidget)
{
    ui->setupUi(this);
    m_scene=new QGraphicsScene(this);
    ui->graphicsView->setScene(m_scene);
    m_scene->addLine(0,0,100,100);

    connect(ui->pushButton, &QPushButton::clicked, this, &TreeWidget::foo);
}

TreeWidget::~TreeWidget()
{
    delete ui;
}

void TreeWidget::foo()
{
    ui->graphicsView->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
}
