/*
 * twit.cpp
 *
 * Copyright (C) 2010 - Ershad K ershad92@gmail.com
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 *  is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */
 
 
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void postStatus(string);

int main()
{

  string status;
   
  cout << "\n Status: ";
  getline (cin, status);

  while (status.size() > 140)
    {
      cout << "\n Too long, the status' size is : " << status.size();
      cout << "\n\n Status: ";
      getline (cin, status);
       
    }
   
  postStatus(status);
   
  return 0;
}

void postStatus(string status)
{
  cout << "\n [OK] The size of status is : " << status.size();
   
  string cmd;
   
  cmd = "curl --basic --user USERNAME:PASSWORD --data status=\"";
  cmd += status + "\" http://twitter.com/statuses/update.xml";
   
  //cout << cmd;
   
  system (cmd.c_str());
  system ("clear");
  cout << "\n Posted successfully!\n\n";
}
