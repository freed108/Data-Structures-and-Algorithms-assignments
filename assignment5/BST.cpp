#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

BST::BST()
{
    root = NULL;
}

BST::node* BST::CreateLeaf(int key, string name, string level, string major, int advisor, double GPA)
{
    node* n = new node;
    n->key = key;
    n->name = name;
    n->level = level;
    n->major = major;
    n->advisor = advisor;
    n->GPA = GPA;
    n->left = NULL;
    n->right = NULL;
    
    return n;
}

void BST::AddLeaf(int key, string name, string level, string major, int advisor, double GPA)
{
    AddLeafPrivate(key, root, name, level, major, advisor, GPA);
}

void BST::AddLeafPrivate(int key, node* Ptr, string name, string level, string major, int advisor, double GPA)
{
    if(root == NULL)
    {
        root = CreateLeaf(key, name, level, major, advisor, GPA);
    }
    else if(key < Ptr->key)
    {
        if(Ptr->left != NULL)
        {
            AddLeafPrivate(key, Ptr->left, name, level, major, advisor, GPA);
        }
        else
        {
            Ptr->left = CreateLeaf(key, name, level, major, advisor, GPA);
        }
    }
    else if(key > Ptr->key)
    {
        if(Ptr->right != NULL)
        {
            AddLeafPrivate(key, Ptr->right, name, level, major, advisor, GPA);
        }
        else
        {
            Ptr->right = CreateLeaf(key, name, level, major, advisor, GPA);
        }
    }
    else
    {
        cout << "The key " << key << " has already been added to the tree" << endl;
    }
}

void BST::StudentPrintInOrder()
{
    StudentPrintInOrderPrivate(root->right);
}

void BST::StudentPrintInOrderPrivate(node* Ptr)
{
    if(root != NULL)
    {
        if(Ptr->left != NULL && Ptr->left->key > 10000)
        {
            StudentPrintInOrderPrivate(Ptr->left);
        }
        cout << Ptr->key << endl;
        cout << Ptr->name << endl;
        cout << Ptr->level << endl;
        cout << Ptr->major << endl;
        cout << Ptr->advisor << endl;
        cout << Ptr->GPA << endl;
        cout << endl;
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

/*void BST::StudentWriteInOrder()
{
    ofstream myfile;
    myfile.open("StudentTable.txt");
    StudentWriteInOrderPrivate(root->right, myfile);
    myfile.close();
}

void BST::StudentWriteInOrderPrivate(node* Ptr, ofstream myfile)
{
    if(root != NULL)
    {
        if(Ptr->left != NULL && Ptr->left->key > 10000)
        {
            StudentWriteInOrderPrivate(Ptr->left, myfile);
        }
        myfile << Ptr->key << endl;
        myfile << Ptr->name << endl;
        myfile << Ptr->level << endl;
        myfile << Ptr->major << endl;
        myfile << Ptr->advisor << endl;
        myfile << Ptr->GPA << endl;
        if(Ptr->right != NULL && Ptr->right->key > 10000)
        {
            StudentWriteInOrderPrivate(Ptr->right, myfile);
        }
    }
    else
    {
        cout << "The tree is empty" << endl;
    }
}*/

void BST::FacultyPrintInOrder()
{
    FacultyPrintInOrderPrivate(root->left);
}

void BST::FacultyPrintInOrderPrivate(node* Ptr)
{
    if(root != NULL)
    {
        if(Ptr->left != NULL && Ptr->left->key < 10000)
        {
            FacultyPrintInOrderPrivate(Ptr->left);
        }
        cout << Ptr->key << endl;
        cout << Ptr->name << endl;
        cout << Ptr->level << endl;
        cout << endl;
        if(Ptr->right != NULL && Ptr->right->key < 10000)
        {
            FacultyPrintInOrderPrivate(Ptr->right);
        }
    }
    else
    {
        cout << "The tree is empty" << endl;
    }
}

BST::node* BST::ReturnNode(int key)
{
    return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{
    if(Ptr != NULL)
    {
        if(Ptr->key == key)
        {
            return Ptr;
        }
        else
        {
            if(key < Ptr->key)
            {
                return ReturnNodePrivate(key, Ptr->left);
            }
            else
            {
                return ReturnNodePrivate(key, Ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }
}

void BST::StudentReturnNode(int key)
{
    return StudentReturnNodePrivate(key, root);
}

void BST::StudentReturnNodePrivate(int key, node* Ptr)
{
    if(Ptr != NULL)
    {
        if(Ptr->key == key)
        {
            cout << Ptr->name << endl;
            cout << Ptr->level << endl;
            cout << Ptr->major << endl;
            cout << Ptr->advisor << endl;
            cout << Ptr->GPA << endl;
            cout << endl;
        }
        else
        {
            if(key < Ptr->key)
            {
                StudentReturnNodePrivate(key, Ptr->left);
            }
            else
            {
                StudentReturnNodePrivate(key, Ptr->right);
            }
        }
    }
    else
    {
        cout << "There is no Student #" << key << endl;
    }
}

void BST::ChangeAdvisor(int key, int NewAdvisor)
{
    return ChangeAdvisorPrivate(key, NewAdvisor, root);
}

void BST::ChangeAdvisorPrivate(int key, int NewAdvisor, node* Ptr)
{
    if(Ptr != NULL)
    {
        if(Ptr->key == key)
        {
            Ptr->advisor = NewAdvisor;
        }
        else
        {
            if(key < Ptr->key)
            {
                ChangeAdvisorPrivate(key, NewAdvisor, Ptr->left);
            }
            else
            {
                ChangeAdvisorPrivate(key, NewAdvisor, Ptr->right);
            }
        }
    }
    else
    {
        cout << "There is no Student #" << key << endl;
    }
}

void BST::FacultyReturnNode(int key)
{
    return FacultyReturnNodePrivate(key, root);
}

void BST::FacultyReturnNodePrivate(int key, node* Ptr)
{
    if(Ptr != NULL)
    {
        if(Ptr->key == key)
        {
            cout << Ptr->name << endl;
            cout << Ptr->level << endl;
            cout << Ptr->major << endl;
            cout << "Professor " << Ptr->name << " advises these students:" << endl;
        }
        else
        {
            if(key < Ptr->key)
            {
                FacultyReturnNodePrivate(key, Ptr->left);
            }
            else
            {
                FacultyReturnNodePrivate(key, Ptr->right);
            }
        }
    }
    else
    {
        cout << "There is no Professor #" << key << endl;
    }
}

void BST::AdvisePrintInOrder(int advisor)
{
    AdvisePrintInOrderPrivate(advisor, root->right);
}

void BST::AdvisePrintInOrderPrivate(int advisor, node* Ptr)
{
    if(root != NULL)
    {
        if(Ptr->left != NULL && Ptr->left->key > 10000)
        {
            AdvisePrintInOrderPrivate(advisor, Ptr->left);
        }
        if(Ptr->advisor == advisor)
        {
            cout << Ptr->name << endl;
        }
        if(Ptr->right != NULL && Ptr->right->key > 10000)
        {
            AdvisePrintInOrderPrivate(advisor, Ptr->right);
        }
    }
    else
    {
        cout << "This professor does not advise any students" << endl;
    }
}

void BST::NewAdvisorPrintInOrder(int OldAdvisor, int NewAdvisor)
{
    NewAdvisorPrintInOrderPrivate(OldAdvisor, NewAdvisor, root->right);
}

void BST::NewAdvisorPrintInOrderPrivate(int OldAdvisor, int NewAdvisor, node* Ptr)
{
    if(root != NULL)
    {
        if(Ptr->left != NULL && Ptr->left->key > 10000)
        {
            NewAdvisorPrintInOrderPrivate(OldAdvisor, NewAdvisor, Ptr->left);
        }
        if(Ptr->advisor == OldAdvisor)
        {
            Ptr->advisor = NewAdvisor;
        }
        if(Ptr->right != NULL && Ptr->right->key > 10000)
        {
            NewAdvisorPrintInOrderPrivate(OldAdvisor, NewAdvisor, Ptr->right);
        }
    }
    else
    {
        cout << "This professor did not advise any students" << endl;
    }
}

int BST::FindSmallest()
{
    return FindSmallestPrivate(root);
}

int BST::FindSmallestPrivate(node* Ptr)
{
    if(root == NULL)
    {
        cout << "The tree is empty" << endl;
        return -1000;
    }
    else
    {
        if(Ptr->left != NULL)
        {
            return FindSmallestPrivate(Ptr->left);
        }
        else
        {
            return Ptr->key;
        }
    }
}

void BST::RemoveNode(int key)
{
    RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent)
{
    if(root != NULL)
    {
        if(key < parent->key && parent->left != NULL)
        {
            if(parent->left->key == key)
            {
                RemoveMatch(parent, parent->left, true);
            }
            else
            {
                RemoveNodePrivate(key, parent->left);
            }
        }
        else if(key > parent->key && parent->right != NULL)
        {
            if(parent->right->key == key)
            {
                RemoveMatch(parent, parent->right, false);
            }
            else
            {
                RemoveNodePrivate(key, parent->right);
            }
        }
        else
        {
            cout << "The key " << key << " was not found in the tree" << endl;
        }
    }
    else
    {
        cout << "The tree is empty" << endl;
    }
}

void BST::RemoveMatch(node* parent, node* match, bool Left)
{
    if(root != NULL)
    {
        node* delPtr;
        int matchkey = match->key;
        int smallestInRightSubtree;
        
        //Case 0 - 0 children
        if(match->left == NULL && match->right == NULL)
        {
            delPtr = match;
            if(Left == true)
            {
                parent->left = NULL;
            }
            else
            {
                parent->right = NULL;
            }
            delete delPtr;
            cout << "The node containing key " << matchkey << " was removed" << endl;
        }
        
        //Case 1 - 1 child
        else if(match->left == NULL && match->right != NULL)
        {
            if(Left == true)
            {
                parent->left = match->right;
            }
            else
            {
                parent->right = match->right;
            }
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchkey << " was removed" << endl;
        }
        else if(match->left != NULL && match->right == NULL)
        {
            if(Left == true)
            {
                parent->left = match->left;
            }
            else
            {
                parent->right = match->left;
            }
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing key " << matchkey << " was removed" << endl;
        }
        
        //Case 2 - 2 children
        else
        {
            smallestInRightSubtree = FindSmallestPrivate(match->right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match->key = smallestInRightSubtree;
        }
    }
    else
    {
        cout << "Can not remove match. The tree is empty" << endl;
    }
}