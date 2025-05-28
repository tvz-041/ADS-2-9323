#pragma once

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class BaseHashTableWidget; }
QT_END_NAMESPACE

class BaseHashTableWidget : public QWidget
{
    Q_OBJECT

public:
    BaseHashTableWidget(QWidget *parent = nullptr);
    ~BaseHashTableWidget();

protected slots:
    virtual void addKeyValue();
    virtual void resizeTable();

protected:
    Ui::BaseHashTableWidget *ui;
};
