#include "Node.h"
#include "Tree.h"


int main() {
    std::string word = " ";
    std::vector<std::string> vec;
    std::cout << "Enter words (enter q to quit):" << std::endl;
    while (word != "q") {
        std::cin >> word;
        if (word != "q")
            vec.push_back(word);
    }

    Tree tree;
    tree.create_tree(vec);

    std::string prompt;
    std::cout << "Enter prompt: ";
    std::cin >> prompt;
    tree.search(prompt);
}
