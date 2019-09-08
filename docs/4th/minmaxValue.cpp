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

    //vector를 이용하기 위한 tmp, 배열과 트리.
    int tmp;
    vector<int> arr;
    vector<int> minTree;
    vector<int> maxTree;

    for(int i = 0; i < n; i++){ 
        cin >> tmp;
        arr.push_back(tmp);
    }

    initMin(arr, minTree, 1, 0, n-1);
    initMax(arr, maxTree, 1, 0, n-1);

    while(m > 0)
    {

        m--;
    }
    return 0;
}

int initMin(vector<int> &arr, vector<int> &tree, int node, int start, int end){
    int l, r;
    if(start == end){
        return tree[node] = arr[start];
    } else{
        l = initMin(arr, tree, node*2, start, (start+end)/2);
        r = initMin(arr, tree, node*2+1, (start+end)/2 + 1, end);
        return tree[node] = l < r? l : r; 
    }
}

int initMax(vector<int> &arr, vector<int> &tree, int node, int start, int end){
    int l, r;
    if(start == end){
        return tree[node] = arr[start];
    } else{
        l = initMax(arr, tree, node*2, start, (start+end)/2);
        r = initMax(arr, tree, node*2+1, (start+end)/2 + 1, end);
        return tree[node] = l < r? r : l; 
    }
}