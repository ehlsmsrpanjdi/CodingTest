/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

void DFS(std::vector<int>& _vec, Node* _root) {
	std::vector<Node*> novec = _root->children;

	for (Node* no : novec) {
		if (no != nullptr) {
			_vec.push_back(no->val);
			if (no->children.size() != 0) {
				DFS(_vec, no);
			}
		}
	}
}

class Solution {
public:
	vector<int> preorder(Node* root) {
		std::vector<int> vec;
		if (root != nullptr) {
			vec.push_back(root->val);
			if (root->children.size() != 0) {
				DFS(vec, root);
			}
		}
		return vec;
	}
};
