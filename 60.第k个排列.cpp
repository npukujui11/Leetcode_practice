/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
#include <string>

class Solution {
public:
    string getPermutation(int n, int k) {
        string ans; //用于存储答案
        string track; 
        bool visited[10] = {0};
        int count = 0;
        backtracking(n, k, count, 0, track, ans, visited);
        return ans;
    }

private:
    void backtracking(int &n, int &k, int& count, int bit, string &track, string &ans, bool* visited)
    {
    	if(count > k)  //设定退出条件
    		return;
    	if(bit == n)   //设定回溯条件
    	{
    		count++;
    		if(count == k)
    			ans = track;
    	}
    	for(int i = 1; i <= n; i++)
    	{
    		if(visited[i])// i写入了答案，继续下一个数
    			continue;
    		track.push_back(i+'0');//数字强制转换为字符串
    		visited[i]=true;
    		backtracking(n, k, count, bit+1, track, ans, visited);
    		track.pop_back();
    		visited[i]=false;
    	}
    }
};
// @lc code=end

