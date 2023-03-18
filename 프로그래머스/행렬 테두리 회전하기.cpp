#include <string>
#include <vector>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;
int map[101][101];
int temp[101][101];
vector<int> v;
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int num=1;
    for(int r=1;r<=rows;r++){
        for(int c=1;c<=columns;c++){
            map[r][c]=num++;
        }
    }
    for(int i=0;i<queries.size();i++){
        int y1=queries[i][0];
        int x1=queries[i][1];
        int y2=queries[i][2];
        int x2=queries[i][3];
        v.clear();
        memcpy(temp,map,sizeof(map));
        for(int i=y2;i>y1;i--) {
            map[i][x2]=temp[i-1][x2];
            v.push_back(temp[i-1][x2]);
        }
        for(int i=x1;i<x2;i++) {
            map[y2][i]=temp[y2][i+1];
            v.push_back(temp[y2][i+1]);
        }
        for(int i=y1;i<y2;i++) {
            map[i][x1]=temp[i+1][x1];
            v.push_back(temp[i+1][x1]);
        }
        for(int i=x2;i>x1;i--) {
            map[y1][i]=temp[y1][i-1];
            v.push_back(temp[y1][i-1]);
        }
        sort(v.begin(),v.end());
        answer.push_back(v[0]);
        // for(int i=1;i<=rows;i++){
        //     for(int j=1;j<=columns;j++) cout<<map[i][j]<<" ";
        //     cout<<"\n";
        // }
        
    }
    return answer;
}