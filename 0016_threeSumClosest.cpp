#include <iostream>
#include<cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include<set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	//自己写的暴力法 通过 但是时间和内存都不ok  
	// 双指针有点问题 
    int threeSumClosest(vector<int>& nums, int target) {
		int dis = 1000000000;
		int res = 0;
		sort(nums.begin(),nums.end());
		for(int a=0;a<nums.size();a++){
			for(int b=a+1;b<nums.size();b++){
				int c = nums.size()-1;
				while(b<c){
					int sum = nums[a]+nums[b]+nums[c];
					int tmp = abs(target-sum);
					if( tmp < dis ){
						dis = tmp;
						res = nums[a]+nums[b]+nums[c];
					}
					c--;
				}
			}
		}
		return res;
    }

	//双指针  
    int threeSumClosest_2(vector<int>& nums, int target) {
		int dis = 1000000000;
		int res = 0;
		sort(nums.begin(),nums.end());
		for(int a=0;a<nums.size();a++){
			int c = nums.size()-1;
			while(b<c){
				int sum = nums[a]+nums[b]+nums[c];
				int tmp = abs(target-sum);
//				cout<<nums[a]<<" "<<nums[b]<<" "<<nums[c]<<" = "<<sum<<" | "<<tmp<<endl;
				if(tmp < dis){
					dis = tmp;
					res = sum;
					c--; 
				}
				if(tmp >= dis){
					b++;
				}			
			}
			}
		}
		return res;
    }
};


int main(){
	vector<int> nums = {0,2,1,-3};
	int target = 1;
	Solution s = Solution();
	int res = s.threeSumClosest(nums,target);
	printf("%d\n",res);

}
