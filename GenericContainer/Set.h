#ifndef SET_H
#define SET_H

#include <memory>
#include <cmath>

namespace GenericContainers {
	template<typename T>
	class Set {
	private:
		struct Node {
			T value;
			int height;
			std::unique_ptr<Node> left;
			std::unique_ptr<Node> right;
			std::unique_ptr<Node> parent;

			Node(const T& value) : value(value), height(1), left(nullptr), right(nullptr), parent(nullptr) {}
			~Node();

			void Insert(const T& value);
			int GetBalanceFactor();
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

		//TODO: Check if value is existing in set
		(*m_Root).Insert(value);
		++m_Size;
	}

	template<typename T>
	inline void Set<T>::Node::Insert(const T& value) {
		if (value < this->value) {
			if (this->left == nullptr) {
				this->left = std::make_unique<Node>(value);
				this->left->height = this->height + 1;
			}
			else {
				this->left->Insert(value);
			}
		}
		else if (value > this->value) {
			if (this->right == nullptr) {
				this->right = std::make_unique<Node>(value);
				this->right->height = this->height + 1;
			}
			else {
				this->right->Insert(value);
			}
		}

		int balanceFactor = GetBalanceFactor();

		if (balanceFactor > 1) {
			if (value < this->left->value) {
				//RotateRight();
			}
			else {
				//this->left->RotateLeft();
				//RotateRight();
			}
		}
		else if (balanceFactor < -1) {
			if (value < this->right->value) {
				//RotateLeft();
			}
			else {
				//this->right->RotateRight();
				//RotateLeft();
			}
		}
	}

	template<typename T>
	inline int Set<T>::Node::GetBalanceFactor() {
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