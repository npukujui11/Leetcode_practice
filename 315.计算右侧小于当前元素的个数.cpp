/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
/*
// 使用index数组来跟踪原始数组的下标，使用归并排序的思想
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        // 存储原始数组的下标
        vector<int> index(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            index[i] = i;
        }

        mergeSort(nums, res, index, 0, nums.size() - 1);
        return res;
    }

private:
    void mergeSort(vector<int>& nums, vector<int>& res, vector<int>& index, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, res, index, left, mid);
        mergeSort(nums, res, index, mid + 1, right);

        merge(nums, res, index, left, mid, right);
    }

    void merge(vector<int>& nums, vector<int>& res, vector<int>& index, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int count = 0;

        while (i <= mid && j <= right) {
            if (nums[index[i]] <= nums[index[j]]) { // 
                res[index[i]] += count; // 计算右侧小于当前元素的个数
                temp[k++] = index[i++];
            } else {
                count++; // 计算右侧小于当前元素的个数
                temp[k++] = index[j++];
            }
        }

        while (i <= mid) {
            res[index[i]] += count; // 计算右侧小于当前元素的个数
            temp[k++] = index[i++];
        }
        while (j <= right) {
            temp[k++] = index[j++];
        }

        for (int p = 0; p < temp.size(); p++) {
            index[left + p] = temp[p];
        }
    }
};
*/
/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
/*
// 使用index数组来跟踪原始数组的下标，使用归并排序的思想
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        // 存储原始数组的下标
        vector<int> index(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            index[i] = i;
        }

        mergeSort(nums, res, index, 0, nums.size() - 1);
        return res;
    }

private:
    void mergeSort(vector<int>& nums, vector<int>& res, vector<int>& index, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(nums, res, index, left, mid);
        mergeSort(nums, res, index, mid + 1, right);

        merge(nums, res, index, left, mid, right);
    }

    void merge(vector<int>& nums, vector<int>& res, vector<int>& index, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int count = 0;

        while (i <= mid && j <= right) {
            if (nums[index[i]] <= nums[index[j]]) { // 
                res[index[i]] += count; // 计算右侧小于当前元素的个数
                temp[k++] = index[i++];
            } else {
                count++; // 计算右侧小于当前元素的个数
                temp[k++] = index[j++];
            }
        }

        while (i <= mid) {
            res[index[i]] += count; // 计算右侧小于当前元素的个数
            temp[k++] = index[i++];
        }
        while (j <= right) {
            temp[k++] = index[j++];
        }

        for (int p = 0; p < temp.size(); p++) {
            index[left + p] = temp[p];
        }
    }
};
*/
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        vector<pair<int, int>> numsIndexPair;
        
        for (int i = 0; i < nums.size(); i++) {
            numsIndexPair.push_back({nums[i], i});
        }

        mergeSort(numsIndexPair, res, 0, nums.size() - 1);
        return res;
    }

private:
    void mergeSort(vector<pair<int, int>>& numsIndexPair, vector<int>& res, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(numsIndexPair, res, left, mid);
        mergeSort(numsIndexPair, res, mid + 1, right);

        merge(numsIndexPair, res, left, mid, right);
    }

    void merge(vector<pair<int, int>>& numsIndexPair, vector<int>& res, int left, int mid, int right) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int count = 0;

        while (i <= mid && j <= right) {
            if (numsIndexPair[i].first > numsIndexPair[j].first) { // 如果左侧某个元素大于右侧某个元素，则右侧小于当前元素的个数加1
                count++; // 右侧小于当前元素的个数+1
                temp[k++] = numsIndexPair[j++]; // 将右侧元素放入temp数组
            } else { // 如果右侧某个元素大于左侧某个元素，则右侧后续的元素都大于左侧当前元素，所以右侧小于当前元素的个数不变
                res[numsIndexPair[i].second] += count; // 右侧小于当前元素的个数不会变，所以直接加到res数组中。
                temp[k++] = numsIndexPair[i++];
            }
        }

        while (i <= mid) { // 如果左侧还有元素，说明右侧元素已经全部放入temp数组，左侧剩余元素都大于右侧最后一个元素
            res[numsIndexPair[i].second] += count; // 右侧小于当前元素的个数不会变，所以直接加到res数组中。
            temp[k++] = numsIndexPair[i++];
        }

        while (j <= right) { // 如果右侧还有元素，说明左侧元素已经全部放入temp数组，右侧剩余元素都小于左侧最后一个元素
            temp[k++] = numsIndexPair[j++];
        }

        // 将排序后的数组赋值给原数组
        for (int p = 0; p < temp.size(); p++) {
            numsIndexPair[left + p] = temp[p];
        }
    }
};
// @lc code=end

