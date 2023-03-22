#ifndef LIGHTWEIGHTSET_H
#define LIGHTWEIGHTSET_H

namespace GenericContainers {
	template<typename T>
	class LightweightSet {
	private:
		size_t m_Size;
	public:
		LightweightSet() : m_Size(0) {}
		~LightweightSet();

		void Insert(const T& value);
		void Remove(const T& value);
		T Get(const size_t& index);
		bool Contains(const T& value) const;
		void Edit(const T& oldValue, const T& newValue);
		void Clear();
		size_t Size() const;
	};
}

#endif