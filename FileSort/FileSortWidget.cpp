#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QThread>

#include "FileSortWidget.h"
#include "ui_FileSortWidget.h"


FileSortWidget::FileSortWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_thread(new QThread(this))
    , m_sorter(new FileSorter())
{
    ui->setupUi(this);

    connect(ui->toolButton_unsortedFile, &QToolButton::clicked, this, &FileSortWidget::selectUnsortedFile);
    connect(ui->toolButton_sortedFile, &QToolButton::clicked, this, &FileSortWidget::setSortedFilePath);

    connect(ui->pushButton_sort, &QPushButton::clicked, this, &FileSortWidget::sort);

    connect(m_sorter, &FileSorter::segmentCountChanged, this, &FileSortWidget::onSegmentCountChanged);
    connect(m_sorter, &FileSorter::segmentMerged, this, &FileSortWidget::onSegmentMerged);

    /**
     * В нашей реализации поток активен всё время работы программы.
     * Если же нужно активировать поток только на время выполнения задачи
     * (и автоматически закрыть по завершении), используйте следующий вариант реализации:
     *
     * worker->moveToThread(workerThread)
     * connect(workerThread, &QThread::started, worker, &Worker::doWork);
     * connect(worker, &Worker::resultReady, this, &Controller::handleResults);
     * connect(workerThread, &QThread::finished, worker, &QObject::deleteLater);
     * thread->start();
     */

    connect(this, &FileSortWidget::fileSortRequested, m_sorter, &FileSorter::sort);
    connect(m_sorter, &FileSorter::sortFinished, this, &FileSortWidget::onSortFinished);
    m_sorter->moveToThread(m_thread); // Переместили объект сортировщика в отдельный поток
    m_thread->start();
}

FileSortWidget::~FileSortWidget()
{
    delete ui;
    m_thread->terminate();
    m_sorter->deleteLater();
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
    setEnabled(false);
    QFile unsortedFile(ui->lineEdit_unsortedFile->text());
    QFile sortedFile(ui->lineEdit_sortedFile->text());
    if (unsortedFile.fileName() != sortedFile.fileName())
    {
        unsortedFile.remove();
        sortedFile.copy(unsortedFile.fileName());
    }
    emit fileSortRequested(ui->lineEdit_sortedFile->text());
}

void FileSortWidget::onSegmentCountChanged(int count)
{
    ui->progressBar->setMaximum(count - 1);
    ui->progressBar->setValue(ui->progressBar->minimum());
}

void FileSortWidget::onSegmentMerged(int mergeCount)
{
    if (mergeCount < 0)
    {
        ui->progressBar->setValue(ui->progressBar->maximum());
    }
    else
    {
        ui->progressBar->setValue(ui->progressBar->value() + mergeCount);
    }
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
