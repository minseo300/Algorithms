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

int t,n,m;
vector<int> a,b;
int bs(int target){
    int start=0,end=b.size()-1;
    while(start<=end){
         int mid=(start+end)/2;
         if(b[mid]<target){
            start=mid+1;
         }
         else{
            end=mid-1;
         }
    }
    return start;
}
int main()
{
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ////////////////////// 입력
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n>>m;
        for(int j=0;j<n;j++){
            int num;
            cin>>num;
            a.push_back(num);
        }
        for(int j=0;j<m;j++){
            int num;
            cin>>num;
            b.push_back(num);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int answer=0;
        for(int i=0;i<n;i++){
            answer+=bs(a[i]);
        }
        cout<<answer<<"\n";
        a.clear(); a.resize(0);
        b.clear(); b.resize(0);
    }
    
    return 0;
}
