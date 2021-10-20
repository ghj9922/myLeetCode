//424. 替换后的最长重复字符
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
    int characterReplacement_1(string s, int k){
    	int len = s.length();    	
    	int left = 0, right = 0;
    	int maxcount = 0;	// 字符出现的最大次数 
    	int res = 0;
    	unordered_map<char,int> mp;
		if(len < 2){
			return len;
		}
    	while(right<len){
    		mp[s[right]]++;		
    		//求窗口中曾出现某字母的最大次数
            //这样做的意义：我们求的是最长，如果找不到更长的维持长度不变返回结果不受影响
			maxcount = max(maxcount,mp[s[right]]);

			// 长度 l=right-left+1
			// l > k + 字符最大出现字数  说明需要移动left，才可能获得长度更大的子串 
			if(right - left + 1 > k + maxcount){
				// left移动，map中的该字符次数-1 
				mp[s[left]]--;
				left++;	
				// 此处不更新maxcount的值是因为要找最大长度的串，
				// 则最大值一定要比之前符合条件的最大值大。是解题的一种优化 
			}
    		right++;
			res = max(res,right-left);			
		}
		return res;
	}
	
	int characterReplacement(string s, int k){
		int len = s.length();
		int maxcount = 0, res = 0;
		int left = 0, right = 0;
		vector<int> vec(26);
		while(right < len){
			vec[s[right]-'A']++;
			maxcount = max(maxcount,vec[s[right]-'A']);
			if(right-left+1 > k+maxcount){
				vec[s[left]-'A']--;
				left++;
			}
			right++;
			res = max(res,right-left);
		}
		return res;
	}
};

int main(){
	string input = "AABABBA";
	int k = 1;
	Solution s = Solution();
	cout<<s.characterReplacement(input,k);

}
