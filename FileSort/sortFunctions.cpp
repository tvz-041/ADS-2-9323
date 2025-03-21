#include <thread>

#include "FileSorter.h"

#include "sortFunctions.h"

bool sort(const std::string &filename, FileSorter* sender)
{
    if (filename.empty())
    {
        return false;
    }

    const int MergeCount = 3;
    int segmentLeft = 300;
    sender->setSegmentCount(segmentLeft);

    while (segmentLeft > 1)
    {
        // Искуственная задержка для имитации работы
        std::this_thread::sleep_for(std::chrono::milliseconds(10));

        if (segmentLeft <= MergeCount)
            segmentLeft = 1;
        else
            segmentLeft = segmentLeft - MergeCount + 1;
        sender->onSegmentMerged(segmentLeft);
    }

    return true;
}
