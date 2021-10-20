//187. 重复的DNA序列
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
    vector<string> findRepeatedDnaSequences(string s) {
    	unordered_map<string,int> st;
    	vector<string> res;
    	if(s.length()<10) return res;
		for(int i=0;i<s.length()- 9;i++){
			int index = i;
			int len = 0;
			string tmp = "";
			while(len < 10){
				tmp += s[index];
				len++;
				if(index+1<s.length()) index++;
				else break;
			}
			if(st.find(tmp) != st.end()){
				if(st[tmp] == 1){
					cout<<tmp<<endl;
					res.push_back(tmp);					
				}

			}
			st[tmp] += 1;			
		}
		return res;
    }
    

    // 官方答案 1：哈希表 和我的思路一样但是写法上简洁很多 
    vector<string> findRepeatedDnaSequences_2(string s){
    	int L = 10;
    	unordered_map<string,int> map;
    	vector<string> res;
    	if(s.length()<10) return res;
    	for(int i=0;i <= s.length()- L;i++){
    		string sub = s.substr(i,L);
    		if(++map[sub] == 2){
    			res.push_back(sub);
			}
		}
		return res;
	}
	
	
};

int main(){
	string input = "AAAAAAAAAAAA";
	Solution s = Solution();
	s.findRepeatedDnaSequences(input);
	
	int i = 97;
	if(97 & 0) printf("111");
}

