#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen( "input.txt", "r", stdin);
    
    string input;
    cin>>input;

    int zero=0,one=0;
    for(int i=0;i<input.length();i++){
        if(input[i]-'0'==1 && input[i-1]-'0'==1) continue;
        else if(input[i]-'0'==1&&input[i-1]-'0'==0) zero++;
        else if(input[i]-'0'==0&&input[i-1]-'0'==0) continue;
        else if(input[i]-'0'==0&&input[i-1]-'0'==1) one++;
    }

    if(zero<one) cout<<zero<<"\n";
    else cout<<one<<"\n";

    


    return 0;
}