#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid command.\n");
        return 1;
    }

    string filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("File not found.\n");
        return 404;
    }

    uint8_t buffer[4];
    uint8_t signature[] = {0, 0, 0, 0};

    fread(buffer, 1, 4, file);
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Not a PDF file.\n");
            fclose(file);
            return 0;
        }
    }
    printf("Likely a PDF file.\n");
    fclose(file);
    return 0;

}
