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
int directY[8]={-2,-2,-1,1,2,2,1,-1};
int directX[8]={-1,1,2,2,1,-1,-2,-2};
int t, l;
struct Node{
    int y,x;
};

Node cur,tar;
int ret[310][310];
int used[310][310];
int bfs(){
    queue<Node> q;
    q.push({cur.y,cur.x});
    used[cur.y][cur.x]=1;
    while(!q.empty()){
        Node now=q.front();
        q.pop();

        
        for(int d=0;d<8;d++){
            int dy=now.y+directY[d];
            int dx=now.x+directX[d];

            if(dy<0||dx<0||dy>=l||dx>=l) continue;
            if(used[dy][dx]==1) continue;
            if(ret[dy][dx]!=0) continue;

            ret[dy][dx]=ret[now.y][now.x]+1;
            used[dy][dx]=1;
            q.push({dy,dx});

            if(dy==tar.y&&dx==tar.x) {
                return 1;
            }
        }
    }
    return 0;
}
void initRet(){
    for(int y=0;y<l;y++){
        for(int x=0;x<l;x++){
            ret[y][x]=0;
            used[y][x]=0;
        }
    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>t;
    for(int tc=0;tc<t;tc++){
        initRet();
        cin>>l;
        int cury,curx,tary,tarx;
        cin>>cury>>curx;
        cin>>tary>>tarx;
        cur={cury,curx};
        tar={tary,tarx};
        if(bfs()) cout<<ret[tar.y][tar.x]<<"\n";
        else cout<<"0\n";
    }
    return 0;
}