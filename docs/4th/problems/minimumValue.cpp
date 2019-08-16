#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n, m;
    int height, size;
    int num;

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

        m--;
    }
    return 0;
}
int init(vector<int> &a, vector<int> &tree, int node, int start, int end){
    if(start == end){
        return tree[node] = a[start];
    } else{
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2 + 1, end);
    }
}

int findMinimum(){

}