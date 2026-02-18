#include <cs50.h>
#include <stdio.h>

void buildPyramid(int height)
{ // declares the function to build the pyramid

    string space = " ";
    string block = "#";
    int x;           // used to measure spaces before left-blocks
    int block_left;  // used to control left-blocks spawns
    int block_right; // same but right
    for (int i = 0; i < height; i++)
    {
        x = height - (i + 1);
        block_left = i + 1;
        block_right = i + 1;
        while (x != 0)
        {
            printf("%s", space);
            x -= 1;
        }
        while (block_left != 0)
        {
            printf("%s", block);
            block_left -= 1;
        }
        printf("  ");
        while (block_right != 0)
        {
            printf("%s", block);
            block_right -= 1;
        }
        printf("\n");
    }
}
int main()
{
    // int height = 0;
    int height =
        get_int("\nbetween positive 1 and 8, what's the pyramid's height, little locust? \n");
    while (height < 1 || height > 8)
    {
        printf("please, follow the rules, little ant! \n \n");
        height =
            get_int("between positive 1 and 8, what's the pyramid's height, little locust? \n");
    }
    buildPyramid(height);
    return 0;
}
