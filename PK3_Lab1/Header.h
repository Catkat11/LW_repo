#pragma once
#include <string>
#include<functional>
#include <iostream>

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
		Vector(const size_t size = 0, const T& defValue = DefValue<T>()) : size(size) , data(new T[size])
		{ 
			for (size_t i = 0; i < size; ++i)
			{
				data[i] = defValue;
			}

		}

		Vector(const Vector& v) noexcept :size(v.sizeGet()), data(new T[size])
		{
			for (size_t i = 0; i < size; ++i)
			{
				data[i] = v.data[i];
			}
		}

		Vector(const Vector&& v) noexcept : size(v.sizeGet()), data(v.sizeGet())
		{
			v.data = 0;
			v.data = nullptr;
		}

		~Vector() noexcept
		{
			delete[] data;
		}

		T& operator[](const size_t index) const
		{
			return data[index];
		}
		T& operator[](const size_t index)
		{
			return data[index];
		}

		size_t sizeGet() const noexcept
		{
			return size;
		}

		size_t dataGet()
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

		bool operator ==(Vector<T>& b) const
		{
			if (size != b.sizeGet())
				return false;
		    if (this->size < b.sizeGet())
			{
				for (int i = 0; i < this->size; i++)
				{
					if (data[i] != b[i])
						return false;
				}
				return false;
			}
			else
			{
				for (int i = 0; i < b.sizeGet(); i++)
				{
					if (data[i] != b[i])
						return false;
				}
				return false;
			}
		}
		bool operator !=(Vector<T>& b) const {
			if (size != b.sizeGet())
				return true;
			if (this->size < b.sizeGet()) 
			{
				for (int i = 0; i < this->size; i++) 
				{
					if (data[i] != b[i])
						return true;
				}
				return false;
			}
			else
			{
				for (int i = 0; i < b.sizeGet(); i++) 
				{
					if (data[i] != b[i])
						return true;
				}
				return false;
			}
		}
	};
}
