#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
double x,y,c;
double guessC(double mid){
    double h1=sqrt(pow(x,2)-pow(mid,2));
    double h2=sqrt(pow(y,2)-pow(mid,2));

    return (h1*h2)/(h1+h2);
}
int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>x>>y>>c;

    double start=0, end=min(x,y),ans=0;

    while(end-start>0.000001){
        double mid=(start+end)/2.0;

        if(guessC(mid)>=c){
            ans=mid;
            start=mid;
        }
        else end=mid;
    }
    printf("%.3lf\n",ans);
	return 0;
}