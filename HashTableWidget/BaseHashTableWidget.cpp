#include "BaseHashTableWidget.h"
#include "ui_BaseHashTableWidget.h"

BaseHashTableWidget::BaseHashTableWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::BaseHashTableWidget)
{
    ui->setupUi(this);
    connect(ui->spinBox_size, &QSpinBox::editingFinished, this, &BaseHashTableWidget::resizeTable);
    connect(ui->pushButton_add, &QPushButton::clicked, this, &BaseHashTableWidget::addKeyValue);
}

BaseHashTableWidget::~BaseHashTableWidget()
{
    delete ui;
}

void BaseHashTableWidget::addKeyValue()
{
}

void BaseHashTableWidget::resizeTable()
{
}
