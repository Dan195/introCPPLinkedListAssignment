//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#ifndef ORDER_H
#define ORDER_H

// Add files include as needed
#include "HotDog.h"
#include "Names.h"

class Order 
{
public:
	// add code here (add more methods if desired)
	Order();
	Order(Order &order);
	Order & operator = (Order & order);
	~Order();
	// Public Methods (Required)
	Order(Name setName);
	Name GetName();
	void SetName(Name setName);
	void Add(HotDog *pDog);
	void Remove(HotDog *pDog);

	// Methods used for Testing and Internals (Required)
	HotDog *GetHead();
	Order *GetNext();
	Order *GetPrev();
	void SetNext(Order *pOrder);
	void SetPrev(Order *pOrder);


private:
	// Data: ---------------------------
	//        add code here
	Name name;
	Order *pPrev;
	Order * pNext;
	HotDog* hotDogHead;
	HotDog* hotDogTail;
	void DeleteAllHotDogs();
};

#endif

// ---  End of File ---------------
