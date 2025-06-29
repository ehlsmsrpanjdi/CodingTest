class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int oneLastPointer = m - 1;
        int twoLastPointer = n - 1;
        int totalLastPointer = m + n - 1;

        while (oneLastPointer >= 0 && twoLastPointer >= 0) {
            if (nums1[oneLastPointer] > nums2[twoLastPointer]) {
                nums1[totalLastPointer] = nums1[oneLastPointer];
                --totalLastPointer;
                --oneLastPointer;
            }
            else {
                nums1[totalLastPointer] = nums2[twoLastPointer];
                --totalLastPointer;
                --twoLastPointer;
            }
        }

        while (twoLastPointer >= 0) {
            nums1[totalLastPointer] = nums2[twoLastPointer];
            --totalLastPointer;
            --twoLastPointer;
        }



    }
};