#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m;

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin>>n>>m;
    vector<int> trees(n,0);
    long long end=0L;
    for(int i=0;i<n;i++){
        cin>>trees[i];
        if(trees[i]>end) end=trees[i];
    }
    
    long long start=1L,ans=0L;
    while(start<=end){
        long long mid=(start+end)/2;
        long long result=0L;
        for(int i=0;i<n;i++){
            if(trees[i]<mid) continue;
            result+=(trees[i]-mid);
        }

        if(result<m) end=mid-1;
        else if(result>m) {
            if(ans<mid) ans=mid;
            start=mid+1;
            // ans=mid; 
        }
        else if(result==m) {
            ans=mid;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}