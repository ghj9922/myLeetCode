//220. 存在重复元素 III
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
//	暴力 超时 
    bool containsNearbyAlmostDuplicate_1(vector<int>& nums, int k, int t) {
    	int n = nums.size();
    	if(n <= 1) return false;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				long tmp = abs(long(nums[i])-nums[j]);
				if(tmp <= t && abs(i-j) <= k){
					return true;
				}
			}
		}
		return false;
    }
    
     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
     	set<long> st;
     	int n = nums.size();
    	if(n <= 1) return false;
		for(int i=0;i<n;i++){
			auto iter = st.lower_bound(double(nums[i])-t);	// 找到第一个大于等于nums[i]-t的数 
//			cout<<double(nums[i])-t<<endl;
			if(iter!=st.end() && *iter<=double(nums[i])+t){		// 判断该数是否同时满足小于等于nums[i]+t 
				return true;
			}
			st.insert(nums[i]);
//			cout<<"nums"<<i<<" "<<nums[i]<<endl;
			if(st.size() > k){
//				cout<<"aa:"<<*st.begin()<<endl;
				st.erase(nums[i-k]);
			}
		}
		return false;
	 }
	 

    bool containsNearbyAlmostDuplicate_2(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<int> rec;
        for (int i = 0; i < n; i++) {
            auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t);
            if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
                return true;
            }
            rec.insert(nums[i]);
            if (i >= k) {
                rec.erase(nums[i - k]);
            }
        }
        return false;
    }

};

int main(){
	vector<int> nums = {-2147483640,-2147483641};
	int k = 1;
	int t = 100;
	Solution s = Solution();
	printf("%d",s.containsNearbyAlmostDuplicate(nums,k,t));
	
}
