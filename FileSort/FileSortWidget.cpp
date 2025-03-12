#include <QDebug>

#include "sortFunctions.h"

#include "FileSortWidget.h"
#include "ui_FileSortWidget.h"


FileSortWidget::FileSortWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton_sort, &QPushButton::clicked, this, &FileSortWidget::sort);

    connect(&m_sender, &ProgressSender::segmentCountChanged, this, &FileSortWidget::onSegmentCountChanged);
    connect(&m_sender, &ProgressSender::segmentMerged, this, &FileSortWidget::onSegmentMerged);
}

FileSortWidget::~FileSortWidget()
{
    delete ui;
}

void FileSortWidget::sort()
{
    ::sort(ui->lineEdit_sortedFile->text().toStdString(), &m_sender);
}

void FileSortWidget::onSegmentCountChanged(int count)
{
    ui->progressBar->setMaximum(count);
    ui->progressBar->setValue(ui->progressBar->minimum());
}

void FileSortWidget::onSegmentMerged(int segmentLeft)
{
    ui->progressBar->setValue(ui->progressBar->maximum() - segmentLeft + ui->progressBar->minimum());
    QApplication::processEvents();
    setEnabled(ui->progressBar->value() == ui->progressBar->maximum());
    ui->progressBar->setEnabled(true);
}
