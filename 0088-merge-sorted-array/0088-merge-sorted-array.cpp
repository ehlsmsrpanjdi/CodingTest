class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
                std::vector<int> vec;
        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin() + n, std::back_inserter(vec));
        nums1 = vec;
    }
};