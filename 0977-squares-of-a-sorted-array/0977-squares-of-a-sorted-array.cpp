class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](int& a, int& b) {
            a = std::abs(a);
            b = std::abs(b);
            return a < b;
            });
        for (int& a : nums) {
            a = a * a;
        }
                return nums;

    }
};