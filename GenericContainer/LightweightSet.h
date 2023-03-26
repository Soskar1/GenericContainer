#ifndef LIGHTWEIGHTSET_H
#define LIGHTWEIGHTSET_H

#include <stdexcept>

namespace GenericContainers {
	template<typename T>
	class LightweightSet {
	private:
		void Sort();

		T* m_Array;
		size_t m_Size;

		void Resize(const size_t& newSize);
	public:
		LightweightSet();
		~LightweightSet();

		void Insert(const T& value);
		void Remove(const T& value);
		T Get(const size_t& index) const;
		size_t GetIndex(const T& value) const;
		bool Contains(const T& value) const;
		void Edit(const T& oldValue, const T& newValue);
		void Clear();
		size_t Size() const;
	};

	template<typename T>
	inline LightweightSet<T>::LightweightSet() {
		m_Size = 0;
		m_Array = new T[1];
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
		if (Contains(value)) {
			return;
		}

		Resize(m_Size + 1);
		m_Array[m_Size - 1] = value;

		Sort();
	}

	template<typename T>
	inline void LightweightSet<T>::Resize(const size_t& newSize) {
		T* newArray = new T[newSize];
		for (int i = 0; i < m_Size; ++i) {
			newArray[i] = m_Array[i];
		}

		delete[] m_Array;
		m_Array = newArray;
		m_Size = newSize;
	}

	template<typename T>
	inline void LightweightSet<T>::Remove(const T& value) {
		size_t index = GetIndex(value);

		if (index != -1) {
			for (int i = index; i < m_Size - 1; ++i) {
				m_Array[i] = m_Array[i + 1];
			}

			--m_Size;
		}
	}

	template<typename T>
	inline T LightweightSet<T>::Get(const size_t& index) const {
		if (index >= m_Size || index < 0) {
			throw std::out_of_range("out_of_range");
		}

		return m_Array[index];
	}

	template<typename T>
	inline size_t LightweightSet<T>::GetIndex(const T& value) const {
		size_t low = 0;
		size_t high = m_Size - 1;
		size_t mid = 0;

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
		size_t index = GetIndex(oldValue);

		if (index != -1) {
			Remove(oldValue);
			Insert(newValue);
		}
	}

	template<typename T>
	inline void LightweightSet<T>::Clear() {
		m_Size = 0;
	}

	template<typename T>
	inline size_t LightweightSet<T>::Size() const {
		return m_Size;
	}
}

#endif