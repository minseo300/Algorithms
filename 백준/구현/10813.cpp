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
    for(int i=1;i<=n;i++) arr[i]=i;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        swap(arr[x],arr[y]);
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
