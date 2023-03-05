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
int n,k;
int gold[1001], silver[1001], bronze[1001];

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int num,g,s,b;
        cin>>num;
        cin>>gold[num]>>silver[num]>>bronze[num];
    }
    int rank=0;
    for(int i=1;i<=n;i++){
        if(gold[i]>gold[k]){
            rank++;
        }
        else if(gold[i]==gold[k]){
            if(silver[i]>silver[k]){
                rank++;
            }
            else if(silver[i]==silver[k]){
                if(bronze[i]>bronze[k]){
                    rank++;
                }
            }
        }
    }
    cout<<rank+1<<"\n";
    return 0;
}