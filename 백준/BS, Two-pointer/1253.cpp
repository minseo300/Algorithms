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
int arr[2000];
int main()
{
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int ans=0;
    for(int i=0;i<n;i++){
        int target=arr[i];
        int start=0,end=n-1;
        int sum;
        while(start<end){
            sum=arr[start]+arr[end];
            if(start==i){
                start++;
                continue;
            }
            if(end==i){
                end--;
                continue;
            }
            if(target>arr[start]+arr[end]) start++;
            else if(target==arr[start]+arr[end]){
                ans++;
                break;
            }
            else end--;
        }
    }
    cout<<ans;



    return 0;
}
