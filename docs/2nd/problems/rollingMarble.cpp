/*-------------------------------------------------------------------------
<문제>
1. x축에 평행하게 굴러가는 n개의 구슬이 있다. 구슬의 y축 좌표는 모두 달라서 충돌이 일어나지 않는다.
2. 각 구슬은 출발하는 x좌표가 모두 다르며 일정한 속도로 움직인다.
3. 일정한 시간 간격으로 사진을 찍어 각 구슬의  x좌표를 나열한다.
4. 사진은 n+1장 주어진다.
<풀이>
-------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

//위치 구하는 함수
int location(int t, int initP, int v){
    //위치 = 초기위치 + 속도 * 시간
    return (initP + v * t);
}
bool validate(int initP, int v);

int n;
int** marble;   // 사진상 구슬의 x좌표를 저장할 2차원 배열
vector<pair<int, int> > ans;    //답을 저장할 배열


int main(){
    cin >> n;

    marble = new int*[n];
    int initP;  //초기위치
    int v;  //속도


    //check배열 초기화, marble 2차원 배열 생성
    for(int i = 0; i < n; i++){
        marble[i] = new int[n+1];
    }

    //marble 2차원 배열 입력.
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n+1; j++){
            cin >> marble[i][j];
        }
    }


    for(int i = 0; i < n; i++){
        initP = marble[0][i];
        for(int j = 0; j < n; j++){
            v = marble[1][j] - marble[0][i];
            if(validate(initP, v) == true){
                ans.push_back(make_pair(initP, v));
                break;
            }
        }
    }
    
    sort(ans.begin(), ans.end());

    //답 출력
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << ' ' << ans[i].second << endl; 
    }

    //메모리 해제
    for(int i = 0; i < n; i++){
        delete [] marble[i];
    }
    delete[] marble;

    return 0;
}

bool validate(int initP, int v){
    int i, j;
    for(i = 2; i < n+1; i++){
        for(j = 0; j < n; j++){
            //가정에 부합하는 값이 존재하면 다음 행을 검사하러.
            if(marble[i][j] == location(i, initP, v)) break;
            //행의 마지막값이 될 때까지 부합하는 값이 없으면 함수를 빠져나간다. 
            if(j == n-1) return false;
        }
    }
    return true;
}

