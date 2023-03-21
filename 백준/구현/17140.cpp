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

int r,c,k;
struct Node{
    int num,cnt;
};
int map[101][101];
int temp[101][101];
bool cmp(Node t, Node v){
    if(t.cnt==v.cnt) return t.num<v.num;
    return t.cnt<v.cnt;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>r>>c>>k;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>map[i][j];
        }
    }
    int answer=0;
    int rowSize=3,colSize=3;
    while(true){
        if(map[r-1][c-1]==k) break;
        if(answer>100){
            cout<<"-1\n";
            return 0;
        }
        
        int newRowSize=0,newColSize=0;
        memset(temp,0,sizeof(temp));
        if(rowSize>=colSize){
            // R연산
            for(int i=0;i<rowSize;i++){
                unordered_map<int,int> um;
                for(int j=0;j<colSize;j++){
                    if(map[i][j]==0) continue;
                    um[map[i][j]]++;
                }
                vector<Node> newData;
                for(auto j=um.begin();j!=um.end();++j){
                    newData.push_back({j->first,j->second});
                }
                sort(newData.begin(),newData.end(),cmp);
                vector<int> new_;
                for(int j=0;j<newData.size();j++){
                    new_.push_back(newData[j].num);
                    new_.push_back(newData[j].cnt);
                }
                for(int j=0;j<new_.size();j++){
                    temp[i][j]=new_[j];
                }
                int s=new_.size();
                newRowSize=max(newRowSize,s);
            }
            colSize=newRowSize;
        }
        else{
            // C연산
            for(int i=0;i<colSize;i++){
                unordered_map<int,int> um;
                for(int j=0;j<rowSize;j++){
                    if(map[j][i]==0) continue;
                    um[map[j][i]]++;
                }
                vector<Node> newData;
                for(auto j=um.begin();j!=um.end();++j){
                    newData.push_back({j->first,j->second});
                }
                sort(newData.begin(),newData.end(),cmp);
                vector<int> new_;
                for(int j=0;j<newData.size();j++){
                    new_.push_back(newData[j].num);
                    new_.push_back(newData[j].cnt);
                }
                for(int j=0;j<new_.size();j++){
                    temp[j][i]=new_[j];
                }
                int s=new_.size();
                newColSize=max(newColSize,s);
            }
            rowSize=newColSize;
        }
        memcpy(map,temp,sizeof(temp));
        answer++;
    }
    
    cout<<answer<<"\n";
    return 0;
}