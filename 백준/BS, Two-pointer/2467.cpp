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
vector<int> liq;

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int i=0;i<n;i++){
        int l;
        cin>>l;
        liq.push_back(l);
    }

    sort(liq.begin(),liq.end());
  
    int s=0,e=n-1;
    int answer[2];
    int min=21e8;
    while(s<e){
        int sum=liq[s]+liq[e];

        if(abs(sum)<min){
            min=abs(sum);
            answer[0]=liq[s];
            answer[1]=liq[e];
            if(sum==0) break;
        }
        if(sum>0){
            e--;
        }
        else s++;
    }
    cout<<answer[0]<<" "<<answer[1]<<"\n";
    return 0;
}