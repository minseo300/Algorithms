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

int t,n,m;
vector<int> arr1,arr2;
int main()
{
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    cin>>t;
    int num;
    for(int i=0;i<t;i++){
        cin>>n;
        arr1.clear(); arr2.clear();
        for(int j=0;j<n;j++){
            cin>>num;
            arr1.push_back(num);
        }
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>num;
            arr2.push_back(num);
        }

        sort(arr1.begin(),arr1.end());
        for(int j=0;j<arr2.size();j++){
            int target=arr2[j];
            int start=0,end=arr1.size()-1;
            int flag=0;
            while(start<=end){
                int mid=(start+end)/2;

                if(arr1[mid]==target){
                    flag=1;
                    break;
                }
                if(arr1[mid]<target) start=mid+1;
                else if(arr1[mid]>target) end=mid-1;
            }
            cout<<flag<<"\n";
        }



    }



    return 0;
}
