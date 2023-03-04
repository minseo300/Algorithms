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
int p1,p2;
int m;
int used[101];
vector<vector<int>> map(101);
queue<int> q;

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    cin>>p1>>p2;
    cin>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        map[x].push_back(y);
        map[y].push_back(x);
    }
    // used[p1]=1;
    q.push(p1);

    while(!q.empty()){
        int now=q.front();
        q.pop();

        for(int i=0;i<map[now].size();i++){
            int next=map[now][i];

            if(used[next]!=0) continue;

            used[next]=used[now]+1;
            q.push(next); 
        }
    }
    for(int i=0;i<=p2;i++) cout<<used[i]<<"\n";
    if(used[p2]==0) cout<<"-1\n";
    else cout<<used[p2]<<"\n";
    return 0;
}