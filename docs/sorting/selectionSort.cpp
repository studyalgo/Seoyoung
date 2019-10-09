# include <iostream>
  
int main()
{
    int array[10] = {1, 9, 3, 8, 7, 6, 4, 5, 10, 2};
    int i, j, min, index, temp;

    for(i = 0; i < 10; i++){
        min = 9999;
        for(j = i; j < 10; j++){
            if(min > array[j]){
                min = array[j];
                index = j;
            }
        }
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }

    return 0;
}