#pragma once

#include <vector>
#include "Node.h"


class Tree {

    Node *root;

public:

    Tree(): root(nullptr) {}
    void create_tree(const std::vector<std::string>& vec);
    Node* create_tree(const std::vector<std::string>& vec, unsigned long long from, unsigned long long size);
    void search(const std::string& prompt);

};
