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

BinaryTree *BinaryTree::buildRandom(int min, int max)
{
    if (min > max)
    {
        std::swap(min , max);
    }

    BinaryTree *tree = new BinaryTree();
    std::vector<int> keys(max - min + 1);
    for (int i = min; i <= max; ++i)
    {
        keys[i - min] = i;
    }

    while (!keys.empty())
    {
        int index = rand() % keys.size();
        tree->add(keys[index]);
        keys.erase(keys.begin() + index);
    }

    return tree;
}

void BinaryTree::clear()
{
    clear(m_root);
}

void BinaryTree::clear(Node *&root)
{
    if (!root)
    {
        return;
    }

    clear(root->left);
    clear(root->right);

    delete root;
    root = nullptr;
}
