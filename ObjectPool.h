#pragma once

#include <vector>
#include <iostream>

class Object
{
private:
	bool InUse{ false };

public:

	int Value{ 3 };
	Object()
	{

	}
	bool IsInUse()
	{
		return InUse;
	}
	void SetInUse(bool use)
	{
		InUse = use;
	}
	void Multiplicate(int mult)
	{
		Value *= mult;
	}
	int GetValue()
	{
		return Value;
	}
};


class ObjectPool
{
private:
	static ObjectPool* PoolInstance;
	size_t PoolMaxSize{ 11 };
	ObjectPool()
	{
		FillList();
	}
	std::vector<Object> ObjectList;

public:
	static ObjectPool* GetInstance();

	Object GetObject()
	{
		for (size_t i = 0; i < PoolMaxSize; i++)
			if (!ObjectList[i].IsInUse())
			{
				ObjectList[i].SetInUse(true);
				ObjectList[i].Multiplicate(20);		//testing
				return ObjectList[i];
			}
		std::cout << "\nNo free objects for you sorry\n";
		Object n;
		return n;
	}

	void ReleaseObject(Object ObjToRelease)
	{

	}

	void FillList()
	{
		for (size_t i = 0; i < PoolMaxSize; i++)
		{
			ObjectList.push_back(Object());
		}
	}
	void testprint()
	{
		for (auto a : ObjectList)
			std::cout << a.Value << std::endl;
	}
};


ObjectPool* ObjectPool::PoolInstance = nullptr;


ObjectPool* ObjectPool::GetInstance() {
	if (!PoolInstance)
		PoolInstance = new ObjectPool();
	return PoolInstance;
}












//private:
//	static Singleton* p_instance;
//	// Конструкторы и оператор присваивания недоступны клиентам
//	Singleton() {}
//	Singleton(const Singleton&);
//	Singleton& operator=(Singleton&);
//  public:
//	  static Singleton* getInstance() {
//		  if (!p_instance)
//			  p_instance = new Singleton();
//		  return p_instance;
//	  }