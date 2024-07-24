/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start


/*
 * 由于左右两部分都是有序的，所以可以使用双指针的方法来统计下标对的数量
 * 如果左边的某个元素大于右边的某个元素两倍，那么左边剩余的元素也一定大于这个元素的两倍
 * 即nums[i] > 2 * nums[j]，那么nums[i] > 2 * nums[j + 1]，因此可以直接统计
 */

// 方法一：归并排序
/*
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0) return 0; // 特例处理
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right) {
        // 递归终止条件
        if (left >= right) return 0;
        int mid = left + (right - left) / 2; // 中间元素下标
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right); // 递归排序左右两部分

        // 统计下标对的数量
        
        int j = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) { // 右边元素的值小于左边元素的值的两倍
                j++;
            }
            count += (j - (mid + 1));
        }

        merge(nums, left, mid, right); // 合并两个有序数组
        return count;
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
*/

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0) return 0; // 特例处理
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        count += merge(nums, left, mid, right);
        return count;
    }
    // 在合并的过程中统计左边数组中的元素大于右边数组中元素的两倍的数量
    // 左边数组的某个值大于右边数组的某个值的两倍，那么左边数组的剩余元素也一定大于这个值的两倍
    int merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1); // 临时数组
        int count = 0;
        int i = left, j = mid + 1, k = 0; // i指向左半部分的起始位置，j指向右半部分的起始位置

        while (i <= mid && j <= right) {
            if ((long)nums[i] <= (long)nums[j] * 2) {
                i++;
            } else {
                count += (mid - i + 1);
                j++;
            }
        }

        i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) { // 如果左半部分的值小于等于右半部分的值
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
        for (int p = 0; p < temp.size(); p++) { // 将临时数组的值赋值给原数组
            nums[left + p] = temp[p];
        }
        return count;
    }
};
// @lc code=end

