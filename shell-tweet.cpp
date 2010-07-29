/*
 *      shell-tweet.cpp
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

/*   This program was written for my personal use. Modify accordingly so
 *   that it would be useful to you too. Suggestions are welcome.
 */


#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
  char name[] = "username", password[] = "password", status[500], cmd[500];

  char sym[] = {char(34),'\0'};

 again: cout << "\n Status: ";
  gets (status);


  cout << "\n Length = " << strlen(status);

  if (strlen(status) > 139) 
    {
      cout << " Exceeds 140 character limit, Type again \n";
      goto again;
    }
  else
    {
      
      strcpy(cmd,"wget --keep-session-cookies --http-user=");
      
      strcat(cmd,name);
      strcat(cmd," --http-password=");
      strcat(cmd,password);
      strcat(cmd," --post-data=");
      strcat(cmd,sym);
      strcat(cmd,"status=");
      strcat(cmd,status);
      strcat(cmd,sym);
      strcat(cmd," http://twitter.com:80/statuses/update.xml");
      
      system(cmd);
    }
  return 0;
}
