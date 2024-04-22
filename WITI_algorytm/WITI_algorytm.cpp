#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "Result.h"
#include "Data.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<string> getFileName()
{
    vector<string> tmpVec;

    string name = "data";
    string exension = ".txt";

    for (int i = 10; i < 21; i++)
    {
        string tmp = to_string(i);
        string tmpName = name + tmp + exension;
        tmpVec.push_back(tmpName);
    }
    return tmpVec;
}

int main()
{
    vector<string> FileNames = getFileName(); 
    vector<Data> dataTab;
    vector<Result> resultTab;
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point stop;
    high_resolution_clock::time_point wholeTime_start;
    high_resolution_clock::time_point wholeTime_stop;



    for (auto x : FileNames)
    {
        Data tmp = Data(x);
        dataTab.push_back(tmp);
    }

    wholeTime_start = high_resolution_clock::now();
    for (auto x : dataTab)
    {
        start = high_resolution_clock::now();
        Result res = x.makeResult();
        stop = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(stop - start);
        res.printResult();
        cout << "Czas: " << time_span.count() << "s\n\n";
    }
    wholeTime_stop = high_resolution_clock::now();
    duration<double> wholeTime_span = duration_cast<duration<double>>(wholeTime_stop - wholeTime_start);
    cout << "Calkowity czas: " << wholeTime_span.count() << "s\n\n";
}