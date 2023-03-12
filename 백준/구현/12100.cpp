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

int board[21][21];
int n;
int path[5];
int ans=-21e8;
int map[21][21];

void scoring(){
    memcpy(map,board,sizeof(board));
    queue<int> q;
    for(int i=0;i<5;i++){
        if(path[i]==0){ // 위로
            for(int x=0;x<n;x++){
                for(int y=0;y<n;y++){
                    if(map[y][x]==0) continue;

                    q.push(map[y][x]);
                    map[y][x]=0;
                }
                int idx=0;
                while(!q.empty()){
                    int now=q.front();
                    q.pop();
                    
                    if(map[idx][x]==0) map[idx][x]=now;
                    else if(map[idx][x]==now){
                        map[idx][x]*=2;
                        idx++;
                    }
                    else{
                        idx++;
                        map[idx][x]=now;
                    }
                }
            }
        }
        else if(path[i]==1){ //아래로
            for(int x=0;x<n;x++){
                for(int y=n-1;y>=0;y--){
                    if(map[y][x]==0) continue;

                    q.push(map[y][x]);
                    map[y][x]=0;
                }
                int idx=n-1;
                while(!q.empty()){
                    int now=q.front();
                    q.pop();

                    if(map[idx][x]==0) map[idx][x]=now;
                    else if(map[idx][x]==now){
                        map[idx][x]*=2;
                        idx--;
                    }
                    else{
                        idx--;
                        map[idx][x]=now;
                    }
                }
            }
        }
        else if(path[i]==2){ // 왼쪽으로
            for(int y=0;y<n;y++){
                for(int x=0;x<n;x++){
                    if(map[y][x]==0) continue;

                    q.push(map[y][x]);
                    map[y][x]=0;
                }
                int idx=0;
                while(!q.empty()){
                    int now=q.front();
                    q.pop();

                    if(map[y][idx]==0) map[y][idx]=now;
                    else if(map[y][idx]==now){
                        map[y][idx]*=2;
                        idx++;
                    }
                    else{
                        idx++;
                        map[y][idx]=now;
                    }
                }
            }
        }
        else if(path[i]==3){ // 오른쪽으로
            for(int y=0;y<n;y++){
                for(int x=n-1;x>=0;x--){
                    if(map[y][x]==0) continue;

                    q.push(map[y][x]);
                    map[y][x]=0;
                }
                int idx=n-1;
                while(!q.empty()){
                    int now=q.front();
                    q.pop();

                    if(map[y][idx]==0) map[y][idx]=now;
                    else if(map[y][idx]==now){
                        map[y][idx]*=2;
                        idx--;
                    }
                    else{
                        idx--;
                        map[y][idx]=now;
                    }
                }
            }
        }
    }
}
void dfs(int lev){
    if(lev==5){
        scoring();
        for(int y=0;y<n;y++){
            for(int x=0;x<n;x++){
                ans=max(ans,map[y][x]);
            }
        }
        return;
    }

    // 0-위로 1-아래로 2-왼쪽으로 3-오른쪽으로
    int temp[21][21];
    for(int i=0;i<4;i++){
        path[lev]=i;
        dfs(lev+1);
        path[lev]=0;
    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin>>board[y][x];
        }
    }

    dfs(0);
    cout<<ans<<"\n";
    return 0;
}
