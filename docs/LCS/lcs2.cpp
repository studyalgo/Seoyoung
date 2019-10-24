//https://www.acmicpc.net/problem/9252
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    string lcs;
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

    for(int i = 1; i < len2; i++){
        table[i][0] = 0;
        for(int j = 1; j < len1; j++){
            if(s1[j]==s2[i]) table[i][j] = table[i-1][j-1] + 1;
            else{
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
    }

    for(int i = len2-1, j = len1-1; i>0 && j>0;){
        if(table[i][j] == table[i][j-1]) j--;
        else if(table[i][j] == table[i-1][j]) i--;
        else{
            lcs = s1[j] + lcs;
            i--;
            j--;
        }
    }

    cout << table[len2-1][len1-1] << '\n';
    cout << lcs << '\n';

    //메모리 해제
    for(int i = 0; i < len2; i++){
        delete [] table[i];
    }
    delete [] table;

    return 0;
}