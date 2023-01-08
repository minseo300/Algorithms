#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,c;

int main() {
    freopen("input.txt","r",stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>c;
    vector<int> house(n);
    for(int i=0;i<n;i++) cin>>house[i];

    sort(house.begin(),house.end());
    if(c==2){
        cout<<house[n-1]-house[0];
        return 0;
    }
    int start=1; int end=house[n-1]-house[0];
    int ret=0;
    while(start<=end){
        int mid=(start+end)/2;
        int install=1;
        int s=house[0];
        for(int i=1;i<n;i++){
            int e=house[i];
            if(e-s>=mid) {
                install++;
                s=e;
            }
        }
        if(install>=c){
            start=mid+1;
            ret=max(ret,mid);
        }
        else end=mid-1;
    }

    cout<<ret<<"\n";
	return 0;
}