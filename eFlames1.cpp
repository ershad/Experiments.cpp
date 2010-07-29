/* This project started on 29-01-2009(DD-MM-YYYY) with an objective
   to compile 'FLAMES' Game in C++ */
//------------------------------------------------------------------------------
// Project : e-FLAMES
// Copyright © 2009. All Rights Reserved.
//
// SUBSYSTEM:    e-Flames Application
// FILE:         flames.cpp
// AUTHOR: Ershad Kunnakkadan
//         e-mail : ershad92@gmail.com
//------------------------------------------------------------------------------

#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <process.h>
#include <stdio.h>
void main()

{
  int len1,len2;
  char name1[30],name2[30];
  /* get the two names to be compared */
 starty:cout<<"\n";
  cout<<"    e-FLAMES   V 1.0                          ";
  cout<<"\n    ----------------";

  cout<<"\n                                               Ershad K  ershad92@gmail.com";
 st:cout<<"\n________________________________________________________________________________";

  cout<<"\n Enter first name  : ";
  gets(name1);

  cout<<"\n Enter second name : ";
  gets(name2);

  len1 = strlen(name1);
  len2 = strlen(name2);
  //removing spaces....
  for (int i=0;name1[i]!='\0'; i++)
    {
      if(name1[i]==' ')
	{
	  len1--;
	  for(int k=i;name1[k]!='\0';k++)
	    {
	      name1[k]=name1[k+1];
	    }
	}

    }
  for (int j=0;name2[j]!='\0';j++)
    {
      if(name2[j]==' ')
	{
	  len2--;
	  for(int l=j;name2[l]!='\0';l++)
	    {
	      name2[l]=name2[l+1];
	    }
	}
    }
  // removed spaces !!!

  //Changing case......

  for(int ii=0;name1[ii]!='\0';ii++)
    {
      if(name1[ii]<=90)
	name1[ii]= name1[ii] + 32;
    }

  for(int ij=0;name2[ij]!='\0';ij++)
    {
      if (name2[ij]<=90)

	name2[ij]= name2[ij] + 32;
    }

  //comparing strings......
  char temp1;
  for (int m=0;name1[m]!='\0';m++)
    {

      for( int n=0;name2[n]!='\0';n++)
        {
	  if (name1[m]==name2[n])
	    {
	      name1[m]=' ';
	      name2[n]=' ';
                 
	    }
        }
    }



  /*------------------------------*/
  for ( int u=0;name1[u]!='\0'; u++)
    {
      if(name1[u]==' ')
	{
	  len1--;
	}

    }
  for (int v=0;name2[v]!='\0';v++)
    {
      if(name2[v]==' ')
	{
	  len2--;
	}
    }
  /*-----------------------------*/
  int xx,tl;

  tl=len1+len2;

  if (tl<=6)
    xx=tl;
  else
    {
      while(tl>6)
	{
	  tl = tl-6;
	}
      xx=tl%10;
    }

  switch (xx)
    {
    case 0: cout<<"\n\n  :-> All letters are cut!! No comparison possible !!\n\n";break;
    case 1: cout<<"\n\n  >>    F - Friend !! ";break;
    case 2: cout<<"\n\n  >>    L - Lover !! ";break;
    case 3: cout<<"\n\n  >>    A - Anger !! ";break;
    case 4: cout<<"\n\n  >>    M - Marriage !! ";break;
    case 5: cout<<"\n\n  >>    E - Enemy !! ";break;
    case 6: cout<<"\n\n  >>    S - Sister !!";break;
    }
  cout<<"\n\n             <Press r- retry, s- Start over, a- about, e- exit>\n";

  /* to debug....
     cout<<"\n\n\n "<<xx<<"\n\n\n";


     cout<<"\nLength of first name is "<<len1<<" ";
puts(name1);
cout<<"\nLength of second name is "<<len2<<" ";
puts(name2);
  */
  char ch;
 ifa:ch=getch();
  if (ch=='r')
    goto st;
  if (ch=='R')
    goto st;
  if (ch=='S')
    {
      clrscr();
      goto starty;
    }
  if (ch=='s')
    {
      clrscr();
      goto starty;
    }
  if (ch=='e')
    exit(0);
  if (ch=='E')
    exit(0);
  if (ch=='a')
    goto about;
  if (ch=='A')
    goto about;

  cout<<"\n Unknown Command !! <Press r- retry, s- Start over, a- about, e- exit>\n";
  goto ifa;
 about:cout<<"\n________________________________________________________________________________";
  cout<<" \n\n\n >>    About";
  cout<<"\n--------------------------------------------------------------------------------";
  cout<<"\n\n e-FLAMES  V 1.0                        Copyright © 2009. All Rights Reserved.";
  cout<<"\n`````````````````````";
  cout<<"\n\n Developed by : Ershad K";
  cout<<"\n\n E-mail : ershad92@gmail.com";
  cout<<"\n ";
  cout<<"\n         This is a free software. You are encouraged to copy or redistribute ";
  cout<<"\n this program for yourself and your friends.If you have any suggestions, please";
  cout<<"\n don't hesitate to mail me. Your feedback is valuble for future development. ";
  cout<<"\n--------------------------------------------------------------------------------";
  cout<<"\n";
  goto gt;
 gt:cout<<"               <Press  r- retry,s- Start over, e- exit>\n";
  goto ifa;
}
