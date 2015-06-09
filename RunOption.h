
// This function will run the main menu and the function followed by the menu options.
#ifndef RUNOPTION_H
#define RUNOPTION_H

#include <iostream>
#include <string>
#include <fstream>
#include "BinarySearchTree.h"
#include <vector>
#include "Hash_Table.h"

using namespace std;

class RunOption
{
private:
   string fileName;
   BinarySearchTree* uniqueTree;
   BinarySearchTree* secondaryKeyTree;
   Hash_Table* hashTable;
   Hash_Table* getData(Hash_Table*);
   vector<Website> treeVector;
   vector<Website> buildTreeNodeArr();
   void caseSearch();
   void caseList();
   void caseAdd();
   void caseDelete();
   void caseWriteFile();
   void caseStatistic();
public:
   // default consturctor
   RunOption(){uniqueTree = 0; secondaryKeyTree = 0; fileName = "";}

   // constructor
   RunOption(string inputFileName){uniqueTree = new BinarySearchTree; secondaryKeyTree = new BinarySearchTree; fileName = inputFileName;}

   // build binary unique key tree
   bool buildUniqueKeyTree();

   // build secondary key tree;
   void buildSecondaryKeyTree();

   // Destructor. Calls tree delete.
   ~RunOption(){uniqueTree->clear(); delete uniqueTree;delete hashTable;}

   // Runs the main functionality of RunOption
   void run();
};

#endif
