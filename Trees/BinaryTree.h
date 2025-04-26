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
    void clear();

    static BinaryTree *buildRandom(int min = 0, int max = 100);

protected:
    void add(int key, Node *&root);
    void clear(Node *&root);

private:
    Node *m_root = nullptr;
};

