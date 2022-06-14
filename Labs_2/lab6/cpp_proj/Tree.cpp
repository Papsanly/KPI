#include "Tree.h"
#include <stack>


void Tree::create_tree(const std::vector<std::string>& vec) {
    root = create_tree(vec, 0, vec.size());
}


Node* Tree::create_tree(const std::vector<std::string>& vec, unsigned long long from, unsigned long long size) {

    if (size == 0)
        return nullptr;

    Node* nodeptr = new Node(vec[from]);

    unsigned long long size_left = size / 2;
    unsigned long long size_right = size - size_left - 1;

    nodeptr->left = create_tree(vec, from + 1, size_left);
    nodeptr->right = create_tree(vec, from + 1 + size_left, size_right);

    return nodeptr;

}

void Tree::search(const std::string& prompt) {

    Node* current = root;
    bool stop = false;
    int level = 0;

    std::stack<Node*> stack;

    while (!stop) {
        while (current != nullptr) {
            stack.push(current);
            ++level;
            current = current->left;
        }
        if (stack.empty()) {
            std::cout << "Word \"" << prompt << "\" not found\n";
            stop = true;
        }
        else {
            --level;
            current = stack.top();
            if (current->word == prompt) {
                std::cout << "The word \"" << prompt << "\" found on level " << level << "\n";
                return;
            }
            current = current->right;
            stack.pop();
        }
    }

}
