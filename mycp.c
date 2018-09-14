#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define BUFFERSIZE 1




/*
 * 
 */
int main(int argc, char** argv) {
    int fileOneResult; 
    int fileTwoResult;
    int fileOneOpen;
    int fileTwoOpen;
    char buffer[BUFFERSIZE];
    char overwriteFile[128];
    ssize_t bytesRead, bytesWritten;
    mode_t mode = S_IRUSR | S_IWUSR | S_IXUSR ;
    if (argc < 2) {
        printf("Please enter your 2 filenames and try again\n");
        exit(1);
    }
    
    fileOneResult = access(argv[1], F_OK);
 
    if (fileOneResult == -1) {
        printf("File does not exist\n");
        exit(1);
    }
    fileOneOpen = open(argv[1], O_RDONLY);
    
    fileTwoResult = access(argv[2], F_OK);

    if (fileTwoResult != -1) {
        printf("Output file already exists. Press y to overwrite?\n");
        if(fgets(overwriteFile, 128 , stdin) != NULL) {
        overwriteFile[strlen(overwriteFile)-1] = '\0';
        if(strcmp(overwriteFile, "y")) {
            printf("Understandable, have a nice day\n");
            exit(1);
        } 
    }
    }
    
    fileTwoOpen = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, mode);
    
    while (bytesRead = read(fileOneOpen, &buffer, BUFFERSIZE) > 0) {
        bytesWritten = write(fileTwoOpen, &buffer, sizeof(buffer));

    }
    if (bytesWritten==-1) {
        printf("error writing to the file\n");
        exit(1);
    }
    
    printf("File successfully copied!\n");
    close(fileOneOpen);
    close(fileTwoOpen);
    
    return (EXIT_SUCCESS);
}

