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
string map[4];
int k;
int rotationDir[4];

void rotateLeft(int num,int dir){
    if(num<=0) return;

    if(map[num][6]!=map[num-1][2]) {
        rotationDir[num-1]=dir*-1;
        rotateLeft(num-1,dir*-1);
    }
    
}
void rotateRight(int num,int dir){
    if(num>=3) return;

    if(map[num][2]!=map[num+1][6]){
        rotationDir[num+1]=dir*-1;
        rotateRight(num+1,dir*-1);
    }
}
void rotation(int num,int dir){
    // cout<<"num: "<<num<<" dir: "<<dir<<"\n";
    // cout<<map[num]<<"\n";
    if(dir==-1){
       string s=map[num].substr(1,7)+map[num].substr(0,1);
       map[num]=s;
    }
    else if(dir==1){
        string s=map[num].substr(7)+map[num].substr(0,7);
        map[num]=s;
    }
}
void check(int num,int dir){
     rotationDir[num]=dir;
    rotateLeft(num,dir);
    rotateRight(num,dir);
    for(int i=0;i<4;i++){
        rotation(i,rotationDir[i]);
    }
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    string s;
    for(int i=0;i<4;i++){
       cin>>map[i];
    }
    int score=0;
    cin>>k;
    for(int i=0;i<k;i++){
        int n,dir;
        cin>>n>>dir;
        // cout<<n<<" "<<dir<<"\n";
        memset(rotationDir,0,sizeof(rotationDir));
        check(n-1,dir);
        
    }
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<8;j++){
    //         cout<<map[i][j];
    //     }
    //     cout<<"\n";
    // }
    int mul = 1;
	for (int i = 0; i < 4; i++) {
		score += (map[i][0] - '0') * mul;
		mul *= 2;
	}
    cout<<score<<"\n";
    return 0;
}
