#include "TableElementWidget.h"
#include "ui_TableElementWidget.h"

TableElementWidget::TableElementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableElementWidget)
{
    ui->setupUi(this);
}

TableElementWidget::~TableElementWidget()
{
    delete ui;
}

int TableElementWidget::key() const
{
    return ui->lineEdit_key->text().toInt();
}

QString TableElementWidget::value() const
{
    return ui->lineEdit_value->text();
}

void TableElementWidget::setKey(int key)
{
    ui->lineEdit_key->setText(QString::number(key));
}

void TableElementWidget::setValue(const QString &value)
{
    ui->lineEdit_value->setText(value);
}

bool TableElementWidget::isEmpty() const
{
    return ui->lineEdit_key->text().isEmpty();
}
