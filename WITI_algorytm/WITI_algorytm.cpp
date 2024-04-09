#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "Result.h"
#include "Data.h"

using namespace std;

int main()
{
    vector<string> FileNames;
    string name = "data";
    string exension = ".txt";

    for (int i = 10; i < 21; i++)
    {
        string tmp = to_string(i);
        string tmpName= name + tmp;
        FileNames.push_back(tmpName);
    }

    for (auto x : FileNames)
    {
        cout << x << "\n";
    }
}
