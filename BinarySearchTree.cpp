
#include "BinarySearchTree.h"


///////////////////////// public function definitions ///////////////////////////

bool BinarySearchTree::insert(const Website & newEntry)
{
    BinaryNode* newNodePtr = new BinaryNode(newEntry);
    this->rootPtr = _insert(this->rootPtr, newNodePtr);
    // increament count
    this->count ++;
    return true;
}


bool BinarySearchTree::remove(const Website & target)
{
    bool isSuccessful = false;
    this->rootPtr = _remove(this->rootPtr, target, isSuccessful);
    // drcrease count
    if (isSuccessful)
    {
        this->count --;
    }
    return isSuccessful;
}


bool BinarySearchTree::getEntry(const Website& anEntry, Website & returnedItem) const
{
    // check if the entry is valid
    if (findNode(this->rootPtr, anEntry) == 0)
    {
        return false;
    }
    else
    {
        returnedItem = findNode(this->rootPtr, anEntry)->getWebsite();
        return true;
    }
}



//////////////////////////// private functions ////////////////////////////////////////////

BinaryNode* BinarySearchTree::_insert(BinaryNode* nodePtr,
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
        nodePtr->setLeftPtr(_insert(nodePtr->getLeftPtr(), newNodePtr));
    }
    // If there is node, insert bigger(equal)
    else
    {
        nodePtr->setRightPtr(_insert(nodePtr->getRightPtr(), newNodePtr));
    }
    
    return nodePtr;
}

BinaryNode* BinarySearchTree::_remove(BinaryNode* nodePtr,
                                                          const Website target,
                                                          bool & success)

{
    if (nodePtr == 0)
    {
        success = false;
        return 0;
    }
    if (nodePtr->getWebsite() > target)
        nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), target, success));
    else if (nodePtr->getWebsite() < target)
        nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), target, success));
    else
    {
        nodePtr = deleteNode(nodePtr);
        success = true;
    }
    return nodePtr;
}

BinaryNode* BinarySearchTree::deleteNode(BinaryNode* nodePtr)
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
        nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }
}

BinaryNode* BinarySearchTree::removeLeftmostNode(BinaryNode* nodePtr,
                                                                     Website & successor)
{
    if (nodePtr->getLeftPtr() == 0)
    {
        successor = nodePtr->getWebsite();
        return deleteNode(nodePtr);
    }
    else
    {
        nodePtr->setLeftPtr(removeLeftmostNode(nodePtr->getLeftPtr(), successor));
        this->count--;
        return nodePtr;
    }
}


BinaryNode* BinarySearchTree::findNode(BinaryNode* nodePtr,
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
        return findNode(nodePtr->getLeftPtr(), target);
    }
    else if (nodePtr->getWebsite() < target)
    {
        return findNode(nodePtr->getRightPtr(), target);
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
