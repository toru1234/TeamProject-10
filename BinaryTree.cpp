
#include "BinaryTree.h"

/************************************************
 Constructor with one parameter. this is a copy
 constructor
 *************************************************/
BinaryTree::BinaryTree(const BinaryTree & tree)
{
    // check if the tree is valid
    if (tree.isEmpty())
    {
        rootPtr = 0;
        count = 0;
    }
    else
    {
        // make the pointer pointing to the tree pointer.
        rootPtr = copyTree(tree.rootPtr);
    }
}

/************************************************
 copyTree function. this function copies all the
 nodes in the BSTs
 *************************************************/

BinaryNode* BinaryTree::copyTree(const BinaryNode* nodePtr)
{
    if (nodePtr == 0)
    {
        return 0;
    }
    
    else
    {
        // make a new node
        BinaryNode* newNode = new BinaryNode(nodePtr->getWebsite());
        newNode->setLeftPtr(copyTree(nodePtr->getLeftPtr()));
        newNode->setRightPtr(copyTree(nodePtr->getRightPtr()));
        return newNode;
    }
}

/************************************************
 destroy function. this function destories all the
 nodes in the tree
 *************************************************/
void BinaryTree::destroyTree(BinaryNode* nodePtr)
{
    // left-root-right
    if (nodePtr == 0)
    {
        return;
    }
    destroyTree(nodePtr->getLeftPtr());
    destroyTree(nodePtr->getRightPtr());
    delete nodePtr;
}

/************************************************
 inOrder function. this function traverses the 
 within the range in order.
 *************************************************/
void BinaryTree::inOrder(void visit(Website &),
                         Website* minItem,
                         Website* maxItem) const
{
    _inorder(visit, rootPtr, minItem, maxItem);
}

/************************************************
 _preOrder function. this function traverses all
 the nodes in pre order
 *************************************************/
void BinaryTree::_preorder(void visit(Website &), BinaryNode* nodePtr) const
{
    // root-left-right
    if (nodePtr != 0)
    {
        Website* web = nodePtr->getWebsite();
        visit(*web);
        _preorder(visit, nodePtr->getLeftPtr());
        _preorder(visit, nodePtr->getRightPtr());
    }
}

/************************************************
 _inorder function. this function traverses all the
 nodes in order
 *************************************************/
void BinaryTree::_inorder(void visit(Website &), BinaryNode* nodePtr) const
{
    // left-root-right
    if (nodePtr == 0)
    {
        return;
    }
    _inorder(visit, nodePtr->getLeftPtr());
    Website* web = nodePtr->getWebsite();
    visit(*web);
    _inorder(visit, nodePtr->getRightPtr());
}

/************************************************
 _writeNodesinFile function. this function
 writes the nodes in an output file using a 
 vector
 *************************************************/
void BinaryTree::_writeNodesinFile(BinaryNode* nodePtr,vector<Website>& outputFile)
{
    // left-root-right
    if (nodePtr == 0)
    {
        return;
    }
    _writeNodesinFile(nodePtr->getLeftPtr(), outputFile);
    Website* web = nodePtr->getWebsite();
    outputFile.push_back(*web);
    _writeNodesinFile(nodePtr->getRightPtr(), outputFile);
}

/************************************************
 _inOrder function. this function traverses all the
 nodes within the range that user decided
 *************************************************/
void BinaryTree::_inorder(void visit(Website &),
                          BinaryNode* nodePtr,
                          Website* minItem,
                          Website* maxItem) const
{
    // Node is null
    if (nodePtr == 0)
    {
        return;
    }
    
    // Node is outside of desired range
    Website* currentItem = nodePtr->getWebsite();
    if (*currentItem < *minItem || *currentItem > *maxItem)
    {
        return;
    }
    
    _inorder(visit, nodePtr->getLeftPtr(), minItem, maxItem);
    visit(*currentItem);
    _inorder(visit, nodePtr->getRightPtr(), minItem, maxItem);
}

/************************************************
 _postOrder function. this function traverses all
 the nodes in post order
 *************************************************/
void BinaryTree::_postorder(void visit(Website &), BinaryNode* nodePtr) const
{
    //left-right-root
    if (nodePtr == 0)
    {
        return;
    }
    _postorder(visit, nodePtr->getLeftPtr());
    _postorder(visit, nodePtr->getRightPtr());
    Website* web = nodePtr->getWebsite();
    visit(*web);
}

/************************************************
 overload operator =: this function assignes the
 all the nodes from the left hand side to the right
 hand side treee
 *************************************************/
BinaryTree & BinaryTree::operator= (const BinaryTree & sourceTree)
{
    // clear data first(if the left object is not empty)
    if (!this->isEmpty())
    {
        this->clear();
    }
    rootPtr = copyTree(sourceTree.rootPtr);
    count = sourceTree.count;
    return *this;
}

/************************************************
 _printTreeIndented function. this function writes
 a tree figure that the actual tree looks like
 *************************************************/
void BinaryTree::_printTreeIndented(BinaryNode* nodePtr, int depth) const
{
    // check if the node points to null.
    if (nodePtr == 0 )
    {
        return;
    }
    // go to the right
    
    _printTreeIndented(nodePtr->getRightPtr(), depth + 1);
    if (nodePtr->getWebsite()->getName() != ""){
        for (int i = depth-1; i > 0; --i)
        {
            
            cout << "\t";
        }
        cout << depth << "." << nodePtr->getWebsite()->getName() << endl;
    }
    else
        depth--;
        // go to the left
    _printTreeIndented(nodePtr->getLeftPtr(), depth + 1);
    
    
}
