#include "ObjectPool.h"
#include "Decorator.h"
#include "ChainOfResponsibility.h"
#include <iostream>


int main()
{
	//1. Object Pool
	{
		ObjectPool* pool = ObjectPool::GetInstance();

		Object* obj = pool->GetObject();

		obj->SetValue(3);
		obj->Multiplicate(3);
		std::cout << obj->GetValue() << std::endl;

		pool->ReleaseObject(obj);
		std::cout << obj->GetValue() << std::endl;

		Object* obj2 = pool->GetObject();
		obj2->SetValue(2);
		obj2->Multiplicate(55);

		std::cout << obj2->GetValue() << std::endl;
	}

	//2. Decorator
	{
		PrintFactory* regular = new Printer();

		PrintFactory* PrintDecOne = new PrinterDecoratorOne(regular);
		PrintFactory* PrintDecTwo = new PrinterDecoratorTwo(regular);
		PrintFactory* PrintDecTwoWrappOne = new PrinterDecoratorTwo(PrintDecOne);


		std::cout << "just regular";
		regular->PrintOperation();

		std::cout << "\n---regular + first : \n";
		PrintDecOne->PrintOperation();

		std::cout << "\n---regular + second : \n";
		PrintDecTwo->PrintOperation();

		std::cout << "\n---regular + first + second : \n";
		PrintDecTwoWrappOne->PrintOperation();


		delete regular;
		delete PrintDecOne;
		delete PrintDecTwo;
		delete PrintDecTwoWrappOne;
	}

	//3. Chain Of Responsibility
	{
		LowPriority* low = new LowPriority;
		NormalPriority* normal = new NormalPriority;
		HighPriority* high = new HighPriority;
		low->SetNext(normal)->SetNext(high);

		std::cout << low->Handle("High");
		std::cout << low->Handle("Normal");
		std::cout << low->Handle("Low");
	}
	return 0;
}