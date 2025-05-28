#include "HashTableWidget.h"
#include "ui_BaseHashTableWidget.h"

HashTableWidget::HashTableWidget(QWidget *parent)
    : BaseHashTableWidget(parent)
    , m_tableWidget(new QTableWidget(this))
{
    ui->verticalLayout->insertWidget(0, m_tableWidget);
}


void HashTableWidget::addKeyValue()
{
    // TODO: проверка на повтор ключа
    int row = -1;
    // TODO: заменить определение строки
    {
        while (row < 0 || !m_tableWidget->item(row, 0)->text().isEmpty())
        {
            row = rand() % m_tableWidget->rowCount();
        }
    }

    m_tableWidget->item(row, 0)->setText(ui->spinBox_key->text());
    QTableWidgetItem *item = m_tableWidget->item(row, 1);
    item->setText(ui->lineEdit_value->text());
    item->setFlags(item->flags() | Qt::ItemIsEditable);
}

void HashTableWidget::resizeTable()
{
    // TODO: resize хеш-таблицы
    int oldSize = m_tableWidget->rowCount();
    m_tableWidget->setRowCount(ui->spinBox_size->value());
    for (int i = 0; i < oldSize; ++i)
    {
        // TODO: заполнить новыми значениями из хеш-таблицы
    }
    for (int i = oldSize; i < m_tableWidget->rowCount(); ++i)
    {
        m_tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i)));
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setTextAlignment(Qt::AlignCenter);
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        m_tableWidget->setItem(i, 0, item);

        item = new QTableWidgetItem();
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        m_tableWidget->setItem(i, 1, item);
    }
}
