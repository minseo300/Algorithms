#include<iostream>

using namespace std;

int n,m;
int cards[3][3];
int main(){
    freopen( "input.txt", "r", stdin);

    cin>>n>>m;
    for(int y=0;y<n;y++){
        for(int x=0;x<m;x++){
            cin>>cards[y][x];
        }
    }
    
    int maxi=-21e8;
    for(int y=0;y<n;y++){
        int mini=21e8;
        for(int x=0;x<m;x++){
            if(cards[y][x]<mini) mini=cards[y][x];
        }
        if(mini>maxi) maxi=mini;
    }
    cout<<maxi<<"\n";
   
}