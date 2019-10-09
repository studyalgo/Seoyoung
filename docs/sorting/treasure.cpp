/*----------------------------------------------------------------------
<문제>
길이가 N인 정수 배열 A와 B.
함수 S = A[0]*B[0] + ... + A[N-1]*B[N-1]
S의 값이 가장 작아지도록 A를 재배열하라.
제한 조건>
B는 고정.
N: 50과 같거나 작은 정수
각 원소: 음이 아닌 100이하의 정수.
<아이디어>
A의 가장 작은값 * B의 가장 큰값
<논리>
1. 정렬된 수를 체크하는 배열을 만든다. checkA,checkB
2. A의 가장 작은수를 B의 가장 큰 값에 정렬한 후 체크한다.
3. 마찬가지로 정렬되지 않은 값 중 A의 가장 작은 값을, 가장 큰 B값의 자리에 정렬.
4. 반복.
+ A를 임시저장할 배열도 필요.
------------------------------------------------------------------------ */
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int min, max;
    int idxA, idxB;
    int S = 0;
    //값을 저장할 각 배열과, 체크를 위한 배열. 배열 A의 값을 임시로 담을 배열.
    int arrA[50];
    int arrB[50];
    int checkA[50];
    int checkB[50];
    int tempA[50];

    //배열 입력받기
    for(int i = 0; i < n; i++){
        cin >> arrA[i];
    }
    for(int i = 0; i < n; i++){
        cin >> arrB[i];
    }
    //check배열 초기화. temp채우기
    for(int i = 0; i < n; i++){
        checkA[i] = 0;
        checkB[i] = 0;
        tempA[i] = arrA[i];
    }

    for(int i = 0; i < n; i++)
    {
        min = 101;
        max = -1;
        for(int j = 0; j < n; j++)
        {
            if(tempA[j]<min && checkA[j] == 0){
            min = tempA[j];
            idxA = j;
            }
            if(arrB[j]>max && checkB[j] == 0){
                max = arrB[j];
                idxB = j;
            }
        }
        arrA[idxB] = min;//B의 가장 큰 값에 A의 가장 작은값
        checkA[idxA] = 1;   //정렬을 마친 원소를 체크
        checkB[idxB] = 1;
    }

    for(int i = 0; i < n; i++){
        S += arrA[i] * arrB[i];
    }
    cout << S << endl;

    return 0;
}