#include "binarytree.h"

DeepSearch::BinaryTree::~BinaryTree()
{
    this->destroyTree();
}

void DeepSearch::BinaryTree::destroyTree(Node *leaf)
{
    if(leaf != NULL) {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

void DeepSearch::BinaryTree::insertNode(int key, Node *leaf)
{
    if(key < leaf->keyValue) {
        if(leaf->left != NULL)
            insertNode(key, leaf->left);
        else {
            leaf->left = new Node;
            leaf->left->keyValue = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    } else if(key >= leaf->keyValue) {
        if(leaf->right != NULL)
            insertNode(key, leaf->right);
        else {
            leaf->right = new Node;
            leaf->right->keyValue = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

DeepSearch::Node *DeepSearch::BinaryTree::searchNode(int key, Node *leaf)
{
    if(leaf != NULL) {
        if(key == leaf->keyValue)
            return leaf;
        if(key < leaf->keyValue)
            return searchNode(key, leaf->left);
        else
            return searchNode(key, leaf->right);
    }
    else
        return NULL;
}

void DeepSearch::BinaryTree::insertKey(int key)
{
    if(this->m_root != NULL)
        this->insertNode(key, this->m_root);
    else {
        this->m_root = new Node;
        this->m_root->keyValue = key;
        this->m_root->left = NULL;
        this->m_root->right = NULL;
    }
}

DeepSearch::Node *DeepSearch::BinaryTree::searchKey(int key)
{
    return this->searchNode(key, this->m_root);
}

void DeepSearch::BinaryTree::destroyTree()
{
    destroyTree(this->m_root);
}

DeepSearch::Node *DeepSearch::BinaryTree::root()
{
    return this->m_root;
}

void DeepSearch::BinaryTree::print()
{
    this->printRecursive(this->m_root);
}

void DeepSearch::BinaryTree::printRecursive(Node *node, int ident)
{
    if(!node)
        return;

    printRecursive(node->left, ident);

    ident++;
    std::cout << node->keyValue << std::endl;

    printRecursive(node->right, ident);
}

void DeepSearch::DepthFirstTraversal(Node *node)
{
    if(node)
    {
        if(node->left)
            DepthFirstTraversal(node->left);
        if(node->right)
            DepthFirstTraversal(node->right);

        std::cout << node->keyValue << " ";;
    }
}

void DeepSearch::PrintDotTree(Node *node)
{
    std::ofstream dotFile ("Graphviz/binarytree.gv");

    dotFile << "digraph G {\n" << "    node [fontname=\"Arial\"];\n" << "    graph [ordering=\"out\"];\n";

    if(!node)
        dotFile << "\n";
    else if (!node->right && !node->left)
        dotFile << node->keyValue << ";\n";
    else
        PrintDotTreeAux(node, dotFile);

    dotFile << "}\n";
    dotFile.close();
}

void DeepSearch::PrintDotTreeAux(Node* node, std::ostream& dotFile)
{
    static int nullcount = 0;

    if(node->left) {
        dotFile << "    " << node->keyValue << " -> " << node->left->keyValue << ";\n";
        PrintDotTreeAux(node->left, dotFile);
    } else
        PrintDotTreeNull(node->keyValue, nullcount++, dotFile);

    if(node->right){
        dotFile << "    " << node->keyValue << " -> " << node->right->keyValue << ";\n";
        PrintDotTreeAux(node->right, dotFile);
     } else
        PrintDotTreeNull(node->keyValue, nullcount++, dotFile);
}

void DeepSearch::PrintDotTreeNull(int key, int nullcount, std::ostream& dotFile)
{
    dotFile << "    null" << nullcount << " [shape=none];\n";
    dotFile << "    " << key << " -> null" << nullcount << ";\n";
}

