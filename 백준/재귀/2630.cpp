#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int zero,one;
vector<vector<int> > map;
bool check(int sy,int sx,int size){
    int first=map[sy][sx];
    for(int y=sy;y<sy+size;y++){
        for(int x=sx;x<sx+size;x++){
            if(map[y][x]!=first) return false;
        }
    }
    return true;
}
void run(int round,int sy,int sx){
    if(pow(2,round)==n){
        if(map[sy][sx]==1) one++;
        else zero++;
        return;
    }

    int size=n/pow(2,round);
    int o=0,z=0;
    for(int y=sy;y<sy+size;y++){
        for(int x=sx;x<sx+size;x++){
            if(map[y][x]==1) o++;
            else z++;
        }
    }
    if(check(sy,sx,size)){ // 다 똑같은 경우
        if(map[sy][sx]==1) one++;
        else zero++;
    }
    else{
        run(round+1,sy,sx); // 왼쪽 위
        run(round+1,sy,sx+size/2); // 오른쪽 위
        run(round+1,sy+size/2,sx); // 왼쪽 아래
        run(round+1,sy+size/2,sx+size/2); // 오른쪽 아래
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin>>n;

    map.assign(n,vector<int>(n));

    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            cin>>map[y][x];
            if(map[y][x]==1) one++;
            else zero++;
        }
    }
    if(one==pow(n,2)) {
        cout<<"0\n1\n";
        return 0;
    }
    else if(zero==pow(n,2)){
        cout<<"1\n0\n";
        return 0;
    }
    else{
        one=0;
        zero=0;
        run(1,0,0);
        run(1,0,n/2);
        run(1,n/2,0);
        run(1,n/2,n/2);
    }
    
    cout<<zero<<"\n"<<one<<"\n";
    return 0;
}