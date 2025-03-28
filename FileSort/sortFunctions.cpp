#include <thread>

#include "FileSorter.h"

#include "sortFunctions.h"

// TODO: заменить содержимое вызовом вашей сортировки
// Если нужно передавать доп. параметры, также поправить следующие методы:
// FileSortWidget::sort()
// FileSorter::sort(const QString &filename)
bool sort(const std::string &filename, FileSorter* sorter)
{
    if (filename.empty())
    {
        return false;
    }

    const int FileCount = 3;
    int segmentLeft = 300;
    sorter->setSegmentCount(segmentLeft);

    while (segmentLeft > 1)
    {
        // Искуственная задержка для имитации работы
        std::this_thread::sleep_for(std::chrono::milliseconds(30));

        int mergeCount = FileCount - 1; // Слили FileCount отрезков в 1
        if (segmentLeft <= FileCount)
            mergeCount = segmentLeft - 1;
        segmentLeft -= mergeCount;
        sorter->onSegmentMerged(mergeCount);
    }

    // См. документацию метода "FileSorter::onSegmentMerged"
    // sorter->onSegmentMerged(-1);

    return true;
}
