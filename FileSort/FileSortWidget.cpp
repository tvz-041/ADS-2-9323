#include <QDebug>
#include <QFileDialog>

#include "FileSortWidget.h"
#include "ui_FileSortWidget.h"


FileSortWidget::FileSortWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton_sort, &QPushButton::clicked, this, &FileSortWidget::sort);

    connect(&m_sorter, &FileSorter::segmentCountChanged, this, &FileSortWidget::onSegmentCountChanged);
    connect(&m_sorter, &FileSorter::segmentMerged, this, &FileSortWidget::onSegmentMerged);
    connect(&m_sorter, &FileSorter::sortFinished, this, &FileSortWidget::onSortFinished);

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
    QFile unsortedFile(ui->lineEdit_unsortedFile->text());
    QFile sortedFile(ui->lineEdit_sortedFile->text());
    if (unsortedFile.fileName() != sortedFile.fileName())
    {
        unsortedFile.remove();
        sortedFile.copy(unsortedFile.fileName());
    }
    m_sorter->sort(ui->lineEdit_sortedFile->text());
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
}


void FileSortWidget::onSortFinished(int returnCode)
{
    if (returnCode != 1)
    {
        QMessageBox::warning(
            this,
            tr("Warning"),
            tr("File is not sorted.\n"
               "Please enshure that file path is valid.\n"
               "If it is correct please contact with developer.")
        );
    }
    setEnabled(true);
}
