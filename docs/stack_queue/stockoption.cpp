//https://programmers.co.kr/learn/courses/30/lessons/42584
#include <iostream>
#include <vector>


using namespace std;

vector<int> solution(vector<int> prices);

int n;  //시간

int main(){
    //--------입력----------    
    cin >> n;

    vector<int> prices(n); // 시간대별 주식의 가격
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }

    //--------출력-----------
    vector<int> answer = solution(prices);
    for(int i = 0; i < n; i++){
        cout << answer[i] << ' ';
    }
    cout << '\n';


    return 0;
}

vector<int> solution(vector<int> prices){
    vector<int> answer(n,0);

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(prices[i] <= prices[j]){
                answer[i]++;
            }
            else{
                answer[i]++;
                break;
            }
        }
    }
    answer[n-1] = 0;

    return answer;
}