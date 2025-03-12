#include "ProgressSender.h"

#include "sortFunctions.h"

void sort(const std::string &filename, ProgressSender* sender)
{
    const int MergeCount = 3;
    int segmentLeft = rand() % 1000 + 10;
    sender->setSegmentCount(segmentLeft);

    while (segmentLeft > 1)
    {
        int max = 0;
        for (int i = 0; i < 15000000; ++i)
        {
            max = (max + i) % 20;
        }

        if (segmentLeft <= MergeCount)
            segmentLeft = 1;
        else
            segmentLeft = segmentLeft - MergeCount + 1;
        sender->onSegmentMerged(segmentLeft);
    }
}
