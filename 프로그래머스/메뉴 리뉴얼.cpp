#include <string>
#include <vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<cstring>
using namespace std;

char path[11];
unordered_map<string,int> um;
struct Node{
    string str;
    int cnt;
};
void dfs(int idx,int lev,int branch,int limit,string order){
    if(lev==limit){
        string s="";
        for(int i=0;i<limit;i++) s+=path[i];
        // cout<<s<<"\n";
        um[s]++;
    }
    
    for(int i=idx;i<branch;i++){
        path[lev]=order[i];
        dfs(i+1,lev+1,branch,limit,order);
        
        
    }
}
bool cmp(Node t, Node v){
    return t.cnt>v.cnt;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0;i<orders.size();i++){
        sort(orders[i].begin(),orders[i].end());
        for(int j=0;j<course.size();j++){
            dfs(0,0,orders[i].length(),course[j],orders[i]);
            
        }
    }
    for(int i=0;i<course.size();i++){
        vector<Node> cnts;
        int ss=course[i];
        for(auto i=um.begin();i!=um.end();++i){
            int len=i->first.length();
            if(len==ss&&i->second>=2){
                cnts.push_back({i->first,i->second});
            }
        }
        sort(cnts.begin(),cnts.end(),cmp);
        for(int i=0;i<cnts.size();i++){
            if(cnts[0].cnt==cnts[i].cnt) answer.push_back(cnts[i].str);
            if(cnts[0].cnt>cnts[i].cnt) break;
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}