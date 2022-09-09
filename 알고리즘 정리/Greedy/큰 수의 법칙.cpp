#include<iostream>

using namespace std;
struct Node{
    int index,cnt;
};
Node acc[8];
int main(){
    freopen( "input.txt", "r", stdin);

    int n,m,k;
    cin>>n>>m>>k;

    int map[5];
    for(int i=0;i<n;i++){
        cin>>map[i];
    }
    sort(map,map+n,greater<int>());
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(acc[i-1].index==j&&acc[i-1].cnt==k) continue;
            else if(acc[i-1].index==j&&acc[i-1].cnt<k){
                acc[i]={j,acc[i-1].cnt+1};
                break;
            }
            else{
                acc[i].index=j;
                acc[i].cnt=acc[i].cnt+1;
                break;
            }
        }
    }
    int result=0;
    for(int i=0;i<m;i++){
        result+=map[acc[i].index];
    }
    cout<<result<<"\n";

    // 교재 코드
    int first=map[0];
    int second=map[1];

    result=0;

    int count=int (m/(k+1))*k;
    count+=m%(k+1);

    result+=(count)*first;
    result+=(m-count)*second;

    cout<<result<<"\n";
}