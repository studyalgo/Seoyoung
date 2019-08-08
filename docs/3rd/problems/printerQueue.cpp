#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int t;
    int n, m;
    cin >> t;

    vector<int> printQ;
    int i = 0;
    int input;
    int target;
    vector<int>::iterator ans;
    while(i < t){
        cin >> n >> m;
        for(int j = 0; j < n; j++){
            cin >> input;
            printQ.push_back(input);
        }

        target = printQ[m];
        sort(printQ.begin(), printQ.end());
        ans = find(printQ.begin(), printQ.end(), target);
        cout << ans;
        n++;
    }
    return 0;
}