#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int LIS(vector< pair<int, int> > arr, int n){
    vector<int> lis;
    for(int i = 0; i < n; i++){
        if(i==0) lis.push_back(arr[i].second);
        if(lis[lis.size()-1] < arr[i].second) lis.push_back(arr[i].second);
        else lis[lowerBound(lis, arr[i].second)] = arr[i].second;
    }
    return lis.size();
}

int lowerBound(vector<int> lis, int n){
    for(int i = 0; i < lis.size()-1; i++){
        if(n < lis[i]) return i;
    }
    return (lis.size()-1);
}
int main(){
    //A전봇대와 B전봇대를 잇는 전깃줄의 개수
    int n;
    cin >> n;
    //A전봇대, B전봇대에 전깃줄이 연결되어 있는 번호 저장.
    vector< pair<int, int> > A(100);

    //전깃줄 연결관계 입력받기
    for(int i = 0; i < n; i++){
        cin >> A[i].first >> A[i].second;
    }

    //pair의 첫번째 값을 기준으로 정렬
    sort(A.begin(), A.begin()+n);
    //그러면 두번째 값을 기준으로 하려면 어떡하지?


    //pair의 두번째 값을 기준으로 lis를 구한다.
    cout << LIS(A, n);
    

    return 0;
}