#include <cstdio>
#include <math.h>
#define MAX_SIZE 100000
typedef struct _heap {
	int item[MAX_SIZE];
	int size;

	_heap() {
		for (int i = 0; i < MAX_SIZE; i++)item[i] = 0;
		this->size = 0;
	}

	bool comparator(int a, int b) {
		if (abs(a) == abs(b))return a < b;
		return abs(a) < abs(b);
	}

	bool isEmpty() {
		if (this->size != 0)return false;
		return true;
	}

	int findAbsMin() {
		return this->item[0];
	}

	void insert(int data) {
		if (this->size == MAX_SIZE)return;
		this->item[size] = data;

		int tmp;
		int parent = (this->size - 1) / 2;
		int idx = this->size;

		while (parent >= 0) {
			if (this->comparator(this->item[idx],this->item[parent])) {
				tmp = this->item[idx];
				this->item[idx] = this->item[parent];
				this->item[parent] = tmp;
				idx = parent;
				parent = (idx - 1) / 2;
			}
			else break;
		}
		this->size++;
	}

	int deleteAbsMin() {
		if (this->isEmpty())return 0;

		int data = this->item[0];
		int newRoot = this->item[this->size - 1];
		this->item[0] = newRoot;

		this->size--;

		int idx = 0;
		int left = 1;
		int right = 2;
		int tmp, min;

		while (left < this->size || right < this->size) {
			min = idx;
			if (left < this->size && this->comparator(this->item[left], this->item[min]))
				min = left;
			if (right < this->size && this->comparator(this->item[right], this->item[min]))
				min = right;

			if (min != idx) {
				tmp = this->item[min];
				this->item[min] = this->item[idx];
				this->item[idx] = tmp;
				idx = min;
				left = min * 2 + 1;
				right = min * 2 + 2;
			}
			else break;
		}
		return data;
	}
}heap;

heap h;
int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int op;
		scanf("%d", &op);
		if (op)
			h.insert(op);
		else printf("%d\n", h.deleteAbsMin());
	}

}


//#include <cstdio>
//#define MAX_SIZE 100000
//typedef struct _heap {
//	int item[MAX_SIZE];
//	int size;
//
//	_heap() {
//		for (int i = 0; i < MAX_SIZE; i++)item[i] = 0;
//		this->size = 0;
//	}
//
//	bool isEmpty() {
//		if (this->size != 0)return false;
//		return true;
//	}
//
//	int findMin() {
//		return this->item[0];
//	}
//
//	void insert(int data) {
//		if (this->size == MAX_SIZE)return;
//		this->item[size] = data;
//
//		int tmp;
//		int parent = (this->size - 1) / 2;
//		int idx = this->size;
//
//		while (parent >= 0) {
//			if (this->item[idx] < this->item[parent]) {
//				tmp = this->item[idx];
//				this->item[idx] = this->item[parent];
//				this->item[parent] = tmp;
//				idx = parent;
//				parent = (idx - 1) / 2;
//			}
//			else break;
//		}
//		this->size++;
//	}
//
//	int deleteMin() {
//		if (this->isEmpty())return 0;
//
//		int data = this->item[0];
//		int newRoot = this->item[this->size - 1];
//		this->item[0] = newRoot;
//
//		this->size--;
//
//		int idx = 0;
//		int left = 1;
//		int right = 2;
//		int tmp, max;
//
//		while (left < this->size || right < this->size) {
//			max = idx;
//			if (left<this->size && this->item[left] < this->item[max])
//				max = left;
//			if (right<this->size && this->item[right] < this->item[max])
//				max = right;
//
//			if (max != idx) {
//				tmp = this->item[max];
//				this->item[max] = this->item[idx];
//				this->item[idx] = tmp;
//				idx = max;
//				left = max * 2 + 1;
//				right = max * 2 + 2;
//			}
//			else break;
//		}
//		return data;
//	}
//}heap;
//
//heap h;
//int main() {
//	freopen("input.txt", "r", stdin);
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		int op;
//		scanf("%d", &op);
//		if (op)
//			h.insert(op);
//		else printf("%d\n", h.deleteMin());
//	}
//
//}


//#include <cstdio>
//#define MAX_SIZE 100000
//typedef struct _heap {
//	int item[MAX_SIZE];
//	int size;
//
//	_heap() {
//		for (int i = 0; i < MAX_SIZE; i++)item[i] = 0;
//		this->size = 0;
//	}
//
//	bool isEmpty() {
//		if (this->size != 0)return false;
//		return true;
//	}
//
//	int findMax() {
//		return this->item[0];
//	}
//
//	void insert(int data) {
//		if (this->size == MAX_SIZE)return;
//		this->item[size] = data;
//
//		int tmp;
//		int parent = (this->size - 1) / 2;
//		int idx = this->size;
//
//		while (parent >= 0) {
//			if (this->item[idx] > this->item[parent]) {
//				tmp = this->item[idx];
//				this->item[idx] = this->item[parent];
//				this->item[parent] = tmp;
//				idx = parent;
//				parent = (idx - 1) / 2;
//			}
//			else break;
//		}
//		this->size++;
//	}
//
//	int deleteMax() {
//		if (this->isEmpty())return 0;
//
//		int data = this->item[0];
//		int newRoot = this->item[this->size - 1];
//		this->item[0] = newRoot;
//
//		this->size--;
//
//		int idx = 0;
//		int left = 1;
//		int right = 2;
//		int tmp, max;
//
//		while (left < this->size || right < this->size) {
//			max = idx;
//			if (left<this->size && this->item[left] > this->item[max])
//				max = left;
//			if (right<this->size && this->item[right] > this->item[max])
//				max = right;
//
//			if (max != idx) {
//				tmp = this->item[max];
//				this->item[max] = this->item[idx];
//				this->item[idx] = tmp;
//				idx = max;
//				left = max * 2 + 1;
//				right = max * 2 + 2;
//			}
//			else break;
//		}
//		return data;
//	}
//}heap;
//
//heap h;
//int main() {
//	freopen("input.txt", "r", stdin);
//	int T;
//	scanf("%d", &T);
//	while (T--) {
//		int op;
//		scanf("%d", &op);
//		if (op)
//			h.insert(op);
//		else printf("%d\n", h.deleteMax());
//	}
//
//}
