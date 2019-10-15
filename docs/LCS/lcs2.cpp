//https://www.acmicpc.net/problem/9252
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void findLCS(int i, int j);

int main(){
    vector<char> lcs;
    //문자열 입력 받음
    string s1, s2;
    cin >> s1;
    cin >> s2;

    s1 = "0" + s1;
    s2 = "0" + s2;

    int len1, len2;
    len1 = s1.length();
    len2 = s2.length();

    //동적할당으로 테이블 만들기
    int** table = new int* [len2];
    for(int i = 0; i < len2; i++){
        table[i] = new int [len1];
    }

    //테이블 채우기
    for(int i = 0; i < len1; i++){
        table[0][i] = 0;
    }

    for(int i = 0; i < len2; i++){
        for(int j = 1; j < len1; j++){
            if(s1[i]==s2[j]) table[i][j] = table[i-1][j-1] + 1;
            else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    findLCS(len2-1, len1-1);

    for (auto l = rbegin(lcs); l != rend(lcs); ++l) {
        cout << *l << " ";
    }
    //메모리 해제
    for(int i = 0; i < len2; i++){
        delete [] table[i];
    }
    delete [] table;

    return 0;
}

void findLCS(int i, int j){
    if(i==0 || j==0) return;
    for(int m = j; m != 0; m--){
        if(table[i][j] != table[i][j-1]){
            lcs.push_back(s1[j]);
            findLCS(i-1, j-1);
            break;
        }
    }
}