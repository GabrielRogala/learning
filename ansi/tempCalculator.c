#include <stdio.h>
/* far to cels */
#define LOWER 0
#define UPPER 300
#define STEP 20

main()
{
    float far, cel;

    far = LOWER;
    printf("far|\t|cels\n");
    while (far <= UPPER)
    {
        cel = (5.0 * (far - 32.0)) / 9.0;     // 5/9 = 0
        printf("%3.0f|\t|%6.1f\n", far, cel); // %6.1f  wyrownanie do prawej bloku 6 znakow z czego 1 po przecinku i kropka
        far += STEP;
    }

    cel = LOWER;
    printf("\ncels|\t|far\n");
    while (cel <= UPPER)
    {
        far = cel * (9.0 / 5.0) + 32.0;
        printf("%4.0f|\t|%6.1f\n", cel, far); // %6.1f  wyrownanie do prawej bloku 6 znakow z czego 1 po przecinku i kropka
        cel += STEP;
    }

    int faren;
    for (faren = LOWER; faren <= UPPER; faren += STEP)
        printf("%3d%6.1f\n", faren, (5.0 / 9.0) * (faren - 32));
}