#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;
vector<int> answer(1,-1);
int maxDif=0;
vector<int> info_, ryan(11,0);
bool cmp(){
    for(int i=10;i>=0;i--){
        if(ryan[i]>answer[i]) return true;
        else if(ryan[i]<answer[i]) return false;
    }
}
void score(){
    int ryanS=0, apeachS=0;
    
    for(int i=0;i<11;i++){
        if(ryan[i]>info_[i]) ryanS+=10-i;
        else if(info_[i]>0) apeachS+=10-i;
    }
    int dif=ryanS-apeachS;
    if(dif>0&&maxDif<=dif){
        cout<<dif<<"\n";
        if(maxDif==dif&&!cmp()) return;
        maxDif=dif;
        answer=ryan;
    }
}
void dfs(int idx,int arrows){
    if(idx==11||arrows==0){
        ryan[10]+=arrows;
        score();
        ryan[10]-=arrows;
        
        return;
    }
    if(info_[idx]<arrows){
        ryan[idx]+=info_[idx]+1;
        dfs(idx+1,arrows-info_[idx]-1);
        ryan[idx]-=info_[idx]+1;
    }
    dfs(idx+1,arrows);
    
}
vector<int> solution(int n, vector<int> info) {
    for(int i=0;i<info.size();i++) info_.push_back(info[i]);
    dfs(0,n);
    return answer;
}