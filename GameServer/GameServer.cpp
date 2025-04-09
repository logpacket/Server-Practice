﻿#include "pch.h"
#include <iostream>
#include "CorePch.h"

#include <thread>
#include <mutex>

vector<int32> v;
mutex m;

// RAII (Resource Acquisition Is Initialization)
template<typename T>

class LockGuard
{
public:
	LockGuard(T& m) : m(m)
	{
		_mutex = m;
		_mutex.lock();
	}
	~LockGuard()
	{
		_mutex.unlock();
	}
private:
	T& _mutex;
};

void Push()
{
	for (int32 i=0; i< 10000;i++)
	{
		// 자물쇠 잠그기
		lock_guard<mutex> lock(m);
		// unique_lock<mutex> uniqueLock(m, std::defer_lock);
		v.push_back(i);
	}
}

int main()
{
	std::thread t1(Push);
	std::thread t2(Push);

	t1.join();
	t2.join();

	cout << "v.size() : " << v.size() << endl;
}
