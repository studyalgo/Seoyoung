#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LIS(vector<int> &arr, vector<int> &lis, int n){
    lis.push_back(arr[0]);
    for(int i = 1; i < n; i++){
        if(lis[lis.size()-1] < arr[i]) lis.push_back(arr[i]);
        else lis[lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin()] = arr[i];
    }

    return lis.size();
}

int main(){
    int n; //수열의 크기
    cin >> n;

    vector<int> arr(n);//수열을 저장할 벡터
    vector<int> lis;//lis를 저장할 벡터
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << LIS(arr, lis, n) << '\n';
    for(int i = 0; i < lis.size(); i++){
        cout << lis[i] << " ";
    }
    cout << '\n';

    
    return 0;
}