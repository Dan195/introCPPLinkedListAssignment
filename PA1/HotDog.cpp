//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"

#include "HotDog.h"

// place holder for compiling purposes
// In each method replace with your code
#define STUB_PLEASE_REPLACE(x) (x)
HotDog::HotDog()
{
	this->condiments = Condiments::Plain;
	this->pNext = nullptr;
	this->pPrev = nullptr;
}

HotDog & HotDog::operator = (HotDog &hotdog)
{
	this->condiments = static_cast<Condiments>(hotdog.GetCondiments());
	this->pNext = nullptr;
	this->pPrev = nullptr;
	return *this;
}

HotDog::HotDog(HotDog &hotdog)
{
	this->condiments = static_cast<Condiments>(hotdog.GetCondiments());
	this->pNext = nullptr;
	this->pPrev = nullptr;

}

HotDog::~HotDog()
{
	//TODO
}

// Methods
void HotDog::Minus(Condiments condiment)
{
	// Only use bit-wise operations
	int condiment_subtract = static_cast<int>(condiment);
	if (static_cast<int>(condiments) >= 0)
	{
		condiment_subtract = static_cast<int>(condiments) &  ~condiment_subtract;
		condiments = static_cast<Condiments>(condiment_subtract);
	}
}

void HotDog::Add(Condiments condiment)
{
	// Only use bit-wise operations

	int condiments_temp = static_cast<int>(condiments);

	if (static_cast<int>(condiments) != 0)
	{
		condiments_temp = condiments_temp | static_cast<int>(condiment);
		condiments = static_cast<Condiments>(condiments_temp);
	}
	else
	{
		condiments = condiment;
	}

}

int HotDog::GetCondiments()
{
	return static_cast<int>(this->condiments);
}

HotDog *HotDog::GetNext()
{
	return this->pNext;
}

HotDog *HotDog::GetPrev()
{
	return this->pPrev;
}

void HotDog::SetNext(HotDog *pDog)
{
	this->pNext = pDog;
}

void HotDog::SetPrev(HotDog *pDog)
{
	this->pPrev = pDog;
}


// ---  End of File ---------------

