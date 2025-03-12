#include "ProgressSender.h"

ProgressSender::ProgressSender(QObject *parent)
    : QObject{parent}
{}

void ProgressSender::setSegmentCount(int count)
{
    emit segmentCountChanged(count);
}

void ProgressSender::onSegmentMerged(int segmentLeft)
{
    emit segmentMerged(segmentLeft);
}
