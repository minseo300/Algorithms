#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1=0,sum2=0;
    queue<int> q1,q2;
    for(int i=0;i<queue1.size();i++){
        sum1+=queue1[i];
        q1.push(queue1[i]);
        sum2+=queue2[i];
        q2.push(queue2[i]);
    }
    int limit=queue1.size()*2,idx1=0,idx2=0;
    while(idx1<limit&&idx2<limit){
        
        if(sum1==sum2) return answer;
        if(sum1<sum2){
            int num=q2.front();
            q1.push(num);
            q2.pop();
            sum1+=num;
            sum2-=num;
            idx2++;
        }
        else{
            int num=q1.front();
            q2.push(num);
            q1.pop();
            sum1-=num;
            sum2+=num;
            idx1++;
        }
        answer++;
    }
    
    return -1;
}