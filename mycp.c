/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Tommy
 *
 * Created on September 8, 2018, 7:15 PM
 */

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
    int fileOneContents;
    int fileOneOpen;
    int fileTwoOpen;
    int fileCopier;
    char buffer[BUFFERSIZE];
    ssize_t bytesRead, bytesWritten;
    mode_t mode = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IROTH | S_IXOTH ;
    if (argc < 2) {
        printf("Please enter your 2 filenames and try again");
        exit(1);
    }
    
    fileOneResult = access(argv[1], F_OK);
 
    if (fileOneResult == -1) {
        printf("File does not exist");
        exit(1);
    }
    fileOneOpen = open(argv[1], O_RDONLY);
    
    fileTwoOpen = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, mode);
    
    while (bytesRead = read(fileOneOpen, &buffer, BUFFERSIZE) > 0) {
        bytesWritten = write(fileTwoOpen, &buffer, sizeof(buffer));
        printf("%s", buffer);

    }
    if (bytesWritten==-1) {
        printf("error writiting to the file");
        exit(1);
    }
    close(fileOneOpen);
    close(fileTwoOpen);
    
    return (EXIT_SUCCESS);
}

