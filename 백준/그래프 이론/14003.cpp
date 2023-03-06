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
struct Node{
    int num,idx;
};
vector<int> ans,stk;
vector<Node> idxs;
void change(int num){
    int s=0, e=ans.size()-1;
    int ret=21e8;
    while(s<=e){
        int mid=(s+e)/2;
        // cout<<"[mid] "<<mid<<"\n";
        // printf("num: %d ans[%d]:%d\n",num,mid,ans[mid]);
        if(ans[mid]>=num){
            // cout<<"--\n";
            if(ret>mid) ret=mid;
            e=mid-1;
        }
        else s=mid+1;
    }
    // cout<<"ret: "<<ret<<"\n";
    ans[ret]=num;
    idxs.push_back({num,ret});
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    
    int num;
    cin>>num;
    ans.push_back(num);
    idxs.push_back({num,0});
    for(int i=1;i<n;i++){
        cin>>num;
        // cout<<"-num: "<<num<<"\n";
        if(num>ans.back()) {
            ans.push_back(num);
            int idx=ans.size()-1;
            idxs.push_back({num,idx});
        }
        else change(num);
        
    }
    cout<<ans.size()<<"\n";
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<"\n";
    int cnt=ans.size()-1;
    for(int i=n-1;i>=0;i--){
        if(cnt==idxs[i].idx){
            stk.push_back(idxs[i].num);
            cnt--;
        }
    }
    for(int i=stk.size()-1;i>=0;i--){
        cout<<stk[i]<<" ";
    }
    return 0;
}