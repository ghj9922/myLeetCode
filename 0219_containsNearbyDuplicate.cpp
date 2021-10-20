//219. 存在重复元素 II
#include <iostream>
#include<cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include<set>
#include<unordered_set>
#include <unordered_map>
#include<string>
using namespace std;


class Solution {
public:
//	滑动窗口 用set实现 
    bool containsNearbyDuplicate_1(vector<int>& nums, int k) {
		int start = 0, end =0;
		int n = nums.size();
		if(n==0){
			return false;
		}
        if(k==0){
            return false;
    	}
        unordered_set<int> st;
		for(int i=0;i<n;i++){
			if(st.find(nums[i])!=st.end()) return true;
			st.insert(nums[i]);
			if(st.size()>k) st.erase(nums[i-k]);
		}
		return false;
	}
};


int main(){
	vector<int> nums = {1,2,1};
	int target = 3;
	Solution s = Solution();
	printf("%d",s.containsNearbyDuplicate(nums,target));
	
}
