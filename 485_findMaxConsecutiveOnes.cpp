//485. 最大连续 1 的个数
#include <iostream>
#include<cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include<set>
#include<map>
#include<unordered_set>
#include <unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
		vector<int> vec(2);
		int len = nums.size();
		int left = 0, right = 0;
		int count = 0;	// 记录最大连续1的个数 
		while(right < len){
			vec[nums[right]]++;
			if(nums[right] == 1){
				count = max(count,vec[1]);
			}
			else if(nums[right] != 1){
				vec[1] -= (right-left);
				left = right + 1;  
			}
			right++;
		}
		return count;
    }
};
int main(){
	vector<int> nums = {0,0,0,0,1,1,0,0,1,1,1,0};
//	int target = 3;
	Solution s = Solution();
	printf("%d",s.findMaxConsecutiveOnes(nums));
	
}
