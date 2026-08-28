#include <iostream>
#include "C:\Users\hp\OneDrive - Hashemite University\Desktop\Course C++ OOP Projects\clsBankClient.h"
#include "C:\Users\hp\OneDrive - Hashemite University\Desktop\Course C++ OOP Projects\clsInputValidate.h"

using namespace std;

void DeleteClient()
{
    string AccountNumber = "";
    
    cout<<"\nPlease Enter Client Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout<<"\nAccount Number Is Already Used , Choose Another One : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout<<"\nAre You sure you want to Delete This Client ?\nYes [Y/y] \nNo [N/n]\nYour Choice : ";

    char Answer = 'n';
    cin >> Answer;

    if (Answer == 'y' || Answer == 'Y')
    {
        if (Client1.Delete())
        {
            cout<<"\nClient Deleted Successfully :-)\n\n";
            Client1.Print();
        }
        else
        {
            cout<<"\nFailed To Delete Client.\n\n";
        }
        
    }
    
}

int main()
{
    DeleteClient();

    return 0;
}