#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

int main()
{
   DIR *dirPtr;
   struct dirent *entryPtr;
   struct stat statBuf;

   dirPtr = opendir (".");



   while ((entryPtr = readdir (dirPtr))){
	  stat(entryPtr->d_name,&statBuf);
		int size = statBuf.st_size;  
	   printf ("%-20s File size: %d bytes.\n", entryPtr->d_name,size);
   }
   closedir (dirPtr);
   return 0;
} 
