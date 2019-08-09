#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    int cur, next;
    int popN = 0;//pop시킨 횟수

    //숫자 입력받기
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    //수열을 만드는 게 가능한지 체크. 가능하지 않다면 종료.
    for(int i = 0; i < n-1; i++){
        cur = arr[i];
        next = arr[i+1];
        if(cur < next || next == cur-1) continue;
        else{
            cout << "NO" << '\n';
            return 0;
        }
    }

    for(int i = 0; i < n-1; i++){
        //첫번째 수는 바로 출력
        if(i==0){
            for(int j = 0; j < arr[i]; j++){
                cout << '+' << '\n';
            }
            cout << '-' << '\n';
            popN++;
        }
        cur = arr[i];
        next = arr[i+1];
        if(next == cur -1){
            cout << '-' << '\n';
            popN++;
            continue;
        }
        else if(next > cur){
            for(int j = 0; j < next - cur - popN + 1; j++){
                cout << '+' << '\n';
            }
            popN = 0;
            cout << '-' << '\n';
            popN++;
        }
    }
    return 0;
}