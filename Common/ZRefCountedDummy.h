#pragma once
#include "ZRefCounted.h"
#include "ZRecyclable.h"
#include "ZRecyclableAvBuffer.h"

template <class T>
class ZRefCountedDummy : public ZRefCounted, public ZRecyclable<ZRefCountedDummy<T>, 16, T>
{
protected:
	T t;

public:
	void* operator new(unsigned int uSize)
	{
		return ZRecyclableAvBuffer<ZRefCountedDummy<T>>::GetInstance()->raw_new();
	}

	void* operator new[](unsigned int uSize)
	{
		return ZRecyclableAvBuffer<ZRefCountedDummy<T>>::GetInstance()->raw_new();
	}

		void operator delete(void* p)
	{
		ZRecyclableAvBuffer<ZRefCountedDummy<T>>::GetInstance()->raw_delete(p);
	}

	void operator delete[](void* p)
	{
		ZRecyclableAvBuffer<ZRefCountedDummy<T>>::GetInstance()->raw_delete(p);
	}
};

assert_size(sizeof(ZRefCountedDummy<int>), 0x14);