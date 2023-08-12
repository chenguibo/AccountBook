#include <iostream>
#include <string>

using namespace std;

// �ݹ���õĶ��ֲ���
int binarySearch(const int a[10], int start, int end, int target) {
	// Ŀ�곬����Χ��û�ҵ�
	if (a[start] > target || a[end] < target || start > end) return -1;

	// ȡ�м�����
	int mid = (start + end) / 2;

	if (a[mid] == target) return mid;
	else if (a[mid] > target) return binarySearch(a, start, mid-1, target);
	else return binarySearch(a, mid+1, end, target);
}

// ��ӡ����ȫ��Ԫ��
void printArray(const int a[10]) {
	for (int i = 0; i < 10;i++) {
		cout << a[i] << "\t";
	}
	cout << endl;
}

// ��������
void quickSort(int (&a)[10], int start, int end) {
	int temp, left = start, right = end;
	if (start < end) {
		temp = a[start];
		while (left < right) {
			while (left < right && a[right] >= temp) right--;
			if (left < right) {
				a[left] = a[right];
				left++;
			}

			while (left < right && a[left] < temp) left++;
			if (left < right) {
				a[right] = a[left];
				right--;
			}
		}
		a[left] = temp;
		quickSort(a, start, left - 1);
		quickSort(a, left+1, end);
	}
}

// �����
struct TreeNode {
	string data;
	TreeNode* left;
	TreeNode* right;
};

// ��������
struct ListNode {
	int data;
	ListNode* next;
};

// ��ӡ����
void printList(ListNode* list){
	ListNode* np = list;
	while (np) {
		cout << np->data << " -> ";
		np = np->next;
	}
	cout << endl;
}

// ���������ݹ���������
void printTreePreOrder(TreeNode* root) {
	// ������ֱ�ӷ���
	if (root == nullptr) return;

	// �ȴ�ӡ���ڵ��ֵ
	cout << root->data << "\t";

	printTreePreOrder(root->left);
	printTreePreOrder(root->right);
}

// ���������ݹ���������
void printTreeInOrder(TreeNode* root) {
	if (root == nullptr) return;

	printTreeInOrder(root->left);
	cout << root->data << "\t";
	printTreeInOrder(root->right);
}

// ���������ݹ�ĺ������
void printTreePostOrder(TreeNode* root) {
	if (root == nullptr) return;

	printTreePostOrder(root->left);
	printTreePostOrder(root->right);
	cout << root->data << "\t";
}

int main() {
	// ���ֲ���
	const int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	cout << binarySearch(arr, 0, 9, 0) << endl; // 5

	// ����
	int arr1[10] = { 55, 10, 26, 66, 5, 68, 41, 85, 41, 7 };
	quickSort(arr1, 0, 9);
	printArray(arr1);
	
	// �������� 1->2->3->4->5->NULL
	ListNode node5 = { 5, nullptr };
	ListNode node4 = { 4, &node5 };
	ListNode node3 = { 3, &node4 };
	ListNode node2 = { 2, &node3 };
	ListNode node1 = { 1, &node2 };
	ListNode* list = &node1;
	printList(list);

	
	// ���������
	TreeNode nodeG = { "G", nullptr, nullptr };
	TreeNode nodeF = { "F", nullptr, nullptr };
	TreeNode nodeE = { "E", &nodeG, nullptr };
	TreeNode nodeD = { "D", nullptr, nullptr };
	TreeNode nodeC = { "C", nullptr, &nodeF };
	TreeNode nodeB = { "B", &nodeD, &nodeE };
	TreeNode nodeA = { "A", &nodeB, &nodeC };
	TreeNode* tree = &nodeA;

	// ����������
	printTreePreOrder(tree);
	cout << endl << endl;
	printTreeInOrder(tree);
	cout << endl << endl;
	printTreePostOrder(tree);
}