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
unordered_map<int,int> um;
int n,m;
int cardCnt=0;

int bs(int start,int end,int target){
    int cnt=0;
    while(start<=end){
        int mid=(start+end)/2;
        if(cards[mid]==target) {
            cnt=um[target];
            break;
        }
        else{
            if(target<cards[mid]) end=mid-1;
            else if(target>cards[mid]) start=mid+1;
        }
        
    }

    return cnt;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n;
    
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        if(um.count(c)==0) {
            um[c]=1;
            cards.push_back(c);
            cardCnt++;
        }
        else um[c]=um[c]+1;
    }
   
    sort(cards.begin(),cards.end());
   
    cin>>m;
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        int s=0,e=cardCnt;
        int answer=bs(s,e,num);
        cout<<answer<<" ";
    }
	return 0;
}