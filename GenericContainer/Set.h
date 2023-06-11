#ifndef SET_H
#define SET_H

#include <cstdlib>
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

		void Remove(size_t index);
		void Remove(const T& value);
		void RemoveFirst();
		void RemoveLast();

		T Get(const int& index);
		T GetFirst();
		T GetLast();

		bool Contains(const T& value) const;

		void Edit(const T& oldValue, const T& newValue);
		size_t Size() const;
		void Clear();
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

	template<typename T>
	inline void Set<T>::Remove(size_t index)
	{
		m_AVLTree->Remove(index);
	}

	template<typename T>
	inline void Set<T>::Remove(const T& value) {
		m_AVLTree->Remove(value);
	}

	template<typename T>
	inline void Set<T>::RemoveFirst()
	{
		Remove(size_t(0));
	}

	template<typename T>
	inline void Set<T>::RemoveLast()
	{
		Remove(m_AVLTree->Size() - 1);
	}

	template<typename T>
	inline T Set<T>::Get(const int& index) {
		return m_AVLTree->Get(index);
	}

	template<typename T>
	inline T Set<T>::GetFirst()
	{
		return Get(0);
	}

	template<typename T>
	inline T Set<T>::GetLast()
	{
		return Get(m_AVLTree->Size() - 1);
	}

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

	template<typename T>
	inline void Set<T>::Clear() {
		delete m_AVLTree;
		m_AVLTree = new Tree::AVLTree<T>();
	}
}
#endif