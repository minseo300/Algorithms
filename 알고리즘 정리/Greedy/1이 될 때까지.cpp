#include<iostream>

using namespace std;

int n,k;
int main(){
    freopen( "input.txt", "r", stdin);

    cin>>n>>k;

    int cnt=0;

    while(n>1){
        if(n%k==0){
            n=n/k;
        }
        else{
            n=n-1;
        }
        cnt++;
    }
    
    cout<<cnt<<"\n";

    // 교재 코드
    while(n>=k){
        while(n%k!=0){
            n--;
            cnt++;
        }
        n=n/k;
        cnt++;
    }
    while(n>1){
        n--;
        cnt++;
    }
    cout<<cnt<<"\n";

    // 효율
    int target=0;
    while(true){
        // n==k로 나누어 떨어지는 수가 될때까지 1씩 빼기
        target=(n/k)*k;
        cnt+=(n-target);
        n=target;

        if(n<k) break;
        cnt+=1;
        n=n/k;
    }
    // 마지막으로 남은 수에 대하여 1씩 빼기
    cnt+=(n-1);
    cout<<cnt<<"\n";
}