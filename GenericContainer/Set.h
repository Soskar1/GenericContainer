#ifndef SET_H
#define SET_H

#include <algorithm>
#include <stdexcept>
#include <cstdlib>

namespace GenericContainers {
	template<typename T>
	class Set {
	private:
		struct Node {
			T value;
			int height;
			Node* left;
			Node* right;

			Node(const T& value) : value(value), height(1), left(nullptr), right(nullptr) {}
			~Node();

			int CalculateBalanceFactor() const;
			void UpdateHeight();
		};

		Node* RotateLeft(Node* node);
		Node* RotateRight(Node* node);
		Node* Insert(Node* node, const T& value);
		Node* Remove(Node* node, const T& value);
		Node* GetMinimumNode(Node* node);
		T InOrderTraversal(Node* node, size_t& index);

		Node* m_Root;
		size_t m_Size;
		T m_DefaultValue;
	public:
		Set() : m_Size(0), m_Root(nullptr), m_DefaultValue(T()) {};
		~Set();

		void Create(const T& initialValue);
		void Destroy();
		void Insert(const T& value);
		void Remove(const T& value);
		T Get(size_t index);
		void Edit(const T& oldValue, const T& newValue);
		bool Contains(const T& value) const;
		size_t Size() const;
		void Clear();
	};

	template<typename T>
	inline Set<T>::Node::~Node() {
		delete left;
		delete right;
	}

	template<typename T>
	inline Set<T>::~Set() {
		m_Size = 0;
		delete m_Root;
	}

	template<typename T>
	inline void Set<T>::Create(const T& initialValue) {
		m_Root = new Node(initialValue);
		m_Size = 1;
	}

	template<typename T>
	inline void Set<T>::Destroy() {
		m_Size = 0;
		delete m_Root;
	}

	template<typename T>
	inline void Set<T>::Insert(const T& value) {
		m_Root = Insert(m_Root, value);
	}

	template<typename T>
	typename Set<T>::Node* Set<T>::Insert(Node* node, const T& value) {
		if (node == nullptr) {
			node = new Node(value);
			++m_Size;
			return node;
		}

		if (value < node->value) {
			node->left = Insert(node->left, value);
		}
		else if (value > node->value) {
			node->right = Insert(node->right, value);
		}
		else {
			return node;
		}

		node->UpdateHeight();

		int balanceFactor = node->CalculateBalanceFactor();

		if (balanceFactor > 1 && value < node->left->value) {
			return RotateRight(node);
		}

		if (balanceFactor < -1 && value > node->right->value) {
			return RotateLeft(node);
		}

		if (balanceFactor > 1 && value > node->left->value) {
			node->left = RotateLeft(node->left);
			return RotateRight(node);
		}

		if (balanceFactor < -1 && value < node->right->value) {
			node->right = RotateRight(node->right);
			return RotateLeft(node);
		}

		return node;
	}

	template<typename T>
	typename Set<T>::Node* Set<T>::RotateLeft(Node* node) {
		Node* rightChild = node->right;
		node->right = rightChild->left;
		rightChild->left = node;

		node->UpdateHeight();
		rightChild->UpdateHeight();

		if (m_Root == node) {
			m_Root = rightChild;
		}

		return rightChild;
	}

	template<typename T>
	typename Set<T>::Node* Set<T>::RotateRight(Node* node) {
		Node* leftChild = node->left;
		node->left = leftChild->right;
		leftChild->right = node;

		node->UpdateHeight();
		leftChild->UpdateHeight();

		if (m_Root == node) {
			m_Root = leftChild;
		}

		return leftChild;
	}

	template<typename T>
	inline int Set<T>::Node::CalculateBalanceFactor() const {
		int balanceFactor = 0;

		if (this->left != nullptr && this->right != nullptr) {
			balanceFactor = this->left->height - this->right->height;
		}
		else if (this->left != nullptr && this->right == nullptr) {
			balanceFactor = this->left->height;
		}
		else if (this->left == nullptr && this->right != nullptr) {
			balanceFactor = -this->right->height;
		}

		return balanceFactor;
	}

	template<typename T>
	inline void Set<T>::Node::UpdateHeight() {
		if (this->left != nullptr && this->right != nullptr) {
			this->height = std::max(this->left->height, this->right->height) + 1;
		}
		else if (this->left != nullptr && this->right == nullptr) {
			this->height = this->left->height + 1;
		}
		else if (this->left == nullptr && this->right != nullptr) {
			this->height = this->right->height + 1;
		}
		else {
			this->height = 1;
		}
	}
	
	template<typename T>
	inline void Set<T>::Remove(const T& value) {
		m_Root = Remove(m_Root, value);
	}

	template<typename T>
	typename Set<T>::Node* Set<T>::Remove(Node* node, const T& value) {
		if (node == nullptr) {
			return node;
		}

		if (value < node->value) {
			node->left = Remove(node->left, value);
		}
		else if (value > node->value) {
			node->right = Remove(node->right, value);
		}
		else {
			if (node->left == nullptr || node->right == nullptr) {
				Node* tmp = node->left ? node->left : node->right;
				if (tmp == nullptr) {
					tmp = node;
					node = nullptr;
				}
				else {
					*node = *tmp;
				}
				free(tmp);

				--m_Size;
			}
			else {
				Node* tmp = GetMinimumNode(node->right);
				node->value = tmp->value;
				node->right = Remove(node->right, tmp->value);
			}
		}

		if (node == nullptr) {
			return node;
		}

		node->UpdateHeight();

		int balanceFactor = node->CalculateBalanceFactor();
		if (balanceFactor > 1) {
			if (node->left->CalculateBalanceFactor() >= 0) {
				return RotateRight(node);
			}
			else {
				node->left = RotateLeft(node->left);
				return RotateRight(node);
			}
		}
		else if (balanceFactor < -1) {
			if (node->right->CalculateBalanceFactor() <= 0) {
				return RotateLeft(node);
			}
			else {
				node->right = RotateRight(node->right);
				return RotateLeft(node);
			}
		}

		return node;
	}

	template<typename T>
	inline T Set<T>::Get(size_t index) {
		if (index >= m_Size) {
			throw std::out_of_range("out_of_range");
		}

		return InOrderTraversal(m_Root, index);
	}

	template<typename T>
	inline T Set<T>::InOrderTraversal(Node* node, size_t& index) {
		T result = T();

		if (node->left != nullptr) {
			result = InOrderTraversal(node->left, index);
		}

		if (result == m_DefaultValue && index == 0) {
			result = node->value;
		}
		else {
			--index;
		}

		if (result == m_DefaultValue && node->right != nullptr) {
			result = InOrderTraversal(node->right, index);
		}

		return result;
	}

	template<typename T>
	typename Set<T>::Node* Set<T>::GetMinimumNode(Node* node) {
		Node* current = node;
		while (current != nullptr) {
			current = current->left;
		}

		return current;
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