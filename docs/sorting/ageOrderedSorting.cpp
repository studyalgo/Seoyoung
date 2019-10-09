/*-------------------------------------------------------------------------
<문제>
1. 가입자의 나이와 이름이 가입한 순서대로 주어짐
2. 나이순으로 정렬, 나이가 같으면 먼저 가입한 순서대로 정렬
<풀이>
-------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a;
    string b;

    vector<pair<int, string> > member;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        member.push_back(make_pair(a, b));
    }

    sort(member.begin(), member.end(), compare);


    for(int i = 0; i < member.size(); i++){
        cout << member[i].first << ' '<< member[i].second << ' ';
    }
    
    return 0;

}

void compare(member a, member b){
    if(a.fistr == b.first) //가입한 순 정렬? a < b;
    else a.first < b.first;

}