#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end);
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff);
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right);

int main(){
    int n, m, k;
    int cmd, b, c;
    int height, size;
    int diff;
    long long num;

    //입력받기
    cin >> n >> m >> k;

    height = ceil(log2(n));
    size = pow(2, height+1);

    vector<long long> arr;
    vector<long long> tree(size);

    for(int i = 0; i < n; i++){
        cin >> num;
        arr.push_back(num);
    }

    //세그먼트 트리 만들기
    init(arr, tree, 1, 0, n-1);

    while(m > 0 || k > 0){
        cin >> cmd;
        if(cmd == 1){
            cin >> b >> c;
            diff = c - arr[b-1];
            arr[b-1] = c;
            update(tree, 1, 0, n-1, b-1, diff);
            m--;
        }
        else if(cmd == 2){
            cin >> b >> c;
            cout << sum(tree, 1, 0, n-1, b-1, c-1) << '\n';
            k--;
        }
    }
    return 0;
}

//세그먼트 트리 만들기
long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    if(start == end){
        return tree[node] = a[start];
    } else{
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2 + 1, end);
    }
}

//업데이트 하기
void update(vector<long long> &tree, int node, int start, int end, int index, long long diff){
    if(index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if(start != end){
        update(tree, node*2, start, (start+end)/2, index, diff);
        update(tree, node*2+1, (start+end)/2 + 1, end, index, diff);
    }
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(right < start || left > end){
        return 0;
    }
    if(left <= start && right >= end){
        return tree[node];
    }
    return sum(tree, node *2, start, (start+end)/2, left, right) + sum(tree, node*2+1, (start+end)/2+1, end, left, right);

}