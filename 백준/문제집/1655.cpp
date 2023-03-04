#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
#include<cstring>
using namespace std;

int dp[10001]; // dp[i] -> 돌이 i개일 때의 게임 횟수

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n;
    cin>>n;

    priority_queue<int, vector<int>, less<int>> maxHeap; // 내림차순
    priority_queue<int, vector<int>, greater<int>> minHeap; // 오름차순

    for(int i=0;i<n;i++){
        int num;
        cin>>num;

        if(maxHeap.size()<=minHeap.size()) maxHeap.push(num);
        else minHeap.push(num);

        while(!minHeap.empty()&&maxHeap.top()>minHeap.top()){
            int max=maxHeap.top();
            int min=minHeap.top();

            maxHeap.pop();
            minHeap.pop();

            minHeap.push(max);
            maxHeap.push(min);
        }
        cout<<maxHeap.top()<<"\n";
    }
    
    return 0;
}