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
    int lengthOfLongestSubstring(string s) {
		unordered_set<char> mp;
		string res = "";
		string tmp = "";
		int maxlen = 0;
		// 枚举每个字符作为开头的情况 
		for(int i=0;i<s.length();i++){
			char c = s[i];
			int index = i; 			
			while(mp.find(c) == mp.end()){
//				printf("%d:%c\n",i,c);
				tmp += c;
				mp.insert(c);
				if(index+1<s.length()){
					index++;
					c = s[index];	
				}
				else break;				
			}
			if(maxlen < tmp.length()){
				maxlen = tmp.length();
				res = tmp;
			}
//			cout<<"string:"<<tmp<<endl;
			tmp="";
			mp.clear();

		}
//		cout<<endl<<"result:"<<res<<endl;
		return maxlen;
    }
    
//    官方答案 滑动窗口 
    int lengthOfLongestSubstring_2(string s){
 		unordered_set<char> st;
 		int maxlen = 0;
 		int rk = -1; //右指针 
   		for(int i=0;i<s.length();i++){
   			if(i!=0){
   				st.erase(s[i-1]);
			}
			while(rk+1<s.length() && st.find(s[rk+1]) == st.end()){
				rk += 1;
				st.insert(s[rk]);
			}
			maxlen = max(maxlen,rk-i+1);	
		}
		return maxlen;
	}
};

int main(){
	string input = "wdvfddawvdf";
	Solution s = Solution();
	cout<< s.lengthOfLongestSubstring_2(input);
	
}
