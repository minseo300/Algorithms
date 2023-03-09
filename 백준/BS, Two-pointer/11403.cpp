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
vector<vector<int>> map(101);
int visited[101];
int bfs(int arr,int dep){
    queue<int> q;
    memset(visited,0,sizeof(visited));

    q.push(arr);
    // visited[arr]=1;
    // cout<<"-arr: "<<arr<<" dep: "<<dep<<"\n";
    while(!q.empty()){
        int now=q.front();
        q.pop();
        // if(now==dep) return 1;
        for(int i=0;i<map[now].size();i++){
            int next=map[now][i];

            if(visited[next]==1) continue;
            // cout<<"now: "<<now<<" next: "<<next<<"\n";
            if(next==dep) return 1;
            q.push(next);
            visited[next]=1;
        }
    }
    return 0;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int c;
            cin>>c;

            if(c==0) continue;

            map[i].push_back(j);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // if(i==j) cout<<"1 ";
            // int ret=bfs(i,j);
                if(bfs(i,j)) cout<<"1 ";
                else cout<<"0 ";
            
        }
        cout<<"\n";
    }


    return 0;
}