#include<iostream>

using namespace std;


int main(){
    freopen( "input.txt", "r", stdin);

    char rc;
    int r,c;
    cin>>rc>>c;

    r=rc-'a';
    c=c-1;
    int direct[8][2]={
        -2,-1,
        -2,1,
        -1,2,
        1,2,
        -1,-2,
        1,-2,
        2,1,
        2,-1
    };
    int cnt=0;
    for(int d=0;d<8;d++){
        int dy=r+direct[d][0];
        int dx=c+direct[d][1];

        if(dy<0||dx<0||dy>=8||dx>=8) continue;
        cnt++;
    }
    cout<<cnt<<"\n";

}