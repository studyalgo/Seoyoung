#include <iostream>

int main()
{
    int i, j, temp;
    int array[10] = {3, 9, 1, 8, 7, 6, 4, 5, 10, 2};

    for(i = 1; i < 10; i++){
        j = i;
        while(array[j] > array[j+1]){
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            j--;
        }
    }

    for(i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}