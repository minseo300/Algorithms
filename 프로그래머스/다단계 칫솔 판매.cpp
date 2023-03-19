#include <string>
#include <vector>
#include<unordered_map>
#include<iostream>
using namespace std;
unordered_map<string,string> um; // 자식 - 부모
unordered_map<string,int> umm; // enroll - 돈
void getProfit(string name,int money){
    if(name=="none") return;
    
    int p=money*0.1;
    umm[name]+=(money-p);
    if(p<1) return;
    getProfit(um[name],p);
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for(int i=0;i<referral.size();i++){
        if(referral[i]=="-") um[enroll[i]]="none";
        else um[enroll[i]]=referral[i];
    }
    for(int i=0;i<seller.size();i++){
        string child=seller[i];
        int cost=amount[i]*100;
        getProfit(child,cost);
        
    }
    for(int i=0;i<enroll.size();i++){
        answer.push_back(umm[enroll[i]]);
    }
    return answer;
}