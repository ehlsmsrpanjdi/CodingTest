class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {

		std::vector<vector<string>> vec;

		std::unordered_map<std::string, std::vector<std::string>> answerMap;

		for (int i = 0; i < strs.size(); ++i) {
			string str = strs[i];
			std::sort(str.begin(), str.end());
			if (answerMap.find(str) != answerMap.end()) {
				answerMap[str].push_back(strs[i]);
			}

			else {
				answerMap[str] = { strs[i] };
			}
		}

		for (std::pair<const std::string, std::vector<std::string>> pp : answerMap) {
			vec.push_back(pp.second);
		}

		return vec;
	}
};