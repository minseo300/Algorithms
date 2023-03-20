#include <string>
#include <vector>
#include<iostream>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;

struct Node{
    string carNum;
    int sum;
};
bool compare(Node t, Node v){
    return stoi(t.carNum)<stoi(v.carNum);
}
unordered_map<string,vector<int>> times;
// unordered_map<string,Node> out;
unordered_map<string,int> cars;
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for(int i=0;i<records.size();i++){
        int idx1=records[i].find(" ");
        int idx2=records[i].find(" ",idx1+1);
        string timeStr=records[i].substr(0,idx1);
        string carNum=records[i].substr(idx1+1,4);
        string case_=records[i].substr(idx2);
        int timeIdx=timeStr.find(":");
        int time=stoi(timeStr.substr(0,timeIdx))*60+stoi(timeStr.substr(timeIdx+1));
        // if(case_.compare("IN")){
        //     // cout<<case_<<"\n";
        //     times[carNum].push_back(time);
        // }
        // else if(case_.compare("OUT")){
        //     times[carNum].push_back(time);
        // }
        times[carNum].push_back(time);
    }
    // cout<<times.size()<<"\n";
    vector<Node> sums;
    for(auto i=times.begin();i!=times.end();++i){
        vector<int> ts=i->second;
        if(ts.size()%2==1) ts.push_back(23*60+59);
        int sum=0;
        for(int i=0;i<ts.size();i+=2){
            int in=ts[i];
            int out=ts[i+1];
            sum+=out-in;
        }
        sums.push_back({i->first,sum});
    }
    vector<Node> ans;
    for(int i=0;i<sums.size();i++){
        int now=sums[i].sum;
        // cout<<"-"<<now<<"\n";
        int cost=0;
        if(now<=fees[0]){
            cost=fees[1];
        }
        else{
            // cout<<"**"<<now-fees[0]<<"\n";
            // cout<<"*"<<ceil((float)(now-fees[0])/fees[2])<<"\n";
            cost=fees[1]+ceil((float)(now-fees[0])/fees[2])*fees[3];
        }
        ans.push_back({sums[i].carNum,cost});
    }
    sort(ans.begin(),ans.end(),compare);
    for(int i=0;i<ans.size();i++){
        answer.push_back(ans[i].sum);
    }
    return answer;
}