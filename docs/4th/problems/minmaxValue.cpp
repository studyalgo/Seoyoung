#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    //세그먼트 트리 높이와 사이즈
    int h = ceil(log2(n));
    int size = (1 << (h+1));

    int tmp;
    vector<int> arr;
    vector<int> tree;

    for(int i = 0; i < n; i++){ 
        cin >> tmp;
        arr.push_back(tmp);
    }
    return 0;
}

int init(vector<int> &arr, vector<int> &tree, int node, int start, int end){
    if(start == end){
        return tree[node] = arr[start];
    } else{
        return tree[node] = init(arr, tree, node*2)
    }

}