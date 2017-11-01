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