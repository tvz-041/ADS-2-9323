#pragma once

#include <QWidget>

namespace Ui {
class TableElementWidget;
}

class TableElementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TableElementWidget(QWidget *parent = nullptr);
    ~TableElementWidget();

    int key() const;
    QString value() const;

    void setKey(int key);
    void setValue(const QString &value);

    bool isEmpty() const;

private:
    Ui::TableElementWidget *ui;
};

