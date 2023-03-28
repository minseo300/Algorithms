#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";
    int len=new_id.length();
    
    // 1단계
    for(int i=0;i<len;i++){
        if(new_id[i]>='A'&&new_id[i]<='Z') new_id[i]+=32;
    }
    // 2단계
    for(int i=0;i<len;i++){
        if(!(new_id[i]=='-'||new_id[i]=='_'||new_id[i]=='.'||(new_id[i]>='0'&&new_id[i]<='9')||(new_id[i]>='a'&&new_id[i]<='z'))) new_id[i]='A';
    }
    new_id.erase(remove(new_id.begin(),new_id.end(),'A'),new_id.end());
    // cout<<new_id<<"\n"; 
    // 3단계
    len=new_id.length();
    for(int i=0;i<len;i++){
        if(new_id[i]=='.'){
            int beforeIdx=i;
            for(int j=i+1;j<len;j++){
                if(new_id[j]=='.'&&j-beforeIdx==1){
                    new_id[j]='A';
                    beforeIdx=j;
                }
                else if(new_id[j]=='.'&&j-beforeIdx>1) break;
            }
        }
    }
    new_id.erase(remove(new_id.begin(),new_id.end(),'A'),new_id.end());
    // 4단계
    len=new_id.length();
    if(new_id[0]=='.') new_id.erase(new_id.begin());
    if(new_id[len-1]=='.') new_id.erase(new_id.end()-1);
    // 5단계
    if(new_id.length()==0) new_id+='a';
    // 6단계
    if(new_id.length()>=16){
        new_id.erase(15,new_id.length()-15);
    }
    if(new_id[new_id.length()-1]=='.') new_id.erase(new_id.length()-1,1);
    if(new_id.length()<=2){
        char c=new_id[new_id.length()-1];
        while(new_id.length()<3){
            new_id+=c;
        }
    }
    answer=new_id;
    return answer;
}