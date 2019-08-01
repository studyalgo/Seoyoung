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
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b);

int main(){
    int n;
    string w;

    cin >> n;

    vector<string> words;
    for(int i = 0; i < n;i++){
        cin >> w;
        words.push_back(w);
    }

    //단어의 길이로 정렬
    sort(words.begin(), words.end(), compare);
    words.erase(unique(words.begin(), words.end()), words.end());
    for(int i = 0; i < words.size(); i++)
    {
        cout << words[i] << ' ';
    }
    return 0;
}

bool compare(string a, string b){
    if(a.length() == b.length()) return a < b;
    return a.length() < b.length();
}