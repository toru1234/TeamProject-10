/*******************************************
Hash Table class
a hash table class that used buckets for
collision resolution.
*******************************************/
#ifndef HASH_TABLE_H_INCLUDED
#define HASH_TABLE_H_INCLUDED

#include "Website.h"
#include <iostream>

using namespace std;

class Hash_Table
{
private:
    //record the size of the table
    int tablesize;
    //record the size of the bucket
    int bucketsize;
    //record the number of collisions
    int collisions;
    //record the number of loaded buckets
    int load;
    //record the number of full buckets
    int fullBuckets;

    struct Hash_Entry
    {
        //the number of element that has filled the bucket
        int count = 0;
        //the bucket array
        Website *bucket;
    };
    //the hash table array
    Hash_Entry *table;

    int getKey(const string &input) const;

public:
    //constructor
    Hash_Table();
    //a constructor that accept the tablesize and bucketsize as argument.
    Hash_Table(const int &tableSize, const int &bucketSize);
    //destructor
    ~Hash_Table();

    //get the pointer of data corresponding the key
    Website* getData(const string &strkey) const;

    bool insert(const Website &input);
    void PrintTable() const;
    void displayList() const;
    void showStatistics() const;
};
#endif // HASH_TABLE_H_INCLUDED
