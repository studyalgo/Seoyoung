#include <iostream>
using namespace std;
//좌표 위의 점
struct dot{
    int x;
    int y;
};

int main()
{
    int n;  //좌표의 개수
    dot temp;   //for swapping
    cin>>n;
    dot array[n];
    for(int i = 0; i < n; i++){
        cin>>array[i].x;
        cin>>array[i].y;
    }
    //y좌표 기준으로 버블정렬
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            if(array[j].y>array[j+1].y){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
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
}