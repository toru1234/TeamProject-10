
#ifndef __TeamProject__Website__
#define __TeamProject__Website__

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

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
    //constructor(default)
    
    // constructor with arguments
    Website(string name = "", string nationality = "", unsigned int global = 0, unsigned int time = 0, string owner = "", float visitor = 0.0)
    {
        this->name = name;
        this->nationality = nationality;
        this->global_rank = global;
        this->Avg_dailyTime_onSite = time;
        this->owner = owner;
        this->Avg_dailyView_perVisitor = visitor;
    }
    //setters
    void setName(string str){name = str;}
    void setNationality(string str){nationality = str;}
    void setGlobalRank(unsigned int num){global_rank = num;}
    void setAvgTime_OnSite(int time){Avg_dailyTime_onSite = time;}
    void setOwner(string str){owner = str;}
    void setAvgview_perVisitor(float num){Avg_dailyView_perVisitor = num;}
    
    //getters
    string getName() const {return name;}
    string getNationality() const {return nationality;}
    unsigned int getGlobalRank() const {return global_rank;}
    int getAvgTime_OnSite() const {return Avg_dailyTime_onSite;}
    string getOwner()const {return owner;}
    float getAvgview_perVisitor() const { return Avg_dailyView_perVisitor;}
    
    Website operator = (const Website& right){
        this->name = right.getName();
        this->nationality = right.getNationality();
        this->global_rank = right.getGlobalRank();
        this->Avg_dailyTime_onSite = right.getAvgTime_OnSite();
        this->owner = right.getOwner();
        this->Avg_dailyView_perVisitor = right.getAvgview_perVisitor();
        return *this;
    }
    
    bool operator > (const Website& right) const{
        return (this->name > right.getName() ? true: false);
    }
    
    bool operator < (const Website& right) const{
        return (this->name < right.getName() ? true: false);
    }
    
    bool operator == (const Website& right) const{
        return (this->name == right.getName() ? true: false);
    }
    
    bool operator >= (const Website& right) const{
        return (this->name >= right.getName() ? true: false);
    }
    
    bool operator <= (const Website& right) const{
        return (this->name <= right.getName() ? true: false);
    }
    
    friend ostream& operator << (ostream& os, const Website& web) {
        if(web.getName() != ""){
            os << setw(22) << left;
            os << "Domain Name: " << web.getName() << endl;
            os << setw(22) << left;
            os << "Nationality: " << web.getNationality() << endl;
            os << setw(22) << left;
            os << "Rank: " << web.getGlobalRank() << endl;
            os << setw(22) << left;
            os << "Average Time on Site: " << web.getAvgTime_OnSite() << endl;
            os << setw(22) << left;
            os << "Owner: " << web.getOwner() << endl;
            os << setw(22) << left;
            os << "Average View: "  << web.getAvgview_perVisitor() << endl;
        }
        return os;
    }
};


#endif
