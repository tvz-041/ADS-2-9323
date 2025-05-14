#pragma once

#include <array>
#include <iostream>

class HuffmanTree
{
struct Node
{
    ~Node();

    std::string stringifySymbols() const;

    void printHorizontal(Node *root, int marginLeft = 0, int levelSpacing = 4) const;

    int frequency = 1;
    std::array<bool, 256> symbols = {false};
    Node *left = nullptr;
    Node *right = nullptr;
};

public:
    HuffmanTree() = default;
    ~HuffmanTree();

    void clear();

    void print();

    void build(const std::string &text);
    double encode(const std::string &text, std::string &encodedText);
    bool decode(const std::string &encodedText, std::string &decodedText);

private:
    std::string encode(const char symbol);
    bool decode(std::istream &encodedStream, std::ostream &decodedStream);

private:
    Node *m_root = nullptr;
};
