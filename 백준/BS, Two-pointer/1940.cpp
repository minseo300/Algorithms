#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
#include<cstring>
#include <map>
using namespace std;

int n,m;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    vector<int> arr;
    int num;

    for(int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(),arr.end());
    int start=0,end=n-1,ans=0;
    while(start<end){
        int sum=arr[start]+arr[end];
        // cout<<sum<<"\n";
        if(sum<m){
            start++;
        }
        else if(sum>m){
            end--;
        }
        else{
            ans++;
            start++;
            end--;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
