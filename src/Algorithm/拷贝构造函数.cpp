#include<iostream>
using namespace std;

class Ctest {
public:
	Ctest() {}
	~Ctest() {}
	Ctest(const Ctest& test) // �������캯����ʽ
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
	Ctest obj1(obj);  // ����Ϊ������Σ�ֵ���ݣ������ÿ������캯��
	obj1 = obj;			// �Ѵ��ڵ��ำֵ���������ظ��Ʋ���������(����ж���Ļ�)
	printf("test_1 end(obj %p),(obj1 %p)\n", obj, obj1);
	obj.Test(obj1);		// ���ú��� ��Ϊ��Σ������ÿ������캯��
	cout << "test_2 end" << endl;
	Ctest obj2;
	obj2 = obj.Test2();	// ��Ϊ��ʱ��������ʱ�������ÿ������캯��
	cout << "test_3 end" << endl;
	obj2.Test3(obj);	// ���ô��ݣ������ÿ������캯��
	cout << "test_4 end" << endl;
	Ctest obj3;
	obj2.Test4();		// ����ֵ�����ã������ÿ������캯��
	cout << "test_5 end" << endl;
	return 0;
}