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

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int k,n;
    cin>>k>>n;
    vector<int> lans;
    int maxi=0;
    for(int i=0;i<k;i++){
        int l;
        cin>>l;
        lans.push_back(l);
        if(maxi<l) maxi=l;
    }
    long long s=1L,e=maxi;
    long long answer=0L;
    while(s<=e){
        long long mid=(s+e)/2;
        int cnt=0;
        for(int i=0;i<k;i++){
            cnt+=lans[i]/mid;
        }
        if(cnt>=n) {
            s=mid+1;
            answer=max(answer,mid);
        }
        else e=mid-1;

    }

    cout<<answer<<"\n";
	return 0;
}