#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
	public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		if (left)
			delete left;

		if (right)
			delete right;
	}
}

int minimum(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return INT_MAX;
	}
	int min1 = min(minimum(root->left), minimum(root->right));
	return min(min1, root->data);
}

int diameter(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return 0;

	int lh = height(root->left);
	int rh = height(root->right);
	int ld = diameter(root->left);
	int rd = diameter(root->right);
	return max(max(ld,rd), lh + rh);
}

int diameter(BinaryTreeNode<int>* root, int& height1) {
	if (root == NULL) {
		height1 = 0;
		return 0;
	}
	int leftHeight, rightHeight;
	int ld = diameter(root->left, leftHeight);
	int rd = diameter(root->right, rightHeight);
	height1 = 1 + max(leftHeight, rightHeight);
	return  max(max(ld, rd), leftHeight + rightHeight);
}

pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		pair<int, int> p(0,0);
		return p;
	}

	pair<int, int> la = heightDiameter(root->left);
	pair<int, int> ra = heightDiameter(root->right);

	int height = 1 + max(la.first,ra.first);
	int diameter = 
		max(max(la.second, ra.second), la.first + ra.first);
	pair<int,int> output(height, diameter);
	return output;
}

int height(BinaryTreeNode<int>* root) {
/*	int max = 0;
	if (root->left)
		max = height(root->left);
	if (root->right)
		max = max(max, height(root->right));
			
	return 1 + max;
	*/
	if (root == NULL)
		return 0;

	return 1 + max(height(root->left), height(root->right));

}

int main() {
	
}

