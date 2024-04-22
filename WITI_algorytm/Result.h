#pragma once
#include <vector>
#include "Task.h"

class Result
{
private:

	int Penalty;
	std::vector<Task> Order;

public:
	Result(std::vector<Task> o); // konstruktor

	//gettery
	int get_Penalty();
	std::vector<Task> get_Order();

	//settery
	void set_Penalty(int Pen);
	void set_Order(std::vector<Task> ord);

	//licz kare calkowita
	int coutPenalty();

	//wyswietl 
	void printOrder();
	void printResult();
};

