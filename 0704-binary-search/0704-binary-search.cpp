class Solution {
public:
    int search(vector<int>& nums, int target) {
       std::vector<int>::iterator iter = std::find(nums.begin(), nums.end(), target);

       if (iter == nums.end()) {
           return -1;
       }
       int distance = std::distance(nums.begin(), iter);

        return distance;
    }
};
