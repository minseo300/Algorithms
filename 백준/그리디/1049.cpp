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
    int n,m;
    vector<int> ps; // 패키지 가격
    vector<int> ss; // 낱개 가격
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int p,s;
        cin>>p>>s;
        ps.push_back(p); ss.push_back(s*6);
    }

    sort(ps.begin(),ps.end());
    sort(ss.begin(),ss.end());

    int answer=0,lines=0;

    while(n>0){
        int p,s,get,line;
        if(n>=6){
            p=ps[0]; s=ss[0];
            line=6;
        }
        else{
            p=ps[0];
            s=ss[0]/6*n;
            if(s<p) line=n;
            else line=6;
        }
        get=p<s?p:s;
        answer+=get;
        n-=line;
    }
    cout<<answer<<"\n";



	return 0;
}