//395. 至少有 K 个重复字符的最长子串
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
    int longestSubstring(string s, int k) {
    	//采用分治思想，需要确定断点
        //用出现次数小于k的字符所在位置作为断点
		map<char,int> m;
		vector<int> split;
		for(int i=0;i<s.length();i++){
			m[s[i]]++;
		}
		// split用来找断点 
		for(int i=0;i<s.length();i++){
			if(m[s[i]]<k){
				split.push_back(i);
			}
		}
		// 如果没有断点说明整个子串满足条件，返回长度即可 
		if(split.size()==0){
			return s.length();
		} 
        //如果有断点就还要把长度作为断点
        split.push_back(s.length());
		// 由断点来判断按照断点划分的子字符串是否满足条件
		// 条件就是其中所有字符都是满足出现次数大于k
		// 用left记录左边的断点，即左边不可能成为满足条件子串的下标
		int left = -1;
		int ans = 0; 
		for(int i=0;i<split.size();i++){
			// 当前的子串长度
			int len = split[i] - left - 1;
			// 判断该子串是否满足
			// 子串递归即可，解法是相同的，因此采用分治
			// 剪枝：限制递归条件，len大于k且大于ans才进行递归
			if(len>=k && len >ans){
				ans = max(ans, longestSubstring(s.substr(left+1,len),k));
			} 
			left = split[i];
		} 
		return ans;		
    }
};
