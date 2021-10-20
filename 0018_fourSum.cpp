//18. 四数之和
#include <iostream>
#include<cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include<set>
#include<unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	// 粗暴法 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	set<vector<int>> res;	// 去重 
    	vector<vector<int>> result;
    	sort(nums.begin(),nums.end()); 
		for(int a=0; a<nums.size(); a++){
			for(int b=a+1; b<nums.size(); b++){
				for(int c=b+1;c<nums.size();c++){
					int tmp = target-nums[a]-nums[b];
					vector<int> tmp_res = {nums[a],nums[b],nums[c]};						
					int d = nums.size()-1;				
					while(c<d && nums[c]+nums[d]>tmp){
						d--;
					}
					if(c == d) break;
					if(nums[c]+nums[d] == tmp){
						tmp_res.push_back(nums[d]);
						res.insert(tmp_res);	
					}
				}
			}
		}
		result.assign(res.begin(),res.end());
		return result;
    }
    //第二层循环下用了双指针 
    vector<vector<int>> fourSum_2(vector<int>& nums, int target) {
    	set<vector<int>> res;	// 去重 
    	vector<vector<int>> result;
    	sort(nums.begin(),nums.end()); 
		for(int a=0; a<nums.size(); a++){
			for(int b=a+1; b<nums.size(); b++){
														
				int tmp = target-nums[a]-nums[b];
				int c = b+1;
				int d = nums.size()-1;
				vector<int> tmp_res = {nums[a],nums[b]};
				while(c<d){
//					printf("tmp:%d sum:%d c:%d d:%d\n",tmp,nums[c]+nums[d],c,d);
					if(nums[c]+nums[d] == tmp){
						tmp_res.push_back(nums[c]);
						tmp_res.push_back(nums[d]);
						res.insert(tmp_res);
//						tmp_res.clear();
						tmp_res={nums[a],nums[b]};
						c++;
						d--;
					}
					if(nums[c]+nums[d] < tmp){
						c++;
					}
					if(nums[c]+nums[d] > tmp){
						d--;
					}
				}
			}
		}
		result.assign(res.begin(),res.end());
		return result;
    }
    
    // 参考官方答案解题思路  增加一些剪枝操作 写到烦躁没改完。。 
    vector<vector<int>> fourSum_3(vector<int>& nums, int target) {
    	set<vector<int>> res;	// 去重 
    	vector<vector<int>> result;
    	sort(nums.begin(),nums.end()); 
    	for(int j=0;j<nums.size();j++){
			printf("%d ",nums[j]);
		}
		printf("\n\n"); 
    	if(nums.size()<4){
    		return result;
		}
		
		int n = nums.size(); 
		for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {	// 剪枝1 
                break;
            }
            if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {	// 剪枝2
                continue;
            }
		for(int a=0; a<nums.size(); a++){
			if(a>0 && nums[a] == nums[a-1]) continue;
			if(a+3<n && nums[a]+nums[a+1]+nums[a+2]+nums[a+3] > target) continue;	
			if(n-3>0 && nums[a]+nums[n-3]+nums[n-2]+nums[n-1] < target) continue;
			for(int b=a+1; b<nums.size(); b++){
				printf("a:%d b:%d\n",a,b);
				if(b>a+1 && nums[b]==nums[b-1]) continue;
				if(b+3<n && nums[a]+nums[b]+nums[b+1]+nums[b+2] > target) continue;	// 剪枝3
				if(n-3>0 && nums[a]+nums[b]+nums[n-1]+nums[n-2] < target) continue;	// 剪枝4													
				int tmp = target-nums[a]-nums[b];
				int c = b+1;
				int d = nums.size()-1;
				vector<int> tmp_res = {nums[a],nums[b]};
				while(c<d){
					printf("tmp:%d a:%d b:%d c:%d d:%d\n",tmp,a,b,c,d);				
					if(nums[c]+nums[d] == tmp){
						tmp_res.push_back(nums[c]);
						tmp_res.push_back(nums[d]);
//						result.push_back(tmp_res);
						res.insert(tmp_res);
//						tmp_res.clear();
						tmp_res={nums[a],nums[b]};
						c++;
						d--;
						// 移动c指针直到与前一个数不同，d同理 
						while(nums[c]+nums[d] == tmp && c+1<d && nums[c]==nums[c+1]) c++;
						while(nums[c]+nums[d] == tmp && c<d-1 && nums[d]==nums[d-1]) d--;
						printf("!!!! c:%d d:%d\n",c,d);	
					}
					if(nums[c]+nums[d] < tmp){
						c++;
					}
					if(nums[c]+nums[d] > tmp){
						d--;
					}
					printf("???? c:%d d:%d\n",c,d);						
				}
			}
		}
		result.assign(res.begin(),res.end());
		return result;
    }
};

// 官方代码 
class Solution_answer {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        if (nums.size() < 4) {
            return quadruplets;
        }
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 加这句，判断是否超过了int类型的最大值，超过了就直接跳过
            if(nums[i] + nums[i+1] > 2147483648 - nums[i+2] - nums[i+3] ||
               nums[i] + nums[length - 3] > 2147483648 - nums[length - 2] - nums[length - 1]) {
                        break;
            }
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if (nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                continue;
            }
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if (nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                    continue;
                }
                int left = j + 1, right = length - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return quadruplets;
    }
};


int main(){
	vector<int> nums = {1,0,-1,0,-2,2};
	int target = 0;
	nums={2,-4,-5,-2,-3,-5,0,4,-2};
	target=-14;
	Solution s = Solution();
	vector<vector<int>> res = s.fourSum_3(nums,target);
	printf("len:%d\n",res.size());
	for(int i=0;i<res.size();i++){
		for(int j=0;j<res[i].size();j++){
			printf("%d ",res[i][j]);
			if(j==res[i].size()-1) printf("\n");	
		}
	}
}

