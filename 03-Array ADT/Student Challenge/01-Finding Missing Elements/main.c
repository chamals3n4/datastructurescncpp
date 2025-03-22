#include <stdlib.h>
#include <stdio.h>

struct Array
{
    int A[100];
    int size;
    int length;
};

void findMissinginFirstNN(struct Array arr)
{
    int n = arr.A[arr.length - 1];
    int sum = n * (n + 1) / 2;
    int s = 0;
    for (int i = 0; i < arr.length; i++)
        s += arr.A[i];
    printf("missing element is %d\n", sum - s);
}

int MAX(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int MIN(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

// single
int findMissing(struct Array arr)
{
    int diff = arr.A[0] - 0;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] - i != diff)
        {
            // printf("missing element is %d\n",(diff+i));
            return (diff + i);
        }
    }
    return -1;
}

// finding multiple missing elements
void findMultipleMissing(struct Array arr)
{
    int diff = arr.A[0] - 0;
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] - i != diff)
        {
            while (diff < arr.A[i] - i)
            {
                printf("missing element : %d", (diff + i));
                diff++;
            }
        }
    }
}

void findMissingElementusingH(struct Array arr)
{
    int h = MAX(arr);
    int l = MIN(arr);

    // Automatically initializes to 0
    int *H = (int *)calloc(h, sizeof(int)); // this is called HASH TABLE

    for (int i = 0; i < arr.length; i++)
        H[arr.A[i]]++;

    printf("---- missing elements are ---- \n");
    for (int i = l; i < h; i++)
    {
        if (H[i] == 0)
            printf("%d ", i);
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 8, 9}, 10, 8};
    struct Array arr1 = {{6, 7, 8, 9, 10, 11, 13, 14}, 10, 8};
    struct Array arr2 = {{6, 7, 8, 9, 11, 12, 15, 16, 17, 18}, 15, 10};

    /*
        findMissinginFirstNN(arr);
        printf("missing element is %d\n", findMissing(arr1));

        printf("--------------------");
        findMultipleMissing(arr2);
    */
    findMissingElementusingH(arr2);
    return 0;
}
