class Solution {
public:
	bool isAnagram(string s, string t) {
		std::unordered_map<char, int> stringmap;

		for (char c : s) {
			++stringmap[c];
		}

		for (char c : t) {
			--stringmap[c];
		}
		for (auto& [ch, value] : stringmap) {
			if (value != 0) {
				return false;
			}
		}

		return true;
	}
};