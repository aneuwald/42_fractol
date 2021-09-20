#include <stdio.h>
#include <math.h>

int main()
{
    int colors[] = {0x00ff0000, 0x0000ff00, 0x000000ff, 0x00ff00ff};
    int max_iter = 100;
    int iter = 100;
    double colors_count = 4;
    double ratio = (max_iter + 1) / colors_count;

    printf("Hello %f \n", floor(iter / ratio));
}