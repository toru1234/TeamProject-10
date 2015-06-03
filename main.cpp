#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
class Website
{
private:
    string name;                        //the name of the website
    string nationality;                 //the nationality of the server
    unsigned int global_rank;           //the global rank by the amount of visitor per day
    unsigned int Avg_dailyTime_onSite;            //the average time that user stay in the website
    string owner;                     //the name of the company or foundation that owns this website
    float Avg_dailyView_perVisitor;       //the average daily view per visitor
public:
    //constructor

    //setters
    void setName(string str){name = str;}
    void setNationality(string str){nationality = str;}
    void setGlobalRank(unsigned int num){global_rank = num;}
    void setAvgTime_OnSite(int time){Avg_dailyTime_onSite = time;}
    void setOwner(string str){owner = str;}
    void setAvgview_perVisitor(float num){Avg_dailyView_perVisitor = num;}

    //getters
    string getName(){return name;}
    string getNationality(){return nationality;}
    unsigned int getGlobalRank(){return global_rank;}
    int getAvgTime_OnSite(){return Avg_dailyTime_onSite;}
    string getOwner(){return owner;}
    float getAvgview_perVisitor(){return Avg_dailyView_perVisitor;}
};

bool readFile();
int main()
{
    if(!readFile())
    return 1;

    return 0;
}

bool readFile(){
    ifstream input("websiteData.txt");
    if (input.fail()){
        cout << "the file didn't open successfully";
        return false;
    }
    string holdData;

    int numOfData = 0;

    getline(input, holdData);
    numOfData = atoi(holdData.data());

    Website* web = new Website[numOfData];
    int index = 0;
    while (index < numOfData){
        getline(input, holdData);
        web[index].setName(holdData);
        cout << holdData << endl;

        getline(input, holdData);
        web[index].setNationality(holdData);
        cout << holdData << endl;

        getline(input, holdData);
        web[index].setGlobalRank(atoi(holdData.data()));
        cout << holdData << endl;

        getline(input, holdData);
        web[index].setAvgTime_OnSite(atoi(holdData.data()));
        cout << holdData << endl;

        getline(input, holdData);
        web[index].setOwner(holdData);
        cout << holdData << endl;

        getline(input, holdData);
        web[index].setAvgview_perVisitor(atof(holdData.data()));
        cout << holdData << endl;

        index++;

    }


    for (int i  = 0; i < numOfData; i++){
       cout <<  web[i].getName() << endl <<
        web[i].getNationality() << endl <<
        web[i].getGlobalRank() << endl<<
        web[i].getAvgTime_OnSite() << endl<<
        web[i].getOwner() << endl <<
        web[i].getAvgview_perVisitor() << endl;
    }

}
