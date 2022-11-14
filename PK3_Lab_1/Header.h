#pragma once
#include <string>
#include<functional>
#include <iostream>
#include <vector>

namespace lw
{

	template<class T> T DefValue() { std::cout << "unknow type"; throw std::exception(); }
	template<> int DefValue() { return 0; };
	template<> double DefValue() { return 0.0; };
	template<> std::string DefValue() { return " "; };
	template<> char DefValue() { return ' '; };
	template<> float DefValue() { return 0; };
	template <typename T>
	class Vector
	{
		size_t size;
		T* data;
	public:
		Vector(const size_t size = 0, const T& defValue = DefValue<T>()) : size(size), data(new T[size])
		{
			for (size_t i = 0; i < size; ++i)
			{
				data[i] = defValue;
			}

		}

		Vector(const Vector& v) noexcept : size(v.sizeGetter()), data(new T[size]) 
		{
			for (size_t i = 0; i < size; i++)
				data[i] = v.data[i];
		}

		Vector(const Vector&& v) noexcept : size(v.sizeGetter()), data(v.sizeGetter())
		{
			v.data = nullptr;
		}

		~Vector() noexcept
		{
			delete[] data;
		}

		const T& operator[](const size_t index) const
		{
			return data[index];
		}
		T& operator[](const size_t index)
		{
			return data[index];
		}

		size_t sizeGetter() const noexcept
		{
			return size;
		}

		size_t dataGetter()
		{
			return data;
		}

		void pushback(const T& value) noexcept
		{
			++size;
			T* datatmp;
			datatmp = new T[size];
			for (size_t i = 0; i < size - 1; i++)
			{
				datatmp[i] = data[i];
			}
			datatmp[size - 1] = value;
			data = nullptr;
			data = datatmp;
		}

		Vector<T> operator =(const std::vector<T> v) noexcept 
		{
			delete[] data;
			data = nullptr;
			size = v.size();
			data = new T[size];
			for (size_t i = 0; i < size; i++) 
			{
				data[i] = v[i];
			}
			return *this;
		}
		void operator =(lw::Vector<T> v) noexcept 
		{
			delete[] this->data;
			this->data = nullptr;
			this->size = v.sizeGetter();
			this->data = new T[size];
			for (size_t i = 0; i < this->size; i++) 
			{
				this->data[i] = v[i];
			}
		}
		bool operator ==(Vector<T>& b) const 
		{
			if (size != b.sizeGetter())
				return false;
			if (this->size < b.sizeGetter()) 
			{
				for (int i = 0; i < this->size; i++) 
				{
					if (data[i] != b[i])
						return false;
				}
				return true;
			}
			else
			{
				for (int i = 0; i < b.sizeGetter(); i++) 
				{
					if (data[i] != b[i])
						return false;
				}
				return true;
			}
		}
		bool operator !=(Vector<T>& b) const 
		{
			if (size != b.sizeGetter())
				return true;
			if (this->size < b.sizeGetter()) {
				for (int i = 0; i < this->size; i++) 
				{
					if (data[i] != b[i])
						return true;
				}
				return false;
			}
			else
			{
				for (int i = 0; i < b.sizeGetter(); i++) 
				{
					if (data[i] != b[i])
						return true;
				}
				return false;
			}
		}
	};
}