#include <iostream>
#include <numeric>

#include "HuffmanTree.h"

using namespace std;

int main()
{
    HuffmanTree tree;
    tree.build("ehal greka cerez reku");
    tree.print();
    return 0;
}
