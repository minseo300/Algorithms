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
struct Node{
    int order,rec,num;
};
bool compare1(Node t,Node v){
    if(t.rec==v.rec) return t.order<v.order;
    return t.rec<v.rec;
}
bool compare2(Node t,Node v){
    return t.num<v.num;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>k;
    vector<Node> arr;
    for(int i=0;i<k;i++){
        int num;
        cin>>num;
        int flag=0, jj=0;
        for(int j=0;j<arr.size();j++){
            if(arr[j].num==num){
                flag=1;
                jj=j;
                break;
            }
        }
        if(flag==1) arr[jj].rec++;
        else{
            if(arr.size()<n) arr.push_back({i,1,num});
            else{
                vector<Node> temp=arr;
                sort(temp.begin(),temp.end(),compare1);
                for(int j=0;j<arr.size();j++){
                    if(arr[j].num==temp[0].num){
                        arr.erase(arr.begin()+j);
                    }
                }
                arr.push_back({i,1,num});
            }
        }
    }
    sort(arr.begin(),arr.end(),compare2);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i].num<<" ";
    }

    cout<<"\n";
    return 0;
}
