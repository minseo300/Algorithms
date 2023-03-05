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
bool is_vowel(char c){
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}
int check(string s){
    int slen=s.length();
    int flag=0;
    int con=0;
    int vow=0;

    for(int i=0;i<slen;i++){
        if(is_vowel(s[i])){
            flag=1;
            vow++;
            con=0;
        }
        else{
            con++;
            vow=0;
        }
        if(con==3||vow==3){
            return 0;
        }
        if(i>0&&s[i-1]==s[i]&&!(s[i]=='e'||s[i]=='o')) return 0;
    }
    if(!flag) return 0;
    return 1;
  
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    string s;
    while(true){
        cin>>s;
        if(s=="end") break;

        if(check(s)) cout<<"<"<<s<<"> is acceptable.\n";
        else  cout<<"<"<<s<<"> is not acceptable.\n";
    }


    return 0;
}