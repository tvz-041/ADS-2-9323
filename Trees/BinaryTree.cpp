#include <stdlib.h>
#include <vector>

#include "BinaryTree.h"

BinaryTree::BinaryTree()
{

}

BinaryTree::Node *BinaryTree::root()
{
    return m_root;
}

void BinaryTree::add(int key)
{
    add(key, m_root);
}

void BinaryTree::add(int key, Node *&root)
{
    if (!root)
    {
        root = new Node();
        root->key = key;
    }
    else if (rand() % 2)
    {
        add(key, root->left);
    }
    else
    {
        add(key, root->right);
    }
}

BinaryTree *BinaryTree::buildRandom(int count)
{
    BinaryTree *tree = new BinaryTree();
    std::vector<int> keys(count);
    for (int i = 0; i < count; ++i)
    {
        keys[i] = i;
    }

    while (!keys.empty())
    {
        int index = rand() % keys.size();
        tree->add(keys[index]);
        keys.erase(keys.begin() + index);
    }

    return tree;
}
