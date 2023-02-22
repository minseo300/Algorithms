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
struct Node{
    int y,x;
};
int used[14];
vector<Node> house;
vector<Node> chi;
vector<Node> candis(13);
int n,m;
int answer=21e8;
void search(int cnt,int idx){
    if(cnt==m){
        vector<int> dis(house.size(),21e8);
        for(int i=0;i<house.size();i++){
            for(int j=0;j<m;j++){
                int distance=abs(house[i].y-candis[j].y)+abs(house[i].x-candis[j].x);
                dis[i]=min(dis[i],distance);
            }
        }
        int total=0;
        for(int i=0;i<dis.size();i++) {
            total+=dis[i];
        }
        answer=min(answer,total);
       
        return;
    }

    for(int i=idx;i<chi.size();i++){
        if(used[i]==1) continue;

        candis[cnt]={chi[i].y,chi[i].x};
        used[i]=1;
        search(cnt+1,i+1);
        used[i]=0;
        candis[cnt]={-1,-1};
    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
   
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            int nn;
            cin>>nn;
            if(nn==1) house.push_back({y,x});
            else if(nn==2) chi.push_back({y,x});
        }
    }

    search(0,0);
    cout<<answer<<"\n";

	return 0;
}