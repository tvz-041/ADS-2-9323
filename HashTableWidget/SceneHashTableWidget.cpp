#include <QGraphicsProxyWidget>

#include "TableElementWidget.h"

#include "SceneHashTableWidget.h"
#include "ui_BaseHashTableWidget.h"

SceneHashTableWidget::SceneHashTableWidget(QWidget *parent)
    : BaseHashTableWidget(parent)
    , m_scene(new QGraphicsScene(this))
    , m_view(new QGraphicsView(this))
{
    m_view->setScene(m_scene);
    ui->verticalLayout->insertWidget(0, m_view);
}

void SceneHashTableWidget::addKeyValue()
{
    // TODO: проверка на повтор ключа
    int row = rand() % m_rows.size();
    int column = 0;
    // TODO: заменить определение строки
    {
        if (!m_rows[row][column]->isEmpty())
        {
            TableElementWidget *item = new TableElementWidget();
            //item->setTextAlignment(Qt::AlignCenter);
            //item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            QGraphicsProxyWidget* proxy = m_scene->addWidget(item);
            column = m_rows[row].size();
            int x = column * (item->width() + 50);
            int y = row * item->height();
            proxy->setX(x);
            proxy->setY(y);

            m_rows[row].append(item);
        }
    }

    m_rows[row][column]->setKey(ui->spinBox_key->value());
    m_rows[row][column]->setValue(ui->lineEdit_value->text());

    //item->setFlags(item->flags() | Qt::ItemIsEditable);
}

void SceneHashTableWidget::resizeTable()
{
    // TODO: resize хеш-таблицы
    int oldSize = m_rows.size();
    // TODO: Удалить лишние элементы
    m_rows.resize(ui->spinBox_size->value());

    for (int i = 0; i < oldSize; ++i)
    {
        // TODO: заполнить новыми значениями из хеш-таблицы
    }
    for (int i = oldSize; i < m_rows.size(); ++i)
    {
        //m_tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(QString::number(i)));
        TableElementWidget *item = new TableElementWidget();
        //item->setTextAlignment(Qt::AlignCenter);
        //item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        QGraphicsProxyWidget* proxy = m_scene->addWidget(item);
        proxy->setX(0);
        int y = i * item->height();
        proxy->setY(y);

        m_rows[i].append(item);
    }
}
