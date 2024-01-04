#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class node
{
public:
    string customer_name;
    string username;
    string account_type;
    int tele_ph;
    int ini_saving;
    int overdraft_limit = 0;
    node *prev;
    node *next;
    node()
    {
        prev = NULL;
        next = NULL;
    }
};

class linked_list
{
private:
    node *start = NULL;

public:
    void insertEnd(string i_customer_name, int i_tele_ph, int i_ini_saving, string acc_type, int cus_count);
    void print(string print_cus);
    void withdraw_or_deposite_value(string select_cus, char transaction_type, int add_value);
    void current_acc_limit(string select_cus, string acc_type, int overdraft_lim);
    void printall();
};

void linked_list::insertEnd(string i_customer_name, int i_tele_ph, int i_ini_saving, string acc_type, int cus_count)
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

void linked_list::current_acc_limit(string select_cus, string acc_type, int overdraft_lim)
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

void linked_list::print(string print_cus)
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

void linked_list::withdraw_or_deposite_value(string select_cus, char transaction_type, int add_value)
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
    linked_list li;
    em_linked_list em_li;
    int customer_count = 1;
    int employee_count = 1;
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
    cout << "                    Welcome to ABC Bank              " << endl;
    while (is_exit != 1)
    {
        cout << "             Select the Correct Interface              " << endl;
        cout << "           Role                 press the number to select the option   " << endl;
        cout << "        Adminstertor                             1                      " << endl;
        cout << "          Employee                               2                     " << endl;
        cout << "          Customer                               3                     " << endl;
        cout << "            Exit                                 4                     " << endl;
        cout << endl;
        cout << "     Enter the option number: ";
        cin >> opt_no;

        switch (opt_no)
        {
        case 1:
            system("cls");
            cout << "             Adminstrator Login" << endl;

            cout << "  Enter the password :";
            cin >> Password;
            if (Password == "Password@1234")
            {
                cout << "correct Password" << endl;
                bool is_adm_exit = 0;
                while (is_adm_exit != 1)
                {
                    int admin_opt_no;
                    cout << "                Select the Operation            " << endl;
                    cout << "           Role                 press the number to select the option   " << endl;
                    cout << "       Add Employee                              1                      " << endl;
                    cout << "      Annual Update                              2                     " << endl;
                    cout << "    Increase day count                           3                     " << endl;
                    cout << "            Exit                                 4                     " << endl;
                    cout << endl;
                    cout << "     Enter the option number: ";
                    cin >> admin_opt_no;
                    switch (admin_opt_no)
                    {
                    case 1:

                        while (is_add_employee != 0)
                        {
                            string em_name;
                            cout << "Enter the employee name:";
                            cin >> em_name;
                            em_li.insertEnd(em_name, employee_count);
                            cout << "Do you want to add another employee[yes=1/no=0]: ";
                            cin >> is_add_employee;
                            employee_count = employee_count + 1;
                        }
                        break;
                    case 2:
                        if (days == 365)
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
                    case 3:
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
                cout << "incorrect Password" << endl;
            }

            break;
        case 2:
            system("cls");
            cout << "           Welcome Employee Interface\n"
                 << endl;
            cout << "         Current employee list" << endl;

            em_li.print();
            cout << "\nEnter username: ";
            cin >> in_EmUsername;
            cout << "Enter password: ";
            cin >> in_EmPassword;
            if (in_EmPassword == "Password@1234")
            {
                cout << "correct Password" << endl;
                bool is_em_exit = 0;
                while (is_em_exit != 1)
                {
                    int em_opt_no;
                    cout << "                Select the Operation            " << endl;
                    cout << "          Option                press the number to select the option   " << endl;
                    cout << "     Create Customers                            1                      " << endl;
                    cout << "  withdraw_or_deposite money                     2                     " << endl;
                    cout << "    view customer details                        3                     " << endl;
                    cout << "            Exit                                 4                     " << endl;
                    cout << endl;
                    cout << "     Enter the option number: ";
                    cin >> em_opt_no;
                    switch (em_opt_no)
                    {
                    case 1:

                        while (is_add_customer != 0)
                        {
                            string customer_name;
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
                            if (account_type == "S" || account_type == "s")
                            {
                                li.insertEnd(customer_name, telephone_no, st_balance, "Saving account", customer_count);
                            }
                            else if (account_type == "C" || account_type == "c")
                            {
                                li.insertEnd(customer_name, telephone_no, st_balance, "Current account", customer_count);
                                int overdraft_limit;
                                cout << "Enter overdraft limit: " << endl;
                                cin >> overdraft_limit;
                                li.current_acc_limit(customer_name, "Current account", overdraft_limit);
                            }
                            else
                            {
                                cout << "invalid input";
                            }
                            cout << "Do you want to add another employee[yes=1/no=0]: ";
                            cin >> is_add_customer;
                            customer_count = customer_count + 1;
                        }
                        break;
                    case 2:
                        cout << "Add customers" << endl;

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
                    case 3:
                        cout << "   Print all details  " << endl;
                        li.printall();
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
        case 3:
            system("cls");
            cout << "              Welcome Customer\n"
                 << endl;
            cout << "\nEnter username: ";
            cin >> in_CusUsername;
            cout << "Enter password: ";
            cin >> in_CusPassword;
            if (in_CusPassword == "Password@1234")
            {
                cout << "correct Password" << endl;
                bool is_em_exit = 0;
                while (is_em_exit != 1)
                {
                    int em_opt_no;
                    cout << "                Select the Operation            " << endl;
                    cout << "          Option                press the number to select the option   " << endl;
                    cout << "     view personal info.                         1                      " << endl;
                    cout << "  withdraw_or_deposite money                     2                     " << endl;
                    cout << "    transaction details                          3                     " << endl;
                    cout << "            Exit                                 4                     " << endl;
                    cout << endl;
                    cout << "     Enter the option number: ";
                    cin >> em_opt_no;
                    switch (em_opt_no)
                    {
                    case 1:
                        cout << "   Personal  details  " << endl;
                        li.print(in_CusUsername);
                        break;
                    case 2:
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
                    case 3:
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