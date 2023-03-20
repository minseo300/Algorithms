#include <string>
#include <vector>
#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<string,int> um;
unordered_map<string,int> for_ans;
unordered_multimap<string,string> umm; // 불량 사용자 - 신고한 사용자
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for(int i=0;i<report.size();i++){
        int idx=report[i].find(" ");
        string user=report[i].substr(0,idx);
        string wrong=report[i].substr(idx);
        // cout<<user<<" "<<wrong<<"\n";
        auto mi=umm.equal_range(wrong);
        int flag=0;
        for(auto j=mi.first;j!=mi.second;++j){
            if(j->second==user){
                flag=1;
                break;
            }
        }
        if(flag==0){
            um[wrong]++;
            umm.insert({wrong, user});
        }
        
    }
    for(auto i=um.begin();i!=um.end();++i){
        cout<<i->first<<" "<<i->second<<"\n";
        if(i->second>=k){
            auto mi=umm.equal_range(i->first);
            for(auto j=mi.first;j!=mi.second;++j){
                // cout<<j->first<<" "<<j->second<<"\n";
                for_ans[j->second]++;
            }
        }
    }
    for(int i=0;i<id_list.size();i++){
        answer.push_back(for_ans[id_list[i]]);
    }
    return answer;
}