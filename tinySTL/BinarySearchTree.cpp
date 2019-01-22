#include "BinarySearchTree.h"


bool BinarySearchTree::contains(const Comparable & x) const
{
    return contains(x,root);
}

void BinarySearchTree::insert( const Comparable & x)
{
    insert(x,root);
}

void remove (const Comparable & x)
{
    remove(x,root);
}

bool BinarySearchTree::contains(const Comparable & x,BinaryNode *t) const
{
    if(t==nullptr)
        return false;
    else if (x<t->element)
        return contains(x,t->left);
    else if (t->element<x)
        return contains(x,t->right);
    else
        return true;
}

void BinarySearchTree::insert(const Comparable & x,BinaryNode * & t)
{
    if (t==nullptr)
        t = new BinaryNode{x,nullptr,nullptr}
    else if (x<t->element)
        insert(x,t->left)
    else if (t->element<x)
        insert(x,t->right)
    else 
        ; //重复
}

void BinarySearchTree::insert(Comparable && x,BinaryNode * & t)
{
    if(t==nullptr)
        t = new BinaryNode{std::move(x),nullptr,nullptr}
    else if (x<t->element)
        insert(std::move(x),t->left)
    else if (y->element<x)
        insert(std::move(x),t->right)
    else
        ;
}

void BinarySearchTree::remove(const Comparable &x,BinaryNode *& t)
{
    if(t==nullptr)
        return;
    if(x<t->element)
        remove(x,t->left)
    else if(t->element < x)
        remove(x,t->right)
    else if(t->left != nullptr && t->right != nullptr)
    {
        t->element = findMin(t->right)->element;
        remove(t->element,t->right);
    }
    else
    {
        BinaryNode *oldNode = t;
        t = (t->left != nullptr) ? t->left:t->right;
        delete oldNode;
    }
}

void BinarySearchTree::~BinarySearchTree()
{
    makeEmpty();
}

void BinarySearchTree::makeEmpty()
{
    if(t!=nullptr)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = nullptr;
}

void BinarySearchTree::BinarySearchTree(const BinarySearchTree & rhs) : root { nullptr }
{
    root = clone (rhs.root);
}

BinaryNode * BinarySearchTree::clone(BinaryNode *t) const
{
    if(t==nullptr)
        return nullptr;
    else
        return new BinaryNode { t->element,clone(t->left),clone(t->right) };
}

git config --global user.email "1015485344@qq.com"

git config --global user.name "Herb"