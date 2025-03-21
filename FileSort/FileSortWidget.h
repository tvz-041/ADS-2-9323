#pragma once

#include <QWidget>

#include "FileSorter.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class FileSortWidget : public QWidget
{
    Q_OBJECT

public:
    FileSortWidget(QWidget *parent = nullptr);
    ~FileSortWidget();
    
    void selectUnsortedFile();
    void setSortedFilePath();

public slots:
    void sort();

signals:
    void fileSortRequested(const QString& fileName);

private slots:
    void onSegmentCountChanged(int count);
    void onSegmentMerged(int segmentLeft);
    void onSortFinished(int returnCode);

private:
    Ui::Widget *ui;
    QThread *m_thread = nullptr;
    FileSorter *m_sorter = nullptr;
};
