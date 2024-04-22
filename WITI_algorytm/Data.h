#pragma once
#include "Task.h"
#include "Result.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <random>
#include <time.h>
#include <stdlib.h>

class Data
{
	int number_of_data;
	std::vector <Task> list;
	std::string file_path;

public:
	void GetData(); // pobira z pliku txt

	Data(std::string fp); // konstruktor
	// wlasne algorytmy
	Result SortW();
	Result SortTw();
	Result TabuAlg(Result res);

	// algorytm pd
	void PD_Algorytm();
	Result makeResult();

	//liczenie kary i aktalengo czasu
	int penalty(int time, Task task);
	int count_time(std::vector<Task> vec);

	// gettery
	std::vector<Task> getList();
	std::string getFilePath();

	// wyswitla liste
	void printList();
};


