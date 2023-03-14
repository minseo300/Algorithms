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
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n;
    vector<int> arr;
    int boss,seboss;
    cin>>n;
    for(int i=0;i<n;i++){
        int nn;
        cin>>nn;
        arr.push_back(nn);
    }
    cin>>boss>>seboss;
    long long ans=0;
    for(int i=0;i<n;i++){
        int se=arr[i]-boss;
        ans++;
        if(se>0){
            ans+=se/seboss;
            if(se%seboss>0) ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
