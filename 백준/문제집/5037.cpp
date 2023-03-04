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


int main() {
    freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ////////////////////// 입력
    vector<int> nums(3);
    while(true){
        cin>>nums[0]>>nums[1]>>nums[2];
        
        if(nums[0]==0&&nums[1]==0&&nums[2]==0) break;

        sort(nums.begin(),nums.end());
        // cout<<nums[0]<<nums[1]<<nums[2]<<"\n";
        if(nums[0]+nums[1]<=nums[2]){
            cout<<"Invalid\n";
            continue;
        }

        if(nums[0]==nums[1]&&nums[1]==nums[2]&&nums[0]==nums[2]){
            cout<<"Equilateral\n";
            continue;
        }
        if(nums[0]==nums[1]||nums[1]==nums[2]||nums[0]==nums[2]){
            cout<<"Isosceles\n";
            continue;
        }
        if(nums[0]!=nums[1]&&nums[1]!=nums[2]&&nums[0]!=nums[2]){
            cout<<"Scalene\n";
            continue;
        }

        
    }



    
    
    return 0;
}