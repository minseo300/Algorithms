#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,connection;
int map[101][101]={0,};
int used[101]={0,};
int cnt=0;
void run(int now){
    for(int i=1;i<=n;i++){
        if(used[i]==1) continue;
        if(map[now][i]==0) continue;

        used[i]=1;
        cnt++;
        run(i);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);

    cin>>n;
    cin>>connection;

    for(int i=0;i<connection;i++){
        int p1,p2;
        cin>>p1>>p2;
        map[p1][p2]=1;
        map[p2][p1]=1;
    }

    cnt++;
    used[1]=1;
    run(1);

    cout<<cnt;
    
    return 0;
}