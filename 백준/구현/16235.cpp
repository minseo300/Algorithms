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

int n,m,k;

int add_nut[11][11];
int nut[11][11];
int diry[8]={-1,-1,-1,0,0,1,1,1};
int dirx[8]={-1,0,1,-1,1,-1,0,1};

struct Node{
    int y,x,age;
};
vector<int> map[11][11];
vector<Node> death;

void spring(){
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            sort(map[y][x].begin(),map[y][x].end());
        }
    }
   for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            // cout<<"-"<<map[y][x].size()<<"\n";
            for(int i=0;i<map[y][x].size();i++){
                if(nut[y][x]-map[y][x][i]>=0){
                    nut[y][x]-=map[y][x][i];
                    map[y][x][i]++;
                }
                else{
                    death.push_back({y,x,map[y][x][i]});
                    map[y][x].erase(map[y][x].begin()+i);
                    i--;
                }
            }
        }
   }
}
void summer(){
    for(int i=0;i<death.size();i++){
        Node now=death[i];
        nut[now.y][now.x]+=now.age/2;
    }
    death.clear(); death.resize(0);
}
void fall(){
    // cout<<"fall\n";
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            for(int i=0;i<map[y][x].size();i++){
                if(map[y][x][i]%5!=0) continue;
                for(int d=0;d<8;d++){
                    int dy=y+diry[d];
                    int dx=x+dirx[d];
                    if(dy<1||dx<1||dy>n||dx>n) continue;

                    map[dy][dx].push_back(1);
                }
            }
        }
    }
}
void winter(){
    // cout<<"winter\n";
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            nut[y][x]+=add_nut[y][x];
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>n>>m>>k;
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            cin>>add_nut[y][x];
            nut[y][x]=5;
        }
    }
   
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        map[x][y].push_back(z);
    }
    
    for(int i=0;i<k;i++){
        spring();
        summer();
        fall();
        winter();
        // cout<<"===========\n";
    }
    int answer=0;
    for(int y=1;y<=n;y++){
        for(int x=1;x<=n;x++){
            // cout<<map[y][x].size()<<"\n";
            answer+=map[y][x].size();
        }
    }
    cout<<answer<<"\n";
    return 0;
}
