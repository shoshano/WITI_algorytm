#pragma once
class Task
{
private:
	int Tp; //czas produkcji
	int W;
	int Tw; //wymagane do czasu

public:
	Task(int Tp, int W, int Tw);
	int get_Tp();
	int get_W();
	int get_Tw();



	
};

