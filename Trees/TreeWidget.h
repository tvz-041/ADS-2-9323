#pragma once

#include <QWidget>

#include "BinaryTree.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class TreeWidget;
}
QT_END_NAMESPACE

class QGraphicsScene;
class QCheckBox;
class QPushButton;

class TreeWidget : public QWidget
{
    Q_OBJECT

public:
    TreeWidget(QWidget *parent = nullptr);
    ~TreeWidget();

    void paintTree();
    void paintTree(BinaryTree::Node *root, int leftBorderPos, int rightBorderPos,
                   int yPos) const;

    void show();

public slots:
    void repaintTree();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::TreeWidget *ui;
    QGraphicsScene *m_scene;
    QCheckBox *m_checkBox;
    QPushButton *m_button;
    BinaryTree *m_tree = nullptr;
};
