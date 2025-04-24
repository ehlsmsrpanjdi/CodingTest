class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();

        std::vector<int> vec;
        int LongHeight = *std::max_element(heights.begin(), heights.end());
        int maxsize = size;
        std::vector<int>::iterator start = heights.begin();
        std::vector<int>::iterator current = start + size;
        int test =*std::min_element(start, current);
        while (size) {
            int maxvalue = 0;
            for (start = heights.begin(), current = start + size; ;++current, ++start) {
                if (test * maxsize > LongHeight * size) {
                    break;
                }


                int width = *std::min_element(start, current);
                if (maxvalue < width * size) {
                    maxvalue = width * size;
                }
                if (current == heights.end()) {
                    break;
                }
            }
            vec.push_back(maxvalue);
            --size;
        }
        return *std::max_element(vec.begin(), vec.end());
    }
};
