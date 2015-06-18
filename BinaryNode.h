#ifndef __TeamProject__BinaryNode__
#define __TeamProject__BinaryNode__

#include <stdio.h>
#include "Website.h"

class BinaryNode
{
private:
    string key;      // key to search, add, etc
    Website item;         // Data portion
    BinaryNode* leftPtr;		// Pointer to left child
    BinaryNode* rightPtr;		// Pointer to right child
    
public:
    // constructors
    BinaryNode(const Website & web)	{item = web; leftPtr = 0; rightPtr = 0;}
    BinaryNode(const Website & web,
               BinaryNode* left,
               BinaryNode* right) {item = web; leftPtr = left; rightPtr = right;}
    
    // accessors
    void setKey(const string inputKey) {key = inputKey;}
    void setItem(const Website & web) {item = web;}
    void setLeftPtr(BinaryNode* left) {leftPtr = left;}
    void setRightPtr(BinaryNode* right) {rightPtr = right;}
    
    // mutators
    string getKey() const {return key;}
    Website getWebsite() const	 {return item;}
    BinaryNode* getLeftPtr() const  {return leftPtr;}
    BinaryNode* getRightPtr() const {return rightPtr;}
    
    bool isLeaf() const {return (leftPtr == 0 && rightPtr == 0);}
};

#endif
