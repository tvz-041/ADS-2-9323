#include <algorithm>
#include <vector>

#include "HuffmanTree.h"

HuffmanTree::Node::~Node()
{
    if (left)
    {
        delete left;
    }
    if (right)
    {
        delete right;
    }
}

std::string HuffmanTree::Node::stringifySymbols() const
{
    std::string str;
    for (int i = 0; i < symbols.size(); ++i)
    {
        if (symbols[i])
        {
            str += char(i);
        }
    }
    return str;
}

void HuffmanTree::Node::printHorizontal(Node *root, int marginLeft, int levelSpacing) const
{
    if (root == nullptr) {
        return;
    }
    printHorizontal(root->right, marginLeft + levelSpacing, levelSpacing);
    std::cout << std::string(marginLeft, ' ');
    std::cout << root->frequency << ' ' << root->stringifySymbols();
    std::cout << std::endl;
    printHorizontal(root->left, marginLeft + levelSpacing, levelSpacing);
}


HuffmanTree::~HuffmanTree()
{
    clear();
}

void HuffmanTree::clear()
{
    if (m_root)
    {
        delete m_root;
        m_root = nullptr;
    }
}

void HuffmanTree::print()
{
    m_root->printHorizontal(m_root);
}

void HuffmanTree::build(const std::string &text)
{
    if (m_root)
    {
        clear();
    }

    std::vector<Node*> nodes;
    for (const char &symbol : text)
    {
        std::vector<Node*>::iterator it = std::find_if(
            nodes.begin(),
            nodes.end(),
            [&symbol](Node *node) // Безымянная функция
            {
                return node->symbols[symbol];
            }
        );

        if (it == nodes.end())
        {
            nodes.push_back(new Node());
            nodes.back()->symbols[symbol] = true;
        }
        else
        {
            Node *node = *it;
            node->frequency++;
        }
    }

    // Ещё одна безымянная функция, сложили в переменную
    auto sorter = [](Node *a, Node *b) -> bool
    {
        return a->frequency < b->frequency;
    };
    std::sort(nodes.begin(), nodes.end(), sorter);

    while (nodes.size() > 1)
    {
        Node *root = new Node();
        root->frequency = nodes[0]->frequency + nodes[1]->frequency;
        for (int i = 0; i < root->symbols.size(); ++i)
        {
            root->symbols[i] = nodes[0]->symbols[i] || nodes[1]->symbols[i];
        }
        root->left = nodes[0];
        root->right = nodes[1];

        nodes.erase(nodes.begin(), nodes.begin() + 2);
        nodes.push_back(root);
        std::sort(nodes.begin(), nodes.end(), sorter);
    }

    m_root = nodes.front();
}

double HuffmanTree::encode(const std::string &text, std::string &encodedText)
{

}

bool HuffmanTree::decode(const std::string &encodedText, std::string &decodedText)
{

}

std::string HuffmanTree::encode(const char symbol)
{

}

bool HuffmanTree::decode(std::istream &encodedStream, std::ostream &decodedStream)
{

}
