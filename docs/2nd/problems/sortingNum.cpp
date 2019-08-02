#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr;
    int tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << endl;
    }
    return 0;
}