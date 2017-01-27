#ifndef CONTAINERS_LIST_H
#define CONTAINERS_LIST_H

#include <memory>
#include <utility>

namespace containers {
	template <class T> class list {
	public:
		list(const list& other) {
			std::shared_ptr<node> current(other.m_front);
			while (current->m_next != nullptr) {
				push_back(*(current->m_data));
				current = current->m_next;
			}
		}

		list(list&& other)
		    : m_front(std::move(other.m_front))
		    , m_back(std::move(other.m_back))
		    , m_size(std::move(other.m_size)) {
			other.m_front = nullptr;
			other.m_back = nullptr;
		}

		list& operator=(list other) {
			std::swap(*this, other);
			return *this;
		}

		void clear() {
			m_front = nullptr;
			m_back = nullptr;
			m_size = 0;
		}

		void push_front(const T& val) {
			std::shared_ptr<node> new_node(new node());
			new_node->m_data(new T(val));
			if (m_front != nullptr) {
				std::shared_ptr<node> old_front(m_front);
				m_front->m_prev = new_node;
				m_front = new_node;
				m_front->m_next = old_front;
			} else {
				m_front = new_node;
				m_back = new_node;
			}
			m_size++;
		}

		void push_back(const T& val) {
			std::shared_ptr<node> new_node(new node());
			new_node->m_data(new T(val));
			if (m_back != nullptr) {
				std::shared_ptr<node> old_back(m_front);
				m_back->m_next = new_node;
				m_back = new_node;
				m_back->m_prev = old_front;
			} else {
				m_front = new_node;
				m_back = new_node;
			}
			m_size++;
		}

		void insert(const T& val, const T& before) {
			std::shared_ptr<node> current(m_front);
			std::shared_ptr<node> new_node(new node());
			new_node->m_data(new T(val));
			while (current != nullptr && *(current->m_data) != val) {
				current = current->m_next;
			}
			if (current != nullptr) {
				new_node->m_prev = current->m_prev;
				new_node->m_next = current;
				current->m_prev->m_next = new_node;
				current->m_prev = new_node;
			}
		}

		void insert_after(const T& val, const T& after) {
			std::shared_ptr<node> current(m_back);
			std::shared_ptr<node> new_node(new node());
			new_node->m_data(new T(val));
			while (current != nullptr && *(current->m_data) != val) {
				current = current->m_prev;
			}
			if (current != nullptr) {
				new_node->m_next = current->m_next;
				new_node->m_prev = current;
				current->m_next->m_prev = new_node;
				current->m_next = new_node;
			}
		}

		void pop_front() {
			m_front = m_front->m_next;
			m_size--;
		}

		void pop_back() {
			m_back = m_back->m_prev;
			m_size--;
		}

		void remove(const T& val) {
			std::shared_ptr<node> current(m_front);
			while (current != nullptr) {
				if (*(current->m_data) == val) {
					current->m_prev->m_next = current->m_next;
					current->m_next->m_prev = current->m_prev;
					m_size--;
				}
			}
		}

		T& front() { return *(m_front->m_data); }
		T& back() { return *(m_back->m_data); }
		size_t size() { return m_size; }

	private:
		struct node {
			std::shared_ptr<node> m_prev;
			std::shared_ptr<node> m_next;
			std::unique_ptr<T> m_data;
		};

		std::shared_ptr<node> m_front;
		std::shared_ptr<node> m_back;
		size_t m_size;
	};
}

#endif
