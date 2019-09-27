/*https://www.acmicpc.net/problem/11053*/
#include <iostream>
#include <vector>
#include <algorithm>//lower_bound를 쓰려면 필요

using namespace std;

int LIS(vector<int> arr, int n);
int lowerBound(vector<int> lis, int n);

int LIS(vector<int> arr, int n){
    vector<int> lis;
    lis.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        if(lis[lis.size()-1] < arr[i]) lis.push_back(arr[i]);
        else lis[lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin()] = arr[i];
    }
    return lis.size();
}


int main(){
    int n;  //수열의 크기
    cin >> n;

    vector<int> arr(n);  //수열을 담을 벡터
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << LIS(arr, n) << '\n';
    

    return 0;
}