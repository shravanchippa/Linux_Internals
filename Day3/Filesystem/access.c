/******************************************************************************
			---------  access.c  ----------

	Description : To check the file permissions
	This example checks the  file permissions for a specified file
	using  access system call is used to  do the  same
	
	Version : 1.0
	Source : R.Stevens

	Author : vikaskaranth@gmail.com
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
*****************************************************************************/
#include<errno.h>
#include<stdio.h>
#include<unistd.h>

int main(int argc, char* argv[])
{
	char* path = argv[1];
	int ret;
	ret = access(path,F_OK); // check for file exists
	if(ret == 0)
	printf(" %s file exists\n",path);
}
// R_OK to check read permission	
// W_OK to check write permission	
// X_OK to check execution permission	
// _OK to check read permission	
// _OK to check read permission	
	 
