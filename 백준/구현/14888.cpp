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
int arr[12];
int opers[4];
int operCnt=0;
int mini=21e8, maxi=-21e8;
void dfs(int val,int lev){

    if(lev==n-1){
        mini=min(mini,val);
        maxi=max(maxi,val);
        return;
    }
    for(int i=0;i<4;i++){
        if(opers[i]==0) continue;

        opers[i]--;
        if(i==0){ // 더하기
            dfs(val+arr[lev+1],lev+1);
        }
        else if(i==1){ // 빼기
            dfs(val-arr[lev+1],lev+1);
        }
        else if(i==2){ // 곱하기
            dfs(val*arr[lev+1],lev+1);
        }
        else if(i==3){ // 나누기
            dfs(val/arr[lev+1],lev+1);
        }
        opers[i]++;
    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   
    for(int i=0;i<4;i++){
        cin>>opers[i];
    }
    dfs(arr[0],0);
    cout<<maxi<<"\n"<<mini<<"\n";
    return 0;
}
