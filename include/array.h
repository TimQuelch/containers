#ifndef CONTAINERS_ARRAY_H
#define CONTAINERS_ARRAY_H

#include <memory>

namespace containers {
	template <class T> class array {
	public:
		array(size_t size = 0)
		    : size_{size}
		    , data_{size ? std::make_unique<T[]>(size) : nullptr} {}

		array(const T& other)
		    : size_{other.size_}
		    , data_{size_ ? std::make_unique<T[]>(other.size_) : nullptr} {
			std::copy(std::begin(other.data_), std::end(other.data_), std::begin(data_));
		}

		array(T&& other)
		    : size_{other.size_}
		    , data_{std::move(other.data_)} {
			other.data_ = nullptr;
		}

		array& operator=(array other) {
			std::swap(*this, other);
			return *this;
		}

		~array() = default;

		T& operator[](size_t index) { return *(data_.get() + index); }
		size_t size() { return size_; }

	private:
		size_t size_;
		std::unique_ptr<T[]> data_;
	};
}

#endif
