/*
 *      checknet.cpp
 *      
 *      Copyright 2009 Ershad K ershad92@gmail.com
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

// Includeing header files....

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Declaring global variables...

long usage = 1;
long lastsize = 0;
int j;
int main()

{
  char d[50];
  char c[200];
  // system ("sudo bash"); - not working
  for (int i = 0;;i++){

    // Declaring local variables and pointers..
    j = 0;
    
    FILE *fpipe;
        
    char *command="sudo ifconfig ppp0 | grep 'RX bytes'"; // get netowrk usage from shell
        
    sleep(1);    // Delay one second
        
    lastsize = usage;  // Assigning last network usage
        
    sleep(1);        // Again Delay
         
    fpipe = (FILE*)popen(command,"r");
    fgets( c, sizeof c, fpipe); 
        
    // cout<<"\n\n------------------------check # "<<i+1<<" -------------\n";
         
    //cout <<" Input string : "; // for debugging
         
    //puts(c);  // for debugging
         
    // extracting 'recieved network usage' as integers from the string
        
    for (int i = 0; c[i] != '('; i++)
      {
	switch (c[i])
	  {
	  case '1' : d[j] = c[i]; j++; break;
	  case '2' : d[j] = c[i]; j++; break;
	  case '3' : d[j] = c[i]; j++; break;
	  case '4' : d[j] = c[i]; j++; break;
	  case '5' : d[j] = c[i]; j++; break;
	  case '6' : d[j] = c[i]; j++; break;
	  case '7' : d[j] = c[i]; j++; break;
	  case '8' : d[j] = c[i]; j++; break;
	  case '9' : d[j] = c[i]; j++; break;
	  case '0' : d[j] = c[i]; j++; break;
	  default : break;
	  }
      }     
        
    d[j] = '\0';
        
    //cout <<"\n After filtering : ";
    //puts(d);
    cout <<"\n";

    usage = atof(d); // converting filtered string
            
    system("clear");
    cout<<"-------------------------------------------------------------------\n";
    cout << " CheckNet V 1.0 Alpha                 www.ershadk.wordpress.com";
    cout<<"\n-------------------------------------------------------------------";   
    //cout << " New usage = " << usage << " Last usage = " << lastsize << "\n"; // For debugging
        
    float speed;
    speed = (float)(usage - lastsize)/2000;

    if (usage == lastsize){
      cout << " \n\n New usage = " << usage << " Last usage = " << lastsize << "  Speed = "<<speed<<" kbps \n"; // For debugging
      cout <<"\n\n CAUTION !! Net is gone or down \a!!\n\n";
    }
    else{
      cout << " \n\n New usage = " << usage << " Last usage = " << lastsize << "  Speed = "<<speed<<" kbps\n"; // For debugging
      cout <<"\n\n Net is working fine :) \n\n";
            
    }
        
  }
  return 0;       
}
