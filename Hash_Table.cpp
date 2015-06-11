
/*******************************************
 default constructor
 default constructor
 *******************************************/
Hash_Table::Hash_Table()
{
    //initialize values
    collisions = 0;
    load = 0;
    fullBuckets = 0;
    
    //set the size to default
    tablesize = 10;
    bucketsize = 4;
    
    //define the size of the table, with bucket size of 3(+1 for original element)
    table = new Hash_Entry[tablesize];
    
    for(int i = 0; i < tablesize; i++)
    {
        table[i].bucket = new Website[bucketsize];
    }
}

/*******************************************
 constructor
 accept tableSize and bucketSize as argument
 initialize the value and check if the inputed size is
 valid.
 *******************************************/
Hash_Table::Hash_Table(const int &tableSize, const int &bucketSize)
{
    //initialize values
    collisions = 0;
    load = 0;
    fullBuckets = 0;
    
    //make sure the size is valid, if not valid, show message and set the size as default.
    if(tableSize > 0 && bucketSize > 0)
    {
        //set tablesize as inputed value
        tablesize = tableSize;
        
        //set the size of the bucketSize, add 1 because bucket[0] is the original data
        bucketsize = bucketSize + 1;
    }
    else
    {
        cout << "Warning : Incorrect input of hash Table size." << endl;
        //set default value
        tablesize = 10;
        bucketsize = 4;
    }
    
    //define the size of the table
    table = new Hash_Entry[tablesize];
    
    //declare the buckets with the size of "bucketSize"
    for(int i = 0; i < tablesize; i++)
    {
        table[i].bucket = new Website[bucketsize];
    }
}
/*******************************************
 destructor
 destroy the buckets first,
 then destroy the table.
 *******************************************/
Hash_Table::~Hash_Table()
{
    //destroy the buckets first
    for(int i = 0; i < tablesize; i++)
    {
        delete [] table[i].bucket;
    }
    //destroy the table
    delete [] table;
}
/*******************************************
 getKey function
 calculate the key by adding all char in the string
 and find the modulus by tablesize.
 *******************************************/
int Hash_Table::getKey(const string &input) const
{
    //for calculating the sum
    int sum = 0;
    
    //get the sum
    for(int i = 0; i < input.size(); i++)
    {
        sum += input[i];
    }
    return sum % tablesize;
}
/*******************************************
 insert function
 get the key from the inputed website.
 if the bucket is full, return false.
 Else, insert the data into the table's bucket,
 and add count by 1, return true.
 *******************************************/
bool Hash_Table::insert(const Website &input)
{
    //get the key from the string
    int key = getKey(input.getName());
    
    //if the bucket is full (count is greater than the bucketsize), return false
    if(table[key].count >= bucketsize)
    {
        return false;
    }
    
    
    //else, insert the data into the table's bucket
    table[key].bucket[table[key].count] = input;
    
    //for statistics, if count is 0, add load
    if(table[key].count == 0)
        load++;
    else //else, add collisions
        collisions++;
    
    //count + 1
    table[key].count++;
    
    //for statistics, if the count is greater or equal than the bucket size, add fullBucket
    if(table[key].count >= bucketsize)
        fullBuckets++;
    
    //success, return true.
    return true;
}


/*******************************************
 Printable function
 print the index and indent synonyms
 *******************************************/
void Hash_Table::PrintTable() const
{
    for(int i = 0; i < tablesize; i++)
    {
        cout << "Index " << i << " : " << table[i].bucket[0].getName() << endl;
        for(int j = 1; j < table[i].count; j++)
        {
            cout << "                " << table[i].bucket[j].getName() << endl;
        }
        cout << endl;
    }
}
/*******************************************
 getData function
 go to the hash address and return the pointer to
 that object.
 return false if the object is not found.
 *******************************************/
Website* Hash_Table::getData(const string &strkey) const
{
    //get the integer key from the input string
    int key = getKey(strkey);
    
    for(int i = 0; i < table[key].count; i++)
    {
        //if the strkey matches the "key" in the bucket, return the address of that member.
        if(strkey == table[key].bucket[i].getName())
        {
            return &table[key].bucket[i];
        }
    }
    
    //the search failed as the target is not in the bucket, return NULL.
    return NULL;
}
/*******************************************
 displayList function
 display the contents of the hash table
 *******************************************/
void Hash_Table::displayList() const
{
    //show all element in the table.
    for(int i = 0; i < tablesize; i++)
    {
        for(int j = 0; j < table[i].count; j++)
        {
            cout << table[i].bucket[j].getName() << endl;
        }
    }
}
/*******************************************
 showStatistics function
 show statistics.
 *******************************************/
void Hash_Table::showStatistics() const
{
    cout << "Collisions  : " << collisions << endl;
    cout << "Load factor : " << static_cast<double>(load) / tablesize * 100 << "%" << endl;
    cout << "Full Bucket : " << fullBuckets << endl;
    cout << "Empty Bucket: " << tablesize - load << endl;
}
Website* Hash_Table::getHashItem(int tableIndex, int bucketIndex) const
{
    return &table[tableIndex].bucket[bucketIndex];
}
