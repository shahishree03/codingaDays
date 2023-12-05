#include<iostream>
using namespace std;
class Employee
{
    public:
    int id;
    string name;
    int age;
    Employee* next;
    
    Employee(int id , string name ,int age )
    {
        this->id = id;
        this->name = name ;
        this-> age = age;
        this-> next =NULL;
    }
    static void insertionAtbeg(Employee*& head, int id , string name , int age)
    {
        Employee *n = new Employee(id, name , age);
      //  Employee *temp;
        n->next = head;
        head =n;
    }
    
    static void insertionAtEnd(Employee*& head, int id , string name, int age)
    {
        Employee* n = new Employee(id, name, age);
        if(head==NULL)
        {
            head= n;
            return;
        }
        Employee* temp= head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next =n;
    }
    
  static void insertionAtSpecificID(Employee*& head, int d, int id, string name , int age)
    {
        Employee *n = new Employee(id , name , age);
       
        if(head == NULL)
        {
            head = n;
            return;
        }
        Employee *temp = head;
        while(temp!= NULL && temp->id !=d)
        {
            temp=temp->next;
        }
        if(temp!=NULL)
        {
            n->next = temp->next;
            temp->next =n;
        }
        else{
            cout<<"Employee with ID "<<d<<"not found"<<endl;
        }
         
        
    }
    
    static void atSpecificId(Employee*& head, int d , int id , string name , int age )
    {
        Employee* n = new Employee(id , name , age);
        if(head == NULL)
        {
            head = n;
            return;
        }
        Employee* temp = head;
        while(temp!= NULL && temp->id!= d)
        {
            temp = temp->next;
        }
        if(temp!= NULL)
        {
            n->next = temp->next;
            temp->next =n;
        }
        else
        {
            cout<<"Employee with ID "<<d<<"not found"<<endl;
        }
    }
    static void deleteById(Employee*& head, int id )
    {
        if(head == NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        
        if(head->id == id)
        {
            Employee* temp = head;
            head = head->next;
            delete temp;
            cout<<"Employee with Id"<<id<<" deleted"<<endl;
            return;
        }
        
        Employee* prev = NULL;
        Employee *current = head;
        
        while(current != NULL && current->id != id) {
            prev =current;
            current = current->next;
        }
        if(current != NULL)
        {
            prev->next = current->next;
            delete current;
            cout<<"Employee with ID"<<id<<"deleted "<<endl;
        }
        else{
            cout<<"Employee with ID "<<id<<"not found"<<endl;
        }
    }
    
    static void deletelast(Employee*& head)
    {
          if(head!=NULL)
        {
            Employee* temp = head;
            Employee* prev = NULL;
            while(temp->next!= NULL)
            {
                prev = temp;
                temp = temp->next;
            }
            if(prev == NULL)
            {
                delete head;
                head = NULL;
                
            }
            else
            {
                delete temp;
                prev->next = NULL;
            }
            cout<<"Last record in the current record\n";
        }
        else
        {
            cout<<"List is empty. "<<endl;
        }
    }
};
void display(Employee* head)
{
    Employee* temp = head;
    while(temp!= NULL)
    {
        cout<<"[ Employee ID: "<<temp->id<<", Name: "<<temp->name<<", Age: "<<temp->age<<
        "]"<<endl;
         temp=temp->next;
    }
}

Employee* merge(Employee* left , Employee* right)
{
    if(!left) {
        return right;
    }
    if(!right)
    {
        return left;
    }
    
    Employee* result = NULL;
    if(left->age<=right->age)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result=right;
        result->next = merge(left, right->next);
    }
    return result;
}

void mergeSort(Employee*& head)
{
    if(!head || !head->next){
        return;
    }
    Employee* middle = head;
    Employee* fast = head->next;
    
    while(fast)
    {
        fast= fast->next;
        if(fast){
            middle = middle ->next;
            fast = fast ->next;
        }
    }
    Employee* left  = head;
    Employee* right = middle ->next;
    middle-> next = NULL;
    
    mergeSort(left);
    mergeSort(right);
    
    head = merge(left , right);
}


int main()
{
    Employee* head = NULL;
    Employee::insertionAtbeg(head, 1001, "B", 27);
     Employee::insertionAtEnd(head, 1003, "D", 20);
     Employee::insertionAtEnd(head, 1004, "E", 25);
    int input;
   do{
       
       cout<<"Menu : \n";
    cout<<"Select an following to do the changing of the list \n";
    cout<<"1 . Insert a new record at the beginning\n 2. Insert a new record at the ned of list \n 3. Insert at specific Id record \n 4. Delete the employee record for specific employee ID \n 5. Sort the record based on employee age \n 6. Delete the last record in the current sorted list\n  7. Dsipaly \n Choosing other will give wrong \n";
    //int input;
    cin>>input;
    switch (input)
    {
        case 1 :
        {
            string name;
            int id , age;
            cout<<"Enter Employee ID: ";
            cin>>id;
            cout<<"Enter Employee name: ";
            cin>>name;
            cout<<"Enter Employee age: ";
            cin>>age;
            Employee::insertionAtbeg(head, id, name , age);
            break;
        }
        case 2:
        {
            int id, age;
            string name;
            cout<<"Enter Employee ID: ";
            cin>>id;
            cout<<"Enter Employee name: ";
            cin>>name;
            cout<<"Enter Employee age: ";
            cin>>age;
            Employee::insertionAtEnd(head, id , name , age);
            break;
        }
        case 3:
        {
            int id,d, age;
            string name;
            cout<<"Enter at specific Employee ID: ";
            cin>>d;
            cout<<"Enter Employee ID: ";
            cin>>id;
            cout<<"Enter Employee name: ";
            cin>>name;
            cout<<"Enter Employee age: ";
            cin>>age;
            Employee::atSpecificId(head, d, id , name , age);
            break;
        }
        
        case 4:
        {
            int id;
            cout<<"Enter employee id";
            cin>>id;
            Employee::deleteById(head, id);
            break;
        }
        
        case 5:
        {
            mergeSort(head);
            cout<<"Employee record sorted by age: "<<endl;
            display(head);
            break;
        }
        case 6:
        {   
            cout<<"\nDelete last Id\n";
          Employee::deletelast(head);
            break;
        }
        case 7:
        {
            cout<<"\nDisplay elements\n";
            display(head);
        }
        default:
        {
            cout<<"\n....Invalid choice........\n"<<endl;
        }
    }
    
   }while(input!=8);
}