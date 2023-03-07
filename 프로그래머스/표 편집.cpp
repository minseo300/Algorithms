#include <string>
#include <vector>
#include<iostream>
#include<stack>
using namespace std;
struct Node{
    int val=-1,prev=-1,next=-1;
};
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    Node node[n];
    stack<Node> deleted;
    for(int i=0;i<n;i++){
        answer+="O";
        node[i].val=i;
        if(i>0) node[i].prev=i-1;
        if(i<n-1) node[i].next=i+1;
    }
    for(int i=0;i<cmd.size();i++){
        string s=cmd[i];
        // cout<<"cmd:"<<s<<"\n";
        string c=s.substr(0,1);
        for(int j=0;j<n;j++){
            cout<<node[j].val<<" "<<node[j].prev<<" "<<node[j].next<<"\n";
        }
        cout<<"\n";
        cout<<"---K: "<<k<<"\n";
        switch(c[0]){
            
                
            case 'U':{
                int num=stoi(s.substr(2));
                cout<<"u\n";
                while(num--){
                    k=node[k].prev;
                    // cout<<"k: "<<k<<"\n";
                }
                // cout<<"\n";
                break;
            }
            case 'D':{
                int num=stoi(s.substr(2));
                while(num--){
                    k=node[k].next;
                }
                break;
            }
            case 'C':{
                int next=node[k].next;
                int prev=node[k].prev;
                deleted.push(node[k]);
                if(prev>-1) node[prev].next=next;
                if(next>-1) node[next].prev=prev;
                k=next>-1?next:prev;
                break;
            }
            case 'Z':{
                Node re=deleted.top();
                
                if(re.prev>-1) node[re.prev].next=re.val;
                if(re.next>-1) node[re.next].prev=re.val;
                deleted.pop();
                break;
            }
        }
       
    }
    while(!deleted.empty()){
        int top=deleted.top().val;
        deleted.pop();
        answer[top]='X';
    }
    return answer;
}