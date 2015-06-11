#ifndef RUNOPTION_H
#define RUNOPTION_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include "BinarySearchTree.h"
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
    void caseSearch();
    void caseList();
    void caseAdd();
    void caseDelete();
    void caseWriteFile();
    void caseStatistic();
public:
    // default consturctor
    RunOption(){uniqueTree = secondaryKeyTree = NULL; hashTable = NULL; fileName = "";}

    // constructor
    RunOption(string inputFileName){uniqueTree = 0; secondaryKeyTree = 0; fileName = inputFileName;}

    // build binary unique key and secondary key tree
    void buildTrees(Hash_Table* hashTable);

    // Destructor. Calls tree delete.
    ~RunOption(){uniqueTree->clear(); delete uniqueTree;delete hashTable;}

    // Runs the main functionality of RunOption
    void run();
};

#endif
