/*
 *      sqpattern.cpp
 *
 *      Copyright 2010 Ershad K  ershad92@gmail.com
 *      Licensed under GPL Version 3
 *
 *      Please change USERNAME, PASSWORD and compile with g++
 *      To compile - g++ -o sqpattern sqpattern.cpp
 *      To execute - ./sqpattern
 */

#include <iostream>
using namespace std;

int main()
{
  int size;
  cout << "Enter size: ";
  cin >> size;
  
  int count = 1;
  cout << " ";
  while (count++ < size) cout << " _";
  
  for (int i = 1; i < size; i++)
    {
      int numOfCharsPerLine = 0;
      cout << "\n";
      for (int j = 0; j < i; j++)
		{
		  cout << " |";
		  numOfCharsPerLine += 2;
		}     

      cout << "_";
      numOfCharsPerLine += 1;

      int k = 1;
      while (k++ < (size*2) -  numOfCharsPerLine )
		cout << " ";
      cout << "|";

    }
  
  count = 1;
  cout << "\n ";
  while (count++ <= (size)-1 ) cout << "|_";

  cout << "|\n";
  
return 0;
}
