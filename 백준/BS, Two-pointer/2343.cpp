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
int ans=21e8;
vector<int> arr;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    int sum=0;
    int maxi=-21e8;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
        sum+=num;
        maxi=max(maxi,num);
    }
    // sort(arr.begin(),arr.end());
    int start=maxi,end=sum;
    while(start<=end){
        int mid=(start+end)/2;
        // cout<<"mid: "<<mid<<"\n";
        int total=0,cnt=1;
        for(int i=0;i<n-1;i++){
            // cout<<"total: "<<total<<"\n";
            total+=arr[i];
            if(total+arr[i+1]>mid){
                // cout<<arr[i]<<"\n";
                total=0;
                cnt++;
            }
        }
        // cout<<"cnt: "<<cnt<<"\n";
        if(cnt>m){
            start=mid+1;
        }
        else if(cnt<=m){
            ans=min(ans,mid);
            end=mid-1;
        }
       
    }
    cout<<ans<<"\n";
    return 0;
}
