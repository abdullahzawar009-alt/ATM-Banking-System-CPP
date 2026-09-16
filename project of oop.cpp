#include <iostream>
#include <stdexcept>

using namespace std;



// ============================================================
//                     ACCOUNT CLASS
// ============================================================

class Account
{
protected:

    int accountNumber;

    string name;

    double balance;



public:

    // --------------------------------------------------------
    //                    CONSTRUCTOR
    // --------------------------------------------------------

    Account(int a, string n, double b)
    {
        accountNumber = a;

        name = n;

        balance = b;
    }



    // --------------------------------------------------------
    //                    DEPOSIT FUNCTION
    // --------------------------------------------------------

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            throw invalid_argument(
                "Deposit amount must be greater than 0"
            );
        }


        balance = balance + amount;
    }



    // --------------------------------------------------------
    //                   WITHDRAW FUNCTION
    // --------------------------------------------------------

    virtual void withdraw(double amount)
    {
        if (amount <= 0)
        {
            throw invalid_argument(
                "Withdrawal amount must be greater than 0"
            );
        }


        if (amount > balance)
        {
            throw runtime_error(
                "Insufficient balance"
            );
        }


        balance = balance - amount;
    }



    // --------------------------------------------------------
    //                 OPERATOR OVERLOADING +
    // --------------------------------------------------------

    Account& operator+(double amount)
    {
        deposit(amount);

        return *this;
    }



    // --------------------------------------------------------
    //                 OPERATOR OVERLOADING -
    // --------------------------------------------------------

    Account& operator-(double amount)
    {
        withdraw(amount);

        return *this;
    }



    // --------------------------------------------------------
    //                    DISPLAY FUNCTION
    // --------------------------------------------------------

    virtual void display()
    {
        cout << "\n";
        cout << "----------------------------------------\n";

        cout << "Account Number : "
             << accountNumber << endl;

        cout << "Customer Name  : "
             << name << endl;

        cout << "Balance        : Rs. "
             << balance << endl;

        cout << "----------------------------------------\n";
    }



    // --------------------------------------------------------
    //                     DESTRUCTOR
    // --------------------------------------------------------

    virtual ~Account()
    {
    }
};



// ============================================================
//                   STUDENT ACCOUNT CLASS
// ============================================================

class StudentAccount : public Account
{
public:

    // --------------------------------------------------------
    //                    CONSTRUCTOR
    // --------------------------------------------------------

    StudentAccount(
        int a,
        string n,
        double b
    )
        : Account(a, n, b)
    {
    }



    // --------------------------------------------------------
    //                  DISPLAY FUNCTION
    // --------------------------------------------------------

    void display() override
    {
        cout << "\n";
        cout << "========================================\n";
        cout << "          STUDENT ACCOUNT\n";
        cout << "========================================\n";

        cout << "Account Number : "
             << accountNumber << endl;

        cout << "Customer Name  : "
             << name << endl;

        cout << "Balance        : Rs. "
             << balance << endl;

        cout << "Withdrawal Limit : Rs. 50000\n";

        cout << "========================================\n";
    }



    // --------------------------------------------------------
    //                  WITHDRAW FUNCTION
    // --------------------------------------------------------

    void withdraw(double amount) override
    {
        if (amount > 50000)
        {
            throw runtime_error(
                "Student account withdrawal limit is Rs. 50000"
            );
        }


        Account::withdraw(amount);
    }
};



// ============================================================
//                    CURRENT ACCOUNT CLASS
// ============================================================

class CurrentAccount : public Account
{
public:

    // --------------------------------------------------------
    //                    CONSTRUCTOR
    // --------------------------------------------------------

    CurrentAccount(
        int a,
        string n,
        double b
    )
        : Account(a, n, b)
    {
    }



    // --------------------------------------------------------
    //                  DISPLAY FUNCTION
    // --------------------------------------------------------

    void display() override
    {
        cout << "\n";
        cout << "========================================\n";
        cout << "          CURRENT ACCOUNT\n";
        cout << "========================================\n";

        cout << "Account Number : "
             << accountNumber << endl;

        cout << "Customer Name  : "
             << name << endl;

        cout << "Balance        : Rs. "
             << balance << endl;

        cout << "Withdrawal Limit : Rs. 100000\n";

        cout << "========================================\n";
    }
};



// ============================================================
//                           MAIN
// ============================================================

int main()
{
    int choice;

    int accountNumber;

    string name;

    double balance;



    // --------------------------------------------------------
    //                     MAIN HEADING
    // --------------------------------------------------------

    cout << "\n";
    cout << "========================================\n";
    cout << "          ATM BANKING SYSTEM\n";
    cout << "========================================\n";



    // --------------------------------------------------------
    //                  ACCOUNT TYPE MENU
    // --------------------------------------------------------

    cout << "\n";

    cout << "1. Student Account\n";

    cout << "2. Current Account\n";



    cout << "\nEnter account type : ";

    cin >> choice;



    // --------------------------------------------------------
    //                 CUSTOMER INFORMATION
    // --------------------------------------------------------

    cout << "\n";

    cout << "Enter account number : ";

    cin >> accountNumber;



    cout << "Enter customer name : ";

    cin.ignore();

    getline(cin, name);



    cout << "Enter initial balance : Rs. ";

    cin >> balance;



    // --------------------------------------------------------
    //                  EXCEPTION HANDLING
    // --------------------------------------------------------

    try
    {
        if (balance < 0)
        {
            throw invalid_argument(
                "Initial balance cannot be negative"
            );
        }



        // ====================================================
        //                   STACK OBJECT
        // ====================================================

        if (choice == 1)
        {
            StudentAccount account(
                accountNumber,
                name,
                balance
            );



            cout << "\n";
            cout << "Student account created on STACK.\n";



            // Display account

            account.display();



            // ------------------------------------------------
            //                    DEPOSIT
            // ------------------------------------------------

            double amount;



            cout << "\nEnter deposit amount : Rs. ";

            cin >> amount;



            account + amount;



            cout << "\nAfter Deposit:";

            account.display();



            // ------------------------------------------------
            //                   WITHDRAW
            // ------------------------------------------------

            cout << "\nEnter withdrawal amount : Rs. ";

            cin >> amount;



            account - amount;



            cout << "\nAfter Withdrawal:";

            account.display();
        }



        // ====================================================
        //                    HEAP OBJECT
        // ====================================================

        else if (choice == 2)
        {
            CurrentAccount* account =
                new CurrentAccount(
                    accountNumber,
                    name,
                    balance
                );



            cout << "\n";

            cout << "Current account created on HEAP.\n";



            // Display account

            account->display();



            // ------------------------------------------------
            //                    DEPOSIT
            // ------------------------------------------------

            double amount;



            cout << "\nEnter deposit amount : Rs. ";

            cin >> amount;



            *account + amount;



            cout << "\nAfter Deposit:";

            account->display();



            // ------------------------------------------------
            //                   WITHDRAW
            // ------------------------------------------------

            cout << "\nEnter withdrawal amount : Rs. ";

            cin >> amount;



            *account - amount;



            cout << "\nAfter Withdrawal:";

            account->display();



            // ------------------------------------------------
            //                DELETE HEAP OBJECT
            // ------------------------------------------------

            delete account;



            cout << "\n";

            cout << "Heap memory released successfully.\n";
        }



        // ====================================================
        //                  INVALID CHOICE
        // ====================================================

        else
        {
            throw invalid_argument(
                "Invalid account type selected"
            );
        }
    }



    // --------------------------------------------------------
    //                    CATCH BLOCK
    // --------------------------------------------------------

    catch (const exception& e)
    {
        cout << "\n";

        cout << "ERROR : "
             << e.what()
             << endl;
    }



    // --------------------------------------------------------
    //                         END
    // --------------------------------------------------------

    cout << "\n";

    cout << "========================================\n";

    cout << "       Thank you for using ATM\n";

    cout << "========================================\n";



    return 0;
}
