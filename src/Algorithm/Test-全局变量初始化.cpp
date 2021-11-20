#include<iostream>
using namespace std;

int Foo();
int Gear();

int g_alice = Foo();
int g_bob = Gear();

int Foo()
{
	return g_bob;
}
int Gear()
{ 
	return 3;
}

int main()
{
	std::cout << g_alice << endl;
	return 0;
}