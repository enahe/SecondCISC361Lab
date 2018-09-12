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

#define BUFFERSIZE 4096




/*
 * 
 */
int main(int argc, char** argv) {
    int fileOneResult;
    int fileTwoResult; 
    
    if (argc < 2) {
        printf("Please enter your 2 filenames and try again");
        exit(1);
    }
    
    fileOneResult = access(argv[1], F_OK);
 
    if (fileOneResult == -1) {
        printf("File does not exist");
        exit(1);
    }
    int fileOneOpen = open(argv[1], O_RDONLY);
    void *buffer = (char*) malloc(4096);
    int fileOneContents = read(fileOneOpen, buffer, BUFFERSIZE);
    close(fileOneOpen);
    
    fileTwoResult = access(argv[2], F_OK);
    int fileTwoOpen;
    
    if (fileTwoResult == -1 ) {
        printf("File already exists. Would you like to procede with copying? Press Y for yes.");
        fileTwoOpen = open(argv[2], O_CREAT | O_WRONLY);
    }
    else {
        fileTwoOpen = open(argv[2], O_WRONLY);
    }
    
    int fileCopier;
    while (fileOneContents = read(fileOneOpen, buffer, BUFFERSIZE) > 0) {
        fileCopier = write(fileTwoOpen, buffer, BUFFERSIZE);
    }
    if (fileCopier==-1) {
        printf("error writiting to the file");
        exit(1);
    }
    close(fileTwoOpen);
    free(buffer);
    
    return (EXIT_SUCCESS);
}

