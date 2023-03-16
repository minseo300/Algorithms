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

int n,m;
int arr[101];
void boy(int num){
    for(int i=num;i<=n;i++){
        if(i%num==0) arr[i]=!arr[i];
    }
}
void girl(int num){
    int cnt=1;
    arr[num]=!arr[num];
    for(int i=1;arr[num+i]==arr[num-i];i++){
        if(num+i>n||num-i<1) break;
        arr[num+i]=!arr[num+i];
        arr[num-i]=!arr[num-i];
    }
    // for(int i=num-1;i>=1;i--){
    //     int p=2*cnt++;
    //     if(arr[i]==arr[i+p]){
    //         arr[i]=!arr[i+p];
    //         arr[i+p]=!arr[i+p];
    //     }
    //     else break;
    // }
    
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int g,num;
        cin>>g>>num;
        if(g==1){ // 남학생
            boy(num);
        }
        else if(g==2){ // 여학생
            girl(num);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
        if(i%20==0) cout<<"\n";
    }
    // cout<<"\n";
    return 0;
}
