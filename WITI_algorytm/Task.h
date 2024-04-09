#pragma once
class Task
{
private:
	int Tp; //czas produkcji
	int W;
	int Tw; //wymagane do czasu

public:
	int get_Tp();
	int get_W();
	int get_Tw();
	Task(int Tp, int W, int Tw);


	
};

