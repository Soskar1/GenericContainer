#ifndef AVLCONTAINER_H
#define AVLCONTAINER_H

#include <memory>

namespace GenericContainers {
	template<typename T>
	class AVLContainer {
	private:
		struct Node {
			T data;
			int height;
			std::unique_ptr<Node> left;
			std::unique_ptr<Node> right;

			Node(const T& data) : data(data), height(1), left(nullptr), right(nullptr) {}
		};

		Node m_Root;
		size_t m_Size;
	public:
		void Create();
		void Destroy();
		void Clear();
		void Add(const T& value);
		void Remove(const T& value);
		T Get(const T& value) const;
		void Edit(const T& oldValue, const T& newValue);
		bool Contains(const T& value) const;
		size_t size() const;
	};
}

#endif