class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		std::vector<std::vector<int>> vec(0);
		std::queue<std::pair<TreeNode*, int>> Qu;

		if (root != nullptr) {
			Qu.push(std::make_pair(root, 1));
		}

		while (!Qu.empty()) {
			std::pair<TreeNode*, int> pa = Qu.front();

			if (pa.first->left != nullptr) {
				Qu.push(std::make_pair(pa.first->left, pa.second + 1));
			}

			if (pa.first->right != nullptr) {
				Qu.push(std::make_pair(pa.first->right, pa.second + 1));
			}

			if (vec.size() < pa.second) {
				vec.push_back(std::vector<int>());
			}

			vec[pa.second - 1].push_back(pa.first->val);

			Qu.pop();
		}
		return vec;
	}
};