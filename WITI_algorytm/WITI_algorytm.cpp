#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "Result.h"
#include "Data.h"

using namespace std;

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

    

    for (auto x : FileNames)
    {
        Data tmp = Data(x);
        dataTab.push_back(tmp);
    }
    /*
    for (auto x : dataTab)
    {
        cout << endl << x.getFilePath() << endl;
        x.printList();
    }*/

    //Result temp =  dataTab[0].SortW();
    //Result temp =  dataTab[0].SortTw();
    Result tempData =  dataTab[0].SortTw();
    //Result temp =  dataTab[0].PD_Algorytm();
    Result temp =  dataTab[0].TabuAlg(tempData);
    cout << temp.get_Penalty() << endl;
    temp.printOrder();
}
