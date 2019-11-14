#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#include <string>
#include <vector>
#include <queue>

using namespace std;

void checkConn(int n, int i, vector<vector<int>> computers, vector<int>& visited){
    if(visited[i] == 1) return;
    
    visited[i] = 1;
    for(int j = 0; j < n; i++){
        if(j==i) continue; //자기자신은 건너뛴다.
        if(visited[j] == 0 && computers[i][j] == 1){
            checkConn(n, j, computers, visited);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++){
        if(visited[i] == 1) continue;
        else{
            visited[i] = 1;
            answer++;
            checkConn(n, i, computers, visited);
        }
    } 
    return answer;
}