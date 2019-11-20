/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

//枚举法

/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int V;
        int MAX_vol = 0;
        int res;
        //unordered_map<int, int> hash;
        int m = height.size();
        int array[m]={0};
        for (int i = 0; i < m - 1; i++){
            for(int j = i + 1; j < m; j++){
                if(height[i] < height[j]){//i duan
                    //判断谁是短板
                    V = height[i] * (j-i);
                }else{//j 短
                    V = height[j] * (j-i);
                }
                if(MAX_vol < V){
                    MAX_vol = V;
                    array[i] = MAX_vol;
                }else{//(MAX_vol >= V)
                    array[i] = MAX_vol; 
                }
                
            }
            if(array[i] < array[i+1]){
                res = array[i+1];
            }else{
                res = array[i];
            }
        }
        return res;
    }
};
*/

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int m = height.size();//获取数组的长度
        int MAX_vol = 0;//用于记录容量的最大值
        int flag = 0;
        int left_index = 0;//左指针
        int right_index = m - 1;//右指针

        int h;//高度
        int l;//长度
        
        while(left_index != right_index){
            l = right_index - left_index;
            if(height[left_index] < height[right_index]){//每次只移动值比较短的一侧
                h = height[left_index]; 
                left_index++;
            }else{
                h = height[right_index];
                right_index--;
            }
            flag = h * l;
            if(flag > MAX_vol){
                MAX_vol = flag;
            }
        }
        return MAX_vol;
    }
};


// @lc code=end