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
    int increase[1001];
    int decrease[1001];
    int arr[1001];
    

    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    //가장 긴 증가하는 부분 수열
    for(int i=1;i<=n;i++){
        increase[i]=1;
        for(int j=1;j<=i;j++){
            if(arr[i]>arr[j]&&increase[i]<increase[j]+1) increase[i]=increase[j]+1;
        }
    }

    // 가장 긴 감소하는 부분 수열
    for(int i=n;i>=1;i--){
        decrease[i]=1;
        for(int j=n;j>=i;j--){
            if(arr[i]>arr[j]&&decrease[i]<decrease[j]+1) decrease[i]=decrease[j]+1;
        }
    }

    // 가장 긴 부분 수열
    int ans=0;
    for(int i=1;i<=n;i++){
        if(ans<increase[i]+decrease[i]-1) ans=increase[i]+decrease[i]-1;
    }
    cout<<ans<<"\n";
    return 0;
}