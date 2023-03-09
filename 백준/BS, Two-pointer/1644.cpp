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

int n;

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;

    // 에라토스테네스의 체를 이용하여 소수 구하기
    vector<int> primes;
    vector<int> check(n+1,0);
    for(int i=2;i*i<=n;i++){
        if(check[i]==1) continue;
        for(int j=i+i;j<=n;j+=i){
            check[j]=1;
        }
    }

    for(int i=2;i<=n;i++){
        if(check[i]==0) primes.push_back(i);
    }
    // 투포인터 알고리즘
    int start=0,end=0,sum=0,ans=0;
    while(start<=end){
        if(sum>n){
            sum-=primes[start++];
        }
        else if(sum<n){
            if(end>=primes.size()) break;

            sum+=primes[end++];
        }
        else if(sum==n){
            ans++;
            if(end>=primes.size()) break;
            sum+=primes[end++];
        }
        
        
    }
    cout<<ans<<"\n";
    return 0;
}