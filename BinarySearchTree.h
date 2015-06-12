

#ifndef __TeamProject__BinarySearchTree__
#define __TeamProject__BinarySearchTree__

#include <stdio.h>
#include "BinaryTree.h"

class BinarySearchTree : public BinaryTree
{
private:
    // internal insert node: insert newNode in nodePtr subtree according to the key.
    BinaryNode* _insert(BinaryNode* nodePtr, BinaryNode* newNode);
    
    // internal remove node: locate and delete target node under nodePtr subtree
    BinaryNode* _remove(BinaryNode* nodePtr, const string key, bool & success);
    
    // delete target node from tree, called by internal remove node
    BinaryNode* deleteNode(BinaryNode* targetNodePtr);
    
    // remove the leftmost node in the left subtree of nodePtr
    BinaryNode* removeLeftmostNode(BinaryNode* nodePtr, Website & successor);
    
    // search for target node
    BinaryNode* findNode(BinaryNode* treePtr, const string key) const;
    
    
    
public:
    // insert a node at the correct location by the key reference
    bool insert(string key, const Website & newEntry);
    // remove a node if found
    bool remove(const string key);
    // remove function to call remove one node, for the case when several nodes need to be removed
    void removeAll(const string key);
    // find a target node
    bool getEntry(const string key, vector<Website> returnedItems) const;
    // print largest item
    bool getHighestKeyItem(Website & highestKeyItem) const;
    // print smallest item
    bool getLowestKeyItem(Website & lowestKeyItem) const;
    
    
};

#endif
