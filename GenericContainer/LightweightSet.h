#ifndef LIGHTWEIGHTSET_H
#define LIGHTWEIGHTSET_H

#include <stdexcept>
#include <cstdlib>

#define INITIAL_CAPACITY 100

namespace GenericContainers {
	template<typename T>
	class LightweightSet {
	private:
		void Sort();

		T* m_Array;
		size_t m_Size;
		size_t m_Capacity;

		void Resize(const size_t& newCapacity);
		int GetIndex(const T& value) const;
	public:
		LightweightSet();
		~LightweightSet();

		void Insert(const T& value);
		
		void Remove(const size_t& index);
		void Remove(const T& value);
		void RemoveFirst();
		void RemoveLast();

		T Get(const size_t& index) const;
		T GetFirst();
		T GetLast();

		bool Contains(const T& value) const;

		void Edit(const T& oldValue, const T& newValue);
		void Clear();
		size_t Size() const;
	};

	template<typename T>
	inline LightweightSet<T>::LightweightSet() {
		m_Size = 0;
		m_Capacity = INITIAL_CAPACITY;
		m_Array = new T[INITIAL_CAPACITY];
	}

	template<typename T>
	inline LightweightSet<T>::~LightweightSet() {
		delete[] m_Array;
	}

	template<typename T>
	inline void LightweightSet<T>::Sort() {
		T value = m_Array[m_Size - 1];
		
		int i = m_Size - 2;
		while (i >= 0 && m_Array[i] > value) {
			m_Array[i + 1] = m_Array[i];
			--i;
		}

		m_Array[i + 1] = value;
	}

	template<typename T>
	inline void LightweightSet<T>::Insert(const T& value) {
		if (m_Size == m_Capacity) {
			Resize(m_Capacity * 2);
		}

		m_Array[m_Size] = value;
		++m_Size;

		Sort();
	}

	template<typename T>
	inline void LightweightSet<T>::Resize(const size_t& newCapacity) {
		T* newArray = new T[newCapacity];
		for (size_t i = 0; i < m_Size; ++i) {
			newArray[i] = m_Array[i];
		}

		delete[] m_Array;
		m_Array = newArray;
		m_Capacity = newCapacity;
	}

	template<typename T>
	inline void LightweightSet<T>::Remove(const size_t& index)
	{
		if (index < 0 || index >= m_Size) {
			throw std::out_of_range("out_of_range");
		}

		for (size_t i = index; i < m_Size - 1; ++i) {
			m_Array[i] = m_Array[i + 1];
		}

		--m_Size;
	}

	template<typename T>
	inline void LightweightSet<T>::Remove(const T& value) {
		int index = GetIndex(value);

		if (index != -1) {
			Remove(size_t(index));
		}
	}

	template<typename T>
	inline void LightweightSet<T>::RemoveFirst()
	{
		Remove(size_t(0));
	}

	template<typename T>
	inline void LightweightSet<T>::RemoveLast()
	{
		Remove(m_Size - 1);
	}

	template<typename T>
	inline T LightweightSet<T>::Get(const size_t& index) const {
		if (index >= m_Size || index < 0) {
			throw std::out_of_range("out_of_range");
		}

		return m_Array[index];
	}

	template<typename T>
	inline T LightweightSet<T>::GetFirst()
	{
		return Get(0);
	}

	template<typename T>
	inline T LightweightSet<T>::GetLast()
	{
		return Get(m_Size - 1);
	}

	template<typename T>
	inline int LightweightSet<T>::GetIndex(const T& value) const {
		int low = 0;
		int high = m_Size - 1;
		int mid = 0;

		while (low <= high) {
			mid = (low + high) / 2;

			if (value == m_Array[mid]) {
				return mid;
			}
			else if (value > m_Array[mid]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}

		return -1;
	}

	template<typename T>
	inline bool LightweightSet<T>::Contains(const T& value) const {
		int low = 0;
		int high = m_Size - 1;
		int mid = 0;

		while (low <= high) {
			mid = (low + high) / 2;

			if (value == m_Array[mid]) {
				return true;
			}
			else if (value > m_Array[mid]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}

		return false;
	}

	template<typename T>
	inline void LightweightSet<T>::Edit(const T& oldValue, const T& newValue) {
		int index = GetIndex(oldValue);

		if (index != -1) {
			Remove(oldValue);
			Insert(newValue);
		}
	}

	template<typename T>
	inline void LightweightSet<T>::Clear() {
		m_Size = 0;

		delete m_Array;
		m_Array = new T[m_Capacity];
	}

	template<typename T>
	inline size_t LightweightSet<T>::Size() const {
		return m_Size;
	}
}

#endif