#include <iostream>
using namespace std;

//좌표 위의 점
struct dot{
    int x;
    int y;
};

void quickSortY(struct dot* array, int start, int end);

int main()
{
    int n;  //좌표의 개수
    dot temp;   //for swapping
    cin>>n;
    dot *array = new dot[n];
    for(int i = 0; i < n; i++){
        cin>>array[i].x;
        cin>>array[i].y;
    }
    //y를 기준으로 퀵정렬
    quickSortY(array, 0, n);

    //y좌표가 같을 경우 x좌표 기준으로 버블정렬
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if((array[j].y == array[j+1].y) && (array[j].x>array[j+1].x)){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    //출력
    for(int i = 0; i < n; i++)
    {
        cout<<array[i].x<<" ";
        cout<<array[i].y<<endl;
    }

    delete[] array;
    return 0;
}

void quickSortY(dot* array,int start, int end){
    if(start>=end) return;

    int i, j, pivot;
    dot temp;
    pivot = start;
    i = start+1;
    j = end;
    while(array[i].y<= array[pivot].y){
        i++;
    }
    while(array[j].y >= array[pivot].y && j > start){
        j--;
    }
    if(i>j){
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    quickSortY(array, start, j-1);
    quickSortY(array, j+1, end);
}