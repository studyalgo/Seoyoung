/*---------------------------------------------------------------------------
<문제>
1. 2차원 평면위에 n개의 좌표가 주어진다.
2. x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순으로 정렬한다.
3. 위치가 같은 두 점은 없다.
<풀이>
1. vector<pair<int, int> >구조로 좌표값 저장.
2. STL에서 sort함수 이용.
3. 구체적인 정렬조건을 담은 compare함수를 sort함수에 인자로 전달. 
---------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b);

int main(){
    int n;
    cin >> n;

    int a, b;
    //벡터 생성 및 값 입력.
    vector<pair<int, int> > coord;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        coord.push_back(make_pair(a, b));
    }
    //정렬하기
    sort(coord.begin(), coord.end(), compare);
    //출력하기
    for(int i = 0; i < n; i++){
        cout << coord[i].first << ' ' << coord[i].second << endl;
    }
    return 0;
}

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}