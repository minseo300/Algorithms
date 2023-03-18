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


int n;
int map[101][101];
int diry[4]={0,-1,0,1};
int dirx[4]={1,0,-1,0};
vector<int> dirs;
int x,y,d,g;
int answer=0;
void dragon_curve(){
    int size=dirs.size();
    for(int i=size-1;i>=0;i--){
        int temp=(dirs[i]+1)%4;
        x+=dirx[temp];
        y+=diry[temp];
        map[x][y]=1;
        dirs.push_back(temp);
    }
}
void counting(){
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            if(map[i][j]==1&&map[i][j+1]==1&&map[i+1][j+1]==1&&map[i+1][j]==1) answer++;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y>>d>>g;
        dirs.clear();
        map[x][y]=1;
        x+=dirx[d];
        y+=diry[d];
        map[x][y]=1;
        dirs.push_back(d);
        while(g--){
            dragon_curve();
        }
        
    }
    counting();
    cout<<answer<<"\n";
    return 0;
}
