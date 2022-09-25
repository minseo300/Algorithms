#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int cal(int f,int s){
    int a=f+s;
    int b=f*s;

    if(a>b) return a;
    else return b;
}
int main(){
    freopen( "input.txt", "r", stdin);

    string input;
    cin>>input;
    int result=0;

    result=cal(input[0]-'0',input[1]-'0');
    
    for(int i=2;i<input.length();i++){
        result=cal(result,input[i]-'0');
        int d=1;
    }

    cout<<result;

    return 0;
}