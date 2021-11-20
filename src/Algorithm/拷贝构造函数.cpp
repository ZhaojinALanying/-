#include<iostream>
using namespace std;

class Ctest {
public:
	Ctest() {}
	~Ctest() {}
	Ctest(const Ctest& test) // 拷贝构造函数形式
	{
		cout << "copy constructor." << endl;
	}
	void operator=(const Ctest& test)
	{
		cout << "operator=" << endl;
	}
	void Test(Ctest test)
	{}
	Ctest Test2()
	{
		Ctest a;
		return a;
	}
	void Test3(Ctest& test)
	{}
	Ctest& Test4()
	{
		Ctest* pA = new Ctest;
		return *pA;
	}
};

int main()
{
	Ctest obj;
	Ctest obj1(obj);  // 类作为函数入参，值传递，将调用拷贝构造函数
	obj1 = obj;			// 已存在的类赋值，调用重载复制操作符函数(如果有定义的话)
	printf("test_1 end(obj %p),(obj1 %p)\n", obj, obj1);
	obj.Test(obj1);		// 调用函数 作为入参，将调用拷贝构造函数
	cout << "test_2 end" << endl;
	Ctest obj2;
	obj2 = obj.Test2();	// 做为临时变量返回时，将调用拷贝构造函数
	cout << "test_3 end" << endl;
	obj2.Test3(obj);	// 引用传递，不调用拷贝构造函数
	cout << "test_4 end" << endl;
	Ctest obj3;
	obj2.Test4();		// 返回值是引用，不调用拷贝构造函数
	cout << "test_5 end" << endl;
	return 0;
}