
// This function will run the main menu and the function followed by the menu options.
#ifndef RUNOPTION_H
#define RUNOPTION_H

#include <iostream>
#include <string>
#include <fstream>
#include "BinarySearchTree.h"
#include <vector>

using namespace std;

class RunOption
{
private:
   Website* firstNode;
   BinarySearchTree* tree;
   bool readFile(string fileName);
   Website* buildTreeNodeArr(string fileName);
   void caseSearch();
   void caseList();
   void caseAdd();
   void caseDelete();
   void caseWriteFile();
   void caseStatistic();
public:
   // default consturctor
   RunOption(){tree = 0;}
   
   // constructor
   RunOption(string fileName){firstNode = buildTreeNodeArr(fileName);}
   
   // build binary unique key tree
    void buildUniqueKeyTree();
   // build secondary key tree;
   void buildSecondaryKeyTree();
   
   // Destructor. Calls tree delete.
   ~RunOption(){tree->clear(); delete tree;}
   
   // Runs the main functionality of RunOption
   void run();
};

#endif