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

int map[21][21];
int visited[21][21];
int division[21][21];
int n;
int answer=21e8;
int getPops(int x,int y,int d1,int d2){
    memset(visited,0,sizeof(visited));
    memset(division,0,sizeof(division));
    int pops[5];
    memset(pops,0,sizeof(pops));
    // 5번 선거구
    for(int r=1;r<=n;r++){
        for(int c=1;c<=n;c++){
            //1번 선거구
            if(r<x+d1&&c<=y&&!(r>=x&&c>=y-(r-x))){
                division[r][c]=1;
                pops[1]+=map[r][c];
            }
            else if(r<=x+d2&&c>y&&!(r>=x&&c<=y+(r-x))){
                division[r][c]=2;
                pops[2]+=map[r][c];
            }
            else if(r>=x+d1&&c<y-d1+d2&&!(r<=x+d1+d2&&c>=(y-d1+d2-(x+d1+d2-r)))){
                division[r][c]=3;
                pops[3]+=map[r][c];
            }
            else if(r>x+d2&&c>=y-d1+d2&&!(r<=x+d1+d2&&c<=(y-d1+d2+(x+d1+d2-r)))){
                division[r][c]=4;
                pops[4]+=map[r][c];
            }
            else{
                pops[0]+=map[r][c];
                division[r][c]=5;
            }
        }
    }
   
   
    sort(pops,pops+5);
    for(int i=0;i<5;i++) {
        if(pops[i]==0) return -1;
        // cout<<pops[i]<<" ";
    }
    // cout<<"\n";
    return pops[4]-pops[0];
    // for(int r=1;r<=n;r++){
    //     for(int c=1;c<=n;c++) cout<<division[r][c]<<" ";
    //     cout<<"\n";
    // }
    // cout<<"\n";
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            for(int d1=1;d1<=y-1;d1++){
                for(int d2=1;d2<=n-y;d2++){
                    // printf("x: %d y: %d d1: %d d2: %d\n",x,y,d1,d2);
                    int ret=getPops(x,y,d1,d2);
                    if(ret==-1) continue;
                    answer=min(answer,ret);
                }
            }
        }
    }
    cout<<answer<<"\n";
    return 0;
}