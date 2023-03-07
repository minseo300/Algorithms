#include <string>
#include <vector>
#include<iostream>
#include<cmath>
using namespace std;
struct Node{
    int index,num;
};
int solution(string s) {
    int answer = 0;
    int len=s.length();
    int numIndex=0;
    vector<Node> nums;
    
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            nums.push_back({numIndex++,s[i]-'0'});
        }
        else{
            string num="";
            for(int j=i;j<len;j++){
                num+=s[j];
                if(num=="one"){
                    nums.push_back({numIndex++,1});
                    i=j;
                    break;
                }
                else if(num=="zero"){
                    nums.push_back({numIndex++,0});
                    i=j;
                    break;

                }
                else if(num=="two"){
                    nums.push_back({numIndex++,2});
                    i=j;
                    break;
                }
                else if(num=="three"){
                    nums.push_back({numIndex++,3});
                    i=j;
                    break;
                }
                else if(num=="four"){
                    nums.push_back({numIndex++,4});
                    i=j;
                    break;
                }
                else if(num=="five"){
                    nums.push_back({numIndex++,5});
                    i=j;
                    break;
                }
                else if(num=="six"){
                    nums.push_back({numIndex++,6});
                    i=j;
                    break;
                }
                else if(num=="seven"){
                    nums.push_back({numIndex++,7});
                    i=j;
                    break;
                }
                else if(num=="eight"){
                    nums.push_back({numIndex++,8});
                    i=j;
                    break;
                }
                else if(num=="nine"){
                    nums.push_back({numIndex++,9});
                    i=j;
                    break;
                }
            }
        }
    
    }
    for(int i=0;i<nums.size();i++){
        answer+=pow(10,nums.size()-nums[i].index-1)*nums[i].num;
        // cout<<nums[i].num<<" "<<nums[i].index<<"\n";
    }
    
    return answer;
}