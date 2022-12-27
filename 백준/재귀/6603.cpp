#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int acc[50]={0,};
int path[6];
vector<int> arr;
void initialize(){
    for(int i=0;i<50;i++) acc[i]=0;
    for(int i=0;i<6;i++) path[i]=0;
    arr.clear();
}
void run(int lev){
    if(lev==6){
        for(int i=0;i<6;i++) cout<<path[i]<<" ";
        cout<<"\n";
        return;
    }

    int size=arr.size();
    for(int i=0;i<size;i++){
        if(acc[arr[i]]==1) continue;
        if(lev>0&&path[lev-1]>arr[i]) continue;
        acc[arr[i]]=1;
        path[lev]=arr[i];
        run(lev+1);
        acc[arr[i]]=0;
        path[lev]=0;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);

    while(1){
        int k;
        cin>>k;
        if(k==0) break;

        for(int i=0;i<k;i++){
            int n;
            cin>>n;
            arr.push_back(n);
        }
        run(0);
        cout<<"\n";
        initialize();

    }
    return 0;
}