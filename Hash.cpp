/* Hash.cpp
 *
 *  Hash table implementation
 *  8 November 2017
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>
#include "hash.h"

using namespace std;

HashT::HashT()   //constructor to create and initialize the initial table
{
    for (int i = 0; i < TableSize; i++)
    {
        HashTable[i] = new Block;
        HashTable[i] -> word = "empty";
        HashTable[i] -> definition = "empty";
        HashTable[i] -> next = NULL;
    }

    ifstream File;
    File.open ( "dict4.txt", ios::in );
    //File.open ( "dict8.txt", ios::in );
    string m;       //word
    string d = "defin";     //replacement

    while ( !File.eof())
    {
        File >> m;
        AddBlock ( m, d );
    }
}

void HashT::AddBlock ( string words, string def )
{
    int idx = Convert2Hash ( words );

    if ( HashTable[idx] -> word == "empty" )
    {
        //column idx is empty in table
        HashTable[idx] -> word = words;
        HashTable[idx] -> definition = def;
    }
    else
    {
        //column idx is not empty
        ListPtr P = HashTable[idx];
        ListPtr N = new Block;
        N -> word = words;
        N -> definition = def;
        N -> next = NULL;

        while ( P -> next != NULL )
        {
            P = P -> next;
        }
        P -> next = N;
    }
}

int HashT::IdxCount ( int Idx )
{
    int num = 0;    //declares and initializes the index count

    if ( HashTable[Idx] -> word == "empty") //empty column
        return num;
    else
    {
        //Column not empty
        num++;
        ListPtr P = HashTable[Idx];
        while ( P -> next != NULL )
        {
            num++;
            P = P -> next;
        }
    }

    return num;
}

void HashT::FindMin ()
{
    int Minimum = 200000;   //set Minimum value to obscenely high number to prevent wrong return
    int ECount = 0;

    for ( int j = 0; j < TableSize; j++ )
    {
        if ( IdxCount ( j ) < Minimum )
        {
            Minimum = IdxCount ( j );
        }
        if ( IdxCount ( j ) == 0)
            ECount++;
    }

    cout << "The bucket with the smallest number of words has " << Minimum << " words!" << endl;
    cout << "The empty bucket count is: " << ECount << endl;
}

void HashT::FindMax ()
{
    int Maximum = 0;   //set Maximum value to obscenely low number to prevent wrong return

    for ( int k = 0; k < TableSize; k++ )
    {
        if ( IdxCount ( k ) > Maximum )
        {
            Maximum = IdxCount ( k );
        }
    }

    cout << "The bucket with the most number of words has " << Maximum << " words!" << endl;
}

void HashT::PrintTable()
{
    int N;

    for ( int i = 0; i < TableSize; i++ )
    {
        N = IdxCount ( i );
        cout << endl << "The cell number is: " << i << endl;
        cout << HashTable[i] -> word << endl;
        cout << HashTable[i] -> definition << endl;
        cout << "The number of words in this bucket is: " << N << endl;
        cout << "________________________________________________" << endl;
    }
}

int HashT::Convert2Hash ( string w )
{
    int HKey = 0;
    int idx;

    for ( int j = 0; j < w.length(); j++ )
    {
        HKey = HKey + ( (int)w[j] * 11 );
    }

    idx = HKey % TableSize;
    return idx;
}

void HashT::WordSearch ( string T )
{
    int Probes = 0;     //will count the number of probes

    for ( int k = 0; k < TableSize; k++ )
    {
        ListPtr P = HashTable[k];

        while ( P != NULL )
        {
            if ( (P -> word) == T )
            {
                cout << "Your word was found in the dictionary!" << endl;
                cout << "The # of probes made: " << Probes << endl << endl;
                break;
            }
            else
            {
                 P = P -> next;
                 Probes++;
            }
        }
    }
}
