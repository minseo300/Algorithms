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

int n,x;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    vector<int> arr;
    int num;

    for(int i=0;i<n;i++){
        cin>>num;
        arr.push_back(num);
    }
    cin>>x;
    
    sort(arr.begin(),arr.end());
    int start=0,end=n-1,sum=0,ans=0;
    while(start<end){
        int sum=arr[start]+arr[end];
        if(sum<x){
            start++;
        }
        else if(sum>x){
            end--;
        }
        else{
            ans++;
            end--;
            start++;
        }
    }
   
    cout<<ans<<"\n";
    return 0;
}
