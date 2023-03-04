#include <string>
#include <vector>
#include<iostream>
#include<cmath>
using namespace std;
long long Max(long long a, long long b){
    return a>b?a:b;
}
int opers[3]={0,1,2}; // +,-,*
int path[3];
int used[3];
vector<long long> arr;
vector<int> ops;
long long answer = 0;
long long cal(){
    vector<long long> for_cal=arr;
    vector<int> for_ops=ops;
   
    int i=0;
    long long ret=0;
    for(int j=0;j<3;j++){
        for(i=0;i<for_ops.size();i++){
            long long caled=0;
            if(for_ops[i]==path[j]){
                if(path[j]==0){
                    caled=for_cal[i]+for_cal[i+1];
                }
                else if(path[j]==1){
                    caled=for_cal[i]-for_cal[i+1];
                }
                else if(path[j]==2){
                    caled=for_cal[i]*for_cal[i+1];
                }
                for_cal[i]=caled;

                for_cal.erase(for_cal.begin()+i+1);
                for_ops.erase(for_ops.begin()+i);
                i--;
            }
        }
    }
    ret=abs(for_cal[0]);
    
    return ret;
}

void dfs(int lev){
    if(lev==3){
        long long ret=cal();
        answer=Max(answer,ret);
        return;
    }
    
    for(int i=0;i<3;i++){
        if(used[i]==1) continue;
        
        used[i]=1;
        path[lev]=opers[i];
        dfs(lev+1);
        used[i]=0;
    }
}


long long solution(string expression) {
    
    int slen=expression.length(),s=0;
    for(int i=0;i<slen;i++){
        if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'){
            long long num=stoll(expression.substr(s,i-s));
            s=i+1;
            arr.push_back(num);
            if(expression[i]=='+'){
                ops.push_back(0);
            }
            else if(expression[i]=='-'){
                ops.push_back(1);
            }
            else if(expression[i]=='*'){
                ops.push_back(2);
            }
        } 
    }
   
    arr.push_back(stoll(expression.substr(s,slen-s)));
    
    
    dfs(0);
    return answer;
}