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
    int tablesize;  //record the size of the table
    int bucketsize;  //record the size of the bucket
   
    int collisions;  //record the number of collisions
    
    int load;   //record the number of loaded buckets
    int fullBuckets;    //record the number of full buckets

    
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
    
    //get the pointer of hash_entry
    struct Hash_Entry* getHash_Entry() const{ return table;}
    //get the pointer of data corresponding the key
    Website* getData(const string &strkey) const;
    // getters for the hash size and the table size
    int getTableSize() const {return tablesize;}
    int getBucketSize() const {return bucketsize;}
    
    bool insert(const Website &input);
    void PrintTable() const;
    void displayList() const;
    void showStatistics() const;
    Website* getHashItem(int tableIndex, int bucketIndex) const;
};

#endif // HASH_TABLE_H_INCLUDED
