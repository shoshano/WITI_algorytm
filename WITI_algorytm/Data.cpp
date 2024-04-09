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
			Task d = Task(0, 0, 0);
			getline(file, line);
			std::stringstream s(line);
			while (getline(s, chunk, ' '))
			{
				tmp.push_back(chunk);
			}
			d.get_Id = i + 1;
			d.get_Tp = stoi(tmp.at(0));
			d.get_W = stoi(tmp.at(1));
			d.get_Tw = stoi(tmp.at(2));

			list.push_back(d);
			tmp.erase(tmp.begin(), tmp.end());
		}
	}
	else {
		std::cout << "Plik nie otwarty";
	}
}

