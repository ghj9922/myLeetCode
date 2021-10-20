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
    int threeSumClosest(vector<int>& nums, int target) {
		int sum = nums[0]+nums[1]+nums[2];	 // 随机初始化最小sum 
		int dis = abs(sum-target);		// 最小距离 
		int b = 0;
		int c = 0;
		sort(nums.begin(),nums.end());
		for(int a=0;a<nums.size();a++){
			int b = a+1;
			int c = nums.size()-1;
			while(b < c){
				int tmp = nums[a]+nums[b]+nums[c];
//				printf("aaa %d %d %d = %d %d\n",a,b,c,sum,tmp);
//				printf("bbb %d %d\n",tmp,target);				
				if(dis > abs(tmp -target)){
					dis = abs(sum -target);
					sum = tmp;
				}
				if(tmp == target){
					return tmp;
				}
				if(tmp > target){
					c--;
//                     移动到下一个不相等的元素					
//					while(b < c-1 && nums[c-1] == nums[c]){
//						c--;
//					}
				}
				if(tmp < target){
					b++;
//					while(b+1 < c && nums[b+1] == nums[b]){
//						b++;
//					}
				}
			}
		}
		return sum;
    }
};

int main(){
//	vector<int> nums = {-1,2,1,-4};
	vector<int> nums = {3,4,5,5,7};
	int target = 13;
	Solution s = Solution();
	int res = s.threeSumClosest(nums,target);
	printf("%d\n",res);
} 


