#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

int main(void)
{

FILE *card = fopen("card.raw", "r");
if (card == NULL)
{
    printf("Cannot open card.raw");
    return 1;
}

bool found_jpg = false;
uint8_t buffer[BLOCK_SIZE];
int jpg_count = 0;
char jpg_name[8];
FILE *outptr = NULL;


while (fread(buffer, BLOCK_SIZE, 1, card) == 1)
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        if (found_jpg)
        {
            fclose(outptr);
        }
        else
        {
            found_jpg = true;
        }

        sprintf(jpg_name, "%03i.jpg", jpg_count);
        outptr = fopen(jpg_name, "w");
        if (outptr == NULL)
        {
            fclose(card);
            printf("Could not create %s\n", jpg_name);
            return 3;
        }
        jpg_count++;
    }

    if (found_jpg)
    {
        fwrite(buffer, BLOCK_SIZE, 1, outptr);
    }
}

fclose(card);
if (found_jpg)
{
    fclose(outptr);
}

return 0;

}
