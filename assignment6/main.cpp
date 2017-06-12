#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

template <class elemType>
void insertionSort(elemType[], int);

template <class elemType>
int partition(elemType[], int, int);

template <class elemType>
void swap(elemType[], int, int);

template <class elemType>
void recursiveQuick(elemType[], int, int);

template <class elemType>
void quickSort(elemType[], int);

template <class elemType>
int minLocation(elemType[], int, int);

template <class elemType>
void selectionSort(elemType[], int);

int main()
{
    int x = 100000;
    int num;
    
    /*ifstream inFile("./List.txt");
    
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
    
    inFile.close();*/
    
    double intList[x];
    double intList2[x];
    double intList3[x];
    
    for(int i = 0; i < 100000; i++)
     {
     num = (rand() + time(0)) % 100000;
     intList[i] = num;
     }
    
    /*ifstream inFile2("./List.txt");
    
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
            intList2[LineNum - 2] = atof(line.c_str());
            intList3[LineNum - 2] = atof(line.c_str());
            LineNum++;
        }
    }
    
    inFile2.close();*/
    
    cout << endl;
    
    time_t currentTime;
    time(&currentTime);
    
    cout << "insertion sort started " << ctime(&currentTime) << endl;
    
    insertionSort(intList, x);
    
    time_t currentTime2;
    time(&currentTime2);
    
    cout << "insertion sort ended " << ctime(&currentTime2) << endl;
    cout << endl;
    
    time_t currentTime3;
    time(&currentTime3);
    
    cout << "quick sort started " << ctime(&currentTime3) << endl;
    
    quickSort(intList2, x);
    
    time_t currentTime4;
    time(&currentTime4);
    
    cout << "quick sort ended " << ctime(&currentTime4) << endl;
    cout << endl;
    
    time_t currentTime5;
    time(&currentTime5);
    
    cout << "selection sort started " << ctime(&currentTime5) << endl;
    
    selectionSort(intList, x);
    
    time_t currentTime6;
    time(&currentTime6);
    
    cout << "selection sort ended " << ctime(&currentTime6) << endl;
    
    return 0;
}

template <class elemType>
void insertionSort(elemType list[], int length)
{
    for(int firstOrder = 1; firstOrder < length; firstOrder++)
    {
        if(list[firstOrder] < list[firstOrder - 1])
        {
            elemType temp = list[firstOrder];
            int location = firstOrder;
            do
            {
                list[location] = list[location - 1];
                location--;
            }while(location > 0 && list[location - 1] > temp);
            list[location] = temp;
        }
    }
}

template <class elemType>
int partition(elemType list[], int first, int last)
{
    elemType pivot;
    int index, smallIndex;
    
    swap(list, first, (first + last) / 2);
    
    pivot = list[first];
    smallIndex = first;
    
    for(index = first + 1; index <= last; index++)
    {
        if(list[index] < pivot)
        {
            smallIndex++;
            swap(list, smallIndex, index);
        }
        swap(list, first, smallIndex);
    }
    return smallIndex;
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
void recursiveQuick(elemType list[], int first, int last)
{
    int pivotLocation;
    
    if(first < last)
    {
        pivotLocation = partition(list, first, last);
        recursiveQuick(list, first, pivotLocation - 1);
        recursiveQuick(list, pivotLocation + 1, last);
    }
}

template <class elemType>
void quickSort(elemType list[], int length)
{
    recursiveQuick(list, 0, length - 1);
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
void selectionSort(elemType list[], int length)
{
    int loc, minIndex;
    for(loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        swap(list, loc, minIndex);
    }
}