#include "BinarySearchTree.h"


///////////////////////// public function definitions ///////////////////////////

/************************************************
insert function. this function inserts an item in
 the tree and increments the count by 1
 *************************************************/
bool BinarySearchTree::insert(string key, Website* newEntry)
{
    BinaryNode* newNodePtr = new BinaryNode(newEntry);
    newNodePtr->setKey(key);
    this->rootPtr = _insert(this->rootPtr, newNodePtr);
    // increament count
    this->count ++;
    return true;
}

/************************************************
 removeAll function. this function removes all the
 nodes that have the matched key
 *************************************************/
bool BinarySearchTree::removeAll(const string key)
{
    if (remove(key))
    {
        remove(key);
        return true;
    }
    return false;
}
/************************************************
 remove function. this function removes the
 node that has the matched key
 *************************************************/
bool BinarySearchTree::remove(const string key)
{
    bool isSuccessful = false;
    this->rootPtr = _remove(this->rootPtr, key, isSuccessful);
    // drcrease count
    if (isSuccessful)
    {
        this->count --;
    }
    return isSuccessful;
}
/************************************************
 getEntry function. this function removes all the
 nodes that have the matched key
 *************************************************/
bool BinarySearchTree::getEntry(const string key, vector<Website> &returnedItems) const
{
    // check if the entry is valid
    if (findNode(this->rootPtr, key) == 0)
    {
        return false;
    }
    else
    {
        BinaryNode *entryNode = findNode(this->rootPtr, key);
        returnedItems.push_back(*entryNode ->getWebsite());
        entryNode = entryNode->getRightPtr();
        while(findNode(entryNode, key)!= 0)
        {
            returnedItems.push_back(*findNode(entryNode, key)->getWebsite());
            entryNode = findNode(entryNode, key)->getRightPtr();
        }
        
        return true;
    }
}


//////////////////////////// private functions ////////////////////////////////////////////
/************************************************
 _insert function. this function inserts nodes
 to the BSTs
 *************************************************/

BinaryNode* BinarySearchTree::_insert(BinaryNode* nodePtr, BinaryNode* newNodePtr)
{
    // if there is no node at all
    if (nodePtr == 0)
    {
        nodePtr = newNodePtr;
        return nodePtr;
    }
    // insert smaller
    if(newNodePtr->getKey() < nodePtr->getKey())
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

/************************************************
 _remove function. this function removes the
 nodes that have the matched key
 *************************************************/
BinaryNode* BinarySearchTree::_remove(BinaryNode* nodePtr, const string key, bool & success)
{
    if (nodePtr == 0)
    {
        success = false;
        return 0;
    }
    if (nodePtr->getKey() > key)
        
        nodePtr->setLeftPtr(_remove(nodePtr->getLeftPtr(), key, success));
    
    else if (nodePtr->getKey() < key)
        
        nodePtr->setRightPtr(_remove(nodePtr->getRightPtr(), key, success));
    
    else
        
    {
        
        nodePtr = deleteNode(nodePtr);
        
        success = true;
        
    }
    
    return nodePtr;
    
}

/************************************************
 delete function. this function actuallly deletes
 nodes from the BSTs
 *************************************************/
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
        Website* newNodeValue;
        nodePtr->setRightPtr(removeLeftmostNode(nodePtr->getRightPtr(), newNodeValue));
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }
}

/************************************************
 removeLeftMostNode function. this function deletes
 the most left node
 *************************************************/
BinaryNode* BinarySearchTree::removeLeftmostNode(BinaryNode* nodePtr, Website* successor)
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

/************************************************
 find function. this function finds the
 node(s) that have the matched key and returns the
 pointer at the node
 *************************************************/
BinaryNode* BinarySearchTree::findNode(BinaryNode* nodePtr, const string key) const
{
    // tree is empty
    if (nodePtr == 0)
    {
        return 0;
        
    }
    // tree is not empty
    // Iterate through the tree
    else if (nodePtr->getKey() > key)
    {
        return findNode(nodePtr->getLeftPtr(), key);
    }
    else if (nodePtr->getKey() < key)
    {
        return findNode(nodePtr->getRightPtr(), key);
    }
    return nodePtr;
}

/************************************************
 getHighestKeyItem function. this function finds
 the highest key item of the BSTs
 *************************************************/
bool BinarySearchTree::getHighestKeyItem(Website* largestItem) const
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
/************************************************
 getLowestKeyItem function. this function finds
 the lowest node of the BSTs
 *************************************************/
bool BinarySearchTree::getLowestKeyItem(Website* lowestKeyItem) const
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
