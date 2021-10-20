//0209 minSubArrayLen
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
	// 暴力法 超时 
    int minSubArrayLen_1(int target, vector<int>& nums) {
		int minlen = 100000;
		vector<int> vec;
		int n = nums.size();
		int sum = 0;
		bool find = false;
//		int r = 0;	// 右指针 
		for(int i=0;i<n;i++){
			sum = 0;
			vec.clear();
			sum += nums[i];
			vec.push_back(nums[i]);
			if(sum >= target){	 
				minlen = vec.size();
				return minlen;
			}
			else{
				for(int j=i+1;j<n;j++){
					sum += nums[j];
					vec.push_back(nums[i]);
					if(sum >= target && minlen > vec.size()){
						minlen = vec.size();	
						find = true;
						break;					
					}
				}
			}
		}
		if(find == false) return 0;
		else return minlen;
    }
    
    int minSubArrayLen(int s, vector<int>& nums){
    	int n = nums.size();
    	if(n == 0){
    		return 0;
		}
		int ans = INT_MAX;
		for(int i=0;i<n;i++){
			int sum = 0;
			for(int j=i;j<n;j++){
				sum += nums[j];
				if(sum >= s){
					ans = min(ans,j-i+1);
					break;
				}
			}
		}
		return ans == INT_MAX? 0:ans;
		
	}
    
    // 官方解法2 前缀和+二分查找 O(nlogn) 
    int minSubArrayLen_2(int s, vector<int>& nums){
    	int n = nums.size();
    	if(n==0){
    		return 0;
		}
		int ans = INT_MAX;
		vector<int> sum(n+1,0);
		 // 为了方便计算，令 size = n + 1 
        // sums[0] = 0 意味着前 0 个元素的前缀和为 0
        // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
        // 以此类推
        for(int i=1;i<=n;i++){
        	sum[i] = sum[i-1] + nums[i-1];
		}
//		因为nums全是正数，所以sum是递增序列 
		for(int i=1;i<=n;i++){
			int target = s + sum[i-1];
			auto bound = lower_bound(sum.begin(),sum.end(),target);	// 二分查找 
			if(bound != sum.end()){
				ans = min(ans,static_cast<int>((bound-sum.begin())-(i-1)));
			}
		}
		return ans == INT_MAX ? 0:ans;
	}
	
	// 官方解法3 滑动窗口 
	int minSubArrayLen_3(int s, vector<int>& nums){
		int n = nums.size();
		if(n==0){
			return 0;
		} 
		int ans = INT_MAX;
		int start = 0, end = 0;
		int sum = 0;
		while(end < n){
			sum += nums[end];
			while(sum >= s){
				ans = min(ans,end-start+1);
				sum -= nums[start];
				start++;
			}
			end++;
		}
		return ans == INT_MAX? 0:ans;	
	}

};


int main(){
	vector<int> nums = {2,3,1,2,4,3};
	int target = 7;
	Solution s = Solution();
	printf("%d",s.minSubArrayLen(7,nums));
	
}
