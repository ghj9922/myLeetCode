#include <iostream>
#include<cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// 普通做法，算法复杂度 O(N2) 
	vector<int> twoSum(vector<int>& nums, int target) {
		int sum = 0;
		vector<int> index;
		for (int i = 0; i < nums.size(); i++) {
			for(int j = i+1;j < nums.size();j++){
				sum = nums[i] + nums[j];
				if (sum == target) {
					index.push_back(i);
					index.push_back(j);
					return index;
				}
				sum = 0;				
			}
		}
		return index;
	}
	//哈希表 寻找 target - x
	vector<int> twoSum_2(vector<int>& nums, int target) {
		unordered_map<int,int> hashtable;
		for (int i=0; i < nums.size(); i++){
			auto it = hashtable.find(target-nums[i]);
			if(it != hashtable.end()){
				return {it->second, i};
			}
			hashtable[nums[i]] = i;
		}
		return {};
	}
};

int main() {
	Solution so = Solution();
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(3);
//	nums.push_back(15);
	int target = 6;
	vector<int> res = so.twoSum_2(nums, target);
	printf("%d %d",res[0],res[1]);
	return 0;
}

