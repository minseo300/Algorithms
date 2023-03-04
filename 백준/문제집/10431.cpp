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
    int p;
    cin>>p;
    vector<int> answers;
    for(int i=0;i<p;i++){
        int tn;
        vector<int> sts;
        cin>>tn;
        int ans=0;
        for(int j=0;j<20;j++){
            int height;
            cin>>height;
            sts.push_back(height);
            // cout<<"h: "<<height<<"\n";
            if(j==0) continue;
            int index=-1;
            // for(int k=0;k<sts.size();k++){
            //     cout<<"sts: "<<sts[k]<<"\n";
            // }
            for(int k=j-1;k>=0;k--){
                // printf("j: sts[%d]-%d k: sts[%d]-%d\n",j,sts[j],k,sts[k]);
                if(sts[k]>sts[j]){
                    index=k;
                }
            }
            if(index==-1) {
                // cout<<"continue\n";
                continue;
            }
            else{
                // cout<<"index: "<<index<<"\n";
                sts.insert(sts.begin()+index,sts[j]);
            } 
            sts.pop_back();
            // for(int k=0;k<sts.size();k++){
            //     cout<<"- "<<sts[k]<<"\n";
            // }
            ans+=sts.size()-index-1;
        }
        answers.push_back(ans);
    }
    for(int i=0;i<answers.size();i++){
        cout<<i+1<<" "<<answers[i]<<"\n";
    }
    return 0;
}