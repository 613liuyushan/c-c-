// cpp_study.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <thread>
#include <future>
#include <iostream>
#include <chrono>
#include <mutex>

using namespace std;
bool bIsStooped = false;
std::mutex mtx;
void funcThread() 
{
	while (!bIsStooped) {
		this_thread::sleep_for(chrono::seconds(5));
	}
}
class CBase
{
public:
	virtual void func();
	void test() { cout << "test"; };
protected:
	//int a = 10;
};
class CDrived : public CBase
{
public:
	virtual void func() { cout << "cai ji"; };
};

int main()
{
	CDrived c;
	//CBase* p = new CBase();
	//p->test();
// 	std::thread th1(funcThread);
// 	this_thread::sleep_for(chrono::seconds(1));
// 	bIsStooped = true;
// 
// 	th1.join();

	return 0;
}

