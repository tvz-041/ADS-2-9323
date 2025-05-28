#include "BaseHashTableWidget.h"
#include "ui_BaseHashTableWidget.h"

BaseHashTableWidget::BaseHashTableWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BaseHashTableWidget)
{
    ui->setupUi(this);
    connect(ui->spinBox_size, &QSpinBox::editingFinished, this, &BaseHashTableWidget::resizeTable);
    connect(ui->pushButton_add, &QPushButton::clicked, this, &BaseHashTableWidget::addKeyValue);
    resizeTable();
}

BaseHashTableWidget::~BaseHashTableWidget()
{
    delete ui;
}

void BaseHashTableWidget::addKeyValue()
{
//    // TODO: проверка на повтор ключа
//    int row = -1;
//    // TODO: заменить определение строки
//    {
//        while (row < 0 || !ui->tableWidget->item(row, 0)->text().isEmpty())
//        {
//            row = rand() % ui->tableWidget->rowCount();
//        }
//    }

//    ui->tableWidget->item(row, 0)->setText(ui->spinBox_key->text());
//    QTableWidgetItem *item = ui->tableWidget->item(row, 1);
//    item->setText(ui->lineEdit_value->text());
//    item->setFlags(item->flags() | Qt::ItemIsEditable);
}

void BaseHashTableWidget::resizeTable()
{
//    // TODO: resize хеш-таблицы
//    int oldSize = ui->tableWidget->rowCount();
//    ui->tableWidget->setRowCount(ui->spinBox_size->value());
//    for (int i = 0; i < oldSize; ++i)
//    {
//        // TODO: заполнить новыми значениями из хеш-таблицы
//    }
//    for (int i = oldSize; i < ui->tableWidget->rowCount(); ++i)
//    {
//        ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i)));
//        QTableWidgetItem *item = new QTableWidgetItem();
//        item->setTextAlignment(Qt::AlignCenter);
//        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
//        ui->tableWidget->setItem(i, 0, item);

//        item = new QTableWidgetItem();
//        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
//        ui->tableWidget->setItem(i, 1, item);
//    }
}
