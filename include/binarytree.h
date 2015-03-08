#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iomanip>
#include <fstream>
#include <iostream>

namespace DeepSearch {
    struct Node {
        int keyValue;
        Node *left  = NULL;
        Node *right = NULL;
};

    class BinaryTree {
        public:
            BinaryTree() : m_root(NULL) {};
            virtual ~BinaryTree();

            void insertKey(int key);
            Node *searchKey(int key);
            void destroyTree();

            Node *root();

            void print();

        private:
            void destroyTree(Node *leaf);
            void insertNode(int key, Node *leaf);
            Node *searchNode(int key, Node *leaf);

            void printRecursive(Node *node, int ident = 0);

            Node *m_root;
};

    void DepthFirstTraversal(Node *node);

    void PrintDotTree(Node *node);
    void PrintDotTreeAux(Node *node, std::ostream& dotFile);
    void PrintDotTreeNull(int key, int nullcount, std::ostream& dotFile);

}


#endif // BINARYTREE_H
