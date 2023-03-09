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


int n,m;
vector<int> arr;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    int start=0,end=0,sum=0,ans=0;
    while(start<=end){
        if(sum==m){
            ans++;
            if(end>=arr.size()) break;
            sum+=arr[end++];
        }
        else if(sum<m){
            if(end>=arr.size()) break;
            sum+=arr[end++];
        }
        else if(sum>m){
            sum-=arr[start++];
        }
    }
    cout<<ans<<"\n";
    return 0;
}