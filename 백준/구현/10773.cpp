#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <stack>
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    int k;
    stack<int> s;
    cin>>k;
    for(int i=0;i<k;i++){
        int num;
        cin>>num;
        if(num!=0) s.push(num);
        else if(num==0) s.pop();
    }
    int answer=0;
    while(!s.empty()){
        answer+=s.top();
        s.pop();
    }
    cout<<answer<<"\n";

	return 0;
}