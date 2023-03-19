#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
#include<cstring>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int n,m;
vector<int> arr;
int answer=21e8;
int main()
{
    freopen("input.txt","r",stdin);
    fastio
    ////////////////////// 입력
    cin>>n>>m;
    int total=0;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        total+=num;
        arr.push_back(num);
    }
    int start=1,end=total;
    while(start<=end){
        int mid=(start+end)/2;
        // cout<<mid<<"\n";
        int out=1,outTotal=mid,possible=0;
        for(int i=0;i<n;i++){
            if(arr[i]>mid) {
                possible=1;
                break;
            }
            if(arr[i]>outTotal){
                out++;
                outTotal=mid;
            }
            outTotal-=arr[i];
        }
        if(out>m||possible==1) {
            start=mid+1;
        }
        else {
            end=mid-1;
            answer=mid;
        }
    }
    cout<<answer<<"\n";
    return 0;
}
