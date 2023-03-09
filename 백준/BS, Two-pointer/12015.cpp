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
vector<int> arr;
vector<int> ans;
void bs(int num){
    int s=0, e=ans.size()-1;
    int ret=21e8;
    while(s<=e){
        int mid=(s+e)/2;
        printf("mid: %d ret:%d num:%d ans[mid]:%d\n",mid,ret,num,ans[mid]);
        if(ans[mid]>=num){
            if(ret>mid) ret=mid;
            e=mid-1;
        }
        else s=mid+1;
    }

    ans[ret]=num;
}
void find(){
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(ans.back()<arr[i]){
            ans.push_back(arr[i]);
        }
        else{
            bs(arr[i]);
        }
    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    for(int i=0;i<n;i++){
        int nn;
        cin>>nn;
        arr.push_back(nn);
    }

    find();
    cout<<ans.size()<<"\n";


    return 0;
}