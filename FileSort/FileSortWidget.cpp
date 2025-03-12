#include <QDebug>
#include <QFileDialog>

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

    connect(ui->toolButton_unsortedFile, &QToolButton::clicked, this, &FileSortWidget::selectUnsortedFile);
    connect(ui->toolButton_sortedFile, &QToolButton::clicked, this, &FileSortWidget::setSortedFilePath);
}

FileSortWidget::~FileSortWidget()
{
    delete ui;
}

void FileSortWidget::selectUnsortedFile()
{
    QString filePath = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "",
        tr("Unsorted File (*.txt *.злой);;All files (*.*)")
    );
    ui->lineEdit_unsortedFile->setText(filePath);
}

void FileSortWidget::setSortedFilePath()
{
    QString filePath = QFileDialog::getSaveFileName(
        this,
        tr("Open File"),
        "",
        tr("Sorted File (*.добрый *.txt);;All files (*.*)")
    );
    ui->lineEdit_sortedFile->setText(filePath);
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
