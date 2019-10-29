//https://programmers.co.kr/learn/courses/30/lessons/42586
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds);

int main(){
    //-------------입력--------------
    int n; // 기능의 개수
    cin >> n;
    vector<int> progresses(n); // 각 기능별 작업 진행 정도(%). 100%가 되면 배포가능
    vector<int> speeds(n);  //각 기능의 하루 개발속도.

    // 기능 별 작업 진행 정도 입력받음
    for(int i = 0; i < n; i++){
        cin >> progresses[i];
    }

    // 기능 별 개발속도 입력 받음
    for(int i = 0; i < n; i++){
        cin >> speeds[i];
    }

    //-------------출력--------------
    vector<int> answer = solution(progresses, speeds);
    
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}

vector<int> solution(vector<int> progresses, vector<int> speeds){
    vector<int> answer;
    int idx = 0; //다음으로 배포될 기능을 가리킬 인덱스
    int num = 0; //배포되는 기능의 개수
    //배포 되지 않은 기능이 남아있는 동안 반복
    while(idx < progresses.size()){
        //개발 속도만큼 각 기능의 진행정도를 높여줌
        for(int i = 0; i < progresses.size(); i++){
            progresses[i] += speeds[i];
        }
        //배포가능하면
        if(progresses[idx] >= 100){
            // 뒤에 같이 배포할 수 있는 기능이 체크하고 있으면 개수세기
            while(progresses[idx]>= 100){
                num++;
                idx++;
            }
            answer.push_back(num);
            //베포했으니까 배포할 기능의 수는 다시 0으로
            num = 0;
        }
    }
    return answer;
}