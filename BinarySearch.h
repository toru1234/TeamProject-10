

#ifndef __TeamProject__BinarySearch__
#define __TeamProject__BinarySearch__

#include <stdio.h>
#include "BinaryTree.h"

class BinarySearchTree : public BinaryTree
{
private:
    // internal insert node: insert newNode in nodePtr subtree
    BinaryNode* _insert(BinaryNode* nodePtr, BinaryNode* newNode);
    
    // internal remove node: locate and delete target node under nodePtr subtree
    BinaryNode* _remove(BinaryNode* nodePtr, const Website target, bool & success);
    
    // delete target node from tree, called by internal remove node
    BinaryNode* deleteNode(BinaryNode* targetNodePtr);
    
    // remove the leftmost node in the left subtree of nodePtr
    BinaryNode* removeLeftmostNode(BinaryNode* nodePtr, Website & successor);
    
    // search for target node
    BinaryNode* findNode(BinaryNode* treePtr, const Website & target) const;
    
    
    
public:
    // insert a node at the correct location
    bool insert(const Website & newEntry);
    // remove a node if found
    bool remove(const Website & anEntry);
    // find a target node
    bool getEntry(const Website & target, Website & returnedItem) const;
    // print largest item
    bool getHighestKeyItem(Website & highestKeyItem) const;
    // print smallest item
    bool getLowestKeyItem(Website & lowestKeyItem) const;
    
    
};

#endif
