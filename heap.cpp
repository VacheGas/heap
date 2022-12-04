#include <iostream>
#include <vector>

template <typename T>
class  heap {
private:
	std::vector<T> m_items;
	int m_size;

public:

	heap(){
		m_size = 0;
	}

	~heap() {}

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

	T getParent(int index) {
		return m_items[getParentindex(index)];
	}

	void swap(int indexOne, int indexTwo) {
		T tmp = m_items[indexOne];
		m_items[indexOne] = m_items[indexTwo];
		m_items[indexTwo] = tmp;
	}

public:

	void heapifyDown() {
		int i = 0;

		while (hasLeftChild(i)) {
			int smallerChild = getLeftChildrenIndex(i);
			if (hasRightChild(i) && getRightChild(i) < m_items[smallerChild]) {
				smallerChild = getRightChildrenIndex(i);
			}
			if (m_items[i] < m_items[smallerChild]) {
				break;
			} else {
				swap(i, smallerChild);
			}
			i = smallerChild;
		}
		
	}

	void heapifyUp() {
		int i = m_size - 1;
		while (hasParent(i) && getParent(i) > m_items[i]) {
			swap(i, getParentindex(i));
			i = getParentindex(i);
		}
	}

	T peek() {
		if (m_size == 0) {
			throw ("heap is empty");
		}
		return m_items[0];
	}

	T poll() {
		if (m_size == 0) throw ("heap is empty");
		T item = m_items[0];
		m_items[0] = m_items[m_size - 1];
		--m_size;
		heapifyDown();
		return item;
	}
	
	void add(T item) {
		if (m_items.size() > m_size) {
			m_items[m_size] = item;
		} else {
			m_items.push_back(item);
		}
		++m_size;
		heapifyUp();
	}
};