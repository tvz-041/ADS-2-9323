#pragma once


class BinaryTree
{
public:
    struct Node
    {
        int key;
        Node *left = nullptr;
        Node *right = nullptr;
    };

public:
    BinaryTree();
    Node *root();
    void add(int key);

    static BinaryTree *buildRandom(int min = 0, int max = 100);

protected:
    void add(int key, Node *&root);

private:
    Node *m_root = nullptr;
};

