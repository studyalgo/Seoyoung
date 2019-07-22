#include <stdio.h>

int main()
{
    int i, j, temp;
    int array[10] = {3, 9, 1, 8, 7, 6, 4, 5, 10, 2};

    for(i = 0; i < 10; i++){
        for(j = 0; j < 9-i; j++){
            if(array[j+1] > array[j]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = array[j];
            }
        }
    }

    for(i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}