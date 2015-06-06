
// funtion declarition for RunOption.h

#include "RunOption.h"

// diaplay function, will be passed in parameter.
void display(Website & website)
{
   cout << website;
}

// main function for runOption. It will display the menu and build trees and hash table.
void RunOption::run()
{
	char choice;
	bool quit = false;

	do {
      cout << "Welcome! Our program is about the popular websited all around the world." << endl;
		cout << "Please input the letter corresponding to the function you'd like to use from the list below." << endl;
		cout << "A - Add New Website\n"
			  << "D - Delete Website\n"
			  << "S - Search for Website(s)\n"
			  << "L - List Websites\n"
           << "W - Write data into file\n"
           << "H - Statistics\n"
			  << "Q - Quit\n"<< endl;
      
		cin >> choice; 
		choice = toupper(choice);
		cout << endl;

		switch (choice)
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
}

// functionality for menu driven function.
void RunOption::caseAdd()
{
   // call tree insert function
}
void RunOption::caseDelete()
{
   // call tree delete function
   
}
void RunOption::caseStatistic()
{
   // hash
}
void RunOption::caseWriteFile()
{
   // save the tree into output file
}
void RunOption::caseSearch()
{
	char subChoice;
	bool invalid;

	do {
		invalid = false;
		cout << "Please select a search type from the options below.\n" << endl
			 << "N - Display website data for given domain name\n"
			 << "C - Display websites by country\n" 
			 << "R - Return to previous menu\n" << endl;
		cin >> subChoice;
		subChoice = toupper(subChoice);
		cout << endl;

		switch (subChoice)
		{
			case 'N': // domain name
         {
            cout << "Please enter the name of the website you want to search:";
            string primarykeyName;
            cin >> primarykeyName;
            Website targetWebsite(primarykeyName);
            Website aquiredWebsite;
            tree->getEntry(primarykeyName, aquiredWebsite);
            display(aquiredWebsite);
				break;
         }
			case 'C': // by country
         {
            cout <<"Please enter the name of the country that you want ot search:";
            string secondaryKey;
            cin >> secondaryKey;
				break;
         }
			case 'R': // previous
            invalid = true;
            run();
				break;
			default:
				invalid = true;
				cout << endl << "Invalid input. ";
				break;
		}
	} while (invalid);
}

void RunOption::caseList()
{
	char subChoice;
	bool invalid;

	do {
		invalid = false;
		cout << "Please select how to display the website data from the options below.\n" << endl;
		cout << "U - display unsorted\n"
			<< "P - display by domain name\n"
			<< "O - display by countries\n"
			<< "I - display special\n" 
			<< "R - Return to previous menu\n" << endl;
		cin >> subChoice;
		subChoice = toupper(subChoice);
		cout << endl;

		switch (subChoice)
		{
			case 'U': // unsorted
            cout << "Unsorted List as Followed:" << endl;
            // call shuffle, shuffle the vector array.
				break;
			case 'P': // alphabetical
            cout << "Sorted by the name of the website:" << endl;
            // call printBST tree.
				break;
			case 'O': // countries
            cout << "Sorted by country:" << endl;
            // call print SecondaryTree function.
				break;
			case 'I': // special
            cout << "Sorted tree indented list:" << endl;
				break;
			case 'R': // previous
            invalid = true;
            run();
				break;
			default: 
				invalid = true;
            cout << "Invalid input." << endl;
				break;
		}
	} while (invalid);
}


Website* RunOption::buildTreeNodeArr(string fileName)
{
   vector<Website> webNodeArr;
   ifstream input(fileName);
   if (input.fail())
   {
      cout << "Error opening file!";
   }
   
   string holdData;
   int numOfData = 0;
   
   
   getline(input, holdData);
   numOfData = atoi(holdData.data());
   
   int index = 0;
   
   Website webNode;
   while (index < numOfData)
   {
      
      getline(input, holdData);
      webNode.setName(holdData);
      
      getline(input, holdData);
      webNode.setNationality(holdData);
      
      getline(input, holdData);
      webNode.setGlobalRank(atoi(holdData.data()));
      
      getline(input, holdData);
      webNode.setAvgTime_OnSite(atoi(holdData.data()));
      
      getline(input, holdData);
      webNode.setOwner(holdData);
      
      getline(input, holdData);
      webNode.setAvgview_perVisitor(atof(holdData.data()));
      
      webNodeArr.push_back(webNode);
      
      getline(input, holdData);
      index++;
      
   }
   
   return &webNodeArr[0];
}

void RunOption::buildUniqueKeyTree()
{
   // call insert function to insert the nodes from array.
}

void buildSecondaryKeyTree()
{
   // build secondary key tree by using the node vector.
}

