#include "Result.h"

Result::Result()
{

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
