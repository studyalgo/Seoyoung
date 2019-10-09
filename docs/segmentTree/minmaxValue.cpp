#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int initMin(vector<int> &arr, vector<int> &tree, int node, int start, int end);
int initMax(vector<int> &arr, vector<int> &tree, int node, int start, int end);
int findMin(vector<int> &tree, int node, int start, int end, int left, int right);
int findMax(vector<int> &tree, int node, int start, int end, int left, int right);

int main(){
    int n, m;
    int a, b;
    cin >> n >> m;

    //세그먼트 트리 높이와 사이즈
    int h = ceil(log2(n));
    int size = (1 << (h+1));

    //배열과 트리.
    vector<int> arr(n);
    vector<int> minTree;
    vector<int> maxTree;

    for(int i = 0; i < n; i++){ 
        cin >> arr[i];
    }

    initMin(arr, minTree, 1, 0, n-1);

    while(m > 0)
    {
        cin >> a >> b;
        cout << findMin(minTree, 1, 0, n-1, a-1, b-1) << ' ' << findMax(maxTree, 1, 0, n-1, a-1, b-1) << '\n';
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

int findMin(vector<int> &tree, int node, int start, int end, int left, int right){
    int l,r;
    if(left > end || right < start) return 1e9;
    if(start == end) return tree[node];
    if(start <= left && right <= end){
        l = findMin(tree, node*2, start, (start+end)/2, left, right);
        r = findMin(tree, node*2+1, (start+end)/2 + 1, end, left, right);
        return l < r ? l : r;
    }
    l = findMin(tree, node*2, start, (start+end)/2, left, right);
    r = findMin(tree, node*2+1, (start+end)/2 + 1, end, left, right);
    return l < r ? l : r;
}

int findMax(vector<int> &tree, int node, int start, int end, int left, int right){
    int l, r;
    if(left > end || right < start) return 0;
    if(start == end) return tree[node];
    if(start <= left && right <= end){
        l = findMax(tree, node*2, start, (start+end)/2, left, right);
        r = findMax(tree, node*2+1, (start+end)/2 + 1, end, left, right);
        return l < r ? r : l;
    }
    l = findMax(tree, node*2, start, (start+end)/2, left, right);
    r = findMax(tree, node*2+1, (start+end)/2 +1, end, left, right);
    return l < r ? r : l;
}