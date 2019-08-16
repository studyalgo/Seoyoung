#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int init(vector<int> &a, vector<int> &tree, int node, int start, int end);
int findMinimum(vector<int> tree, int node, int start, int end, int left, int right);

int main(){
    int n, m;
    int height, size;
    int num;
    int a, b;

    cin >> n >> m;

    //세그먼트 트리의 높이와 사이즈
    height = ceil(log2(n));
    size = (1 >> (height+1));

    //배열과 트리생성 및 초기화
    vector<int> arr;
    vector<int> tree(size);

    for(int i = 0; i < n; i++){
        cin >> num;
        arr.push_back(num);
    }

    init(arr, tree, 1, 0, n-1);

    while(m>0){
        cin >> a >> b;
        cout << findMinimum(tree, 1, 0, n-1, a-1, b-1);
        m--;
    }
    return 0;
}

int init(vector<int> &a, vector<int> &tree, int node, int start, int end){
    int left, right;
    if(start == end){
        return tree[node] = a[start];
    } else{
        left = init(a, tree, node*2, start, (start+end)/2);
        right = init(a, tree, node*2+1, (start+end)/2 + 1, end);
        return tree[node] = left < right? left : right;
    }
}

int findMinimum(vector<int> tree, int node, int start, int end, int left, int right){
    if(left > end || right < start) return 1e9;
    if(left >= start && right <= end) return tree[node];
    left = findMinimum(tree, node*2, start, (start+end)/2, left, right);
    right = findMinimum(tree, node*2+1, (start+end)/2 + 1, end, left, right);
    return left < right? left : right;
}