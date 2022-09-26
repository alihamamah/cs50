#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int height;
    int limit = 1;
    do
    {
        height = get_int("Please enter wished height: ");
    }
    while (height <= 0 || height > 8);

    // rows
    for (int i = 0; i < height; i++)
    {
        // empty space
        for (int j = height; j > i; j--)
        {
            if (j <= limit)
            {
                for (int k = limit; k > 0; k--)
                {
                    printf("#");
                }
            }
            else
            {
                printf(" ");
            }
        }
        limit++;
        printf("\n");
    }
}