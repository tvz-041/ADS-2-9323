#pragma once

#include <QWidget>

#include "ProgressSender.h"

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

private slots:
    void onSegmentCountChanged(int count);
    void onSegmentMerged(int segmentLeft);

private:
    Ui::Widget *ui;
    ProgressSender m_sender;
};
