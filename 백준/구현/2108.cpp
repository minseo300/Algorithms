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

bool cmp(pair<int,int> &t, pair<int,int> &v){
    if(t.second==v.second) return t.first<v.first;
    return t.second>v.second;
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n;
    cin>>n;
    vector<int> v;
    unordered_map<int,int> m;
    int total=0;
    for(int i=0;i<n;i++){
        int nn;
        cin>>nn;
        v.push_back(nn);
        if(m.count(nn)==0) m[nn]=1;
        else m[nn]=m[nn]+1;
        total+=nn;
    }
    sort(v.begin(),v.end());
    int avg=round((float)total/n);
    int mid=v[n/2];
    vector<pair<int,int>> q(m.begin(),m.end());
    sort(q.begin(),q.end(),cmp);
    int most;
    if(q[0].second==q[1].second) most=q[1].first;
    else most=q[0].first;
    int range=v[n-1]-v[0];
    
    cout<<avg<<"\n"<<mid<<"\n"<<most<<"\n"<<range<<"\n";

	return 0;
}