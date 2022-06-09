#pragma once

#include <string>
#include <iostream>


struct Node {
    std::string word;
    Node *left{}, *right{};

    explicit Node(const std::string& word) { this->word = word; }
};
