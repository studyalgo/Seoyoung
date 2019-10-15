//https://www.acmicpc.net/problem/9251
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    //문자열 입력받음
    string s1, s2;
    cin >> s1;
    cin >> s2;

    //연산의 편의를 위해 앞에 0을 추가
    s1 = "0" + s1;
    s2 = "0" + s2;

    //문자열의 길이 저장
    int len1, len2;
    len1 = s1.length();
    len2 = s2.length();

    //테이블 생성
    int** table = new int* [len2];
    for(int i = 0; i < len2; i++){
        table[i] = new int [len1];
    }

    //테이블 채우기
    for(int i = 0; i < len2; i++){
        table[0][i] = 0;
    }

    for(int i = 1; i < len2; i++){
        table[i][0] = 0;
        for(int j = 1; j < len1; j++){
            //문자가 같으면
            if(s2[i] == s1[j]){
                table[i][j] = table[i-1][j-1] + 1;
            }
            //문자가 다르면
            else{
                if(table[i-1][j]>table[i][j-1]) table[i][j] = table[i-1][j];
                else table[i][j] = table[i][j-1];
            }
        }
    }

    //LCS출력
    cout << table[len1-1][len2-1] << '\n';
    
}