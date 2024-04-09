#include "Task.h"

Task::Task(int Id, int Tp, int W, int Tw)
{
	this->Id = Id;
	this->Tp = Tp;
	this->W = W;
	this->Tw = Tw;
}

int Task::get_Id()
{
	return this->Id;
}

int Task::get_Tp()
{
	return this->Tp;
}

int Task::get_W()
{
	return this->W;
}

int Task::get_Tw()
{
	return this->Tw;
}



