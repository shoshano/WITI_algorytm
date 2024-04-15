#include "Result.h"

Result::Result(std::vector<Task> o)
{
	Order = o;
	Penalty = coutPenalty();
}

int Result::get_Penalty()
{
	return this->Penalty;
}

std::vector<Task> Result::get_Order()
{
	return this->Order;
}

void Result::set_Order(std::vector<Task> ord)
{
	this->Order = ord;
}

void Result::set_Penalty(int Pen)
{
	this->Penalty = Pen;
}

int Result::coutPenalty()
{	
	int T = 0;
	int P = 0;
	for (auto i : Order)
	{
		T += i.get_Tp();
		if ((i.get_W() * (T - i.get_Tw())) > 0)
		{
			P += i.get_W() * (T - i.get_Tw());
		}
	}

	return P;
}

void Result::printOrder()
{
	for (auto i : Order)
	{
		std::cout << i.get_Id() << " ";
	}

}
