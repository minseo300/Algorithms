#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

priority_queue<int> pq;
int main(){
    freopen( "input.txt", "r", stdin);

    int n;
    cin>>n;
    int arr[5];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        //int x;
        //cin>>x;
        //pq.push(x);
    }
    sort(arr,arr+n);
    int cnt=0,result=0;
    for(int i=0;i<n;i++){
        cnt++;
        if(cnt>=arr[i]){ // 현재 그룹에 포함된 모험가의 수가 현재의 공포도 이상이라면
            result++;
            cnt=0;
        }
    }
    // while(!pq.empty()){
    //     int q=pq.top();
    //     pq.pop();
    //     for(int i=0;i<q-1;i++){
    //         pq.pop();
    //     }

    //     cnt++;
    // }
    cout<<result<<"\n";




    return 0;
}