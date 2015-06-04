#ifndef SEARCHMANAGER_H
#define SEARCHMANAGER_H

#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

class SearchManager
{
private:
   BinarySearchTree* tree;
   void caseSearch();
   void caseList();
   bool readFile(string fileName);
public:
   // Constructor. Takes input parameter filename. Parses input file into tree.
   SearchManager(string fileName);
   
   // Destructor. Calls tree delete.
   ~SearchManager();
   
   // Runs the main functionality of search manager
   void run();
};

#endif