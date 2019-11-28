//https://programmers.co.kr/learn/courses/30/lessons/43237
#include <iostream>
#include <vector>
#include <numeric>
//numeric: acculumate을 사용하기 위한 헤더
//http://www.cplusplus.com/reference/numeric/accumulate/


using namespace std;

int sum(vector<int> budgets, int max);
int solution(vector<int> budgets, int M);

int main(){
    vector<int> budgets; // 각 지방에서 요청하는 예산이 담긴 배열. 지방의 개수는 3이상 100000이하
    int M; // 총 예산
    return 0;
}

int solution(vector<int> budgets, int M){
    int answer = 0;

    if(accumulate(budgets.begin(), budgets.end(), 0) <= M){
        return *max_element(budgets.begin(), budgets.end());
    }
    else{
         // 이분 탐색하기 위한 변수들. left, right은 각각 범위의 왼쪽 끝, 오른쪽 끝, max는 범위의 중간.
        int left = 0;
        int right = M;
        int max = (left + right) / 2; // 예산의 상한
        while(true){
            max = (left + right) / 2;
            if(sum(budgets, max) == M){
                return max;
            }
            else if(sum(budgets, max) > M){
                right = max;
                continue;
            }
            else if(sum(budgets, max) < M){
                left = max;
                if(left == right) return max;
                continue;
            }
        }
    }
    return answer;
}

//상한이 max일 때 할당하게 되는 예산의 총합 구하기
int sum(vector<int> budgets, int max){
    int m = max;
    int sum = 0;
    for(vector<int>::iterator iter = budgets.begin(); iter != budgets.end(); iter++){
        if(*iter <= m){
            sum += *iter;
        }
        else{
            sum += m;
        }
    }
    return sum;
}