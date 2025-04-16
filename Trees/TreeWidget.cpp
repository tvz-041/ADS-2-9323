#include <QCheckBox>
#include <QGraphicsScene>
#include <QPushButton>

#include "BinaryTree.h"
#include "TreeNodeGraphicsItem.h"

#include "TreeWidget.h"
#include "ui_TreeWidget.h"

TreeWidget::TreeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TreeWidget)
{
    ui->setupUi(this);
    m_scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(m_scene);
    m_tree = BinaryTree::buildRandom(25);

    connect(ui->pushButton, &QPushButton::clicked, this, &TreeWidget::foo);
}

TreeWidget::~TreeWidget()
{
    delete ui;
}

void TreeWidget::paintTree()
{
    paintTree(m_tree->root(), 0, ui->graphicsView->width(), 0);
}

void TreeWidget::paintTree(BinaryTree::Node *root, int leftBorderPos, int rightBorderPos, int yPos) const
{
    if (root == nullptr)
    {
        return;
    }
    auto* item = new TreeNodeGraphicsItem(root->key);

    int xCenter = (leftBorderPos + rightBorderPos) / 2;
    int xPos = xCenter - item->boundingRect().width() / 2;
    item->setPos(xPos, yPos);
    m_scene->addItem(item);

    QPoint p1(
        xPos + item->boundingRect().width() / 2,
        yPos + item->boundingRect().height()
    );

    yPos += item->boundingRect().height() + 30;

    if (root->left)
    {
        QPoint p2(
            (xCenter + leftBorderPos) / 2,
            yPos
        );
        m_scene->addLine(QLineF(p1, p2));
    }
    if (root->right)
    {
        QPoint p2(
            (xCenter + rightBorderPos) / 2,
            yPos
        );
        m_scene->addLine(QLineF(p1, p2));
    }


    paintTree(root->left, leftBorderPos, xCenter, yPos);
    paintTree(root->right, xCenter, rightBorderPos, yPos);
}

void TreeWidget::repaintTree()
{
    ui->graphicsView->setSceneRect(0, 0, ui->graphicsView->viewport()->width(), ui->graphicsView->viewport()->height());
    m_scene->clear();
    paintTree();
}
