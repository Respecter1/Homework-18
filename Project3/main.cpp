/*
	3. ������� ���� Set, ���� ���������� � ����� ������ BoundedAray.
*/
#include <iostream>
#include <cstdlib>
#include <format>

class BoundedAray
{
private:
	int* arr_;
	size_t size_;
public:
	BoundedAray() = default;                //Default constructor
	BoundedAray(size_t size);               //Construction
	BoundedAray(const BoundedAray& other);  //Copy construction
	BoundedAray(BoundedAray&& other);       //Move constructor 
	~BoundedAray();							//Destrucrtor 

	size_t GetSize()const { return size_; }					//Field access "size"
	const int* GetArr()const { return arr_ ? arr_ : 0; };	//Field access "arr"

	BoundedAray operator[] (size_t index) { return arr_[size_]; };			 // []
	const BoundedAray operator[] (size_t index)const { return arr_[size_]; } //Const []

	BoundedAray operator=(const BoundedAray& other);//Copy =
	BoundedAray operator=(BoundedAray&& other);		//Move =
	friend std::ostream& operator<<(std::ostream& out, const BoundedAray& other);
	friend std::istream& operator>>(std::istream& in, BoundedAray& other);

};

BoundedAray::BoundedAray(size_t size)
	:size_(size), arr_(new int[size_])
{ }

BoundedAray::BoundedAray(const BoundedAray& other)
	:size_(other.size_), arr_(other.arr_)
{
	for (size_t i = 0; i < size_; i++)
	{
		arr_[i] = other.arr_[i];
	}
}

BoundedAray::BoundedAray(BoundedAray&& other)
	:size_(other.size_), arr_(other.arr_)
{
	other.size_ = 0;
	other.arr_ = nullptr;
}

BoundedAray::~BoundedAray()
{
	delete[] arr_;
	size_ = 0;
	arr_ = nullptr;
}


BoundedAray BoundedAray::operator=(const BoundedAray& other)
{
	if (this != &other)
	{
		delete[] arr_;

		size_ = other.size_;
		arr_ = new int[size_];

		for (size_t i = 0; i < size_; i++)
		{
			arr_[i] = other.arr_[i];
		}
	}
	return *this;
}

BoundedAray BoundedAray::operator=(BoundedAray&& other)
{
	if (this != &other)
	{
		delete[] arr_;

		size_ = other.size_;
		arr_ = new int[size_];

		other.size_ = 0;
		other.arr_ = nullptr;
	}
	return *this;
}
//��� ������
std::ostream& operator<<(std::ostream& out, const BoundedAray& other) {
	// ����������, �� BoundedAray ������ ����� � ������ ����� ��� ������ ����
	for (size_t i = 0; i < other.size_; ++i) {
		out << other.arr_[i]; // ��������� ������� �������� ������
	}
	return out; // ���������� ��������� �� ���� ��� ������������ ���������
}

//��� ����� 
std::istream& operator>>(std::istream& in, BoundedAray& other) //��� ������� ����� �� ������ ������� ����
{
	// ����������, �� BoundedAray ������ ����� � ������ ����� ��� ������ ����
	for (size_t i = 0; i < other.size_; ++i)
	{
		in >> other.arr_[i]; // �������� ������� �������� ������
	}
	return in; // ���������� ��������� �� ���� ��� ������������ ��������
}


class Set
{
public:
	Set() = default;
	Set(size_t size): array_(size){}
	~Set(){}

	void Show();
	void initialize();
private:
	BoundedAray array_;
};

void Set::Show()
{
	for (size_t i = 0; i < array_.GetSize(); i++)
	{
		std::cout << array_[i];
	}
}

void Set::initialize()
{
	for (size_t i = 0; i < array_.GetSize(); i++)
	{
		array_[i] = rand() % 20;
	}
}
