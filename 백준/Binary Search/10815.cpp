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

vector<int> cards;
int bs(int s,int e,int target){
    int check=0;
    while(s<=e){
        int mid=(s+e)/2;

        if(cards[mid]==target){
            check=1;
            break;
        }
        else{
            if(target<cards[mid]) e=mid-1;
            else if(target>cards[mid]) s=mid+1;
        }
    }
    return check;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        cards.push_back(c);
    }
    sort(cards.begin(),cards.end());
    cin>>m;
    vector<int> nums;
    for(int i=0;i<m;i++){
        int nn;
        cin>>nn;
        int s=0,e=n;
        int exist=bs(s,e,nn);
        cout<<exist<<" ";
    }
	return 0;
}