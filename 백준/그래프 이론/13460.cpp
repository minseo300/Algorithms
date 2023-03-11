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

int n,m; // 세로, 가로
char map[11][11];
struct Node{
    int ry,rx;
    int by,bx;
    int cnt;
};
int visited[11][11][11][11];
queue<Node> q;
int direct[4][2]={
    -1,0,
    0,-1,
    0,1,
    1,0
};
int ret=-1;
int bfs(){
    while(!q.empty()){
        Node now=q.front();
        q.pop();

        if(now.cnt>10) break;
        if(map[now.ry][now.rx]=='O'&&map[now.by][now.bx]!='O'){
            ret=now.cnt;
            break;
        }

        for(int d=0;d<4;d++){
            int dry=now.ry;
            int drx=now.rx;
            int dby=now.by;
            int dbx=now.bx;

            while(1){
                if(map[dry][drx]!='#'&&map[dry][drx]!='O'){
                    dry+=direct[d][0];
                    drx+=direct[d][1];
                }
                else{
                    if(map[dry][drx]=='#'){
                        dry-=direct[d][0];
                        drx-=direct[d][1];
                    }
                    break;
                }
            }

            while(1){
                if(map[dby][dbx]!='#'&&map[dby][dbx]!='O'){
                    dby+=direct[d][0];
                    dbx+=direct[d][1];
                }
                else{
                    if(map[dby][dbx]=='#'){
                        dby-=direct[d][0];
                        dbx-=direct[d][1];
                    }
                    break;
                }
            }

            if(dry==dby&&drx==dbx){
                if(map[dry][drx]!='O'){
                    int rdis=abs(dry-now.ry)+abs(drx-now.rx);
                    int bdis=abs(dby-now.by)+abs(dbx-now.bx);
                    if(rdis>bdis){
                        dry-=direct[d][0];
                        drx-=direct[d][1];
                    }
                    else{
                        dby-=direct[d][0];
                        dbx-=direct[d][1];
                    }
                }
            }
            if(visited[dry][drx][dby][dbx]==0){
                visited[dry][drx][dby][dbx]=1;
                q.push({dry,drx,dby,dbx,now.cnt+1});
            }
        }
    }
    return ret;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    string s;
    int ry,rx,by,bx;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            map[i][j]=s[j];
            if(map[i][j]=='R'){
                ry=i;
                rx=j;
            }
            else if(map[i][j]=='B'){
                by=i;
                bx=j;
            }
        }
    }
    q.push({ry,rx,by,bx,0});
    visited[ry][rx][by][bx]=1;
    cout<<bfs();
    return 0;
}
