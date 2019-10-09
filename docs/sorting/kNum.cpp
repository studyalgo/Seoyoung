/*-------------------------------------------------------------------------
<문제>

-------------------------------------------------------------------------*/
#include <iostream>
#include <algorithm>

using namespace std;

void Q(int i, int j, int k);

int* arr;

int main(){
    int n, m;
    cin >> n >> m;

    arr = new int[n];
    int a, b, c;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        Q(a, b, c);
    }
    return 0;
}

void Q(int i, int j, int k){
    int len = j - i + 1;
    int* sub = new int[len];
    for(int x = 0; x < len; x++){
        sub[x] = arr[x+i-1];
    }
    sort(sub, sub+len);
    cout << sub[k-1] << endl;
}