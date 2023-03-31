#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
vector<string> infos;
string path[5];
// unordered_multimap<string,int> umm;
map<string, vector<int>> m;
struct Node{
    string str;
    int score;
};
void makeCases(int score){
    string matrix[4][2];
    for(int i=0;i<4;i++){
        matrix[i][0]=infos[i];
        matrix[i][1]="-";
    }
    for(int a=0;a<2;a++){
        for(int b=0;b<2;b++){
            for(int c=0;c<2;c++){
                for(int d=0;d<2;d++){
                    string s=matrix[0][a]+matrix[1][b]+matrix[2][c]+matrix[3][d];
                    // umm.insert({s,score});
                    m[s].push_back(score);
                }
            }
        }
    }
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(int i=0;i<info.size();i++){
        string in=info[i];
        in+=" ";
        int start=0,score=0,idx=0;
        infos.clear(); infos.resize(0);
        while(in.find(" ",start)!=string::npos){
            int findIdx=in.find(" ",start);
            string sub=in.substr(start,findIdx-start);
            if(idx==4){
                score=stoi(sub);
                break;
            }
            
            infos.push_back(sub);
            start=findIdx+1;
            idx++;
        }
        makeCases(score);
    }
    
    // for(auto i=umm.begin();i!=umm.end();++i){
    //     cout<<i->first<<" "<<i->second<<"\n";
    // }
    vector<Node> qs;
    for(int i=0;i<query.size();i++){
        string q=query[i];
        q+=" and ";
        int start=0,idx=0,score=0;
        string s;
        while(q.find(" and ",start)!=string::npos){
            int findIdx=q.find(" and ",start);
            string sub=q.substr(start,findIdx-start);
            // cout<<"sub: "<<sub<<"\n";
            if(idx==3){
                // cout<<"sub: "<<sub<<"\n";
                int scoreIdx=sub.find(" ");
                s+=sub.substr(0,scoreIdx);
                score=stoi(sub.substr(scoreIdx+1));
                // cout<<"score: "<<score<<"\n";
                break;
            }
            
            s+=sub;
            idx++;
            start=findIdx+5;
            
        }
        // cout<<score<<" "<<s<<"\n";
        qs.push_back({s,score});
    }
    for(auto itr = m.begin(); itr != m.end(); itr++){
        sort(itr->second.begin(), itr->second.end());
    }
    for(int i=0;i<qs.size();i++){
        string str=qs[i].str;
        int score=qs[i].score;
        
        auto itr = lower_bound(m[str].begin(), m[str].end(), score);
        
        answer.push_back(m[str].size() - (itr - m[str].begin()));
        
    }
    
    return answer;
}