/*
 *      SDPP.cpp
 *      
 *      Copyright 2009 Ershad <ershad92@gmail.com>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */


#include <iostream>
#include <stdio.h>

using namespace std;

/*
TABLE 50 * 8 : 
      C0 - Malayalam
      C1 - English
      C2 - Physics
      C3 - Chemistry
      C4 - Maths
      C5 - CS
      C6 - Sum
      C7 - Average
*/

int maxst = 10000,row,col,temp = 1;
char ctemp = 'a';


class result
{
private:
  float table[10000][8];
  char  names[10000][50];
public:
  void inputname();
  void inputdata();
  void processdata();             
  void display();
           
  float sum (float mal, float eng, float phy, float chy, float maths, float cs)   
  {
    return (mal + eng + phy + chy + maths + cs); 
  }        
};

void result::inputdata()
{
  cout << "\n >> Writing some data in to fields.Please wait...";
  for (row = 0; row < maxst; row++)
    {
      for ( col = 0; col < 6; col++)
	{
	  if (temp == 49) 
	    {
	      temp = 1; 
	      table[row][col] = temp++;
	    }
	  else 
	    table[row][col] = temp++;
	}
    }
     
  cout << "\n    !! Done, Filled "<<maxst*8<<" data entries. \n";
     
}

void result::inputname()
{
          
  cout << "\n >> Generating random character sets.Please wait...";
     
  for (row = 0; row < maxst; row++)
    {
      for ( col = 0; col < 5; col++)
	{
	  if (ctemp == 'z')
	    {
	      ctemp = 'a'; 
	      names[row][col] = ctemp++;
	    }
	  else 
	    names[row][col] = ctemp++;
	}
      names[row][++col] = '\0';
    }
             
  cout << "\n    !! Done, Wrote "<<maxst<<" Names...\n";
    
}           

void result::processdata()
{
  cout << "\n >> Processing...Please wait... ";
  for (row = 0; row < maxst; row++) // Individual sum...
    {
      table[row][6] = sum(table[row][0], table[row][1],table[row][2],table[row][3],table[row][4],table[row][5]);
      table[row][7] = (table[row][6])/6; // Average
    }
  //subject wise result....
     
  for (temp = 0; temp <5; temp++) // initialisation of sum row....
    table[maxst+1][temp] = 0;
       
  //Average..
  for (col = 0; col < 6; col++)
    {
      for (row = 0; row < maxst; row++)
	table[maxst+1][col] = (table[maxst+1][col] + table[row][col]);
    }
     
  cout << "\n    !! Completed.Displaying... \n";
}

void result::display()
{
  int i,j;
  cout<<"\n\n\n";
  cout << "\n Table "<<maxst+2<<" x 9\n\n";
  cout << "---------------------------------------------------------------------";
  cout << "\nName   Mal\tEng\tPhy\tChy\tMaths\tCS\tSum\tAvg\n";
  cout << "---------------------------------------------------------------------\n";
     
     
  for (row = 0; row < maxst; row++)
    {
      for(i =0; i < 5; i++)
	cout<<names[row][i];
         
      cout <<" \t";
         
      for (col = 0; col < 8; col++)
	cout << table[row][col]<<"\t";
         
         
      cout <<"\n\n";
    }
     
  for (j = 0; j < 6; j++)
    {
      if (j==0) {
	cout << "\n---------------------------------------------------------------------";          
        cout<<"\nAverage ";
      } 
      cout<<(table[maxst+1][j] / maxst)<<"\t";
    }
  cout << "\n---------------------------------------------------------------------\n";
}

int main()
{
  result std10;
  std10.inputname();
  std10.inputdata();
  std10.processdata();
  std10.display();
  
  getchar();
  return 0;
}
