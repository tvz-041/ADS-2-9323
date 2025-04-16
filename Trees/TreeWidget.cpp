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

    int xPos = (leftBorderPos + rightBorderPos - item->boundingRect().width()) / 2;
    item->setPos(xPos, yPos);
    m_scene->addItem(item);

    QPoint p1(
        xPos + item->boundingRect().width(),
        yPos + item->boundingRect().height()
    );

    yPos += item->boundingRect().height() + 15;

    if (root->left)
    {
        auto child = TreeNodeGraphicsItem(root->left->key);
        QPoint p2(
            (xPos - leftBorderPos) / 2,
            yPos
        );
        m_scene->addLine(QLineF(p1, p2));
    }

    paintTree(root->left, leftBorderPos, xPos, yPos);
    paintTree(root->right, xPos, rightBorderPos, yPos);
}

void TreeWidget::foo()
{
    ui->graphicsView->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    m_scene->clear();
    paintTree();
}
