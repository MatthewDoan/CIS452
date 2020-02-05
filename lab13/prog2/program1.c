#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main (int argc, char *argv[]) {
   if (argv[1][1] == 'h') {
     if ((link(argv[2], argv[3])) < 0) {
        perror("Error: Creation of hard  link failed");
        exit(1);
     }
     printf("Hard link created\n");
   } else if (argv[1][1] == 's') {
     if ((symlink(argv[2], argv[3])) < 0) {
        perror("Error: Creation of soft link failed");
        exit(1);
     }
     printf("Symbolic link created\n");
   }
   return 0;
}
