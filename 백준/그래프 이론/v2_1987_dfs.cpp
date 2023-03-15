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

int r,c; // 세로, 가로
char map[21][21];
int diry[4]={-1,0,0,1};
int dirx[4]={0,-1,1,0};
int used[300];
int visited[21][21];
int ans=0;
void dfs(int y,int x,int cnt){
    ans=max(ans,cnt);

    for(int d=0;d<4;d++){
        int dy=y+diry[d];
        int dx=x+dirx[d];

        if(dy<1||dx<1||dy>r||dx>c) continue;
        if(used[map[dy][dx]]==1) continue;
        
        used[map[dy][dx]]=1;
        dfs(dy,dx,cnt+1);
        used[map[dy][dx]]=0;

    }

}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        string s;
        cin>>s;
        for(int j=1;j<=c;j++){
            map[i][j]=s[j-1];
        }
    }
    
    used[map[1][1]]=1;
    dfs(1,1,1);
    cout<<ans<<"\n";
    return 0;
}
