#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256
    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    //char cmd[BUFSIZE] = "wc -c < ";
    //strcat(cmd, argv[1]);
    //system(cmd);

    //Open file
    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open the file. Please make sure file exists.\n");
        return -1;
    }
    //Determine file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fclose(file);
    //Print the size of the file
    if (file_size < 0) {
        fprintf(stderr, "Error: Could not figure out the file size.\n");
        return -1;
    }
    printf("File size: %ld bytes", file_size);
    return 0;

}
