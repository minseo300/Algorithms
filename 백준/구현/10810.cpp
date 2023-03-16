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
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m;
    for(int a=0;a<m;a++){
        int i,j,k;
        cin>>i>>j>>k;
        for(int b=i;b<=j;b++){
            arr[b]=k;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<"\n";
    return 0;
}
