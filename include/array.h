#ifndef CONTAINERS_ARRAY_H
#define CONTAINERS_ARRAY_H

#include <memory>

namespace containers {
	template <class T> class array {
	public:
		array(size_t size = 0)
		    : m_size(size)
		    , m_data(size ? new T[size] : nullptr) {}

		array(const T& other)
		    : m_size(other.m_size)
		    , m_data(m_size ? new T[other.m_size] : nullptr) {
			std::copy(std::begin(other.m_data), std::end(other.m_data), std::begin(m_data));
		}

		array(T&& other)
		    : m_size(other.m_size)
		    , m_data(std::move(other.m_data)) {
			other.m_data = nullptr;
		}

		array& operator=(array other) {
			std::swap(*this, other);
			return *this;
		}

		~array() = default;

		T& operator[](size_t index) { return *(m_data.get() + index); }

	private:
		size_t m_size;
		std::unique_ptr<T> m_data;
	};
}

#endif
