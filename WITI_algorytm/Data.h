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

	void GetData();
	Data(std::string fp);
	Result SortW();
	Result SortTw();

	std::vector<Task> getList();
	std::string getFilePath();

	void printList();
};


