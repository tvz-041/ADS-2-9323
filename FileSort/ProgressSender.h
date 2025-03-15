#pragma once

#include <QObject>

class ProgressSender : public QObject
{
    Q_OBJECT
public:
    explicit ProgressSender(QObject *parent = nullptr);

    /**
     * @brief Сообщает GUI начальное количество отрезков.
     * @param count количество отрезков.
     */
    void setSegmentCount(int count);

    /**
     * @brief Сообщает GUI об уменьшении числа отрезков.
     * @param segmentLeft количество оставшихся отрезков.
     */
    void onSegmentMerged(int segmentLeft);

signals:
    void segmentCountChanged(int count);
    void segmentMerged(int segmentLeft);
};
