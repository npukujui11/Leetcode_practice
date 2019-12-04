class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if(nums.empty())
            return {-1, -1};
        //lower_bound：返回一个迭代器，指向键值 <= key的第一个元素。
        //upper_bound：返回一个迭代器，指向键值 > key的第一个元素。
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        if(left == right)
            return {-1, -1};
        return {left - nums.begin(), right - nums.begin() - 1}; 
    }
}