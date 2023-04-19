#include<iostream>
using namespace std;

class Account
{
private:
    string customerName;
    string accountNumber;
    string accountType;
public:
    void getAccountDetails()
    {
        cout<<"\nEnter Customer Name : ";
        cin>>customerName;
        cout<<"Enter Account Number  : ";
        cin>>accountNumber;
        cout<<"Enter Account Type    : ";
        cin>>accountType;
    }
    void displayDetails()
    {
        cout<<"\n\nCustomer Name : "<<customerName;
        cout<<"\nAccount Number  : "<<accountNumber;
        cout<<"\nAccount Type    : "<<accountType;
    }
};

class CurrentAccount : public Account
{
private:
    float accountBalance;
public:
    void displayBalance()
    {
        cout<<"\nBalance :"<<accountBalance;
    }
    void deposit()
    {
        float depositAmount;
        cout<<"\nEnter amount to Deposit :  ";
        cin>>depositAmount;
        accountBalance = accountBalance + depositAmount;
    }
    void withdraw()
    {
        float withdrawAmount;
        cout<<"\n\nBalance : "<<accountBalance;
        cout<<"\nEnter amount to be withdraw :";
        cin>>withdrawAmount;
        if(accountBalance > 1000)
        {
            accountBalance = accountBalance - withdrawAmount;
            cout<<"\nBalance Amount After Withdraw: "<<accountBalance;
        }
        else
        {
            cout<<"\n Insufficient Balance";
        }
    }
};

class SavingsAccount : public Account
{
private:
    float accountBalance;
public:
    void displayBalance()
    {
        cout<<"\nBalance :  "<<accountBalance;
    }
    void deposit()
    {
        float depositAmount, interest;
        cout<<"\nEnter amount to Deposit :  ";
        cin>>depositAmount;
        accountBalance = accountBalance + depositAmount;
        interest = (accountBalance * 2) / 100;
        accountBalance = accountBalance + interest;
    }
    void withdraw()
    {
        float withdrawAmount;
        cout<<"\nBalance :- "<<accountBalance;
        cout<<"\nEnter amount to be withdraw : ";
        cin>>withdrawAmount;
        if(accountBalance > 500)
        {
            accountBalance = accountBalance - withdrawAmount;
            cout<<"\nBalance Amount After Withdraw: "<<accountBalance;
        }
        else
        {
            cout<<"\n Insufficient Balance";
        }
    }
};

int main()
{
    CurrentAccount currentAccount;
    SavingsAccount savingsAccount;
    char accountType;
    cout<<"\nWelcome to Prashanth Bank"<<endl;
    cout<<"\Type 'S' for saving account customer and 'C' for current account customer : ";
    cin>>accountType;

    int choice;

    if(accountType == 's' || accountType == 'S')
    {
        savingsAccount.getAccountDetails();
        while(1)
        {
            cout<<"\nWhich Operation would you like to perform?"<<endl;
            cout<<"1)   Deposit Money"<<endl;
            cout<<"2)   Withdraw Money"<<endl;
            cout<<"3)   Display Balance"<<endl;
            cout<<"4)   Display with full Details"<<endl;
            cout<<"5)   Exit"<<endl;
            cout<<"Enter Your choice: ";
            cin>>choice;
            cout<<"\nProcessing..."<<endl;
            switch(choice)
            {
                case 1:
                    savingsAccount.deposit();
                    break;
                case 2:
                    savingsAccount.withdraw();
                    break;
                case 3:
                    savingsAccount.displayBalance();
                    break;
                case 4:
                    savingsAccount.displayDetails();
                    savingsAccount.displayBalance();
                    break;
                case 5:
                   goto end;
                default:
                cout<<"\nInvalid Choice!!!";
        }
    }
}
else if(accountType == 'c' || accountType == 'C')
{
    currentAccount.getAccountDetails();
    while(1)
    {
        cout<<"\nWhich Operation would you like to perform?"<<endl;
        cout<<"1)   Deposit Money"<<endl;
        cout<<"2)   Withdraw Money"<<endl;
        cout<<"3)   Display Balance"<<endl;
        cout<<"4)   Display with full Details"<<endl;
        cout<<"5)   Exit"<<endl;
        cout<<"Enter Your choice: ";
        cin>>choice;
        cout<<"\nProcessing..."<<endl;
        switch(choice)
        {
            case 1:
                currentAccount.deposit();
                break;
            case 2:
                currentAccount.withdraw();
                break;
            case 3:
                currentAccount.displayBalance();
                break;
            case 4:
                currentAccount.displayDetails();
                currentAccount.displayBalance();
                break;
            case 5:
                goto end;
            default:
                cout<<"\nInvalid Choice!!!";
        }
    }
}
else
{
    cout<<"\nInvalid Account Type!!!";
}
end:
cout<<"\nThank you for banking with us!!!\n";
return 0;}

