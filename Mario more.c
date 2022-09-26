#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height;
    do
    {
        height = get_int("Please enter wished height: ");
    }
    while (height <= 0 || height > 8);
    int limit = height - 1;
    int limit2 = height + 2;
    int a = 0;

    for (int i = 0; i < height; i++)
    {
        for (a = 0; a < height; a++)
        {
            if (a < limit)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        limit--;
        a = 0;
        printf(" ");
        printf(" ");
        for (int b = height + 2; b < height * 2 + 2; b++)
        {
            if (b <= limit2)
            {
                printf("#");
            }
        }
        limit2++;
        a = 0;
        printf("\n");
    }
}