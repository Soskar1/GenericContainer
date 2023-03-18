#ifndef SET_H
#define SET_H

#include <memory>

namespace GenericContainers {
	template<typename T>
	class Set {
	private:
		struct Node {
			T value;
			int height;
			std::unique_ptr<Node> left;
			std::unique_ptr<Node> right;

			Node(const T& value) : value(value), height(1), left(nullptr), right(nullptr) {}
			~Node();
		};

		std::unique_ptr<Node> m_Root;
		size_t m_Size;
	public:
		Set() : m_Size(0), m_Root(nullptr) {};
		~Set();

		void Create(const T& initialValue);
		void Destroy();
		void Insert(const T& value);
		void Remove(const T& value);
		T Get(const size_t& index) const;
		void Edit(const T& oldValue, const T& newValue);
		bool Contains(const T& value) const;
		size_t Size() const;
		void Clear();
	};

	template<typename T>
	inline Set<T>::Node::~Node() {
		left.reset();
		right.reset();
	}

	template<typename T>
	inline Set<T>::~Set() {
		m_Size = 0;
		m_Root.reset();
	}

	template<typename T>
	inline void Set<T>::Create(const T& initialValue) {
		m_Root = std::make_unique<Node>(initialValue);
		m_Size = 1;
	}

	template<typename T>
	inline void Set<T>::Destroy() {
		m_Size = 0;
		m_Root.reset();
	}

	template<typename T>
	inline void Set<T>::Insert(const T& value) {
		if (m_Root == nullptr) {
			m_Root = std::make_unique<Node>(value);
			return;
		}

		std::unique_ptr<Node>* current = &m_Root;

		while (*current) {
			Node* node = current->get();

			if (value < node->value) {
				current = &(node->left);
			}
			else if (value > node->value) {
				current = &(node->right);
			}
			else {
				return;
			}
		}

		std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
		*current = std::move(newNode);
		++m_Size;
	}

	template<typename T>
	inline void Set<T>::Remove(const T& value) {

	}

	template<typename T>
	inline T Set<T>::Get(const size_t& index) const {
		return T();
	}

	template<typename T>
	inline void Set<T>::Edit(const T& oldValue, const T& newValue) {

	}

	template<typename T>
	inline bool Set<T>::Contains(const T& value) const {
		return false;
	}

	template<typename T>
	inline size_t Set<T>::Size() const {
		return m_Size;
	}

	template<typename T>
	inline void Set<T>::Clear() {

	}
}
#endif