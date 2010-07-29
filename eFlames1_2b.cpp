/*
 *      e-FLAMES.cpp
 *     
 *      Copyright 2009 Ershad K <ershad92@gmail.com>
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

//Including header files..
#include <iostream>
#include <string.h>
#include <stdlib.h> //for system() function
#include "jesse_conio.h"

char name1[30], name2[30]; //declaring global name variables

using namespace std; // dunno what's this, please tell me..

void message(); // for general headings and texts

void getnames(); // for names input

void copyright(); //print copyright notice


void changecase( char names[]); //change case function

void removespecial(char name_1[]); //remove spaces

int compare( char n1[], char n2[]); // cut similar characters and returns total length

int totnospace(char na1[]); // total length with no spaces..

int main()
{
  system("clear");
  int length1, length2, sum, switch_num;
 label1:message();
 label2:getnames();
   
  //finding length of each string
  length1 = strlen(name1);
  length2 = strlen(name2);
   
  //Removing spaces of name1....
   
  removespecial(name1);
       
  //Removing spaces of name2....
   
  removespecial(name2);
       
               
  // all characters must be in same case to cut similar ones using their ASCII values
  //changing case of name1...
 
  changecase(name1);

  // changing case name2...

  changecase(name2);
  
  //comparing and removing similar characters (the game logic)

  sum = compare(name1,name2);
  
  // Applying the total number on FLAMES
  
  if (sum<=6)
    switch_num=sum;
  else
    {
      while(sum>6)
	{
	  sum = sum-6;
	}
      switch_num=sum % 10;
    }
   
  switch (switch_num) //print output
    {
    case 0: cout<<"\n\n  :-> All letters are cut!! No comparison possible !!\n\n";break;
    case 1: cout<<"\n\n  >>    F - Friend !! ";break;
    case 2: cout<<"\n\n  >>    L - Lover !! ";break;
    case 3: cout<<"\n\n  >>    A - Anger !! ";break;
    case 4: cout<<"\n\n  >>    M - Marriage !! ";break;
    case 5: cout<<"\n\n  >>    E - Enemy !! ";break;
    case 6: cout<<"\n\n  >>    S - Sister !!";break;
    }

  //Menu

  char ch,ch1;
 label3:cout<<"\n\n             <Press r- Retry, s- Start over, a- About, Ctlr+c- Exit>\n";
 label4:ch=getch();
 
  if ((ch=='r')||(ch=='R'))
    goto label2;
  if ((ch=='a')||(ch=='A'))
    goto about;
  if ((ch=='s')|| (ch=='S'))
    {
      system("clear");
      goto label1;
    }
   
  if((ch1=='c') || (ch1=='C'))
    {
      copyright();
      goto label3;
    }
 


  cout<<"\n Unknown Command !! <Press r- Retry, s- Start over, a- About, Ctrl+c- Exit>\n";
  goto label4;

  //Print 'about' on command
 about:system("clear");
  cout<<"\n________________________________________________________________________________";
  cout<<" \n >>    About";
  cout<<"\n--------------------------------------------------------------------------------";
  cout<<"\n\n e-FLAMES  V 1.0 Beta (GNU/Linux edition)     ";
  cout<<"\n`````````````````";
  cout<<"\n                               Copyright (C) 2009 Ershad K. All Rights Reserved.";
  cout<<"\n\n Developed by : Ershad K";
  cout<<"\n\n +1 CS B.E.M.H.S.S, Palakkad, Kerala";
  cout<<"\n\n E-mail : ershad92@gmail.com";
  cout<<"\n\n URL    : www.ershadk.wordpress.com";
  cout<<"\n\n\n      Thanks to jesse (thejpf-integratinglife.blogspot.com), who made getch() \nfunction for this program in GNU/Linux. This program is just for fun and it \nworks purely based on a mathematical logic. If you have any suggestions, please don't hesitate to mail me.   Your feedback is valuble for future development. ";
  cout<<"\n ";
  cout<<"\n                     <Press  c- View copyright,s- Start over, Ctrl+c- Exit>\n";
     
  // Menu
  ch1 =getch();
  if((ch1=='c') || (ch1=='C'))
    {
      copyright();
      goto label3;
    }
        
  if((ch1=='s') || (ch1=='S'))
    { system("clear");
      goto label1;
    }
     
  goto label4; // To avoid unintentional termination of program
  return 0;
}


// Function Definitions....

void message()
{
  cout<<"\n--------------------------------------------------------------------------------";
  cout<<"\n";
  cout<<"    e-FLAMES   V 1.0 Beta (GNU/Linux edition)                          ";
  cout<<"\n    ----------------";
  cout<<"                                 www.ershadk.wordpress.com";
  cout<<"\n--------------------------------------------------------------------------------";
  cout<<"\n           Please don't use special characters other than space";
     
}
 
void getnames()
{
  cout<<"\n--------------------------------------------------------------------------------";
  cout<<"\n\n Enter first name  : ";
  gets(name1);
    
  cout<<"\n Enter second name : ";
  gets(name2);
}
 
void changecase(char names[])
{
  for (int count = 0; names[count] != '\0'; count++)
    {
      if ((names[count]>=65) && (names[count]<=90))
	names[count] = names[count]+32;             
    }
}

void removespecial(char nam[])
{
  int len = strlen(nam);
  for (int j = 0; nam[j] != '\0'; j++) { //Beginning of for loop
    if (nam[j]==' ') { //Beginning of if condition
      len--;
      for (int l=j; nam[l] != '\0'; l++) { //Beginning of inner for loop
	nam[l] = nam[l+1];
      } // Ending of inner for loop
    } // Ending of if condition
  } // Ending of for loop
}

int compare( char n1[], char n2[])
{
  for (int count1 = 0; n1[count1] != '\0'; count1++)
    {
      for (int count2 = 0;n2[count2] != '\0'; count2++)
	{
	  if (n1[count1] == n2[count2])
	    {
	      n1[count1] = ' ';
	      n2[count2] = ' ';
	    }
	}
    }
                     
  int total = totnospace(n1) + totnospace(n2);
  return total;
     
}

int totnospace(char na1[])
{
  int tot = strlen(na1);
  for ( int u=0;name1[u]!='\0'; u++)
    {
      if(name1[u]==' ')
	{
	  tot--;
	}
    }
  return tot;
}   
  
void copyright()
{
  system("clear");
  cout<<"\n--------------------------------------------------------------------------------";
  cout<<"\nCOPYRIGHT";
  cout<<"\n--------------------------------------------------------------------------------";
  cout<<" e-FLAMES V 1.0 Beta\n";
  cout<<" Copyright (C) 2009  Ershad K";
   
  cout<<"\n\nThis program is free software: you can redistribute it and/or modify";
  cout<<"\nit under the terms of the GNU General Public License as published by";
  cout<<"\nthe Free Software Foundation, either version 3 of the License, or";
  cout<<"\n(at your option) any later version.";

  cout<<"\n\nThis program is distributed in the hope that it will be useful,";
  cout<<"\nbut WITHOUT ANY WARRANTY; without even the implied warranty of";
  cout<<"\nMERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the";
  cout<<"\nGNU General Public License for more details.";

  cout<<"\n\nYou should have received a copy of the GNU General Public License";
  cout<<"\nalong with this program.  If not, see <http://www.gnu.org/licenses/>.";
}
