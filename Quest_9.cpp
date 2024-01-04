#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;

class node                  //class to represent a node in the linkedlist
{
public:
    string customer_name;       //customer details
    string username;
    string account_type;
    int tele_ph;
    int ini_saving;
    int overdraft_limit = 0;
    node *prev;
    node *next;                 //pointers to ajdacent items
    node()
    {
        prev = NULL;
        next = NULL;
    }
};

class linked_list               //linkedlist to store the details of users of the system
{
private:
    node *start = NULL;         //starting with a null

public:
    void insertEnd(string i_customer_name, int i_tele_ph, int i_ini_saving, string acc_type, int cus_count);        //inserting a new customer
    void print(string print_cus);                                                                                   //displaying details
    void withdraw_or_deposite_value(string select_cus, char transaction_type, int add_value);                       //withdrawing or depositting by customer
    void current_acc_limit(string select_cus, string acc_type, int overdraft_lim);
    void printall();
    void deleteCustomer(string targetUsername);
};

void linked_list::insertEnd(string i_customer_name, int i_tele_ph, int i_ini_saving, string acc_type, int cus_count)       //customer details storing linkedlist which is updated by the employees
{
    node *prt;
    node *new_node = new node;
    prt = start;
    if (prt == NULL)
    {
        start = new_node;
    }
    else
    {
        while (prt->next != NULL)
        {
            prt = prt->next;
        }
        // new_node->val = x;
        if (prt != NULL)
        {
            prt->next = new_node;
        }
    }
    // new_node->prev = prt;
    new_node->customer_name = i_customer_name;
    new_node->tele_ph = i_tele_ph;
    // new_node->player_name_2 = bat_name_2;
    new_node->ini_saving = i_ini_saving;
    new_node->account_type = acc_type;
    new_node->username = "Customer" + to_string(cus_count);
    new_node->next = NULL;
}

void linked_list::current_acc_limit(string select_cus, string acc_type, int overdraft_lim)          //current account details linke lsit
{
    node *prt;
    prt = start;
    while (prt != NULL)
    {
        if (prt->customer_name == select_cus && prt->account_type == acc_type)
        {
            prt->overdraft_limit == overdraft_lim;
        }
        prt = prt->next;
    }
    cout << endl;
}

void linked_list::print(string print_cus)                   //linkedlist to print customer details
{
    node *prt;
    prt = start;
    while (prt != NULL)
    {
        if (prt->username == print_cus)
        {
            cout << setw(17) << " Customer Name :" << setw(17) << prt->customer_name << endl;
            cout << setw(17) << " Telephone No. :" << setw(11) << prt->tele_ph << endl;
            cout << setw(17) << " Account type  :" << setw(11) << prt->account_type << endl;
            cout << setw(21) << " Amount        : Rs. " << setw(10) << prt->ini_saving << endl;
        }
        prt = prt->next;
    }
    cout << endl;
}

void linked_list::printall()
{
    node *prt;
    prt = start;
    while (prt != NULL)
    {
        cout << setw(19) << " Customer Name   :" << setw(17) << prt->customer_name << endl;
        cout << setw(19) << " Telephone No.   :" << setw(11) << prt->tele_ph << endl;
        cout << setw(19) << " Account type    :" << setw(11) << prt->account_type << endl;
        cout << setw(24) << " Account Balance : Rs. " << setw(10) << prt->ini_saving << endl;
        prt = prt->next;
    }
    cout << endl;
}

void linked_list::withdraw_or_deposite_value(string select_cus, char transaction_type, int add_value)           //transaction storing list
{
    node *prt;
    prt = start;
    while (prt != NULL)
    {
        if (prt->username == select_cus)
        {
            if (transaction_type == 'D' || transaction_type == 'd')
            {
                prt->ini_saving = prt->ini_saving + add_value;
            }
            else if (transaction_type == 'W' || transaction_type == 'w')
            {
                prt->ini_saving = prt->ini_saving - add_value;
            }
            else
            {
                cout << "Wrong Input!!!" << endl;
            }
        }
        prt = prt->next;
    }
    cout << endl;
}

void linked_list::deleteCustomer(string targetname)                 //deleting a customer
{
    node *current = start;
    node *previous = nullptr;

    while (current != nullptr && current->customer_name != targetname)
    {
        previous = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Customer with the name " << targetname << " not found." << endl;
        return;
    }

    if (previous != nullptr)
    {
        previous->next = current->next;
    }
    else
    {
        start = current->next;
    }

    delete current;

    cout << "Customer with the name " << targetname << " deleted successfully." << endl;
}

class employee_node
{
public:
    string employee_name;
    string employee_username;
    employee_node *prev;
    employee_node *next;
    employee_node()
    {
        prev = NULL;
        next = NULL;
    }
};

class em_linked_list
{
private:
    employee_node *start = NULL;

public:
    void insertEnd(string i_employee_name, int em_count);
    void print();
};

void em_linked_list::insertEnd(string i_employee_name, int em_count)
{
    employee_node *prt;
    employee_node *new_node = new employee_node;
    prt = start;
    if (prt == NULL)
    {
        start = new_node;
    }
    else
    {
        while (prt->next != NULL)
        {
            prt = prt->next;
        }
        // new_node->val = x;
        if (prt != NULL)
        {
            prt->next = new_node;
        }
    }
    // new_node->prev = prt;
    new_node->employee_name = i_employee_name;
    new_node->employee_username = "Employee" + to_string(em_count);
    // new_node->player_name_2 = bat_name_2;
    new_node->next = NULL;
}

void em_linked_list::print()
{
    employee_node *prt;
    prt = start;
    cout << setw(17) << " Employee Name :" << setw(12) << "   Username" << endl;
    while (prt != NULL)
    {
        cout << setw(17) << prt->employee_name << setw(20) << prt->employee_username << endl;
        prt = prt->next;
    }
    cout << endl;
}

int main()
{
    //definignt he variables 
    linked_list li;
    em_linked_list em_li;
    int customer_count = 1;
    int employee_count = 1;
    string targetname;
    string Password;
    string in_EmUsername;
    string in_EmPassword;
    string in_CusPassword;
    string in_CusUsername;
    int saving_intrest = 4;
    int overdraft_charge = 2;
    int days = 1;
    bool is_exit = 0;
    bool is_add_employee = 1;
    bool is_add_customer = 1;
    int opt_no;
    cout << "-----------------------------------------------------" << endl;
    cout << "                    Welcome to ABC Bank              " << endl;
    cout << "-----------------------------------------------------" << endl;
    cout<<endl;
    while (is_exit != 1)                    //taking user inputs to select the type of user for the system
    {
        cout << "                      Select the Correct Interface              " << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "           Role                 press the number to select the option   " << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "        Adminstrator                             1                      " << endl;
        cout << "          Employee                               2                     " << endl;
        cout << "          Customer                               3                     " << endl;
        cout << "            Exit                                 4                     " << endl;
        cout << endl;
        cout << "     Enter the option number: ";
        cin >> opt_no;

        switch (opt_no)             //switching based on the type of user
        {
        case 1:
            system("cls");
            cout << "-----------------------------------------------------" << endl;
            cout << "             Adminstrator Login" << endl;
            cout << "-----------------------------------------------------" << endl;

            cout << "  Enter the password :";
          
            char ch;

            // Loop to read characters until Enter (newline) is pressed
            while ((ch = _getch()) != '\r' && ch != '\n') {
                Password.push_back(ch);
                cout << '*';  // Display '*' to mimic password input
            }
            cout<<endl;   

            if (Password == "Password@1234")
            {
                cout << "correct Password" << endl;
                bool is_adm_exit = 0;
                while (is_adm_exit != 1)
                {
                    int admin_opt_no;                       //administrator operaations selection
                    cout << "-----------------------------------------------------" << endl;

                    cout << "                Select the Operation            " << endl;
                    cout << "-----------------------------------------------------" << endl;
                    cout<<endl;
                    cout << "           Role                 press the number to select the option   " << endl;
                    cout << "-----------------------------------------------------------------------------" << endl;

                    cout << "       Add Employee                              1                      " << endl;
                    cout << "      Annual Update                              2                     " << endl;
                    cout << "    Increase day count                           3                     " << endl;
                    cout << "            Exit                                 4                     " << endl;
                    cout << endl;
                    cout << "     Enter the option number: ";
                    cin >> admin_opt_no;
                    switch (admin_opt_no)           //switching based on administraator operations
                    {
                    case 1:                         //adding employee

                        while (is_add_employee != 0)
                        {
                            string em_name;
                            cout << "Enter the employee name:";
                            cin >> em_name;
                            em_li.insertEnd(em_name, employee_count);       //adding employees towards the end of linkedlist
                            cout << "Do you want to add another employee[yes=1/no=0]: ";
                            cin >> is_add_employee;
                            employee_count = employee_count + 1;            //count increaased by 1
                        }
                        break;
                    case 2:
                        if (days == 365)                            //annual update of interest rates
                        {
                            cout << "Update the saving intrest: ";          
                            cin >> saving_intrest;
                            cout << "Update the overdraft charge: ";
                            cin >> overdraft_charge;
                        }
                        else
                        {
                            cout << "Error:Still year is not completed" << endl;
                        }
                        break;
                    case 3:                         //days increasing algorithm
                        days = days + 1;
                        cout << "Increased the date." << endl;
                        break;
                    case 4:
                        cout << "     Successfully exit from the administer interface " << endl;
                        is_adm_exit = 1;
                        break;
                    default:
                        cout << "Invalid input" << endl;
                        break;
                    }
                }
            }
            else
            {
                cout << "Incorrect Password" << endl;
            }

            break;
        case 2:
            system("cls");
            cout<<"---------------------------------------------------"<<endl;
            cout << "           Welcome Employee Interface"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<endl;
            cout << "Current employee list:" << endl;

            em_li.print();              //employee list printing
            cout << "\nEnter username: ";
            cin >> in_EmUsername;
            cout << "Enter password: ";

            char ch1;

            // Loop to read characters until Enter (newline) is pressed
            while ((ch1 = _getch()) != '\r' && ch1 != '\n') {
                in_EmPassword.push_back(ch1);
                cout << '*';  // Display '*' to mimic password input
            }
            cout<<endl;

            if (in_EmPassword == "Password@1234")               //password accuracy checking
            {
                cout << "correct Password" << endl;
                bool is_em_exit = 0;
                while (is_em_exit != 1)
                {
                    int em_opt_no;              //employee operations display
                    
                    cout << "                Select the Operation            " << endl;
                    cout << "--------------------------------------------------------------------------------" << endl;
                    cout << "          Option                press the number to select the option   " << endl;
                    cout << "--------------------------------------------------------------------------------" << endl;
                    cout << "     Create Customers                            1                      " << endl;
                    cout << "  withdraw_or_deposite money                     2                     " << endl;
                    cout << "    view customer details                        3                     " << endl;
                    cout << "       Delete customer                           4                     " << endl;
                    cout << "            Exit                                 5                     " << endl;
                    cout << endl;
                    cout << "     Enter the option number: ";
                    cin >> em_opt_no;
                    switch (em_opt_no)              //switching based on employee tasks
                    {
                    case 1:                 //adding a new customer

                        while (is_add_customer != 0)
                        {
                            string customer_name;           //customer details
                            int telephone_no;
                            int st_balance;
                            string account_type;
                            cout << "Enter the customer name:";
                            cin >> customer_name;
                            cout << "Enter the telephone no.:";
                            cin >> telephone_no;
                            cout << "Enter the starting saving:";
                            cin >> st_balance;
                            cout << "Enter the account type[saving acc. = 'S'/current acc. = 'C']:";
                            cin >> account_type;
                            if (account_type == "S" || account_type == "s")         //update the same linkedlist in 2 diff ways based on type of account
                            {
                                li.insertEnd(customer_name, telephone_no, st_balance, "Saving account", customer_count);
                            }
                            else if (account_type == "C" || account_type == "c")
                            {
                                li.insertEnd(customer_name, telephone_no, st_balance, "Current account", customer_count);
                                int overdraft_limit;
                                cout << "Enter overdraft limit: " << endl;              //od limit set for current accounts only
                                cin >> overdraft_limit;
                                li.current_acc_limit(customer_name, "Current account", overdraft_limit);
                            }
                            else
                            {
                                cout << "invalid input";
                            }
                            cout << "Do you want to add another customer[yes=1/no=0]: ";
                            cin >> is_add_customer;
                            customer_count = customer_count + 1;
                        }
                        break;
                    case 2:             //carrying out a transaction
                        cout << "Select the customer for transaction:" << endl;    

                        int in_Amount;
                        char in_transaction_type;

                        cout << "Enter customer user name: ";
                        cin >> in_CusUsername;
                        cout << "Enter Amount: Rs. ";
                        cin >> in_Amount;
                        cout << "Enter transaction type[Deposit = 'D', Withdraw = 'W']: ";
                        cin >> in_transaction_type;
                        li.withdraw_or_deposite_value(in_CusUsername, in_transaction_type, in_Amount);      //updating the linst
                        break;
                    case 3:
                        cout << "   Print all details  " << endl;
                        li.printall();
                        break;
                    case 4:
                        cout<<"Please enter the name of the customer to be deleted: "<< endl;
                        cin>> targetname;
                        li.deleteCustomer(targetname);
                        break;

                    case 5:
                        cout << "     Successfully exit from the administer interface " << endl;
                        is_em_exit = 1;
                        break;
                    default:
                        cout << "Invalid input" << endl;
                        break;
                    }
                }
            }
            else
            {
                cout << "Invalid Input" << endl;
            }

            break;
        case 3:
            system("cls");                  //customer interface
            cout << "-------------------------------------------------" << endl;
            cout << "              Welcome Customer"<<endl;

            cout << "\nEnter username: ";
            cin >> in_CusUsername;
            cout << "Enter password: ";
            char ch2;

            // Loop to read characters until Enter (newline) is pressed
            while ((ch2 = _getch()) != '\r' && ch2 != '\n') {
                in_CusPassword.push_back(ch2);
                cout << '*';  // Display '*' to mimic password input
            }
            cout<<endl;

            //cin >> in_CusPassword;
            if (in_CusPassword == "Password@1234")
            {
                cout << "correct Password" << endl;
                bool is_em_exit = 0;
                while (is_em_exit != 1)
                {
                    int em_opt_no;
                    
                    cout << "                Select the Operation            " << endl;
                    cout << "-----------------------------------------------------------------------------" <<endl;
                    cout << "          Option                press the number to select the option   " << endl;
                    cout << "-----------------------------------------------------------------------------" <<endl;
                    cout << "     view personal info.                         1                      " << endl;
                    cout << "  withdraw_or_deposite money                     2                     " << endl;
                    cout << "    transaction details                          3                     " << endl;
                    cout << "            Exit                                 4                     " << endl;
                    cout << endl;
                    cout << "     Enter the option number: ";
                    cin >> em_opt_no;
                    switch (em_opt_no)              //switching based on customer operations
                    {
                    case 1:                     //details view tab
                        cout << "   Personal  details  " << endl;
                        li.print(in_CusUsername);
                        break;
                    case 2:                     //transaction interface
                        cout << "Cash flow interface" << endl;

                        int in_Amount;
                        char in_transaction_type;

                        cout << "Enter customer user name: ";
                        cin >> in_CusUsername;
                        cout << "Enter Amount: Rs. ";
                        cin >> in_Amount;
                        cout << "Enter transaction type[Deposit = 'D', Withdraw = 'W']: ";
                        cin >> in_transaction_type;
                        li.withdraw_or_deposite_value(in_CusUsername, in_transaction_type, in_Amount);
                        break;
                    case 3:                 //viewing all transactions
                        cout << "   Transaction details  " << endl;

                        break;
                    case 4:
                        cout << "     Successfully exit from the administer interface " << endl;
                        is_em_exit = 1;
                        break;
                    default:
                        cout << "Invalid input" << endl;
                        break;
                    }
                }
            }
            else
            {
                cout << "Invalid Input" << endl;
            }

            break;
        case 4:
            system("cls");
            cout << "     Successfully exit from the system" << endl;
            is_exit = 1;
            break;
        default:
            system("cls");
            cout << "     Wrong Input  " << endl;
            break;
        }
    }

    return 0;
}