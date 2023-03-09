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
    cin>>n;
    int highest=0;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        arr.push_back(c);
    }
    cin>>m;
    sort(arr.begin(),arr.end());
    int s=1, e=arr[n-1];
    int answer=0;
    while(s<=e){
        int mid=(s+e)/2;
        int c=0;

        for(int i=0;i<n;i++){
            c+=min(arr[i],mid);
        }
        // cout<<"sum: "<<c<<" mid: "<<mid<<"\n";
        if(c>m){
            e=mid-1;
        }
        else if(c<=m){
            s=mid+1;
            answer=mid;
        }
    }
    cout<<answer<<"\n";




    return 0;
}