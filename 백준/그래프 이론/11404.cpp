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

int n,m; // 도시 개수, 버스 개수
int map[101][101];
int ret[100][100];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            map[i][j]=21e8;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c; // 시작 도시, 도착 도시, 비용 c
        cin>>a>>b>>c;
        
        if(map[a][b]<c) continue;
        
        map[a][b]=c;
    }
   
    for(int k=1;k<=n;k++){ // 거쳐가는 정점
        for(int i=1;i<=n;i++){ // 출발 정점
            for(int j=1;j<=n;j++){ // 도착 정점
                if(map[i][k]==21e8||map[k][j]==21e8) continue; 
                if(map[i][j]<map[i][k]+map[k][j]) continue;

                map[i][j]=map[i][k]+map[k][j];
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]==21e8||i==j) cout<<"0 ";
            
            else cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}