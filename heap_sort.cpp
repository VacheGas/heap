
#include <iostream>
#include <vector>
#include <iterator>

template <typename T>
class  heap {
private:
	std::vector<T> m_items;
	int m_size;

public:

	heap(){}
	heap(std::vector<T> &new_items) {
		m_size = m_items.size();
		m_items.insert(m_items.begin(),new_items.begin(), new_items.end());
	}
	~heap() {
		m_size = 0;
	}

private:

	int getLeftChildrenIndex(int parentIndex) {
		return 2 * parentIndex + 1;
	}

	int getRightChildrenIndex(int parentIndex) {
		return 2 * parentIndex + 2;
	}

	int getParentindex(int childindex) {
		return (childindex - 1) / 2;
	}

	bool hasLeftChild(int index){
		return getLeftChildrenIndex(index) < m_size;
	}

	bool hasRightChild(int index){
		return getRightChildrenIndex(index) < m_size;
	}

	bool hasParent(int index){
		return getParentindex(index) >= 0;
	}

	T getLeftChild(int index) {
		return m_items[getLeftChildrenIndex(index)];
	}

	T getRightChild(int index) {
		return m_items[getRightChildrenIndex(index)];
	}

	T getRParentChild(int index) {
		return m_items[getParentindex(index)];
	}

	void swap(int indexOne, int indexTwo) {
		int tmp = m_items[indexOne];
		m_items[indexOne] = m_items[indexTwo];
		m_items[indexTwo] = tmp;
	}
};

int main() {
std::vector<int> arr {1,2,3,4,5};
heap obj(arr);
return 1;
}
