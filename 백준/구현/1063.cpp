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

int map[9][9];
string stone,king;
int n;
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>king>>stone>>n;
    int kx=king[0]-'A'+1;
    int ky=king[1]-'0';
    int sx=stone[0]-'A'+1;
    int sy=stone[1]-'0';
    // printf("-sy: %d sx: %d\n",sy,sx);

    string order;
    for(int i=0;i<n;i++){
        // printf("ky: %d kx: %d\n",ky,kx);
        // printf("sy: %d sx: %d\n",sy,sx);
        cin>>order;
        int dy,dx,dsy,dsx;
        if(order=="R"){
            dx=kx+1; dsx=sx+1;
            dy=ky; dsy=sy;
        }
        else if(order=="L"){
            dx=kx-1; dsx=sx-1;
            dy=ky; dsy=sy;
        }
        else if(order=="B"){
            dy=ky-1; dsy=sy-1;
            dx=kx; dsx=sx;
        }
        else if(order=="T"){
            dy=ky+1; dsy=sy+1;
            dx=kx; dsx=sx;
        }
        else if(order=="RT"){
            dy=ky+1; dsy=sy+1;
            dx=kx+1; dsx=sx+1;
        }
        else if(order=="LT"){
            dy=ky+1; dsy=sy+1;
            dx=kx-1; dsx=sx-1;
        }
        else if(order=="RB"){
            dy=ky-1; dsy=sy-1;
            dx=kx+1; dsx=sx+1;
        }
        else if(order=="LB"){
            dy=ky-1; dsy=sy-1;
            dx=kx-1; dsx=sx-1;
        }

        if(dy==sy&&dx==sx){
            if(dy<1||dx<1||dy>8||dx>8||dsy<1||dsx<1||dsy>8||dsx>8) continue;
            else{
                kx=dx; ky=dy;
                sy=dsy; sx=dsx;
            }
        }
        else{
            if(dy<1||dx<1||dy>8||dx>8) continue;
            else{
                kx=dx; ky=dy;
            }
        }
    }
    // cout<<sx;
    cout<<(char)(kx+'A'-1)<<ky<<"\n"<<(char)(sx+'A'-1)<<sy<<"\n";
 
    return 0;
}
