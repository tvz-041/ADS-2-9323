#pragma once

#include <QObject>

class FileSorter : public QObject
{
    Q_OBJECT
public:
    explicit FileSorter(QObject *parent = nullptr);


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

public slots:
    void sort(const QString &filename);

signals:
    void segmentCountChanged(int count);
    void segmentMerged(int segmentLeft);
    void sortFinished(int reason);
};
