#pragma once

#include <QObject>

class ProgressSender : public QObject
{
    Q_OBJECT
public:
    explicit ProgressSender(QObject *parent = nullptr);

    void setSegmentCount(int count);
    void onSegmentMerged(int segmentLeft);

signals:
    void segmentCountChanged(int count);
    void segmentMerged(int segmentLeft);
};
