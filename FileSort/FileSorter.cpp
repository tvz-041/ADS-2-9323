#include "sortFunctions.h"

#include "FileSorter.h"

FileSorter::FileSorter(QObject *parent)
    : QObject{parent}
{}

void FileSorter::sort(const QString &filename)
{
    int returnCode = ::sort(filename.toStdString(), this);
    emit sortFinished(returnCode);
}

void FileSorter::setSegmentCount(int count)
{
    emit segmentCountChanged(count);
}

void FileSorter::onSegmentMerged(int segmentLeft)
{
    emit segmentMerged(segmentLeft);
}
