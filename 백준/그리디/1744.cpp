#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n;
    int answer=0;
    vector<int> minus;
    vector<int> zero;
    vector<int> plus;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num==0) zero.push_back(num);
        else if(num>0) plus.push_back(num);
        else if(num<0) minus.push_back(num);
    }
    int minus_index=0;
    sort(minus.begin(),minus.end());
    
    while(minus_index<minus.size()){
        int first=minus[minus_index];
        if(minus_index+1>=minus.size()) {
            break;
        }
        int second=minus[minus_index+1];

        answer+=first*second;
        minus_index+=2;
    }

    if(minus.size()-minus_index>zero.size()) answer+=minus[minus_index];
    sort(plus.begin(),plus.end(),greater<int>());
    int plus_index=0;
    while(plus_index<plus.size()){
        int first=plus[plus_index];
        if(plus_index+1>=plus.size()){
            answer+=first;
            break;
        }
        int second=plus[plus_index+1];
        int sum=first+second;
        int mul=first*second;
        if(sum<mul){
            answer+=mul;
            plus_index+=2;
        }
        else{
            answer+=first;
            plus_index+=1;
        }
    }


    cout<<answer<<"\n";

	return 0;
}