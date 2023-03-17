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

int n,w,l;
queue<int> q;
vector<int> arr;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>w>>l;
    for(int i=0;i<n;i++){
        int ww;
        cin>>ww;
        arr.push_back(ww);
    }
    int ans=0;
    int sum=0;

    for(int i=0;i<n;i++){
        while(true){
            if(q.size()==w){
                sum-=q.front();
                q.pop();
            }
            if(arr[i]+sum<=l){
                break;
            }
            else q.push(0);
            ans++;
        }
        q.push(arr[i]);
        sum+=arr[i];
        ans++;
    }
    cout<<ans+w;
    cout<<"\n";
    return 0;
}
