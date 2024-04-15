#pragma once
#include <vector>
#include "Task.h"

class Result
{
private:
	int Penalty;
	std::vector<Task> Order;
public:
	Result(std::vector<Task> o);

	int get_Penalty();
	std::vector<Task> get_Order();

	void set_Penalty(int Pen);
	void set_Order(std::vector<Task> ord);

	int coutPenalty();

	void printOrder();
};

