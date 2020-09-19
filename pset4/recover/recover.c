#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
typedef uint8_t BYTE;
#define BLOCKSIZE 512
bool is_a_jpeg_header(uint8_t buffer[]);


int main(int argc, char *argv[])
{

    uint8_t buffer[BLOCKSIZE];
    int jpegCounter = 0;
    FILE* outfile = NULL;
    char filename[8];

    //make sure user supplies an argument upon running the program
    if(argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //check whether user has supplied a file
    FILE* infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("File does not exist\n");
        return 1;
    }

    //read through the provided jpeg file, create a new jpeg image if you come accross a jpeg header
    while (fread(buffer, sizeof(uint8_t), BLOCKSIZE, infile) || feof(infile) == 0)
    {
        if(is_a_jpeg_header(buffer))
        {
            if (outfile != NULL)
            {
                fclose(outfile);
            }
            sprintf(filename, "%03i.jpg", jpegCounter);
            outfile = fopen(filename, "w");
            jpegCounter++;
        }
        if (outfile != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, outfile);
        }
    }
    //close your files
    fclose(infile);
    fclose(outfile);
}
bool is_a_jpeg_header(uint8_t buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}