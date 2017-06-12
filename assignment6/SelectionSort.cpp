#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

template <class elemType>
void print(elemType[], int);

template <class elemType>
int minLocation(elemType[], int, int);

template <class elemType>
void swap(elemType[], int, int);

template <class elemType>
void selectionSort(elemType[], int);

int main()
{
    time_t currentTime;
    time(&currentTime);
    
    cout << "started " << ctime(&currentTime) << endl;
    cout << endl;
    
    int x;
    //int num;
    
    ifstream inFile("./List.txt");
    
    if(inFile.fail())
    {
        cerr << "Error Opening File" << endl;
        exit(1);
    }
    
    string line;
    int LineNum = 1;
    
    while(getline(inFile, line))
    {
        if(LineNum == 1)
        {
            x = atoi(line.c_str());
            LineNum++;
        }
    }
    
    inFile.close();
    
    double intList[x];
    
    /*for(int i = 0; i < 100; i++)
     {
     num = (rand() + time(0)) % 10000;
     intList[i] = num;
     }*/
    
    ifstream inFile2("./List.txt");
    
    if(inFile2.fail())
    {
        cerr << "Error Opening File" << endl;
        exit(1);
    }
    
    LineNum = 1;
    
    while(getline(inFile2, line))
    {
        if(LineNum == 1)
        {
            LineNum++;
        }
        else
        {
            intList[LineNum - 2] = atof(line.c_str());
            LineNum++;
        }
    }
    
    inFile2.close();
    
    cout << "intList before sorting: " << endl;
    print(intList, x);
    cout << endl << endl;
    
    selectionSort(intList, x);
    
    cout << "intList after selection sort: " << endl;
    print(intList, x);
    cout << endl;
    
    time_t currentTime2;
    time(&currentTime2);
    
    cout << "ended " << ctime(&currentTime2) << endl;
    cout << endl;
    
    return 0;
}

template <class elemType>
void print(elemType list[], int length)
{
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        cout << setw(5) << list[i];
        count++;
        if(count % 10 == 0)
        {
            cout << endl;
        }
    }
}

template <class elemType>
int minLocation(elemType list[], int first, int last)
{
    int loc, minIndex;
    minIndex = first;
    for(loc = first + 1; loc <= last; loc++)
    {
        if(list[loc] < list[minIndex])
        {
            minIndex = loc;
        }
    }
    return minIndex;
}

template <class elemType>
void swap(elemType list[], int first, int second)
{
    elemType temp;
    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

template <class elemType>
void selectionSort(elemType list[], int length)
{
    int loc, minIndex;
    for(loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        swap(list, loc, minIndex);
    }
}