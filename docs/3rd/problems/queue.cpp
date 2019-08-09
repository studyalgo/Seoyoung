#include <iostream>
#include <string>

using namespace std;

string cmd;
int param;
int sz;
int emp;
int front;
int back;

int main(){
    //변수 초기화
    sz = 0;
    emp = 1;
    front = 0;
    back = 0;

    //명령어 입력 횟수
    int n;
    cin >> n;

    int* queue = new int[10000];

    //n번만큼 실행
    while(n>0){
        cin >> cmd;
        if(cmd == "push"){
            cin >> param;
            queue[back] = param;
            back++;
            sz++;
            emp = 0;
        }
        else if(cmd == "pop"){
            if(sz == 0) cout << "-1" << '\n';
            else {
                cout << queue[front]<< '\n';
                queue[front] = 0;
                front++;
                sz--;
            }
        }
        else if(cmd =="size"){
            cout << sz << '\n';
        }
        else if(cmd =="empty"){
            if(sz == 0) cout << "1" << '\n';
            else cout << "0"<< '\n';
        }
        else if(cmd =="front"){
            if(sz == 0) cout << "-1" << '\n';
            else cout << queue[front]<< '\n';
        }
        else if(cmd =="back"){
            if(sz == 0) cout << "-1" << '\n';
            else cout << queue[back-1] << '\n';
        }
        n--;
    }

    delete queue;
    return 0;
}