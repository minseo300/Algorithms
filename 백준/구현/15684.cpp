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

int n,m,h;
int map[31][11];
int visited[31][11];
int answer=21e8;
int game(){
    for (int i = 1; i <= n; i++)
    {
        int Current_Num = i;
        for (int j = 1; j <= h; j++)
        {
            if (visited[Current_Num][j] == true) Current_Num = Current_Num + 1;
            else if (visited[Current_Num-1][j] == true) Current_Num = Current_Num - 1;
        }
 
        if (Current_Num != i) return 0;
    }
    return 1;
}
void dfs(int idx,int cnt){
    if(cnt>=4) return;
    if(game()){
        answer=min(answer,cnt);
        return ;
    }
    
    for(int i=1;i<=h;i++){
        for(int j=1;j<n;j++){
           if(visited[j][i]==1) continue;
           if(visited[j-1][i]==1) continue;
           if(visited[j+1][i]==1) continue;

           visited[j][i]=1;
           dfs(i,cnt+1);
           visited[j][i]=0;
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
    cin>>n>>m>>h;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        // map[a][b]=1; map[a][b+1]=1;
        visited[b][a]=1; 
    }
   
    dfs(1,0);
    if(answer==21e8) answer=-1;
    cout<<answer<<"\n";

    return 0;
}
