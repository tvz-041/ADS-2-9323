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
     * @param mergeCount количество слитых отрезков.
     *
     * @note при естественном слиянии суммарное число слитых отрезков может оказаться меньше,
     * чем исходное из-за слияния соседних отрезков в выходном файле.
     * Для корректного установления прогресс-бара на 100% в конце сортировки
     * вызовите данный метод с параметром "-1".
     */
    void onSegmentMerged(int mergeCount);

public slots:
    void sort(const QString &filename);

signals:
    void segmentCountChanged(int count);
    void segmentMerged(int mergeCount);
    void sortFinished(int reason);
};
