#include <iostream>

class MyClass 
{
	int id;
	int size;
	int* arr;
	static int amount_of_objects;
public:
	MyClass() 
	{
		id = ++amount_of_objects; //увеличение с 1
		size = 2;
		std::cout << "Создан обьект: " << this << std::endl;
		arr = new int[size] {-44, 58}; 
	}
	~MyClass()
	{
		std::cout << "Удален обьект: " << this << std::endl;
		delete[] arr;
		arr = nullptr;
	}
	MyClass(const MyClass& copy_object)
	{
		id = copy_object.id;
		std::cout << &copy_object << " копируется в " << this << std::endl;
		size = copy_object.size;
		arr = new int[size];
		for (int i = 0; i < size; i++) arr[i] = copy_object.arr[i];
	}
	MyClass& printInfo()
	{
		std::cout << "У обьекта " << this << " есть массив " << arr << std::endl;
		return *this;
	}
};

int MyClass::amount_of_objects = 0;

void myFunction(MyClass func_object)
{
	func_object.printInfo();
}

int main()
{
	system("chcp 1251");
	MyClass main_object;
	main_object.printInfo();
	myFunction(main_object);
	
	return 0;
}