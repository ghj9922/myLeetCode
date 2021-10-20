//424. �滻�����ظ��ַ�
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
    	int maxcount = 0;	// �ַ����ֵ������� 
    	int res = 0;
    	unordered_map<char,int> mp;
		if(len < 2){
			return len;
		}
    	while(right<len){
    		mp[s[right]]++;		
    		//�󴰿���������ĳ��ĸ��������
            //�����������壺����������������Ҳ���������ά�ֳ��Ȳ��䷵�ؽ������Ӱ��
			maxcount = max(maxcount,mp[s[right]]);

			// ���� l=right-left+1
			// l > k + �ַ�����������  ˵����Ҫ�ƶ�left���ſ��ܻ�ó��ȸ�����Ӵ� 
			if(right - left + 1 > k + maxcount){
				// left�ƶ���map�еĸ��ַ�����-1 
				mp[s[left]]--;
				left++;	
				// �˴�������maxcount��ֵ����ΪҪ����󳤶ȵĴ���
				// �����ֵһ��Ҫ��֮ǰ�������������ֵ���ǽ����һ���Ż� 
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
