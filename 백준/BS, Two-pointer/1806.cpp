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

int n,s;
vector<int> arr;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>s;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }

    int start=0,end=0,minLen=21e8,sum=0;
    while(start<=end){
        if(sum>=s){
            minLen=min(minLen,end-start);
            sum-=arr[start++];
        }
        else if(end==n) break;
        else{
            sum+=arr[end++];
        }
    }
    if(minLen==21e8) cout<<"0\n";
    else cout<<minLen<<"\n";
    
    return 0;
}