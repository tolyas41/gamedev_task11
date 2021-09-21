#pragma once

#include <list>
#include <iostream>

class Object
{
private:
	int Value{ 0 };
	bool InUse{ false };

public:

	const bool operator==(const Object& RightObject)
	{
		return Value == RightObject.Value;
	}

	Object(){}
	Object(const Object& source)
	{
		Value = source.Value;
	}
	Object& operator=(const Object& source)
	{
		Value = source.Value;
	}
	void Reset()
	{
		Value = 0;
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
	void SetValue(int val)
	{
		Value = val;
	}
};


class ObjectPool
{
private:

	static ObjectPool* PoolInstance;
	ObjectPool(){}
	std::list<Object*> ObjectList;

public:

	static ObjectPool* GetInstance() {
		if (!PoolInstance)
			PoolInstance = new ObjectPool;
		return PoolInstance;
	}

	Object* GetObject()
	{
		if (!ObjectList.empty())
		{
			std::cout << "using existing object\n";
			Object* obj = ObjectList.front();
			ObjectList.pop_front();
			return obj;
		}
		else
		{
			std::cout << "creating new object\n";
			return new Object;
		}
	}

	void ReleaseObject(Object* ObjToRelease)
	{
		ObjectList.push_back(ObjToRelease);
		ObjToRelease->Reset();
	}

	void testprint()
	{
		for (auto a : ObjectList)
		std::cout << a->GetValue() << std::endl;
	}
};


ObjectPool* ObjectPool::PoolInstance = nullptr;