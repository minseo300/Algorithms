#include <string>
#include <vector>
#include<iostream>
#include<cmath>
using namespace std;
string ret="";
bool isPrime(long long num){
    if(num<2) return false;
    for(int i=2;i<=sqrt(num);i++){
        if(num%i==0) return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    while(n){
        ret+=to_string(n%k);
        n=n/k;
    }
    ret=string(ret.rbegin(),ret.rend());
    string str="";
    for(char c:ret){
        if(c=='0'){
            if(str.length()==0) continue;
            if(isPrime(stol(str))==true) answer++;
            str="";
        }
        else str+=c;
    }
    if(str.length()!=0) {
        if(isPrime(stol(str))==true) answer++;
    }
    return answer;
}