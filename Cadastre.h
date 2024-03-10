#ifndef CADASTREPROPERTY_CADASTRE_H
#define CADASTREPROPERTY_CADASTRE_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <ctime>
using namespace std;

class CIterator
{
public:
   CIterator(const string& region, unsigned int id, const string& city, const string& addr, const string& owner = "");

   bool EqualCA(const string& city, const string& addr) const;

   bool EqualRID(const string& region, unsigned int id) const;

   void Print() const; // My own method, delete later

private:
    string m_Region;
    unsigned int m_ID;
    string m_City;
    string m_Address;
    string m_Owner;
};

class CLandRegister
{
public:
    CLandRegister();

    bool add (const string& city, const string& addr, const string& region, unsigned int id);

    void PrintAll() const; // My own method, delete later

    //bool del (const string& city, const string& addr);

    //bool del (const string& region, unsigned int id);

    //bool getOwner (const string& city, const string& addr, string& owner) const;

    //bool getOwner ( const string& region, unsigned int id, string& owner) const;

    //bool newOwner (const string& city, const string& addr, const string& owner);

    //bool newOwner ( const string& region, unsigned int id, const string& owner);

private:
    std::vector<CIterator> m_List;
};

#endif //CADASTREPROPERTY_CADASTRE_H
