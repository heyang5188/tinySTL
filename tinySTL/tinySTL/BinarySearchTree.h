#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>

template <typename Comparable >
class BinarySearchTree {
public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree & rhs);
    BinarySearchTree(BinarySearchTree &&rhs );
    ~BinarySearchTree();

    const Comparable & findMin () const;
    const Comparable & findMax () const;

    bool contains ( const Comparable & x ) const;
    bool isEmpty() const;
    void printTree( ostream & out = cout ) const;

    void makeEmpty();
    void insert( const Comparable & x );
    void insert( Comparable && x);
    void remove(const Comparable & x);

    BinarySearchTree & operator=(const BinarySearchTree & rhs);
    BinarySearchTree & operator=( BinarySearchTree && rhs);

private:
    struct BinaryNode {
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;
        
        BinaryNode(const Comparable & theElement,BinaryNode *lt ,BinaryNode *rt)
            :element(theElement),left(lt),right(rt)
        BinaryNode(Comparable && theElement,BinaryNode * lt,BinaryNode *rt)
            :element(std::move(theElement)),left(lt),right(rt)
    };

  

    BinaryNode *root;

    void insert( const Comparable & x,BinaryNode * & t );
    void insert( Comparable && x,BinaryNode * & x);
    void remove( const Comparable & x,BinaryNode * & t);

    BinaryNode * findMin (BinaryNode * t) const;
    BinaryNode * findMax (BinaryNode * t) const;
    bool contains (const Comparable & x,BinaryNode *t) const;
    void makeEmpty(BinaryNode *& t);
    void printTree (BinaryNode * t,ostream & out) const;
    BinaryNode * clone( BinaryNode * t) const;

    struct AvlNode {
        Comparable element;
        AvlNode *left;
        AvlNode *right;
        int height;
        AvlNode(const Comparable &ele ,AvlNode *lt,AvlNode *rt,int h = 0)
            :element{ele},left(lt),right(rt),height(h){}
        AvlNode(Comparable && ele,AvlNode *lt,AvlNode *rt,int h = 0)
            :element(std::move(ele)),left(lt),rigth(rt),height(h){}  
    };
    /*
        返回节点的高度，如果是空的树则返回-1
    */
    int height(AvlNode *t)
    {
        return t == nullptr ? -1:t->height;
    }

    void insert(const Comparable & x,AvlNode * & t)
    {
        if(t==nullptr)
            t=new AvlNode(x,nullptr,nullptr);
        else if (x<t->element)
            insert(x,t->left);
        else if (t->element<x)
            insert(x,t->right);

        balance(t);
    }

    static const int ALLOWED_IMBALANCE = 1;

    void balance(AvlNode *&t)
    {
        if(height(t->left)-height(t->right)>ALLOWED_IMBALANCE)
            if(height(t->left->left)>=height(t->left->right))
                rotateWithLeftChild(t)
            else
                doubleWithLeftChild(t)
        else
        if(height(t->right)-height(t->left)>ALLOWED_IMBALANCE)
            if(height(t->right->right)>=height(t->right->left))
                rotateWithRightChild(t)
            else
                doubleWithRigthChilde(t)
        
        t->height = max(height(t->left),height(t->right)) + 1;
    }
    void rotateWithLeftChild(AvlNode * & k2)
    {
        AvlNode *k1 = k2 ->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left),height(k2->right))+1;
        k1->height = max(height(k1->left),k2->height)+1;
        k2=k1;
    }
};




#endif // !BINARYSEARCHTREE