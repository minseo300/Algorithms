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
int n,k;

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>k;
    // k=min(pow(10,9),pow(n,2));
    int s=1,e=k;
    int result=-1;
    while(s<=e){
        int cnt=0;
        int mid=(s+e)/2;
        for(int i=1;i<=n;i++){
            cnt+=min(mid/i,n); // mid보다 작은 j의 수 (i*j<=mid)
        }

        if(cnt<k) s=mid+1;
        else{
            result=mid;
            e=mid-1;
        }
    }

    cout<<result<<"\n";



    return 0;
}