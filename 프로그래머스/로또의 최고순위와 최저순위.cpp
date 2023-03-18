#include <string>
#include <vector>
#include<iostream>
using namespace std;
int used[46];
int anomys;
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);
    for(int i=0;i<lottos.size();i++){
        used[lottos[i]]++;
        if(lottos[i]==0) anomys++;
    }
    int same=0;
    for(int i=0;i<win_nums.size();i++){
        if(used[win_nums[i]]==1) same++;
    }
    
    if(same==6) answer[1]=1;
    else if(same==5) answer[1]=2;
    else if(same==4) answer[1]=3;
    else if(same==3) answer[1]=4;
    else if(same==2) answer[1]=5;
    else answer[1]=6;
    
    if(same+anomys==6) answer[0]=1;
    else if(same+anomys==5) answer[0]=2;
    else if(same+anomys==4) answer[0]=3;
    else if(same+anomys==3) answer[0]=4;
    else if(same+anomys==2) answer[0]=5;
    else answer[0]=6;
    return answer;
}