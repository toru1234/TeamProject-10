/*********************************
 funtion declarition for RunOption.
 **********************************/

#include "RunOption.h"
#include <cstdlib>

/************************************************
 diaplay function, will be passed in parameter.
 *************************************************/
void RunOption::display(Website& web)
{
    cout << web << endl;
}

/************************************************
 main function for runOption.
 It will display the menu and build trees and hash table.
 *************************************************/
void RunOption::run()
{
    welcomeMessage();
    
    // build the hash table off the input file
    if (!getData()){
        return;
    }
    
    // build trees
    
    buildTrees();
    
    string input;
    //	char choice;
    bool quit = false;

    
    do {
        cout << "Please input the letter corresponding to the function you'd like to use from the list below." << endl;
        cout << "A - Add New Website\n"
        << "D - Delete Website\n"
        << "S - Search for Website(s)\n"
        << "L - List Websites\n"
        << "W - Write data into file\n"
        << "H - Statistics\n"
        << "Q - Quit\n";
        
        cout << endl;
        getline(cin, input);
        cout << endl;
        
        switch (toupper(input[0])) //take the first character of input
        {
            case 'A': // add
                caseAdd();
                break;
            case 'D': // delete
                caseDelete();
                break;
            case 'S': // search
                caseSearch();
                break;
            case 'L': // list
                caseList();
                break;
            case 'W': // write to file
                caseWriteFile();
                break;
            case 'H': // Statistic
                caseStatistic();
                break;
            case 'Q': // quit
                quit = true;
                break;
            default:
                cout << "Invalid input.\n";
        }
    } while (!quit);
    
    farawellMessage();
}

/*************************************************
 build trees functions. Buiding the BSTs using
 the hash table.
 *************************************************/
void RunOption::buildTrees()
{
    Website* hashTableItem;
    uniqueTree = new BinarySearchTree;
    secondaryKeyTree = new BinarySearchTree;
    
    for (int i = 0; i < hashTable->getTableSize(); ++i) //loop for the table size
    {
        for (int j = 0; j < hashTable->getHash_Entry()[i].count; ++j) //loop for the counter in each element of the table
        {
            hashTableItem = hashTable->getHashItem(i, j);
            uniqueTree->insert(hashTableItem->getName(), hashTableItem);
            secondaryKeyTree->insert(hashTableItem->getNationality(), hashTableItem);
        }
    }
}

/*************************************************
 functionality for menu driven function.
 *************************************************/
void RunOption::caseAdd()
{
    string newWebString;
    string newCopuntryString;
    string newCompanyNameString;
    string newRankString;
    string newSpendTimeString;
    string newOwner;
    string newDailyViewString;
    
    cout << "Please enter the name of the website that you want to add: ";
    getline(cin,newWebString);
    while(hashTable->getData(newWebString) != nullptr){ //if the name already exists, it's invalid
        cout << "The name already exists!\n";
        cout << "Try another name.\n";
        getline(cin,newWebString);
    }
    
    cout << "Please enter the nationalidty of the website: ";
    getline(cin, newCopuntryString);
    
    cout << "Please enter the rank of the website bigger than " << uniqueTree->getCount() << " : ";
    getline(cin,newRankString);
    while(atoi(newRankString.data()) < uniqueTree->getCount()){
        cout << "invalid rank typed!!\n";
        cout << "Please enter the rank of the website no bigger than " << uniqueTree->getCount() << " : ";
        getline(cin,newRankString);
    }

    cout << "Please enter the average time that visiter spend on this website(round it to sharp minute): ";
    getline(cin,newSpendTimeString);
    while(!(atoi(newSpendTimeString.data()) > 0)){
        cout << "invalid time typed!!\n";
        getline(cin,newSpendTimeString);
    }
    
    cout << "Please enter the company name of the website: ";
    getline(cin, newCompanyNameString);
    
    cout << "Please enter the average times that a visiter visited on this website per day (round it to sharp minute): ";
    getline(cin,newDailyViewString);
    while(!(atoi(newDailyViewString.data()) > 0)){
        cout << "invalid time typed!!\n";
        cout << "Please enter the average times that a visiter visited on this website per day (round it to sharp minute): ";
        getline(cin,newDailyViewString);
    }
  
    
    Website addWebsite;
    addWebsite.setName(newWebString);
    addWebsite.setNationality(newCopuntryString);
    addWebsite.setGlobalRank(atoi(newRankString.data()));
    addWebsite.setAvgTime_OnSite(atoi(newSpendTimeString.data()));
    addWebsite.setOwner(newCompanyNameString);
    addWebsite.setAvgview_perVisitor(atof(newDailyViewString.data()));
    
    cout << "Inserting the website.......\n";
    sleepFor();     //sleep for a second
    // insert to the hash table
    hashTable->insert(addWebsite);
    buildTrees();

    cout << "Inserting done!" << endl << endl;
}

/*************************************************
 functionality for delete case.
 *************************************************/
void RunOption::caseDelete()
{
    string getChoice;
    // call tree delete function
    cout << "Do you want to remove the data by name or nationality? N for name, T for nationality: ";
    char deleteChoice;
    getline(cin,getChoice);
    deleteChoice = toupper(getChoice[0]);
    if (deleteChoice == 'N')
    {
        cout << "Please enter the name of the website: ";
        string deleteWebName;
        getline(cin,deleteWebName);       //get a delete key
        for(int i = 0; i < deleteWebName.size(); i++)
        {
            deleteWebName[i] = tolower(deleteWebName[i]); //all websites should be in small letters
        }
        
        Website deleteWeb;
        cout << "Deleting the websites......\n";
        if(hashTable->deleteItem(deleteWebName))   //delete it if it's found
        {
            cout << "Deletion done!" << endl;
        }
        else
            cout << "Not found!";
        
    }
    else if (deleteChoice == 'T')
    {
        cout << "Please enter the nationality of the website: ";
        
        string deleteWebNationality;
        
        getline(cin,deleteWebNationality);    //get a delete key
        
        Website targetWebsite;
        cout << "Deleting....\n";
        sleepFor();     //sleep for a second
        if (secondaryKeyTree->getEntry(deleteWebNationality, aquiredWebsite))
        {
            for (int i = 0; i < aquiredWebsite.size(); i++){
                hashTable->deleteItem(aquiredWebsite[i].getName());
            }
            cout << "Delete complited\n";
        }
        else{
            cout << "Not Found!\n";
        }
    }
    
    else
    {
        cout << "Invalid input!" << endl;
    }
    cout << endl;
}

/*************************************************
 functionality for statistic case.
 *************************************************/
void RunOption::caseStatistic()
{
    hashTable->showStatistics();
    
}

/*************************************************
 save the tree into output file
 *************************************************/
void RunOption::caseWriteFile()
{
    string getChoice;
    cout << "Do you want to write the file by its name or nationality? N for name and T for nationality:";
    char writeFileChar;
    getline(cin,getChoice);     //get a choice
    writeFileChar = toupper(getChoice[0]); //take the first character of getChoice
    if (writeFileChar == 'N')
    {
        // Open output file
        ofstream outputFileByUnique;
        if (!outputFileValidation(outputFileByUnique))
        {
            return;
        }
        uniqueTree->writeNodesinFile(outputFile);   //get all the data and store it in the vector
        cout << "outputFile:\n";
        cout << "writing the result......." << endl;
        
        sleepFor();     //sleep for a second
        
        for (auto p : outputFile){
            outputFileByUnique << p << endl;    //writing the data to the file
        }
        outputFileByUnique.close();
        cout << "Out put file Web_Data_Out.txt done!" << endl;
        
    }
    else if (writeFileChar == 'T')
    {
        // Open output file
        ofstream outputFileBySecondary;
        if (!outputFileValidation(outputFileBySecondary))
        {
            return;
        }
        
        secondaryKeyTree->writeNodesinFile(outputFile);  //get all the data in the vector
        cout << "outputFile:\n";
        cout << "writing the result......." << endl;
        
        sleepFor();     //sleep for a second
        
        for (auto p : outputFile){
            outputFileBySecondary << p << endl; //wrting the data to the file
        }
        outputFileBySecondary.close();
        cout << "Out put file Web_Data_Out.txt done!" << endl << endl;
    }
    else
    {
        cout << "Invalid input!" << endl;
    }
    
    cout << endl;
}
/*************************************************
 This function returns false when the output file
 is not opened successfully
 *************************************************/
bool RunOption::outputFileValidation(ofstream &outputFile)
{
    string outputFileName = "Web_Data_Out.txt";
    outputFile.open(outputFileName.c_str());
    if (!outputFile.is_open())
    {
        cout <<"Error opening output file!" << endl;
        return false;
    }
    return true;
}

/*************************************************
 Functionality for case search
 *************************************************/
void RunOption::caseSearch()
{
    
    // use hash table to search, faster.
    char subChoice;
    bool invalid;
    string getChoice;
    do {
        invalid = false;
        cout << "Please select a search type from the options below.\n" << endl
        << "N - Search website data for given domain name\n"
        << "C - Search websites by country\n"
        << "R - Return to previous menu\n" << endl;
        getline(cin,getChoice);       //get a choice
        subChoice = toupper(getChoice[0]); //take the first character of getChoice
        cout << endl;
        
        switch (subChoice)
        {
            case 'N': // domain name
            {
                cout << "Please enter the name of the website you want to search: ";
                string primarykey;
                getline(cin,primarykey);  //get a search key
                for(int i = 0; i < primarykey.size(); i++)
                    primarykey[i] = tolower(primarykey[i]);
                
                cout << "Searing the website......\n";
                Website* targetWebsite;
                targetWebsite = hashTable->getData(primarykey); //return the address
                
                     //sleep for a second
                
                if (targetWebsite)
                {
                    cout << *targetWebsite << endl;
                }
                else
                {
                    cout << "Not found!" << endl;
                }
                break;
            }
            case 'C': // by country
            {
                cout << "Please enter the name of the country that you want to search: ";
                string secondaryKey;
                getline(cin,secondaryKey);    // get a search key
                Website targetWebsite;
                cout << "Searing the websites......\n";
                if (secondaryKeyTree->getEntry(secondaryKey, aquiredWebsite)) //get all the secondary key
                {
                    // dsplay all searched items
                    for (int i = 0; i < aquiredWebsite.size(); ++i)
                    {
                        display(aquiredWebsite[i]); //show all the data that's matched with the search key
                        
                    }
                    aquiredWebsite.clear();
                }
                else
                {
                    cout << "not found!" << endl;
                }
                cout << "Search done!" << endl;
                break;
            }
            case 'R': // previous
                invalid = false;
                break;
            default:
                invalid = true;
                cout << endl << "Invalid input. ";
                break;
        }
    } while (invalid);
    
    cout << endl;
}

/*************************************************
 Functionality for case list
 *************************************************/
void RunOption::caseList()
{
    char subChoice;
    bool invalid;
    string getChoice;
    do {
        invalid = false;
        cout << "Please select how to display the website data from the options below.\n" << endl;
        cout << "U - display unsorted\n"
        << "P - display by domain name\n"
        << "O - display by countries\n"
        << "I - display special\n"
        << "R - Return to previous menu\n" << endl;
        getline(cin, getChoice);   //get a choice
        subChoice = toupper(getChoice[0]); //take the first character of getChoice
        cout << endl;
        
        switch (subChoice)
        {
            case 'U': // unsorted
                cout << "Unsorted List as Followed: " << endl;
                cout << "Shuffling......\n";
                sleepFor();
                hashTable->displayList();
                break;
            case 'P': // alphabetical
                cout << "Sorted by the name of the website: " << endl;
                // call printBST tree.
                uniqueTree->preOrder(display);
                break;
                
            case 'O': // countries
                cout << "Sorted by country:" << endl;
                // call print SecondaryTree function.
                secondaryKeyTree->inOrder(display);
                break;
                
            case 'I': // special indented list
                cout << "Sorted tree indented list: " << endl;
                cout << "Sorted by name: " << endl;
                uniqueTree->indented();
                cout << endl;
                cout << "Sorted by nationality: " << endl;
                secondaryKeyTree->indented();
                cout << endl;
                break;
                
            case 'R': // previous
                invalid = false;
                break;
                
            default:
                invalid = true;
                cout << "Invalid input." << endl;
                break;
        }
    } while (invalid);
    
    cout << endl;
}

/*************************************************
 This function waits for a second to make the
 processes look like they are goind on.
 *************************************************/
void RunOption::sleepFor(int seconds){
    clock_t endwait;
    endwait = clock() +
    seconds +
    CLOCKS_PER_SEC;
    while(clock() < endwait);
}
/*************************************************
 This function finds the next prime number.
 *************************************************/
int RunOption::getNextPrimeNumber(int num)
{
    while(true)
    {
        num++;
        bool prime = true;
        for(int i = 2; i < num / 2 && prime == true; i++)
        {
            if(num % i == 0)
            {
                prime = false;
            }
        }
        
        if(prime == true)
        {
            return num;
        }
    }
}
/*************************************************
 HashTable getData function initialize the size of
 the hash table and read the data from the file.
 *************************************************/
bool RunOption::getData()
{
    // TODO**************************change name back
    ifstream input("websiteData.txt");
    if(input.fail())
    {
        cout << "Cannot open websiteData.txt!" << endl;
        return false;
    }
    
    string holdData;
    int size = 10;  //default size of the hash table
    int numOfData;
    do{
        input >> numOfData;     //get the number of lines in the file
        input.ignore();
        hashTable = new Hash_Table(size, 3);    //allocate memory for the hash table
        for(int i = 0; i < numOfData; i++)
        {
            //get the name of the website
            Website webNode;
            getline(input, holdData);
            webNode.setName(holdData);
            
            //get the nationality of the website
            getline(input, holdData);
            webNode.setNationality(holdData);
            //get the globalrank of the website
            getline(input, holdData);
            webNode.setGlobalRank(atoi(holdData.data()));
            //get he average time that visitor on the website
            getline(input, holdData);
            webNode.setAvgTime_OnSite(atoi(holdData.data()));
            //get the owner of the website
            getline(input, holdData);
            webNode.setOwner(holdData);
            //get hte average amount of pages viewed by a visitor per day
            getline(input, holdData);
            webNode.setAvgview_perVisitor(atof(holdData.data()));
            
            hashTable->insert(webNode);
            getline(input, holdData);
        }
        input.clear();  //reset the input file
        input.seekg(0, ios::beg);   //rebegin with the first line
        size = getNextPrimeNumber(size); //get the next prime number
       
    } while(hashTable->getLoadFactor() > 65 && cout << "Rehashing...\n");   //this loop is repeated until the load factor becomes less than 70%
    cout << "Now the table size is " << hashTable->getTableSize() << endl;  // finally get the table size.
    cout << "Let's begin!!\n\n";
    input.close();
    return true;
}

/************************************************
 welcome function, displays a welcome messege.
 *************************************************/
void RunOption::welcomeMessage()
{
    cout << "|=========================================================================|\n";
    cout << "|Welcome! Our program is about the popular websites all around the world. |\n";
    cout << "|                                                                         |\n";
    cout << "|     *             *                           *        *           *    |\n";
    cout << "|   *      *      *     *  Popular Website      *    *         *    *     |\n";
    cout << "|     *  *   *      *      ---------------    *   *   *     *     *       |\n";
    cout << "|  *    *      *  *     *                       *   *    * *    *         |\n";
    cout << "|                                                                         |\n";
    cout << "|  #       #       #   ######   ######     #####   ######  #######  ######|\n";
    cout << "|   #     # #     #    #        *     #   #          #        #     #     |\n";
    cout << "|    #   #   #   #     ######   ######     ####      #        #     ######|\n";
    cout << "|     # #     # #      #        #     #        #     #        #     #     |\n";
    cout << "|      #       #       ######   ######    #####    ######     #     ######|\n";
    cout << "|                                                                         |\n";
    cout << "| -----------------------------                                           |\n";
    cout << "| | Developers: Toru Nakajima |      *   *  *    *    *        *   *      |\n";
    cout << "| |             Tingting Wang |   *            *         *   *         *  |\n";
    cout << "| |             Tin Hang Chui |                                           |\n";
    cout << "| |             John Dwyer    | *    *   *      *      *       *    *     |\n";
    cout << "| -----------------------------                                           |\n";
    cout << "|=========================================================================|\n";
}


/************************************************
 farawell function, displays a farawell messege.
 *************************************************/
void RunOption::farawellMessage()
{
    cout << "Thank you for using our program.\n";
    cout << "We hope you enjoyed this program.\n";
    cout << "Have a nice day!";
}
