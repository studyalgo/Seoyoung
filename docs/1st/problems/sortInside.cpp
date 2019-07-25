/*---------------------------------------------------------------------------
 <문제>
 입력받은 수의 각 자릿수를 내림차순으로 정렬.
 <논리>
 1. 수를 입력받는다.
 2. 자릿수를 구하고, 자릿수만큼의 배열을 만들어 저장한다.(or 미리 배열을 만들어둔다.)
    -> 미리 배열을 만들어두는 것을 선택. 문제의 제한 조건때문에 크기 10의 배열이면 충분하기 때문.
 3. 배열을 정렬한다.
 ----------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

void selectionSort(int* arr, int size);

int main()
{
    int n;  //입력받은 수 저장
    int digit = 0;  //자릿수 저장
    cin >> n;
    int temp = n; // 원래 데이터를 손상시키지 않기 위한 변수
    int array[10];  //각 자리의 수를 저장할 배열
     

    while(temp>0){
        array[digit] = temp%10;
        temp = temp/10;
        digit++;
    }

    selectionSort(array, digit);

    for(int i = 0; i < digit; i++){
        cout << array[i];
    }
    cout << endl;

    return 0;
}

void selectionSort(int* arr, int size)
{
    int max, temp, index;

    for(int i = 0; i < size; i++)
    {
        max = -1;
        for(int j = i; j < size; j++)
        {
            if(arr[j] > max){
                max = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;    
    }
}