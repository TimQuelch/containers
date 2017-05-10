#ifndef CONTAINERS_LIST_H
#define CONTAINERS_LIST_H

#include <memory>
#include <utility>

namespace containers {
	template <class T> class list {
	public:
		list()
		    : front_{nullptr}
		    , back_{nullptr}
		    , size_{0} {}

		list(const list& other) {
			std::shared_ptr<node> current{other.front_};
			while (current->next_ != nullptr) {
				push_back(*(current->data_));
				current = current->next_;
			}
		}

		list(list&& other)
		    : front_{std::move(other.front_)}
		    , back_{std::move(other.back_)}
		    , size_{std::move(other.size_)} {
			other.front_ = nullptr;
			other.back_ = nullptr;
		}

		list& operator=(list other) {
			std::swap(*this, other);
			return *this;
		}

		void clear() {
			front_ = nullptr;
			back_ = nullptr;
			size_ = 0;
		}

		void push_front(const T& val) {
			std::shared_ptr<node> new_node{std::make_shared<node>()};
			new_node->data_ = std::make_shared<T>(val);
			if (front_ != nullptr) {
				std::shared_ptr<node> old_front{front_};
				front_->prev_ = new_node;
				front_ = new_node;
				front_->next_ = old_front;
			} else {
				front_ = new_node;
				back_ = new_node;
			}
			size_++;
		}

		void push_back(const T& val) {
			std::shared_ptr<node> new_node{std::make_shared<node>()};
			new_node->data_ = std::make_shared(val);
			if (back_ != nullptr) {
				std::shared_ptr<node> old_back{front_};
				back_->next_ = new_node;
				back_ = new_node;
				back_->prev_ = old_back;
			} else {
				front_ = new_node;
				back_ = new_node;
			}
			size_++;
		}

		void insert(const T& val, const T& before) {
			std::shared_ptr<node> current{front_};
			std::shared_ptr<node> new_node{std::make_shared<node>()};
			new_node->data_ = std::make_shared<T>(val);
			while (current != nullptr && *(current->data_) != val) {
				current = current->next_;
			}
			if (current != nullptr) {
				new_node->prev_ = current->prev_;
				new_node->next_ = current;
				current->prev_->next_ = new_node;
				current->prev_ = new_node;
			}
		}

		void insert_after(const T& val, const T& after) {
			std::shared_ptr<node> current{back_};
			std::shared_ptr<node> new_node{std::make_shared<node>()};
			new_node->data_ = std::make_shared<T>(val);
			while (current != nullptr && *(current->data_) != val) {
				current = current->prev_;
			}
			if (current != nullptr) {
				new_node->next_ = current->next_;
				new_node->prev_ = current;
				current->next_->prev_ = new_node;
				current->next_ = new_node;
			}
		}

		void pop_front() {
			front_ = front_->next_;
			size_--;
		}

		void pop_back() {
			back_ = back_->prev_;
			size_--;
		}

		void remove(const T& val) {
			std::shared_ptr<node> current{front_};
			while (current != nullptr) {
				if (*(current->data_) == val) {
					current->prev_->next_ = current->next_;
					current->next_->prev_ = current->prev_;
					size_--;
				}
			}
		}

		void merge(list<T> other) {}
		void reverse() {}
		void unique() {}
		void sort() {}
		T& front() { return *(front_->data_); }
		T& back() { return *(back_->data_); }
		bool empty() { return true; }
		size_t size() { return size_; }

	private:
		struct node {
			std::shared_ptr<node> prev_;
			std::shared_ptr<node> next_;
			std::unique_ptr<T> data_;
		};

		std::shared_ptr<node> front_;
		std::shared_ptr<node> back_;
		size_t size_;
	};
}

#endif
