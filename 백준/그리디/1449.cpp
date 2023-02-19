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
    int n,l;
    
    cin>>n>>l;
    vector<int> pos;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        pos.push_back(p);
    }
    sort(pos.begin(),pos.end());
    int limit=pos[0]-0.5+l;
    int before=pos[0];
    vector<int> v;
    int answer=0;
    for(int i=1;i<n;i++){
        if(l<=pos[i]-before) {
            before=pos[i];
            answer++;
        }
        // else if(before-0.5+l<pos[i]+0.5){
        //     before=pos[i];
        //     answer++;
        // }
       
    }
    
    cout<<answer+1<<"\n";
	return 0;
}