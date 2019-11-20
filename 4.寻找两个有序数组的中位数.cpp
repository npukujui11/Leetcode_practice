/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 */

// @lc code=start

/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m > n){
            return findMedianSortedArrays(nums2, nums1);
        }

        //
        //            left_part        |          right_part
        //   A[0],A[1],...      A[i-1] |  A[i],A[i+1],...A[m - 1]
        //   B[0],B[1],...      B[j-1] |  B[j],B[j+1],...B[n - 1]
        //


        int imin = 0, imax = m, halflen = (m + n + 1) / 2;
        //二叉树搜索
        while(imin <= imax){
            int i = (imin + imax) / 2;
            int j = halflen - i;
            
            if(nums1[i-1] <= nums2[j] && nums2[j-1] <= nums1[i]){
                //命中目标后，讨论中位数的计算方法
                int maxleft = 0;
                int minright = 0;

                if(i == 0){
                    maxleft = nums2[j];
                }else if(j == 0){
                    maxleft = nums1[i-1];
                }else{
                    maxleft = max(nums1[i-1], nums2[j-1]);
                }

                if((m + n) % 2 == 1){//奇数
                    return maxleft;
                }

                if(i == m){
                    minright = nums2[j];
                }else if(j == n){
                    minright = nums1[i];
                }else{
                    minright = min(nums2, nums1);
                }
                
                return (maxleft + minright) / 2.0;

            }else if (nums2[j-1] > nums1[i] && i < imax)
            {
                imin = i + 1;                
            }else// nums1[i-1] > nums2[j] && i>imin 
            {
                imax = i - 1;
            }     
            
        }
        return 0.0;
    }
};
*/

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		int m = nums2.size();

		if (n > m)  //保证数组1一定最短
		{
			return findMedianSortedArrays(nums2, nums1);
		}

		// Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
		int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度

		while (lo <= hi)   //二分
		{
			c1 = (lo + hi) / 2;  //c1是二分的结果
			c2 = m + n - c1;

			LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
			RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
			LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

			if (LMax1 > RMin2)
				hi = c1 - 1;
			else if (LMax2 > RMin1)
				lo = c1 + 1;
			else
				break;
		}
		return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
	}
};

// @lc code=end

