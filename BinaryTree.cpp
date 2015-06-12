
#include "BinaryTree.h"

//------------------------------------




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

void BinaryTree::inOrder(void visit(Website &),
                         const Website & minItem,
                         const Website & maxItem) const
{
    _inorder(visit, rootPtr, minItem, maxItem);
}


void BinaryTree::_preorder(void visit(Website &), BinaryNode* nodePtr) const
{
    // root-left-right
    if (nodePtr != 0)
    {
        Website web = nodePtr->getWebsite();
        visit(web);
        _preorder(visit, nodePtr->getLeftPtr());
        _preorder(visit, nodePtr->getRightPtr());
    }
}

void BinaryTree::_inorder(void visit(Website &), BinaryNode* nodePtr) const
{
    // left-root-right
    if (nodePtr == 0)
    {
        return;
    }
    _inorder(visit, nodePtr->getLeftPtr());
    Website web = nodePtr->getWebsite();
    visit(web);
    _inorder(visit, nodePtr->getRightPtr());
}


void BinaryTree::_writeUniqueKeyinFile(BinaryNode* nodePtr,vector<Website>& outputFile)
{
    // left-root-right
    if (nodePtr == 0)
    {
        return;
    }
    _writeUniqueKeyinFile(nodePtr->getLeftPtr(), outputFile);
    Website web = nodePtr->getWebsite();
    outputFile.push_back(web);
    _writeUniqueKeyinFile(nodePtr->getRightPtr(), outputFile);
}

void BinaryTree::_writeSecondaryKeyinFile(BinaryNode* nodePtr,vector<Website>& outputFile)
{
    // left-root-right
    if (nodePtr == 0)
    {
        return;
    }
    _writeSecondaryKeyinFile(nodePtr->getLeftPtr(), outputFile);
    Website web = nodePtr->getWebsite();
    outputFile.push_back(web);
    _writeSecondaryKeyinFile(nodePtr->getRightPtr(), outputFile);
}
void BinaryTree::_inorder(void visit(Website &),
                          BinaryNode* nodePtr,
                          const Website & minItem,
                          const Website & maxItem) const
{
    // Node is null
    if (nodePtr == 0)
    {
        return;
    }
    
    // Node is outside of desired range
    Website currentItem = nodePtr->getWebsite();
    if (currentItem < minItem || currentItem > maxItem)
    {
        return;
    }
    
    _inorder(visit, nodePtr->getLeftPtr(), minItem, maxItem);
    visit(currentItem);
    _inorder(visit, nodePtr->getRightPtr(), minItem, maxItem);
}

void BinaryTree::_postorder(void visit(Website &), BinaryNode* nodePtr) const
{
    //left-right-root
    if (nodePtr == 0)
    {
        return;
    }
    _postorder(visit, nodePtr->getLeftPtr());
    _postorder(visit, nodePtr->getRightPtr());
    Website web = nodePtr->getWebsite();
    visit(web);
}

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


void BinaryTree::_printTreeIndented(BinaryNode* nodePtr, int depth) const
{
    // check if the node points to null.
    if (nodePtr == 0)
    {
        return;
    }
    // go to the right
    _printTreeIndented(nodePtr->getRightPtr(), depth + 1);
    for (int i = depth-1; i > 0; --i)
    {
        cout << "\t";
    }
    cout << depth << "." << nodePtr->getWebsite() << endl;
    // go to the left
    _printTreeIndented(nodePtr->getLeftPtr(), depth + 1);
}
