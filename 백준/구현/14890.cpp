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

int n,l;
int map[101][101];
int used[101][101];

int check(int y){
    int before=map[y][0];
    memset(used,0,sizeof(used));
    for(int x=1;x<n;x++){
        if(map[y][x]>before){
            if(map[y][x]-before!=1) return 0;
            int cnt=0;
            before=map[y][x-1];
            for(int i=x-1;i>=0;i--){
                if(map[y][i]==before&&used[y][i]==0){
                    cnt++;
                    used[y][i]=1;
                }
                else break;
                if(cnt==l) break;
            }
            if(cnt!=l) return 0;
        }
        else if(map[y][x]<before){
            if(before-map[y][x]!=1) return 0;
            int cnt=0;
            before=map[y][x];
            for(int i=x;i<n;i++){
                if(map[y][i]==before&&used[y][i]==0){
                    cnt++;
                    used[y][i]=1;
                }
                else break;
                if(cnt==l) break;
            }
            if(cnt!=l) return 0;
        }
        before=map[y][x];
    }
    return 1;
}
int temp[101][101];
void rotate(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp[i][j]=map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[j][n-i-1]=temp[i][j];
        }
    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>l;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin>>map[y][x];
        }
    }
    int ans=0;
    for(int y=0;y<n;y++){
        // cout<<check(y)<<" ";
       if(check(y)==1) ans++; 
    }
    rotate();
    // cout<<"\n";
    for(int y=0;y<n;y++){
        if(check(y)==1) ans++;
        // cout<<check(y)<<" ";

    }
    cout<<ans<<"\n";
    return 0;
}
