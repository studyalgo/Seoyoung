#include <stdio.h>

int array[10] = {3, 9, 1, 8, 7, 6, 4, 5, 10, 2};

int main()
{
    //정렬실행
    quickSort(0, 9);

    //출력하기
    for(int i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }
    return 0;
}

void quickSort(int start, int end)
{
    //재귀함수에서 빠져나갈 조건
    if(start >= end) return;    //'=='보다는 '>='로 범위를 더 넒게 잡아주는 것이 안전

    int pivot, i, j;    //인덱스값
    int temp;   //스와핑할 때 값 임시저장용

    pivot = start; // 제일 앞에 있는 값을 기준값으로.
    i = start + 1;
    j = end;

    while(i <= j)
    {
        //왼쪽에서부터 기준값보다 큰 값을 만날 때 까지 반복.
        while(array[i] <= array[pivot]){
            i++;
        }
        //오늘쪽에서부터 기준값보다 작은 값을 만날 때 까지 반복.
        while(array[j] >= array[pivot] && j > start){
            j--;
        }
        //엇갈린 경우(위 과정에서 찾은 작은값이 큰값보다 왼쪽에 있을 때)
        if(i > j)
        {
            //작은값과 기준값의 자리를 바꾸고 기준값기준 왼쪽과 오른쪽 데이터값들에도 퀵정렬을 적용한다.
            temp = array[pivot];
            array[pivot] = array[j];
            array[j] = temp;
        }
        //엇갈리지 않은 경우
        else
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        // 왼쪽 정렬
        quickSort(start, j-1);
        //오른쪽 정렬
        quickSort(j+1, end);
    }
}