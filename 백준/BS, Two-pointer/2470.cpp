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
    int n;
    cin>>n;
    vector<int> liq(n);
    for(int i=0;i<n;i++){
        cin>>liq[i];
    }
    sort(liq.begin(),liq.end());

    int s=0,e=n-1;
    int min=21e8;
    int ans[2]={0,0};
    while(s<e){
        int sum=liq[s]+liq[e];
        if(abs(sum)<min){
            min=abs(sum);
            ans[0]=liq[s];
            ans[1]=liq[e];
            if(sum==0) break;
        }
        if(sum<0) s++;
        else e--;
    }
    cout<<ans[0]<<" "<<ans[1];
	return 0;
}