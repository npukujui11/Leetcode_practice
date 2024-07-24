/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
/*递归实现归并排序算法*/
/*
 * 递归的递推公式 mergeSort(nums, left, right) = merge(mergeSort(nums, left, mid), mergeSort(nums, mid + 1, right))
 * 递归的终止条件 left >= right
 */
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
private:
    void mergeSort(vector<int>& nums, int left, int right) {
        // 递归终止条件
        if (left >= right) return;

        int mid = left + (right - left) / 2; // 中间元素下标
        mergeSort(nums, left, mid); // 递归排序左半部分
        mergeSort(nums, mid + 1, right); // 递归排序右半部分

        // 如果已经有序，就不需要合并了
        if (nums[mid] <= nums[mid + 1]) return;

        merge(nums, left, mid, right); // 合并两个有序数组
        
        return;
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
       
        vector<int> temp(right - left + 1); // 临时数组
        int i = left, j = mid + 1, k = 0; // i指向左半部分的起始位置，j指向右半部分的起始位置，k指向临时数组的起始位置
        
        while (i <= mid && j <= right) { // 合并两个有序数组
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) { // 如果左半部分还有剩余元素
            temp[k++] = nums[i++]; 
        }
        while (j <= right) { // 如果右半部分还有剩余元素
            temp[k++] = nums[j++]; 
        } 

        for (int p = 0; p < temp.size(); p++) {
            nums[left + p] = temp[p];
        }
    }
};
// @lc code=end

