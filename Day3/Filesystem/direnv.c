/***************************************************************************
                          direnv.c  -  description
                             -------------------
    begin                : Wed Jul 23 2003
	Description:
		To print the environmental variable 
	version : 1.0
	Source R.Stevens
	Author : vikaskaranth@gmail.com
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/


extern  char ** environ;
int i;

main()
{
	system(" clear");
	for (i = 1; i < 30 ;i++)
	
		printf("\t%d. %s\n",i, environ[i]);
		printf("\n");
}
