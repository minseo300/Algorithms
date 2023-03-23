#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    int start,end;
};
bool cmp(Node t, Node v){
    return t.start<v.start;
}

priority_queue<Node> q;
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<Node> times;
    for(int i=0;i<book_time.size();i++){
        int start=stoi(book_time[i][0].substr(0,2))*60+stoi(book_time[i][0].substr(3,2));
        int end=stoi(book_time[i][1].substr(0,2))*60+stoi(book_time[i][1].substr(3,2))+10;
        times.push_back({start,end});
    }
    sort(times.begin(),times.end(),cmp);
    vector<int> rooms;
    rooms.push_back(times[0].end);
    answer++;
    for(int i=1;i<times.size();i++){
        // cout<<times[i].start<<" "<<times[i].end<<"\n";
        int flag=0;
        for(int j=0;j<rooms.size();j++){
            // cout<<"-"<<rooms[j]<<"\n";
            if(rooms[j]<=times[i].start){
                rooms[j]=times[i].end;
                flag=1;
                break;
            }
        }
        if(flag==0) {
            rooms.push_back(times[i].end);
            answer++;
        }
        sort(rooms.begin(),rooms.end());
    }
    
    return answer;
}