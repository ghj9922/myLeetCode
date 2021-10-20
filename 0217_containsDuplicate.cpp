//217. ´æÔÚÖØ¸´ÔªËØ
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
    bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> st;
		int n = nums.size();
		for(int i=0;i<n;i++){
			if(st.find(nums[i])==st.end()){
				st.insert(nums[i]);
			}
			else{
				return true;
			}
		}
		return false;
    }
};

int main(){
	vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
	int target = 3;
	Solution s = Solution();
	printf("%d",s.containsDuplicate(nums));
	
}


