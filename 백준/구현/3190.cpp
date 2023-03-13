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

int n,k;
int l;
char rot[10001]={'0',};
int map[101][101];
struct Node{
    int y,x;
};
int used[101][101];
int direct[4][2]={
    0,1,
    1,0,
    0,-1,
    -1,0
};
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int y,x;
        cin>>y>>x;
        map[y][x]=1;
    }
    cin>>l;
    queue<Node> q;
    q.push({1,1});
    int dir=0,ans=0;
    int hy=1,hx=1;
    for(int i=0;i<l;i++){
        int t;
        char d;
        cin>>t>>d;
        while(ans<t||i==l-1){
            ans++;
            int dy=hy+direct[dir][0];
            int dx=hx+direct[dir][1];

            if(dy>=1&&dx>=1&&dy<=n&&dx<=n&&!used[dy][dx]){
                if(map[dy][dx]==1){
                    map[dy][dx]=0;
                    q.push({dy,dx});
                    used[dy][dx]=1;
                }
                else{
                    q.push({dy,dx});
                    used[dy][dx]=1;
                    used[q.front().y][q.front().x]=0;
                    q.pop();
                }
            }
            else{
                cout<<ans<<"\n";
                return 0;
            }

            hy=dy; hx=dx;
            if(ans==t){
                if(d=='D'){
                    dir+=1;
                    if(dir==4) dir=0;
                }
                else{
                    dir-=1;
                    if(dir==-1) dir=3;
                }
            }

            
        }
    }
   
    return 0;
}
