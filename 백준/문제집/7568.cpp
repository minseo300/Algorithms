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
int height[51], weight[51];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>weight[i]>>height[i];
    }
    for(int i=1;i<=n;i++){
        int rank=0;
        for(int j=1;j<=n;j++){
            if(height[i]<height[j]&&weight[i]<weight[j]){
                rank++;
            }
        }
        cout<<rank+1<<" ";
    }
    return 0;
}