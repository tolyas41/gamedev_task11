#include "ObjectPool.h"
#include <iostream>


int main()
{

	ObjectPool::GetInstance()->testprint();

	Object obj = ObjectPool::GetInstance()->GetObject();
	obj.Multiplicate(3);
	std::cout << obj.GetValue();

	return 0;
}