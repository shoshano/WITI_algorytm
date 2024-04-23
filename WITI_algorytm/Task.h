#pragma once
#include <iostream>

class Task
{
private:
	int Id;
	int Tp; //czas produkcji
	int W;
	int Tw; //wymagane do czasu

public:
	Task(int Id, int Tp, int W, int Tw);
	int get_Id();
	int get_Tp();
	int get_W();
	int get_Tw();
	void printTask();	
};
