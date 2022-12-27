#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<vector<int> > map;
int n,zero=0,one=0;
string ans;
void run(int round,int sy,int sx){
    if(pow(2,round)==n){
        ans.append(to_string(map[sy][sx]));
        return ;
    }
    int size=n/(pow(2,round+1));
    int z=0,o=0;
    for(int y=sy;y<sy+size;y++){
        for(int x=sx;x<sx+size;x++){
            if(map[y][x]==0) z++;
            else o++;
        }
    }
    if(z==pow(size,2))  ans.append("0");
    else if(o==pow(size,2)) ans.append("1");

    else {
        ans.append("(");
        run(round+1,sy,sx); // 왼쪽 위
        run(round+1,sy,sx+size/2); // 오른쪽 위
        run(round+1,sy+size/2,sx); // 왼쪽 아래
        run(round+1,sy+size/2,sx+size/2); // 오른쪽 아래
        ans.append(")");
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin>>n;

    map.assign(n,vector<int>(n));
    for(int y=0;y<n;y++){
        string row;
        cin>>row;
        for(int x=0;x<n;x++){
            map[y][x]=row[x]-'0';
            if(map[y][x]==0) zero++;
            else one++;
        }
    }

    if(zero==pow(n,2)) {
        cout<<"0\n";
        return 0;
    }
    else if(one==pow(n,2)) {
        cout<<"1\n";
        return 0;
    }
    else {
    
        run(0,0,0);
        run(0,0,n/2);
        run(0,n/2,0);
        run(0,n/2,n/2);
    }

    cout<<"("<<ans<<")\n";
    return 0;
}