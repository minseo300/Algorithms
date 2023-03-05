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

#define DIV		1000000007

int n,k;
long long temp;
long long power(long long a, long long m){
    if(m==0) return 1;

    temp=power(a,m/2)%DIV;
    if(m%2==1) return temp*temp%DIV*a%DIV;
    return temp*temp%DIV;
}
void solve(){
    if(k==1){
        cout<<n;
        return;
    }
    if(k==0||n==k){
        cout<<1;
        return;
    }
    if(n-k==1){
        cout<<n;
        return;
    }

    long long a=1, b=1, ans;
    for(int i=n;i>=n-k+1;i--) a=(a*i)%DIV;
    for(int i=1;i<=k;i++) b=(b*i)%DIV;
    ans=((a%DIV)*power(b,DIV-2)%DIV)%DIV;
    cout<<ans;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>k;

    solve();


    return 0;
}