

#ifndef __TeamProject__BinarySearchTree__
#define __TeamProject__BinarySearchTree__

#include <stdio.h>
#include "BinaryTree.h"

class BinarySearchTree : public BinaryTree
{
private:
    // internal insert node: insert newNode in nodePtr subtree
    BinaryNode* _insertUniqueTree(BinaryNode* nodePtr, BinaryNode* newNode);
    
    BinaryNode* _insertSecondaryTree(BinaryNode* nodePtr, BinaryNode* newNode);
    
    // internal remove node: locate and delete target node under nodePtr subtree
    BinaryNode* _removeUniqueKey(BinaryNode* nodePtr, const Website target, bool & success);
    BinaryNode* _removeSecondaryKey(BinaryNode* nodePtr, const Website target, bool & success);
    
    // delete target node from tree, called by internal remove node
    BinaryNode* deleteUniqueNode(BinaryNode* targetNodePtr);
    BinaryNode* deleteSecondaryNode(BinaryNode* targetNodePtr);
    
    // remove the leftmost node in the left subtree of nodePtr
    BinaryNode* removeUniqueLeftmostNode(BinaryNode* nodePtr, Website & successor);
    BinaryNode* removeSecondaryLeftmostNode(BinaryNode* nodePtr, Website & successor);
    
    // search for target node
    BinaryNode* findUniqueNode(BinaryNode* treePtr, const Website & target) const;
    BinaryNode* findSecondaryNode(BinaryNode* treePtr, const Website & target) const;
    
    
    
public:
    // insert a node at the correct location
    bool insertUniqueTree(const Website & newEntry);
    bool insertSecondaryTree(const Website & newEntry);
    
    // remove a node if found
    bool removeUniqueTree(const Website & anEntry);
    bool removeSecondaryKey(const Website & anEntry);
    
    // find a target node
    bool getUniqueTreeEntry(const Website & target, Website & returnedItem) const;
    bool getSecondaryTreeEntry(const Website & target, Website & returnedItem) const;
    // print largest item
    bool getHighestKeyItem(Website & highestKeyItem) const;
    // print smallest item
    bool getLowestKeyItem(Website & lowestKeyItem) const;
};


#endif
