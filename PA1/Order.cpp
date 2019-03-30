//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "Order.h"

// place holder for compiling purposes
// In each method replace with your code
#define STUB_PLEASE_REPLACE(x) (x)

// Methods
Order::Order()
{
	this->name = Name::Unknown;
	this->pNext = nullptr;
	this->pPrev = nullptr;
	this->hotDogHead = nullptr;
}

Order::Order(Name setNname)
{
	this->name = setNname;
	this->pNext = nullptr;
	this->pPrev = nullptr;
	this->hotDogHead = nullptr;
}

Order::Order(Order &order)
{
	this->name = order.name;
	this->hotDogHead = new HotDog(*order.hotDogHead);
	HotDog* tempHotDog = order.hotDogHead->GetNext();
	HotDog* tempHead = hotDogHead;
	while (tempHotDog)
	{
		tempHead->SetNext(new HotDog(*tempHotDog));
		tempHead->GetNext()->SetPrev(tempHead);
		if (tempHead->GetNext() == nullptr) {
			this->hotDogTail = tempHotDog;
		}
		tempHotDog = tempHotDog->GetNext();
		tempHead = tempHead->GetNext();
	}
	this->pPrev = order.pPrev;
	this->pNext = order.pNext;
}

Order & Order::operator = (Order &order)
{
	if (this->hotDogHead)
		this->DeleteAllHotDogs();
	this->name = order.name;
	this->hotDogHead = new HotDog(*order.GetHead());
	HotDog* tempHotDog = order.hotDogHead->GetNext();
	HotDog* tempHead = hotDogHead;
	while (tempHotDog)
	{
		tempHead->SetNext(new HotDog(*tempHotDog));
		tempHead->GetNext()->SetPrev(tempHead);
		tempHotDog = tempHotDog->GetNext();
		tempHead = tempHead->GetNext();
	}
	this->hotDogTail = tempHotDog != nullptr ? tempHotDog : tempHead;
	this->pPrev = order.pPrev;
	this->pNext = order.pNext;
	return *this;
}


Order::~Order()
{
	this->DeleteAllHotDogs();
}

void Order::Add(HotDog *p)
{
	if (this->hotDogHead == nullptr) 
	{
		this->hotDogHead = p;
		this->hotDogTail = p;
	}
	else
	{
		this->hotDogTail->SetNext(p);
		p->SetPrev(this->hotDogTail);
		this->hotDogTail = p;
	}
}

void Order::Remove(HotDog *p)
{
	if (p == hotDogHead)
	{
		this->hotDogHead = p->GetNext();
	}
	if (p == hotDogTail)
		this->hotDogTail = p->GetPrev();
	if (p->GetPrev() != nullptr)
		p->GetPrev()->SetNext(p->GetNext());
	if (p->GetNext() != nullptr)
		p->GetNext()->SetPrev(p->GetPrev());
	delete p;
}

Order *Order::GetNext()
{
	return this->pNext;
}

Order *Order::GetPrev()
{
	return this->pPrev;
}

HotDog *Order::GetHead()
{
	return this->hotDogHead;
}

void Order::SetNext(Order *p)
{
	this->pNext = p;
}

void Order::SetPrev(Order *p)
{
	this->pPrev = p;
}

Name Order::GetName()
{
	return static_cast<Name>(this->name);
}

void Order::SetName(Name setName)
{
	this->name = setName;
}

void Order::DeleteAllHotDogs()
{
	HotDog * temp = hotDogHead;
	while (temp != nullptr)
	{
		HotDog* next = temp->GetNext();
		delete temp;
		temp = next;
	}
}


// ---  End of File ---------------
