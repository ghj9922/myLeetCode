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
    vector<vector<int>> threeSum(vector<int>& nums) {
    	int sum = 0;
    	sort(nums.begin(),nums.end());
    	vector<int> tmp;
    	set<vector<int>> res_set;
    	vector<vector<int>> res_vec;
		for (int i = 0; i<nums.size(); i++){
			for(int j = i+1; j<nums.size(); j++){
				for(int u = j+1; u<nums.size(); u++){
					sum =  nums[i]+ nums[j] + nums[u];
					if(sum == 0){
						tmp = {nums[i],nums[j],nums[u]};
						res_set.insert(tmp);
					}
					sum = 0;
				}
			}
		}
		res_vec.assign(res_set.begin(),res_set.end());
		return res_vec;
    }
    
    // 双指针 
    vector<vector<int>> threeSum_2(vector<int>& nums) {
    	int sum = 0;
    	sort(nums.begin(),nums.end());	// 从小到大排序 
    	vector<vector<int>> res;
    	for(int first=0; first<nums.size(); first++){
    		//若 nums[i]>0 因为已经排序好，所以后面不可能有三个数加和等于 0，直接返回结果。
			// 被选中a不应该和上一次选中的相同 
    		if(first>0 && nums[first] == nums[first-1]){
    			continue;
			} 
			int third = nums.size()-1;	// c的指针从最后一个数开始
			int target = sum-nums[first]; 
			for(int second=first+1; second<nums.size(); second++){
				if(second>first+1 && nums[second] == nums[second-1]){
					continue;
				}
				// 确定b，确保c的指针在b的右侧, 且  a+c+b>0
				while(second<third && nums[second]+nums[third]>target){
					third--;
				}
				// 若bc指针重合，则跳出循环 
				if(second == third){
					break;
				}
				if(nums[second]+nums[third] == target){
					res.push_back({nums[first],nums[second],nums[third]});
				}				
			}
		}
		return res; 		 
    }
};

int main(){
	vector<int> nums = {-1,0,1,2,-1,-4};
	Solution s = Solution();
	vector<vector<int>> res = s.threeSum_2(nums);
	printf("%d\n",res.size());
	for(int i = 0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
}
