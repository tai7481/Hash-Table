/*
William Tai
CS121, Fall 2017
HW#5 - Hash Tables and Dictionaries
Will input 2 separate dictionaries into the program from
the class implementation and will convert the data into hash
values and stored in a table with containers (buckets) of
linked lists

8 November 2017
*/

#include <iostream>
#include <cstdlib>
#include "Hash.h"

using namespace std;

int main()
{
    int Option;     //loop for user options

    HashT Object;   //creates the tables from dictionary dependent data
    //Object.PrintTable();    //Prints the Table
    Object.FindMax();       //Prints the maximum bucket count
    Object.FindMin();       //Prints the minimum bucket count

    do
    {
        cout << "Welcome to word search!" << endl;
        cout << "Would you like to continue?  ";
        cout << "Please enter your choice (1)yes, (2)no: ";
        cin >> Option;
        string User;        //user input

        switch (Option)
        {
        case 1:
            {
                cout << endl << "Please input your word: ";
                cin >> User;
                Object.WordSearch ( User );
                break;
            }
        case 2:
            {
                cout << "OK, Goodbye!" << endl;
                break;
            }
        default:
            {
                cout << "Invalid choice! Try again." << endl;
                break;
            }

        }
    }
    while ( Option != 2 );

    return 0;
}
