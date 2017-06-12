#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

void PrintForward(node* head);

int main()
{
    node* head;
    node* tail;
    node* n;
    
    string TextFile = "TestFile.txt";
    
    cout << "Enter the name of the file" << endl;
    cin >> TextFile;
    
    ifstream inFile(TextFile);
    
    if(inFile.fail())
    {
        cerr << "Error Opening File" << endl;
    }
    
    int number;
    int count = 0;
    
    while(!inFile.eof())
    {
        inFile >> number;
        
        if(count == 0)
        {
            n = new node;
            n->data = number;
            n->prev = NULL;
            head = n;
            tail = n;
        }
        
        else
        {
            n = new node;
            n->data = number;
            tail->next = n;
            n->prev = tail;
            tail = n;
            tail->next = NULL;
            //cout << "Node " << count << " has the value of" << n->data << endl;
        }
        
        count++;
    }
    
    inFile.close();
    
    cout << "This is what you linked list looks like" << endl;
    PrintForward(head);
    
    int y = 5;
    int x = 12;
    int xCount = 0;
    
    node* temp2 = head->next;
    
    while(temp2 != NULL)
    {
        x = temp2->data;
        temp2 = temp2->next;
        xCount = temp2->data;
        while(xCount > 0)
        {
            temp2 = temp2->next;
            xCount = xCount - 1;
        }
        temp2 = temp2->next;
    }
    xCount = 0;
    
    cout << "There are " << y << " windows open in this file" << endl;
    
    cout << "The latest time students visit the windows is " << x << endl;
    
    double WindowLines[y][x + 1];
    
    int yCount = 0;
    
    while(yCount < y)
    {
        while(xCount < x + 1)
        {
            WindowLines[yCount][xCount] = 0;
            xCount++;
        }
        xCount = 0;
        yCount++;
    }
    yCount = 0;
    
    int xCount2 = 0;
    
    int yCount2 = 0;
    
    double StudentTotal = 0;
    int StudentNumber = 0;
    
    temp2 = head->next;
    
    while(temp2 != NULL)
    {
        xCount2 = temp2->data;
        temp2 = temp2->next;
        xCount = temp2->data;
        while(xCount > 0)
        {
            temp2 = temp2->next;
            StudentTotal = StudentTotal + temp2->data;
            if(WindowLines[yCount][xCount2] == 0)
            {
                WindowLines[yCount][xCount2] = temp2->data;
            }
            
            if(WindowLines[yCount][xCount2] != 0)
            {
                yCount2 = yCount + 1;
                while(yCount2 != yCount && WindowLines[yCount2][xCount2] != 0)
                {
                    yCount2++;
                    if(yCount2 >= y)
                    {
                        yCount2 = 0;
                    }
                }
                WindowLines[yCount2][xCount2] = WindowLines[yCount2][xCount2] + temp2->data;
            }
            yCount++;
            if(yCount >= y)
            {
                yCount = 0;
            }
            
            if(WindowLines[yCount][xCount2] > 60 && xCount2 < x)
            {
                WindowLines[yCount][xCount2 + 1] = WindowLines[yCount][xCount2 + 1] + (WindowLines[yCount][xCount2] - 60);
            }
            StudentNumber++;
            xCount = xCount - 1;
        }
        yCount = 0;
        temp2 = temp2->next;
    }
    xCount = 0;
    
    //cout << "The second student at time 1 will need " << WindowLines[1][1] << " minutes" << endl;
    
    double Mean_Student_Wait_Time = 0;
    double Median_Student_Wait_Time = 0;
    double Longest_Student_Wait_Time = 0;
    int Number_of_Students_Waiting_Over_10_Min = 0;
    double Mean_Window_Idle_Time = 0;
    double WindowTotal = 0;
    double WindowNumber = 0;
    double Longest_Window_Idle_Time = 0;
    int Number_of_Windows_Idle_for_over_5_min = 0;
    
    while(yCount < y)
    {
        while(xCount < x + 1)
        {
            if(Longest_Student_Wait_Time < WindowLines[yCount][xCount])
            {
                Longest_Student_Wait_Time = WindowLines[yCount][xCount];
            }
            
            if(WindowLines[yCount][xCount] > 10)
            {
                Number_of_Students_Waiting_Over_10_Min++;
            }
            
            if(WindowLines[yCount][xCount] < 60)
            {
                WindowTotal = WindowTotal + (60 - WindowLines[yCount][xCount]);
                WindowNumber++;
                if(Longest_Window_Idle_Time < 60 - WindowLines[yCount][xCount])
                {
                    Longest_Window_Idle_Time = 60 - WindowLines[yCount][xCount];
                }
                
                if(60 - WindowLines[yCount][xCount] > 5)
                {
                    Number_of_Windows_Idle_for_over_5_min++;
                }
            }
            xCount++;
        }
        xCount = 0;
        yCount++;
    }
    yCount = 0;
    
    Mean_Student_Wait_Time = StudentTotal / StudentNumber;
    Mean_Window_Idle_Time = WindowTotal / WindowNumber;
    
    double MedianCalculator[StudentNumber];
    
    xCount = 0;
    yCount = 0;
    xCount2 = 0;
    yCount2 = 0;
    temp2 = head->next;
    
    cout << "The student wait times are" << endl;
    
    while(temp2 != NULL)
    {
        temp2 = temp2->next;
        xCount = temp2->data;
        while(xCount > 0)
        {
            temp2 = temp2->next;
            MedianCalculator[xCount2] = temp2->data;
            xCount2++;
            xCount = xCount - 1;
            cout << temp2->data << " ";
        }
        temp2 = temp2->next;
    }
    xCount = 0;
    cout << endl;
    
    if(StudentNumber % 2 == 0)
    {
        Median_Student_Wait_Time = MedianCalculator[(StudentNumber / 2) - 1];
    }
    
    else
    {
        Median_Student_Wait_Time = MedianCalculator[((StudentNumber - 1) / 2)];
    }
    
    cout << "The mean student wait time is " << Mean_Student_Wait_Time << " minute(s)" << endl;
    cout << "The median student wait time is " << Median_Student_Wait_Time << " minute(s)" << endl;
    cout << "The longest student wait time is " << Longest_Student_Wait_Time << " minute(s)" << endl;
    cout << "The number of students waiting over 10 minutes is " << Number_of_Students_Waiting_Over_10_Min << " student(s)" << endl;
    cout << "The mean window idle time is " << Mean_Window_Idle_Time << " minute(s)" << endl;
    cout << "The longest window idle time is " << Longest_Window_Idle_Time << " minute(s)" << endl;
    cout << "There is/are " << Number_of_Windows_Idle_for_over_5_min << " window(s) idle for over 5 minutes" << endl;
}

void PrintForward(node* head)
{
    //cout << "PrintForward started" << endl;
    node* temp = head;
    
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    //cout << "PrintForward executed" << endl;
}