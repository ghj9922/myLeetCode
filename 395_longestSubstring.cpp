//395. ������ K ���ظ��ַ�����Ӵ�
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
    	//���÷���˼�룬��Ҫȷ���ϵ�
        //�ó��ִ���С��k���ַ�����λ����Ϊ�ϵ�
		map<char,int> m;
		vector<int> split;
		for(int i=0;i<s.length();i++){
			m[s[i]]++;
		}
		// split�����Ҷϵ� 
		for(int i=0;i<s.length();i++){
			if(m[s[i]]<k){
				split.push_back(i);
			}
		}
		// ���û�жϵ�˵�������Ӵ��������������س��ȼ��� 
		if(split.size()==0){
			return s.length();
		} 
        //����жϵ�ͻ�Ҫ�ѳ�����Ϊ�ϵ�
        split.push_back(s.length());
		// �ɶϵ����жϰ��նϵ㻮�ֵ����ַ����Ƿ���������
		// �����������������ַ�����������ִ�������k
		// ��left��¼��ߵĶϵ㣬����߲����ܳ�Ϊ���������Ӵ����±�
		int left = -1;
		int ans = 0; 
		for(int i=0;i<split.size();i++){
			// ��ǰ���Ӵ�����
			int len = split[i] - left - 1;
			// �жϸ��Ӵ��Ƿ�����
			// �Ӵ��ݹ鼴�ɣ��ⷨ����ͬ�ģ���˲��÷���
			// ��֦�����Ƶݹ�������len����k�Ҵ���ans�Ž��еݹ�
			if(len>=k && len >ans){
				ans = max(ans, longestSubstring(s.substr(left+1,len),k));
			} 
			left = split[i];
		} 
		return ans;		
    }
};
