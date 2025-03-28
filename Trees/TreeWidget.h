#pragma once

#include <QWidget>

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

public slots:
    void foo();

private:
    Ui::TreeWidget *ui;
    QGraphicsScene *m_scene;
    QCheckBox *m_checkBox;
    QPushButton *m_button;
};
