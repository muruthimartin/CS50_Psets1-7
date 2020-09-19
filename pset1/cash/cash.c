#include<stdio.h>
#include<math.h>
#include<cs50.h>
int main(void)
{
    float dollars;
    //prompt user for change owed
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    int cents = round(dollars * 100);
    int coins = 0;
    int denominations[] = {25, 10, 5, 1};
    int size = 4;

    for (int i = 0; i < size; i++)
    {
        // divide cents by the denominations and increment coins with the result
        coins += cents / denominations[i];
        // allocate the remainder to cents
        cents %= denominations [i];
    }
    printf("%i\n", coins);
}
