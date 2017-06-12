class BST
{
private:
    struct node
    {
        int key;
        std::string name;
        std::string level;
        std::string major;
        int advisor;
        double GPA;
        node* left;
        node* right;
    };
    
    node* root;
    node* CreateLeaf(int key, std::string name, std::string level, std::string major, int advisor, double GPA);
    node* ReturnNode(int key);
    
    void AddLeafPrivate(int key, node* Ptr, std::string name, std::string level, std::string major, int advisor, double GPA);
    void StudentPrintInOrderPrivate(node* Ptr);
    //void StudentWriteInOrderPrivate(node* Ptr, ofstream myfile);
    void StudentReturnNodePrivate(int key, node* Ptr);
    void ChangeAdvisorPrivate(int key, int NewAdvisor, node* Ptr);
    void FacultyReturnNodePrivate(int key, node* Ptr);
    void AdvisePrintInOrderPrivate(int advisor, node* Ptr);
    void NewAdvisorPrintInOrderPrivate(int OldAdvisor, int NewAdvisor, node* Ptr);
    void FacultyPrintInOrderPrivate(node* Ptr);
    node* ReturnNodePrivate(int key, node* Ptr);
    int FindSmallestPrivate(node* Ptr);
    void RemoveNodePrivate(int key, node* parent);
    void RemoveMatch(node* parent, node* match, bool Left);
    
public:
    BST();
    void AddLeaf(int key, std::string name, std::string level, std::string major, int advisor, double GPA);
    void StudentPrintInOrder();
    //void StudentWriteInOrder();
    void StudentReturnNode(int key);
    void ChangeAdvisor(int key, int NewAdvisor);
    void FacultyReturnNode(int key);
    void AdvisePrintInOrder(int advisor);
    void NewAdvisorPrintInOrder(int OldAdvisor, int NewAdvisor);
    void FacultyPrintInOrder();
    int FindSmallest();
    void RemoveNode(int key);
};