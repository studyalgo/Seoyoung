#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> &tree, int i){
    int ans = 0;
    while(i>0){
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(vector<int> &tree, int i, int diff){
    while(i < tree.size()){
        tree[i] += diff;
        i += (i & -i);
    }

}

int main(){
    int n, m;
    int t1, t2, t3, t4;
    int diff;
    int w;
    int x, y, c;
    int x1, y1, x2, y2;
    int ans;
    cin >> n >> m;
    vector<int> arr(n*n);

    for(int i = 0; i < n; i++){
        cin >> t1 >> t2 >> t3 >> t4;
        arr.push_back(t1);
        arr.push_back(t2);
        arr.push_back(t3);
        arr.push_back(t4);
    }

    while(m > 0){
        cin >> w;
        if(w ==0 ){
            cin >> x >> y >> c;
            diff = c - arr[n*(x-1) + (y-1)];
            arr[n*(y-1) + (x-1)] = c;
            update(arr, n*(y-1) + (x-1), diff);
        } else{
            cin >> x1 >> y1 >> x2 >> y2;
            ans = 0;
            for(int i = y2; i >= y1 ; i--){
                ans += sum(arr, n*(i-1) + x2);
                ans -= sum(arr, n*(i-1) + x1);
            }
            cout << ans << endl;
        }
        m--;
    }


    return 0;
}