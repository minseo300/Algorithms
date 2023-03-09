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

int n;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    vector<long long> arr;
    long long l;
    for(int i=0;i<n;i++){
        cin>>l;
        arr.push_back(l);
    }
    sort(arr.begin(),arr.end());
    int start=0,end=0;
    long long candi=3000000001;
    vector<long long> ans(3);
    for(int k=0;k<n-2;k++){
        int start=k+1,end=n-1;
        while(start<end){
            long long sum=arr[k]+arr[start]+arr[end];
            if(abs(sum)<candi){
                candi=abs(sum);
                ans[0]=arr[k];
                ans[1]=arr[start];
                ans[2]=arr[end];
            }
            if(sum<0) start++;
            else end--;
        }
    }
    for(int i=0;i<3;i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
