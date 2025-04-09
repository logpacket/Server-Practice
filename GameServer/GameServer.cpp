#include "pch.h"
#include <iostream>
#include "CorePch.h"

#include <thread>
#include <mutex>
#include "AccountManager.h"
#include "UserManager.h"


void Func1()
{
	for (int32 i = 0; i < 1; i++)
	{
		UserManager::Instance()->ProcessSave();
	}
}

void Func2()
{
	for (int32 i = 0; i < 1; i++)
	{
		AccountManager::Instance()->ProcessLogin();
	}
}

int main()
{
	thread t1(Func1);
	thread t2(Func2);

	t1.join();
	t2.join();

	cout << "Jobs done!" << endl;

	mutex m1;
	mutex m2;
	lock(m1, m2);

	lock_guard<mutex> lg1(m1, std::adopt_lock);
	lock_guard<mutex> lg2(m2, std::adopt_lock);

	return 0;
}
