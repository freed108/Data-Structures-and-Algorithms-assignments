#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

#include "BST.cpp"

using namespace std;

int main()
{
    BST myTree;
    BST myTree2;
    BST myTree3;
    BST myTree4;
    BST myTree5;
    int undo = 0;
    int idNum;
    int idNum2;
    int idNum3;
    int idNum4;
    string Name;
    string Year;
    string Level;
    string Major;
    string Department;
    int Advisor;
    double Grade;
    
    myTree.AddLeaf(10000, "none", "none", "none", 0, 0);
    
    int choice = 1;
    int choice2 = 1;
    
    ifstream inFile("./StudentTable.txt");
    
    if(inFile.fail())
    {
        cerr << "Error Opening File" << endl;
        exit(1);
    }
    
    string line;
    int LineNum = 1;
    idNum =10001;
    
    while(getline(inFile, line))
    {
        if(LineNum == 1)
        {
            Name = line;
            cout << "1" << endl;
            cout <<"name " << Name << endl;
            LineNum++;
        }
        else if(LineNum == 2)
        {
            Year = line;
            cout << "2" << endl;
            cout << Year << endl;
            LineNum++;
        }
        else if(LineNum == 3)
        {
            Major = line;
            cout << "3" << endl;
            cout << Major << endl;
            LineNum++;
        }
        else if(LineNum == 4)
        {
            Advisor = atoi(line.c_str());
            cout << "4" << endl;
            cout << Advisor << endl;
            LineNum++;
        }
        else if(LineNum == 5)
        {
            Grade = atof(line.c_str());
            cout << "5" << endl;
            cout << Grade << endl;
            
            cout << "6" << endl;
            myTree.AddLeaf(idNum, Name, Year, Major, Advisor, Grade);
            cout << "7" << endl;
            idNum++;
            cout << "8" << endl;
            cout << "9" << endl;
            LineNum = 1;
        }
    }
    
    inFile.close();
    
    ifstream inFile2("FacultyTable.txt");
    
    if(inFile2.fail())
    {
        cerr << "Error Opening File" << endl;
        exit(1);
    }
    
    LineNum = 0;
    idNum2 = 1;
    
    while(getline(inFile2, line))
    {
        LineNum++;
        if(LineNum == 1)
        {
            Name = line;
            cout << "1" << endl;
            cout << Name << endl;
        }
        else if(LineNum == 2)
        {
            Level = line;
            cout << "2" << endl;
            cout << Level << endl;
        }
        else if(LineNum == 3)
        {
            Department = line;
            cout << "3" << endl;
            cout << Department << endl;
            
            myTree.AddLeaf(idNum2, Name, Level, Department, 0, 4.0);
            idNum2++;
            cout << "4" << endl;
            LineNum = 0;
        }
    }
    
    inFile2.close();
    
    cout << "Welcome to the assignment 5 database recreation" << endl;
    cout << endl;
    
    cout << "Enter 1 to print all students and their information by ascending id #" << endl;
    cout << "Enter 2 to print all faculty and their information by ascending id #" << endl;
    cout << "Enter 3 to find and display student information" << endl;
    cout << "Enter 4 to find and display faculty information" << endl;
    cout << "Enter 5 to add a new student" << endl;
    cout << "Enter 6 to delete a student" << endl;
    cout << "Enter 7 to add a new faculty member" << endl;
    cout << "Enter 8 to delete a faculty member" << endl;
    cout << "Enter 9 to change a student's advisor" << endl;
    cout << "Enter 10 to rollback the last change made to the tables" << endl;
    cout << "Enter 11 to exit the program" << endl;
    cout << "Which option would you like to choose?" << endl;
    cin >> choice2;
    
    while(choice == 1)
    {
        if(choice2 == 1)
        {
            cout << "You have chosen to print all students and their information by ascending id #" << endl;
            cout << endl;
            cout << endl;
            
            myTree.StudentPrintInOrder();
            
            cout << endl;
            
            cout << "Enter 1 to print all students and their information by ascending id #" << endl;
            cout << "Enter 2 to print all faculty and their information by ascending id #" << endl;
            cout << "Enter 3 to find and display student information" << endl;
            cout << "Enter 4 to find and display faculty information" << endl;
            cout << "Enter 5 to add a new student" << endl;
            cout << "Enter 6 to delete a student" << endl;
            cout << "Enter 7 to add a new faculty member" << endl;
            cout << "Enter 8 to delete a faculty member" << endl;
            cout << "Enter 9 to change a student's advisor" << endl;
            cout << "Enter 10 to rollback the last change made to the tables" << endl;
            cout << "Enter 11 to exit the program" << endl;
            cout << "Which option would you like to choose?" << endl;
            cin >> choice2;
        }
        
        else if(choice2 == 2)
        {
            cout << "You have chosen to print all faculty and their information by ascending id #" << endl;
            cout << endl;
            cout << endl;
            
            myTree.FacultyPrintInOrder();
            
            cout << endl;
            
            cout << "Enter 1 to print all students and their information by ascending id #" << endl;
            cout << "Enter 2 to print all faculty and their information by ascending id #" << endl;
            cout << "Enter 3 to find and display student information" << endl;
            cout << "Enter 4 to find and display faculty information" << endl;
            cout << "Enter 5 to add a new student" << endl;
            cout << "Enter 6 to delete a student" << endl;
            cout << "Enter 7 to add a new faculty member" << endl;
            cout << "Enter 8 to delete a faculty member" << endl;
            cout << "Enter 9 to change a student's advisor" << endl;
            cout << "Enter 10 to rollback the last change made to the tables" << endl;
            cout << "Enter 11 to exit the program" << endl;
            cout << "Which option would you like to choose?" << endl;
            cin >> choice2;
        }
        
        else if(choice2 == 3)
        {
            cout << "You have chosen to find and display student information" << endl;
            cout << endl;
            
            cout << "Enter the student's ID #" << endl;
            cin >> idNum3;
            
            myTree.StudentReturnNode(idNum3);
            
            cout << endl;
            
            cout << "Enter 1 to print all students and their information by ascending id #" << endl;
            cout << "Enter 2 to print all faculty and their information by ascending id #" << endl;
            cout << "Enter 3 to find and display student information" << endl;
            cout << "Enter 4 to find and display faculty information" << endl;
            cout << "Enter 5 to add a new student" << endl;
            cout << "Enter 6 to delete a student" << endl;
            cout << "Enter 7 to add a new faculty member" << endl;
            cout << "Enter 8 to delete a faculty member" << endl;
            cout << "Enter 9 to change a student's advisor" << endl;
            cout << "Enter 10 to rollback the last change made to the tables" << endl;
            cout << "Enter 11 to exit the program" << endl;
            cout << "Which option would you like to choose?" << endl;
            cin >> choice2;
        }
        
        else if(choice2 == 4)
        {
            cout << "You have chosen to find and display faculty information" << endl;
            cout << endl;
            
            
            cout << "Enter the professor's ID #" << endl;
            cin >> idNum3;
            
            myTree.FacultyReturnNode(idNum3);
            
            myTree.AdvisePrintInOrder(idNum3);
            cout << endl;
            
            cout << "Enter 1 to print all students and their information by ascending id #" << endl;
            cout << "Enter 2 to print all faculty and their information by ascending id #" << endl;
            cout << "Enter 3 to find and display student information" << endl;
            cout << "Enter 4 to find and display faculty information" << endl;
            cout << "Enter 5 to add a new student" << endl;
            cout << "Enter 6 to delete a student" << endl;
            cout << "Enter 7 to add a new faculty member" << endl;
            cout << "Enter 8 to delete a faculty member" << endl;
            cout << "Enter 9 to change a student's advisor" << endl;
            cout << "Enter 10 to rollback the last change made to the tables" << endl;
            cout << "Enter 11 to exit the program" << endl;
            cout << "Which option would you like to choose?" << endl;
            cin >> choice2;
        }
        
        else if(choice2 == 5)
        {
            cout << "You have chosen to add a new student" << endl;
            cout << endl;
            
            cout << "What is his/her name?" << endl;
            cin >> Name;
            
            cout << "What year is he/she?" << endl;
            cin >> Year;
            
            cout << "What is his/her major?" << endl;
            cin >> Major;
            
            cout << "Which advisor do they have?" << endl;
            cout << "Enter the number assigned to the advisor" << endl;
            cin >> Advisor;
            
            cout << "What is his/her GPA?" << endl;
            cin >> Grade;
            //cout << Grade << endl;
            
            myTree.AddLeaf(idNum, Name, Year, Major, Advisor, Grade);
            idNum++;
            
            cout << endl;
            
            myTree5 = myTree4;
            myTree4 = myTree3;
            myTree3 = myTree2;
            myTree2 = myTree;
            
            if(undo >= 0 && undo < 5)
            {
                undo++;
            }
            
            cout << "Enter 1 to print all students and their information by ascending id #" << endl;
            cout << "Enter 2 to print all faculty and their information by ascending id #" << endl;
            cout << "Enter 3 to find and display student information" << endl;
            cout << "Enter 4 to find and display faculty information" << endl;
            cout << "Enter 5 to add a new student" << endl;
            cout << "Enter 6 to delete a student" << endl;
            cout << "Enter 7 to add a new faculty member" << endl;
            cout << "Enter 8 to delete a faculty member" << endl;
            cout << "Enter 9 to change a student's advisor" << endl;
            cout << "Enter 10 to rollback the last change made to the tables" << endl;
            cout << "Enter 11 to exit the program" << endl;
            cout << "Which option would you like to choose?" << endl;
            cin >> choice2;
        }
        
        else if(choice2 == 6)
        {
            cout << "You have chosen to delete a student" << endl;
            cout << endl;
            
            cout << "Enter the student's ID #" << endl;
            cin >> idNum3;
            
            myTree.RemoveNode(idNum3);
            
            cout << endl;
            
            myTree5 = myTree4;
            myTree4 = myTree3;
            myTree3 = myTree2;
            myTree2 = myTree;
            
            if(undo >= 0 && undo < 5)
            {
                undo++;
            }
            
            cout << "Enter 1 to print all students and their information by ascending id #" << endl;
            cout << "Enter 2 to print all faculty and their information by ascending id #" << endl;
            cout << "Enter 3 to find and display student information" << endl;
            cout << "Enter 4 to find and display faculty information" << endl;
            cout << "Enter 5 to add a new student" << endl;
            cout << "Enter 6 to delete a student" << endl;
            cout << "Enter 7 to add a new faculty member" << endl;
            cout << "Enter 8 to delete a faculty member" << endl;
            cout << "Enter 9 to change a student's advisor" << endl;
            cout << "Enter 10 to rollback the last change made to the tables" << endl;
            cout << "Enter 11 to exit the program" << endl;
            cout << "Which option would you like to choose?" << endl;
            cin >> choice2;
        }
        
        else if(choice2 == 7)
        {
            cout << "You have chosen to add a new faculty member" << endl;
            cout << endl;
            
            cout << "What is his/her name?" << endl;
            cin >> Name;
            
            cout << "What type of professor is he/she?" << endl;
            cin >> Level;
            
            cout << "What is his/her department?" << endl;
            cin >> Department;
            
            myTree.AddLeaf(idNum2, Name, Level, Department, 0, 4.0);
            idNum2++;
            
            cout << endl;
            
            myTree5 = myTree4;
            myTree4 = myTree3;
            myTree3 = myTree2;
            myTree2 = myTree;
            
            if(undo >= 0 && undo < 5)
            {
                undo++;
            }
            
            cout << "Enter 1 to print all students and their information by ascending id #" << endl;
            cout << "Enter 2 to print all faculty and their information by ascending id #" << endl;
            cout << "Enter 3 to find and display student information" << endl;
            cout << "Enter 4 to find and display faculty information" << endl;
            cout << "Enter 5 to add a new student" << endl;
            cout << "Enter 6 to delete a student" << endl;
            cout << "Enter 7 to add a new faculty member" << endl;
            cout << "Enter 8 to delete a faculty member" << endl;
            cout << "Enter 9 to change a student's advisor" << endl;
            cout << "Enter 10 to rollback the last change made to the tables" << endl;
            cout << "Enter 11 to exit the program" << endl;
            cout << "Which option would you like to choose?" << endl;
            cin >> choice2;
        }
        
        else if(choice2 == 8)
        {
            cout << "You have chosen to delete a faculty member" << endl;
            cout << endl;
            
            cout << "Enter the professor's ID #" << endl;
            cin >> idNum3;
            
            myTree.RemoveNode(idNum3);
            
            cout << "Enter the ID # of the professor who will advise the former professor's students" << endl;
            cin >> idNum4;
            
            if(idNum3 != idNum4)
            {
                myTree.NewAdvisorPrintInOrder(idNum3, idNum4);
            }
            
            else
            {
                while(idNum3 == idNum4)
                {
                    cout << "You need to enter an ID # that is a # other than " << idNum3 << endl;
                    cout << "Enter the ID # of the professor who will advise the former professor's students" << endl;
                    cin >> idNum4;
                    
                    if(idNum3 != idNum4)
                    {
                        myTree.NewAdvisorPrintInOrder(idNum3, idNum4);
                    }
                }
            }
            
            cout << endl;
            
            myTree5 = myTree4;
            myTree4 = myTree3;
            myTree3 = myTree2;
            myTree2 = myTree;
            
            if(undo >= 0 && undo < 5)
            {
                undo++;
            }
            
            cout << "Enter 1 to print all students and their information by ascending id #" << endl;
            cout << "Enter 2 to print all faculty and their information by ascending id #" << endl;
            cout << "Enter 3 to find and display student information" << endl;
            cout << "Enter 4 to find and display faculty information" << endl;
            cout << "Enter 5 to add a new student" << endl;
            cout << "Enter 6 to delete a student" << endl;
            cout << "Enter 7 to add a new faculty member" << endl;
            cout << "Enter 8 to delete a faculty member" << endl;
            cout << "Enter 9 to change a student's advisor" << endl;
            cout << "Enter 10 to rollback the last change made to the tables" << endl;
            cout << "Enter 11 to exit the program" << endl;
            cout << "Which option would you like to choose?" << endl;
            cin >> choice2;
        }
        
        else if(choice2 == 9)
        {
            cout << "You have chosen to change a student's advisor" << endl;
            cout << endl;
            
            cout << "Enter the student's ID #" << endl;
            cin >> idNum3;
            
            cout << "Enter the ID # of their new advisor" << endl;
            cin >> idNum4;
            
            myTree.ChangeAdvisor(idNum3, idNum4);
            
            cout << endl;
            
            cout << "Enter 1 to print all students and their information by ascending id #" << endl;
            cout << "Enter 2 to print all faculty and their information by ascending id #" << endl;
            cout << "Enter 3 to find and display student information" << endl;
            cout << "Enter 4 to find and display faculty information" << endl;
            cout << "Enter 5 to add a new student" << endl;
            cout << "Enter 6 to delete a student" << endl;
            cout << "Enter 7 to add a new faculty member" << endl;
            cout << "Enter 8 to delete a faculty member" << endl;
            cout << "Enter 9 to change a student's advisor" << endl;
            cout << "Enter 10 to rollback the last change made to the tables" << endl;
            cout << "Enter 11 to exit the program" << endl;
            cout << "Which option would you like to choose?" << endl;
            cin >> choice2;
        }
        
        else if(choice2 == 10)
        {
            cout << "You have chosen to rollback the last change made to the tables" << endl;
            
            if(undo > 0)
            {
                myTree = myTree2;
                myTree2 = myTree3;
                myTree3 = myTree4;
                myTree4 = myTree5;
                undo = undo - 1;
            }
            
            else
            {
                cout << "You can't undo any more actions" << endl;
            }
            
            cout << endl;
            
            cout << "Enter 1 to print all students and their information by ascending id #" << endl;
            cout << "Enter 2 to print all faculty and their information by ascending id #" << endl;
            cout << "Enter 3 to find and display student information" << endl;
            cout << "Enter 4 to find and display faculty information" << endl;
            cout << "Enter 5 to add a new student" << endl;
            cout << "Enter 6 to delete a student" << endl;
            cout << "Enter 7 to add a new faculty member" << endl;
            cout << "Enter 8 to delete a faculty member" << endl;
            cout << "Enter 9 to change a student's advisor" << endl;
            cout << "Enter 10 to rollback the last change made to the tables" << endl;
            cout << "Enter 11 to exit the program" << endl;
            cout << "Which option would you like to choose?" << endl;
            cin >> choice2;
        }
        
        else if(choice2 == 11)
        {
            cout << "You have chosen to exit the program" << endl;
            choice = 0;
        }
        
        else
        {
            cout << "Please choose a number between 1 and 14" << endl;
            cout << endl;
            cout << endl;
            cout << "Enter 1 to print all students and their information by ascending id #" << endl;
            cout << "Enter 2 to print all faculty and their information by ascending id #" << endl;
            cout << "Enter 3 to find and display student information" << endl;
            cout << "Enter 4 to find and display faculty information" << endl;
            cout << "Enter 5 to add a new student" << endl;
            cout << "Enter 6 to delete a student" << endl;
            cout << "Enter 7 to add a new faculty member" << endl;
            cout << "Enter 8 to delete a faculty member" << endl;
            cout << "Enter 9 to change a student's advisor" << endl;
            cout << "Enter 10 to rollback the last change made to the tables" << endl;
            cout << "Enter 11 to exit the program" << endl;
            cout << "Which option would you like to choose?" << endl;
            cin >> choice2;
        }
    }
    
    //myTree.StudentWriteInOrder();
    
    /*ofstream myfile;
    myfile.open("StudentTable.txt");
    
    Ptr->root;
    
    for(i == 10001; i < idNum; i++)
    {
        if(root != NULL)
        {
            if(Ptr->left != NULL && Ptr->left->key > 10000)
            {
                StudentPrintInOrderPrivate(Ptr->left);
            }
            myfile << Ptr->key << endl;
            myfile << Ptr->name << endl;
            myfile << Ptr->level << endl;
            myfile << Ptr->major << endl;
            myfile << Ptr->advisor << endl;
            myfile << Ptr->GPA << endl;
            if(Ptr->right != NULL && Ptr->right->key > 10000)
            {
                StudentPrintInOrderPrivate(Ptr->right);
            }
        }
        else
        {
            cout << "The tree is empty" << endl;
        }
    }
    
    myfile.close();*/
    
    return 0;
}