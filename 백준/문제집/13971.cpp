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

int h,w,n,m;

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>h>>w>>n>>m;

    int a=(h-1)/(n+1)+1;
    int b=(w-1)/(m+1)+1;

    cout<<a*b<<"\n";



    
    
    return 0;
}