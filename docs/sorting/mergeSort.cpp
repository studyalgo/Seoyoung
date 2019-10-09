#include <stdio.h>

int array[10] = {3, 9, 1, 8, 7, 6, 4, 5, 10, 2};
int main()
{
    int n = 10;  //데이터의 개수
    mergeSort(0, n-1);

    for(int i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }
    return 0;
}

void mergeSort(int start, int end)
{
    int num = end - start + 1;    //분할한 데이터의 개수
    if(num == 1) return;

    int i,j,k; //인덱스
    k = start;  //합치기 위한 인덱스
    i = start;  //앞부분 인덱스
    j = (int)num/2; //뒷부분 인덱스
    int m1 = (int)num/2 -1;
    int m2 = (int)num/2;
    //분할
    mergeSort(start, m1);
    mergeSort(m2, end);

    while((i <= m1) && (j <= end))
    {
        if(array[i] <= array[j]){
            array[k] = array[i];
            i++;
            k++;
        }
        else{
            array[k] = array[j];
            j++;
            k++;
        }
    }
    if(i>m1){
        while(j<=end){
            array[k] = array[j];
            j++;
            k++;
        }
    }
    else{
        while(i <= m1){
            array[k] = array[i];
            i++;
            k++;
        }
    }   

    return;
}