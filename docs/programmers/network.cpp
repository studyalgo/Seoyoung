#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void checkConn(int n, int i, vector<vector<int> > computers, vector<int>& visited){
    if(visited[i] == 1) return;
    visited[i] = 1;
    for(int j = 0; j < n; j++){
        if(j==i) continue; //자기자신은 건너뛴다.
        if(visited[j] == 0 && computers[i][j] == 1){
            checkConn(n, j, computers, visited);
        }
    }
    return;
}

int solution(int n, vector<vector<int> > computers) {
    int answer = 0;
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++){
        if(visited[i] == 1) continue;

        visited[i] = 1;
        checkConn(n, i, computers, visited);
        answer++;
        
        cout << "i: " << i << "      answer:" << answer << '\n';
        cout << "visited["<<i<<"] : " << visited[i] << '\n';

    } 
    return answer;
}

int main(){
     int n; //컴퓨터 개수
     cin >> n; // 컴퓨터 개수 입력

      vector<vector<int> > computers(n, vector<int>(n, 0));//컴퓨터 연결 자료구조

      //컴퓨터 연결 자료구조 입력받음
     //입력정보 들어가는 순서
     // 1 2 ... n
     // n+1 ... 2n
     //2n+1 ... 3n
     for(int i = 0; i < n; i++){//행
         for(int j = 0; j < n; j++){//열
             cin >> computers[i][j];
         }
     }
    int answer = solution(n, computers);
    cout << answer << '\n';
    return 0;
}