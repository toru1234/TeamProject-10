#ifndef __TeamProject__BinaryTree__
#define __TeamProject__BinaryTree__

#include <stdio.h>
#include "BinaryNode.h"
#include <iostream>
#include <vector>

class BinaryTree
{
protected:
    BinaryNode* rootPtr;		// ptr to root node
    int count;							// number of nodes in tree
    
public:
    // "admin" functions
    BinaryTree() {rootPtr = 0; count = 0;}
    
    // copy constructor
    BinaryTree(const BinaryTree & tree);
    virtual ~BinaryTree() { }
    BinaryTree & operator = (const BinaryTree & sourceTree);
    
    // common functions for all binary trees
    bool isEmpty() const	{return count == 0;}
    int size() const	    {return count;}
    void clear()			{destroyTree(rootPtr); rootPtr = 0; count = 0;}
    void preOrder(void visit(Website &)) const {_preorder(visit, rootPtr);}
    void inOrder(void visit(Website &)) const  {_inorder(visit, rootPtr);}
    void writeNodesinFile(vector<Website>& outputFile)  {_writeNodesinFile(rootPtr, outputFile);}
    void inOrder(void visit(Website &),
                Website* minItem,
                Website* maxItem) const;
    void postOrder(void visit(Website &)) const{_postorder(visit, rootPtr);}
    void bfsOrder(void visit(Website &)) const;
    void indented() const {_printTreeIndented(rootPtr, 1);}
    bool searchInRange(Website* minVal, Website* maxVal);
    int getCount(){return count;}
    
    
    
    // abstract functions to be implemented by derived class
    virtual bool insert(const string inputString, Website* newData) = 0;
    virtual bool getEntry(const string key, vector<Website> &returnedItems) const = 0;
    BinaryNode* searchInRange(Website* minRange, Website* maxRange) const;
    
private:
    // delete all nodes from the tree
    void destroyTree(BinaryNode* nodePtr);
    
    // copy from the tree rooted at nodePtr and returns a pointer to the copy
    BinaryNode* copyTree(const BinaryNode* nodePtr);
    
    // internal traverse
    void _preorder(void visit(Website &), BinaryNode* nodePtr) const;
    void _inorder(void visit(Website &), BinaryNode* nodePtr) const;
    void _writeNodesinFile(BinaryNode* nodePtr, vector<Website>&);
    void _inorder(void visit(Website &), BinaryNode* nodePtr, Website* minItem, Website* maxItem) const;
    void _postorder(void visit(Website &), BinaryNode* nodePtr) const;
    void _printTreeIndented(BinaryNode* nodePtr, int depth) const;
    
};

#endif
