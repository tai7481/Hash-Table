/*

Hash.h header file for dictionary hash table assignment

8 November 2017

*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

class HashT
{
private:

    static const int TableSize = 101;   //maximum Table Sizes
    //static const int TableSize = 8017;
    //static const int TableSize = 11037;
    //static const int TableSize = 49957;

    struct Block    //entry of the hash table
    {
        string word;    //word from file
        string definition;  //replacement definition
        Block * next;   //linked list pointer to next Block
    };

    typedef struct Block * ListPtr;  //general pointer for the Block
    ListPtr HashTable[TableSize];

public:
    HashT();            //constructor
    void PrintTable();  //Table printer
    void AddBlock ( string words, string def );  //Inserting new Block into designated column
    int IdxCount ( int Idx );   //Counts the number of blocks in specific column
    int Convert2Hash ( string w );  //converting text to numbers
    void FindMin ();    //Finds the minimum bucket and outputs it
    void FindMax ();    //Finds the maximum bucket and outputs it
    void WordSearch ( string T );   //word search function

};


#endif // HASH_H_INCLUDED
