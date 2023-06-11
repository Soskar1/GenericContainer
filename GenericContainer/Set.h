#ifndef SET_H
#define SET_H

#include <algorithm>
#include <stdexcept>

#include "AVLTree.h"

namespace GenericContainers {
	template<typename T>
	class Set {
	private:
		Tree::AVLTree<T>* m_AVLTree;
	public:
		Set();
		~Set();

		void Insert(const T& value);

		//void Remove(size_t index);
		void Remove(const T& value);
		//void RemoveFirst();
		//void RemoveLast();

		//T Get(size_t index);
		//T GetFirst();
		//T GetLast();

		bool Contains(const T& value) const;

		void Edit(const T& oldValue, const T& newValue);
		size_t Size() const;
		//void Clear();
	};

	template<typename T>
	inline Set<T>::Set()
	{
		m_AVLTree = new Tree::AVLTree<T>();
	}

	template<typename T>
	inline Set<T>::~Set()
	{
		delete m_AVLTree;
	}

	template<typename T>
	inline void Set<T>::Insert(const T& value) {
		m_AVLTree->Insert(value);
	}

	//template<typename T>
	//inline void Set<T>::Remove(size_t index)
	//{
	//	if (index < 0 || index >= m_AVLTree->Size()) {
	//		throw std::out_of_range("out_of_range");
	//	}

	//	//m_AVLTree.Remove(
	//}

	template<typename T>
	inline void Set<T>::Remove(const T& value) {
		m_AVLTree->Remove(value);
	}

	//template<typename T>
	//inline void Set<T>::RemoveFirst()
	//{
	//	Remove(size_t(0));
	//}

	//template<typename T>
	//inline void Set<T>::RemoveLast()
	//{
	//	Remove(size_t(m_AVLTree->Size() - 1));
	//}

	//template<typename T>
	//inline T Set<T>::Get(size_t index) {
	//	if (index < 0 || index >= m_AVLTree->Size()) {
	//		throw std::out_of_range("out_of_range");
	//	}

	//	return InOrderTraversal(m_Root, index);
	//}

	//template<typename T>
	//inline T Set<T>::GetFirst()
	//{
	//	return Get(0);
	//}

	//template<typename T>
	//inline T Set<T>::GetLast()
	//{
	//	return Get(m_AVLTree->Size() - 1);
	//}

	//template<typename T>
	//inline T Set<T>::InOrderTraversal(Node* node, size_t& index) {
	//	T result = T();

	//	if (node->left != nullptr) {
	//		result = InOrderTraversal(node->left, index);
	//	}

	//	if (result == m_DefaultValue && index == 0) {
	//		result = node->value;
	//	}
	//	else {
	//		--index;
	//	}

	//	if (result == m_DefaultValue && node->right != nullptr) {
	//		result = InOrderTraversal(node->right, index);
	//	}

	//	return result;
	//}

	template<typename T>
	inline void Set<T>::Edit(const T& oldValue, const T& newValue) {
		m_AVLTree->Edit(oldValue, newValue);
	}

	template<typename T>
	inline bool Set<T>::Contains(const T& value) const {
		return m_AVLTree->Contains(value);
	}

	template<typename T>
	inline size_t Set<T>::Size() const {
		return m_AVLTree->Size();
	}

	//template<typename T>
	//inline void Set<T>::Clear() {
	//	//TODO
	//}
}
#endif