#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[]){
	//check if there is enough arguments
	if(argc <=2){
		printf("Error: Not enough arguments!\n");
		exit(1);
	}

	//declare variables
	struct stat statBuf;
	DIR *dirPtr;
	struct dirent *entryPtr;
	char *path = argv[2];

	//if either command is found set to 1 otherwise 0
	int hasIDs = 0; //ls -n
	int hasInodes = 0; //ls -i
	if(argc == 3){
		if(!strcmp(argv[1], "-n")){
			hasIDs = 1;
		}
		else if(!strcmp(argv[1],"-i")){
			hasInodes = 1;
		}
	}

	dirPtr = opendir(path);
	if(dirPtr == NULL){
		printf("Error: directory not found\n");
		exit(1);
	}
	
	while((entryPtr = readdir(dirPtr))){
		//printf("hasID and hasInode: %d %d ", hasIDs, hasInodes);
		//if(hasIDs == 1 || hasInodes == 1){
			stat(entryPtr->d_name,&statBuf);
		//}
		
		//if the command is -n
		if(hasIDs == 1){
			//displays User and Group IDs
			printf("%u %u\t", statBuf.st_uid, statBuf.st_gid);
		}
		//if the command is -i
		if(hasInodes == 1){
			//displays the inode number
			printf("%ld\t", entryPtr->d_ino);
		}
		printf("%s\n",entryPtr->d_name);
	}
	closedir(dirPtr);
	return 0;
}
