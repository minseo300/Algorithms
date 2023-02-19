#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;
struct Node{
    int m,v;
};

int dat[300001];
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int n,k; // 보석 개수, 가방 개수
    vector<int> bags; // 가방이 최대 담을 수 있는 무게
    vector<pair<int,int>> vec;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int m,v;
        cin>>m>>v;
        vec.push_back({m,v});
    }
    for(int i=0;i<k;i++){
        int c;
        cin>>c;
        bags.push_back(c);
    }
    
    ////////////////////// 정렬
    sort(vec.begin(),vec.end());
    sort(bags.begin(),bags.end());
    long long total=0L;
    priority_queue<int> q;
    int j=0;
    for(int i=0;i<k;i++){
        while(vec[j].first<=bags[i]&&j<n){
            q.push(vec[j].second);
            j++;
        }
        if(!q.empty()){
            total+=q.top();
            q.pop();
        }
        
    }
    
    cout<<total<<"\n";
	return 0;
}