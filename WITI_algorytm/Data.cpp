#include "Data.h"

void Data::GetData() 
{
	number_of_data = 0;
	std::string n;
	std::fstream file;
	file.open(file_path);
	std::string line, chunk;
	std::vector<std::string> tmp;
	if (file.is_open()) {
		getline(file, line);
		number_of_data = stoi(line);
		for (int i = 0; i < number_of_data; i++) {
			getline(file, line);
			std::stringstream s(line);
			while (getline(s, chunk, ' '))
			{
				tmp.push_back(chunk);
			}
			Task d = Task(i+1, stoi(tmp.at(0)), stoi(tmp.at(1)), stoi(tmp.at(2)));
			
			list.push_back(d);
			tmp.erase(tmp.begin(), tmp.end());
		}
	}
	else {
		std::cout << "Plik nie otwarty";
	}
}

Data::Data(std::string fp)
{
	file_path = fp;
	GetData();
}

Result Data::SortW() //sort W
{
	std::vector<Task> temp = this->list;
	sort(temp.begin(), temp.end(), [](Task l, Task r) {
			return l.get_W() > r.get_W();
	});

	Result result(temp);


	return result;
}

Result Data::SortTw() //sort tW
{
	std::vector<Task> temp = this->list;
	sort(temp.begin(), temp.end(), [](Task l, Task r) {
		return l.get_Tw() < r.get_Tw();
		});

	Result result(temp);


	return result;
}

void Data::PD_Algorytm(std::vector<Task> vec)
{
	//std::vector<Task> tmpOrder = vec;
	if (vec.size() == 1)
	{
		resultsList.push_back(vec.at(0));
		return;
	}
	
	int cTime = count_time(vec);
	int current_penalty = INT16_MAX;
	int chosen_id = 0;

	for (int i =0; i<vec.size();++i)
	{
		int pen = penalty(cTime, vec.at(i));
		if (current_penalty > pen)
		{
			chosen_id = i;
			current_penalty = pen;
		}
	}

	Task tmp = vec.at(chosen_id);
	vec.erase(vec.begin() + chosen_id);
	PD_Algorytm(vec);
	resultsList.push_back(tmp);
	return;
}

Result Data::makeResult(std::vector<Task> order)
{
	return Result(order);
}

Result Data::TabuAlg(Result res)
{
	std::vector<Task> s = res.get_Order();
	//std::vector<Task> s = schrage();
	std::vector<Task> best = s;

	int bestPen = res.coutPenalty();

	std::vector<std::vector<Task>> neighbors;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			std::vector<Task> neighbor = s;
			std::swap(neighbor.at(i), neighbor.at(j));
			neighbors.push_back(neighbor);
		}
	}

	for (auto x : neighbors)
	{
		Result result(x);
		int tmpPen = result.coutPenalty();
		if (tmpPen < bestPen)
		{
			best = x;
			bestPen = tmpPen;
		}
	}

	Result bestRes(best);
	return bestRes;
}


std::vector<Task> Data::getList()
{
	return this->list;
}

std::vector<Task> Data::getResultOrder()
{
	return this->resultsList;
}

std::string Data::getFilePath()
{
	return this->file_path;

}

void Data::printList()
{
	for(auto i:list)
	{
		i.printTask();
	}
	
}

int Data::penalty(int time, Task task) 
{
	return task.get_W() * std::max(0, time - task.get_Tw());
}

int Data::count_time(std::vector<Task> vec)
{
	int Cmax = 0;
	for (auto x : vec)
	{
		Cmax += x.get_Tp();
	}
	return Cmax;
}
