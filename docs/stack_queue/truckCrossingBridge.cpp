//https://programmers.co.kr/learn/courses/30/lessons/42583
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int sumWeight(queue<int> truckOnBridge, vector<int> truck_weights);
int solution(int bridge_length, int weight, vector<int> truck_weights);

int main(){
    int n;//다리를 건널 트럭의 수
    int bridge_length;//다리의 길이
    int weight;//다리가 견딜 수 있는 무게

    //변수 입력받기
    cin >> n >> bridge_length >> weight;

    vector<int> truck_weights(n);//트럭의 무게를 저장할 벡터

    //무게 입력받기
    for(int i = 0; i < n; i++){
        cin >> truck_weights[i];
    }

    cout << solution(bridge_length, weight, truck_weights) << '\n';

    return 0;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0; //트럭이 다리를 건너는데 걸리는 시간을 저장할 변수
    int sum_weight = 0; //다리 위에 있는 트럭들의 무게의 합
    queue<int> truckOnBridge; // 다리위에 있는 트럭을 저장할 큐, 트럭의 인덱스 값을 저장.
    vector<int> time(truck_weights.size(), 0);  // 각 트럭이 다리위에 머무른 시간을 저장할 벡터.
    
    //i는 트럭 인덱스. 다리에 올라가려는 트럭을 가리킴. 트럭이 다리에 올라가면 i++해줌
    for(int i = 0; i < truck_weights.size() || !truckOnBridge.empty();){
        /*
        //트럭한대의 무게가 다리가 견딜 수 있는 무게보다 큰 경우.
        if(truck_weights[i] > weight){
            cout << "트럭이 다리를 건널 수 없습니다." << '\n';
            return 0;
        }
        */
        // 첫 번째 트럭은 무조건 출발
        if(i==0){
            truckOnBridge.push(i);
            time[i]++;
            i++;
            continue;
        }
        //제일 앞에 있는 트럭이 다리를 다 건너면 큐에서 삭제
        if(time[truckOnBridge.front()] > bridge_length){
            truckOnBridge.pop();
        }
        // 무게제한 때문에 다리 위에 올라가지 못하는 경우(다리 위에 있는 트럭의 무게의 합 + 대기 중인 트럭의 무게 > 다리가 견딜 수 있는 무게)
        // 다리 위 트럭의 위치(시간)만 1씩 올린다.
        if(i < truck_weights.size() && sumWeight(truckOnBridge, truck_weights)+truck_weights[i]>weight)
        {
            for(int j = 0; j < i; j++){
                time[j]++;
            }
            continue;
        }
        //마지막 트럭의 경우, 다리 위에 올라가려고 대기중인 트럭(truck_weights[i])이 존재하지 않으므로 그냥 다리위에 있는 트럭만 조사한다.
        else if(i >= truck_weights.size()){
            for(int j = 0; j < i; j++){
                time[j]++;
            }
            continue;
        }
        //다음 트럭이 다리 위에 올라감
        else{
            truckOnBridge.push(i);
            for(int j = 0; j <= i; j++){
                time[j]++;
            }
            i++;
        }
        answer++;
    }
    return answer;
}
    
int sumWeight(queue<int> truckOnBridge, vector<int> truck_weights){
    int sum = 0;
    while(!truckOnBridge.empty()){
        sum += truck_weights.at(truckOnBridge.front());
        truckOnBridge.pop();
    }
    return sum;
}