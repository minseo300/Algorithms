#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m;
int boss[1001]={0,};
int group=0;
int find(int p){
    if(boss[p]==0) return p;

    int myBoss=find(boss[p]);
    boss[p]=myBoss;

    return myBoss;
}
void setUnion(int u,int v){
    int uu=find(u);
    int vv=find(v);

    if(uu==vv) return;

    boss[vv]=uu;
    group++;
}
int main()
{
    freopen("input.txt", "r", stdin);

    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        setUnion(u,v);

    }
    cout<<n-group<<"\n";
    return 0;
}