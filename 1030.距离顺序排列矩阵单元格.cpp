/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        /* Algorithm ideas:
		 * determines whether the value entered is legal
		 * none of the rows and columns of a matrix can be less than or equal to 0
		 * the coordinates you scanf in can't be less than zero。
		 **traverse each position in the matrix and calculate the Manhattan distance to each position
		 **and then we're going to sort the distances
		 */
		if (R <= 0 || C <= 0 || r0 < 0 || c0 < 0) {
			return vector<vector<int>> ();
		}

		 /*Create an unordered_map to store 
		  *the distance data key and coordinate value for each location
		  */
		 /*The insert lookup of unordered_map is slightly faster than the hashmap, 
		  *but the map is primarily a one-to-one correspondence.
		  */
		 //unordered_map, map does not support sorting
		 unordered_map<int, vector<vector<int>>> dict;
		 
		 for(int i=0; i!=R; i++){
			 for(int j=0; j!=C; j++){
				 int distance = abs(i-r0) + abs(j-c0);
				 dict[distance].push_back(vector<int>({i,j}));
			 }
		 }
		 
		 //sorts the distances in the array
		 /*The keys are primarily used to store 
		  *distance of type int in dict
		  */
		 vector<int> keys;
		 /*
		  *Sort sort only works if the distance in the unordered_map is saved
		  */
		  
		 for (auto distance : dict){
			 keys.push_back(distance.first);
		 }
		 sort(keys.begin(), keys.end());
		 
		 //inserted into the container in sorted order
		 vector<vector<int>> res;
		 for (auto distance : keys){
			 res.insert(res.end(), dict[distance].begin(), dict[distance].end());
		 }
		 
		 return res;
    }
};
// @lc code=end

