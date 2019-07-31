/*------------------------------------------------------
<문제>
1. n개의 단어를 받아 정렬한다.
2. 단어의 길이가 짧은게 먼저. 길이가 같으면 사전순으로
3. 같은 단어가 여러번 입력되면 한 번만 출력된다.
<논리>
1. 길이비교
2. 길이가 같을 경우 같은 단어인지 먼저 체크. 같은 단어면 정렬안함.
3. 사전 순 정렬.
------------------------------------------------------ */
#include <iostream>
using namespace std;

bool compare(string a, string b);

int main(){
    int n;
    bool same;

    cin >> n;
    string* words = new string[n];
    for(int i = 0; i < n; i++)
    {
        cin >> words[i];
        for(int j = 0; j < i; j++)
        {
            //i가 0일 땐 비교군이 없으니까 그냥 지나감
            if(i == 0) break;
            //앞에 있는 애들과 비교했들 때 같은 애가 있으면 해당 문자열을 지우고 반복문을 빠져나간다.
            if(words[j].compare(words[i])==0){
                words[i] = "";
                break;
            } 
        }
    }

    //단어의 길이로 정렬
    sort(words, words + n, compare);
    for(int i = 0; i < n; i++)
    {
        cout << words[i] << ' ';
    }
    return 0;
}

bool compare(string a, string b){
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}