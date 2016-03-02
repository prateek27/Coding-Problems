#ifndef SEPARATE_CHAINING_H
#define SEPARATE_CHAINING_H

#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;


int nextPrime(int n);

// SeparateChaining Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert(x)       --> Insert x
// bool remove(x)       --> Remove x
// bool contains(x)     --> Return true if x is present
// void makeEmpty()      --> Remove all items

template <typename HashedObj>
class HashTable {
  private:
    vector<list<HashedObj> > theLists;   // The array of Lists
    int  currentSize;

    void rehash();
    unsigned int myhash(const HashedObj & x) const;
  
  public:
    explicit HashTable(int size = 101) : currentSize(0){ 
        theLists.resize(size); 
    };

    bool contains(const HashedObj & x) const;
    void makeEmpty();
    bool insert(const HashedObj & x);
    bool remove(const HashedObj & x);
};

#endif
