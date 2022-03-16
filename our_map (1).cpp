#include <iostream>
using namespace std;


class Node {
	Node* left = nullptr,
		* right = nullptr;
	int key; // T < (less)
	int value;
public:
	Node(int key, int value) : key(key), value(value) {}

	int search_value(int parent_key) {
		if (parent_key == this->key) {
			return this->value;
		}

		if (parent_key < this->key) {
			cout << " left";
			if (left != nullptr) { // Search more
				return left->search_value(parent_key);
			}
			else {
				cout << ":(";
				return 0;
			}
		}
		else {  // greater
			cout << " right";
			if (right != nullptr) {
				return right->search_value(parent_key);
			}
			else {
				cout << ":(";
				return 0;
			}
		}
	}

	void add_node(int parent_key) {
		if (parent_key < this->key) {
			if (left != nullptr) { // Search more
				left->add_node(parent_key);
			}
			else {
				left = new Node(parent_key * parent_key, parent_key);
				cout << left->key << " " << left->value << endl;
			}
		}
		else {  // greater
			if (right != nullptr) {
				right->add_node(parent_key);
			}
			else {
				right = new Node(parent_key * parent_key, parent_key);
				cout << right->key << " " << right->value << endl;
			}
		}
	}
};
// Составить с помощью дерева таблицу соответствий квадратам чисел
// их корней: например: 9, 3 ...... 16, 4
int main() {
	int arr[8]{ 17,3,23,8,4,9,12,25 };
	Node* node = new Node(arr[0] * arr[0], arr[0]);
	for (int i = 0; i < 8; i++) {
		node->add_node(arr[i]);
	}
}