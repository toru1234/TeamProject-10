
#include "BinarySearchTree.h"



///////////////////////// public function definitions ///////////////////////////

bool BinarySearchTree::insertUniqueTree(const Website & newEntry)
{
    BinaryNode* newNodePtr = new BinaryNode(newEntry);
    this->rootPtr = _insertUniqueTree(this->rootPtr, newNodePtr);
    // increament count
    this->count ++;
    return true;
}

bool BinarySearchTree::insertSecondaryTree(const Website & newEntry)
{
    BinaryNode* newNodePtr = new BinaryNode(newEntry);
    this->rootPtr = _insertSecondaryTree(this->rootPtr, newNodePtr);
    // increament count
    this->count ++;
    return true;
}



bool BinarySearchTree::removeUniqueTree(const Website & target)
{
    bool isSuccessful = false;
    this->rootPtr = _removeUniqueKey(this->rootPtr, target, isSuccessful);
    // drcrease count
    if (isSuccessful)
    {
        this->count --;
    }
    return isSuccessful;
}


bool BinarySearchTree::getUniqueTreeEntry(const Website& anEntry, Website & returnedItem) const
{
    // check if the entry is valid
    if (findUniqueNode(this->rootPtr, anEntry) == 0)
    {
        return false;
    }
    else
    {
        returnedItem = findUniqueNode(this->rootPtr, anEntry)->getWebsite();
        return true;
    }
}



//////////////////////////// private functions ////////////////////////////////////////////

BinaryNode* BinarySearchTree::_insertUniqueTree(BinaryNode* nodePtr,
                                      BinaryNode* newNodePtr)
{
    // if there is no node at all
    if (nodePtr == 0)
    {
        nodePtr = newNodePtr;
        return nodePtr;
    }
    // insert smaller
    if(newNodePtr->getWebsite() < nodePtr->getWebsite())
    {
        nodePtr->setLeftPtr(_insertUniqueTree(nodePtr->getLeftPtr(), newNodePtr));
    }
    // If there is node, insert bigger(equal)
    else
    {
        nodePtr->setRightPtr(_insertUniqueTree(nodePtr->getRightPtr(), newNodePtr));
    }
    
    return nodePtr;
}

BinaryNode* BinarySearchTree::_insertSecondaryTree(BinaryNode* nodePtr,
                                                BinaryNode* newNodePtr)
{
    // if there is no node at all
    if (nodePtr == 0)
    {
        nodePtr = newNodePtr;
        return nodePtr;
    }
    // insert smaller
    if(newNodePtr->getWebsite().getNationality() < nodePtr->getWebsite().getNationality())
    {
        nodePtr->setLeftPtr(_insertUniqueTree(nodePtr->getLeftPtr(), newNodePtr));
    }
    // If there is node, insert bigger(equal)
    else
    {
        nodePtr->setRightPtr(_insertUniqueTree(nodePtr->getRightPtr(), newNodePtr));
    }
    
    return nodePtr;
}
BinaryNode* BinarySearchTree::_removeUniqueKey(BinaryNode* nodePtr,
                                      const Website target,
                                      bool & success)

{
    if (nodePtr == 0)
    {
        success = false;
        return 0;
    }
    if (nodePtr->getWebsite() > target)
        nodePtr->setLeftPtr(_removeUniqueKey(nodePtr->getLeftPtr(), target, success));
    else if (nodePtr->getWebsite() < target)
        nodePtr->setRightPtr(_removeUniqueKey(nodePtr->getRightPtr(), target, success));
    else
    {
        nodePtr = deleteUniqueNode(nodePtr);
        success = true;
    }
    return nodePtr;
}

BinaryNode* BinarySearchTree::_removeSecondaryKey(BinaryNode* nodePtr,
                                      const Website target,
                                      bool & success)

{
    if (nodePtr == 0)
    {
        success = false;
        return 0;
    }
    if (nodePtr->getWebsite().getNationality() > target.getNationality())
        nodePtr->setLeftPtr(_removeSecondaryKey(nodePtr->getLeftPtr(), target, success));
    else if (nodePtr->getWebsite() < target)
        nodePtr->setRightPtr(_removeSecondaryKey(nodePtr->getRightPtr(), target, success));
    else
    {
        nodePtr = deleteSecondaryNode(nodePtr);
        success = true;
    }
    return nodePtr;
}

BinaryNode* BinarySearchTree::deleteUniqueNode(BinaryNode* nodePtr)
{
    if (nodePtr->isLeaf())
    {
        delete nodePtr;
        nodePtr = 0;
        return nodePtr;
    }
    else if (nodePtr->getLeftPtr() == 0)
    {
        BinaryNode* nodeToConnectPtr = nodePtr->getRightPtr();
        delete nodePtr;
        nodePtr = 0;
        return nodeToConnectPtr;
    }
    else if (nodePtr->getRightPtr() == 0)
    {
        BinaryNode* nodeToConnectPtr = nodePtr->getLeftPtr();
        delete nodePtr;
        nodePtr = 0;
        return nodeToConnectPtr;
    }
    else
    {
        Website newNodeValue;
        nodePtr->setRightPtr(removeUniqueLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }
}
BinaryNode* BinarySearchTree::deleteSecondaryNode(BinaryNode* nodePtr)
{
    if (nodePtr->isLeaf())
    {
        delete nodePtr;
        nodePtr = 0;
        return nodePtr;
    }
    else if (nodePtr->getLeftPtr() == 0)
    {
        BinaryNode* nodeToConnectPtr = nodePtr->getRightPtr();
        delete nodePtr;
        nodePtr = 0;
        return nodeToConnectPtr;
    }
    else if (nodePtr->getRightPtr() == 0)
    {
        BinaryNode* nodeToConnectPtr = nodePtr->getLeftPtr();
        delete nodePtr;
        nodePtr = 0;
        return nodeToConnectPtr;
    }
    else
    {
        Website newNodeValue;
        nodePtr->setRightPtr(removeSecondaryLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }
}

BinaryNode* BinarySearchTree::removeUniqueLeftmostNode(BinaryNode* nodePtr,
                                                 Website & successor)
{
    if (nodePtr->getLeftPtr() == 0)
    {
        successor = nodePtr->getWebsite();
        return deleteUniqueNode(nodePtr);
    }
    else
    {
        nodePtr->setLeftPtr(removeUniqueLeftmostNode(nodePtr->getLeftPtr(), successor));
        this->count--;
        return nodePtr;
    }
}


BinaryNode* BinarySearchTree::removeSecondaryLeftmostNode(BinaryNode* nodePtr,
                                                 Website & successor)
{
    if (nodePtr->getLeftPtr() == 0)
    {
        successor = nodePtr->getWebsite();
        return deleteSecondaryNode(nodePtr);
    }
    else
    {
        nodePtr->setLeftPtr(removeSecondaryLeftmostNode(nodePtr->getLeftPtr(), successor));
        this->count--;
        return nodePtr;
    }
}

BinaryNode* BinarySearchTree::findUniqueNode(BinaryNode* nodePtr,
                                       const Website & target) const
{
    // tree is empty
    if (nodePtr == 0)
    {
        return 0;
    }
    
    // tree is not empty
    // Iterate through the tree
    else if (nodePtr->getWebsite() > target)
    {
        return findUniqueNode(nodePtr->getLeftPtr(), target);
    }
    else if (nodePtr->getWebsite() < target)
    {
        return findUniqueNode(nodePtr->getRightPtr(), target);
    }
    return nodePtr;
}

BinaryNode* BinarySearchTree::findSecondaryNode(BinaryNode* nodePtr,
                                       const Website & target) const
{
    // tree is empty
    if (nodePtr == 0)
    {
        return 0;
    }
    
    // tree is not empty
    // Iterate through the tree
    else if (nodePtr->getWebsite().getNationality() > target.getNationality())
    {
        return findSecondaryNode(nodePtr->getLeftPtr(), target);
    }
    else if (nodePtr->getWebsite().getNationality() < target.getNationality())
    {
        return findSecondaryNode(nodePtr->getRightPtr(), target);
    }
    return nodePtr;
}

bool BinarySearchTree::getHighestKeyItem(Website & largestItem) const
{
    // Return if the tree is empty
    if (this->isEmpty())
    {
        return false;
    }
    
    BinaryNode* maxNode = this->rootPtr;
    while(maxNode->getRightPtr() != 0)
    {
        maxNode = maxNode->getRightPtr();
    }
    
    largestItem = maxNode->getWebsite();
    
    return true;
}

bool BinarySearchTree::getLowestKeyItem(Website & lowestKeyItem) const
{
    // Return if the tree is empty
    if (this->isEmpty())
    {
        return false;
    }
    
    BinaryNode* minNode = this->rootPtr;
    while(minNode->getLeftPtr() != 0)
    {
        minNode = minNode->getLeftPtr();
    }
    
    lowestKeyItem = minNode->getWebsite();
    
    return true;
}
