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
int map[100001];
int used[100001];
struct Node{
    int cur,time;
};
queue<Node> q;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n,k; // 수빈, 동생
    cin>>n>>k;

    q.push({n,0});

    while(!q.empty()){
        Node now=q.front();   
        q.pop();
        
        if(now.cur==k) {
            break;
        }


        // X-1
        if(now.cur-1>=0&&used[now.cur-1]==0) {
            map[now.cur-1]=now.time+1;
            used[now.cur-1]=1;
            q.push({now.cur-1,now.time+1});
        }
       
        // X+1
        if(now.cur+1<=100000&&used[now.cur+1]==0) {
            map[now.cur+1]=now.time+1;
            used[now.cur+1]=1;
            q.push({now.cur+1,now.time+1});
        }
        
        // 순간이동
        
        if(now.cur*2<=100000&&used[now.cur*2]==0) {
            map[now.cur*2]=now.time+1;
            used[now.cur*2]=1;
            q.push({now.cur*2,now.time+1}); 
        }
        

        // cout<<"q size: "<<q.size()<<"\n";
    }
    int ans=0;
    if(n>=k) ans=n-k;
    else ans=map[k];

    cout<<ans<<"\n";

    return 0;
}