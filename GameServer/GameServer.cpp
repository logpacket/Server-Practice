﻿#include "pch.h"
#include <iostream>
#include "CorePch.h"

#include <thread>

atomic<int32> sum = 0;

void Add()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		sum++;
	}
}
void Sub()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		sum--;
	}
}
int main()
{
	Add();
	Sub();
	std::cout << sum << std::endl;

	std::thread t1(Add);
	std::thread t2(Sub);
	t1.join();
	t2.join();
	std::cout << sum << std::endl;
}
