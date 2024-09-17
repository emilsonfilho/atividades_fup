#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *values;
    int size;
} IntArray;

int countDigits(int number)
{
    int count = 0;

    if (number == 0)
        return 1;

    while (number != 0)
    {
        number /= 10;
        count++;
    }

    return count;
}

IntArray getArray(int num)
{
    int size = countDigits(num);
    int temp = num;

    IntArray arr;
    arr.values = (int *)malloc(size * sizeof(int));
    arr.size = size;

    for (int i = 0; i < size; i++)
    {
        arr.values[size - i - 1] = temp % 10;
        temp /= 10;
    }

    return arr;
}

int getDigitLedsQuantity(int value)
{
    if (value == 1)
    {
        return 2;
    }
    else if (value == 7)
    {
        return 3;
    }
    else if (value == 4)
    {
        return 4;
    }
    else if (value == 2 || value == 3 || value == 5)
    {
        return 5;
    }
    else if (value == 6 || value == 9 || value == 0)
    {
        return 6;
    }
    else
    {
        return 7;
    }
}

int getLedsQuantity(IntArray arr)
{
    int sum = 0;

    for (int i = 0; i < arr.size; i++)
    {
        int currentValue = arr.values[i];

        sum += getDigitLedsQuantity(currentValue);
    }

    return sum;
}

int main()
{
    int num = 0, cases = 0;

    scanf("%d", &cases);

    for (int i = 0; i < cases; i++)
    {
        scanf("%d", &num);
        IntArray nums = getArray(num);

        int leds = getLedsQuantity(nums);

        printf("%d leds\n", leds);

        free(nums.values);
    }

    return 0;
}