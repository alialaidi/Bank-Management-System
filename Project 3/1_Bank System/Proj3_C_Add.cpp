#include <iostream>
#include "C:\Users\hp\OneDrive - Hashemite University\Desktop\Course C++ OOP Projects\clsBankClient.h"
#include "C:\Users\hp\OneDrive - Hashemite University\Desktop\Course C++ OOP Projects\clsInputValidate.h"

using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
    cout<<"\nEnter First Name : " ;
    Client.SetFirstName(clsInputValidate::ReadString());
    
    cout<<"\nEnter Last Name : " ;
    Client.SetLastName(clsInputValidate::ReadString());

    cout<<"\nEnter Email : " ;
    Client.SetEmail(clsInputValidate::ReadString());
    
    cout<<"\nEnter Phone Number : " ;
    Client.SetPhone(clsInputValidate::ReadString());


    cout<<"\nEnter PinCode : " ;
    Client.SetPinCode(clsInputValidate::ReadString());
    
    cout<<"\nEnter Account Balance : " ;
    Client.SetAccountBalance(clsInputValidate::ReadFloutNumber());


}


void AddClient()
{
    string AccountNumber = "";
    
    cout<<"\nPlease Enter Client Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout<<"\nAccount Number Is Already Used , Choose Another One : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResulte SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
        case clsBankClient::enSaveResulte::svSucceeded :
        {
            cout<<"\nAccount Added Successfully :-)\n";
            NewClient.Print();
            break;
        }
        case clsBankClient::enSaveResulte::svFaildEmptyObject : 
        {
            cout<<"\nError Account Wasn't Saved Because It's Empty :-( \n";   
            break;
        }
        case clsBankClient::enSaveResulte::svFaildAccountNumberExists : 
        {
            cout << "\nError Account Was Not Saved Because Account Number Is Used!\n";
            break;
        }

    }


}



int main()
{
    AddClient();
    return 0;
}