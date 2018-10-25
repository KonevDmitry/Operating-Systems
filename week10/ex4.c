#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main()
{
    DIR *tmp=opendir("tmp");
    struct dirent *dp=readdir(tmp);
    char command[64],path[64];
    struct stat data;
    while (dp != NULL) {
		if (dp->d_name[0] != '.') {
			sprintf(path,"./tmp/%s",dp->d_name);
			stat(path,&data);
			if (data.st_nlink >= 2) {
				printf("For %s",dp->d_name,"Link:\n" );
				sprintf(command, "find -inum %lu", data.st_ino);
				system(command);
			}
		}
		dp=readdir(tmp);
	}
}
