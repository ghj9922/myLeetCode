//0454  四数相加 II
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
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int,int> mp;
		int count;
		for(int i:nums1){
			for(int j:nums2){
				mp[i+j]++;
			}
		}
		for(int u:nums3){
			for(int v:nums4){
				if(mp.find(-u-v)!=mp.end()){
					count += mp [-u-v];
				}
			}
		}
		return count;
    }
};


