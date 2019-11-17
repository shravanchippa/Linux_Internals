/*
*/

# include <iostream>
# include <cstdio>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
using namespace std;

main(int argc,char *argv[])
{
	FILE	*fin, *fout;
	char	buffer[1024];
	int	n;
	system("clear");
	if(argc < 3) {
		cerr << "Usage a.out  " << "cmd1 cmd2" << endl;
		return 1;
	}
	fin = popen(argv[1], "r");
	fout = popen(argv[2], "w");
	fflush(fout);
	while((n = read(fileno(fin), buffer, 1024)) > 0)
		write(fileno(fout), buffer, n);
	pclose(fin);
	pclose(fout);
	return 0;
}
			
