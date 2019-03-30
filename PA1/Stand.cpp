//-----------------------------------------------------------------------------
// Copyright Ed Keenan 2019
// Optimized C++
//----------------------------------------------------------------------------- 

#include "Framework.h"
#include "Stand.h"

// place holder for compiling purposes
// In each method replace with your code
#define STUB_PLEASE_REPLACE(x) (x)

// Methods

Stand::Stand()
{
	this->pHead = nullptr;
	this->pTail = nullptr;
	this->currentOrders = 0;
	this->peakOrders = 0;
}

Stand::Stand(Stand & stand)
{
	this->currentOrders = stand.GetCurrOrders();
	this->peakOrders = stand.GetPeakOrders();

}

Stand::~Stand()
{
	Order * temp = this->pHead;
	while (temp != nullptr)
	{
		Order * next = temp->GetNext();
		delete temp;
		temp = next;
	}
}

int Stand::GetCurrOrders()
{
	return this->currentOrders;
}

int Stand::GetPeakOrders()
{
	return this->peakOrders;
}

Order *Stand::GetHead()
{
	return this->pHead;
}

void Stand::Remove(Name name)
{
	Order * temp = this->pHead;
	while (temp)
	{
		Order * next = temp->GetNext();
		if (temp->GetName() == name)
		{
			if (temp == pTail && temp == pHead)
			{
				this->pHead = this->pTail = nullptr;
			}
			else if (temp == pTail)
			{
				this->pTail = temp->GetPrev();
				temp->GetPrev()->SetNext(nullptr);
			}
			else if (temp == pHead)
			{
				this->pHead = temp->GetNext();
				temp->GetNext()->SetPrev(nullptr);
			}
			else
			{
				temp->GetNext()->SetPrev(temp->GetPrev());
				temp->GetPrev()->SetNext(temp->GetNext());
			}
			delete temp;
		}
		temp = next;
	}
	this->currentOrders--;
}

void Stand::Add(Order *pOrder)
{
	if (!pHead)
	{
		this->pHead = pOrder;
		this->pTail = pOrder;
	}
	else
	{
		pOrder->SetPrev(this->pTail);
		this->pTail->SetNext(pOrder);
		this->pTail = pOrder;
	}
	this->currentOrders++;
	if (this->currentOrders > this->peakOrders)
		this->peakOrders++;
}

// ---  End of File ---------------

