#include <ctime>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "binarytree.h"

using namespace std;

int randomgen(int i)
{
    return std::rand() % i;
}

int main()
{
    std::vector<int> numbers;
    DeepSearch::BinaryTree teste;

    srand(time(NULL));

    for(int i = 0; i <= 15; i++)
        numbers.push_back(i);

    std::random_shuffle(numbers.begin(), numbers.end());
    std::random_shuffle(numbers.begin(), numbers.end(), randomgen);

    for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        teste.insertKey(*it);

    DeepSearch::PrintDotTree(teste.root());

    teste.print();

    system("dot Graphviz/binarytree.gv | gvpr -c -fGraphviz/tree.gv | neato -n -Tpng -o Graphviz/binarytree.png");
}
