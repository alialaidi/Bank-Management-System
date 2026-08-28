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


void UpdateClient()
{
    string AccountNumber = "";
    
    cout<<"\nPlease Enter Client Account Number : ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout<<"\nAccount Number Is Not Found Chose Another One : ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    cout<<"\n\nUpdate Client INFO : ";
    cout<<"\n====================";

    ReadClientInfo(Client1);

    clsBankClient::enSaveResulte SaveResult;

    SaveResult = Client1.Save();
    switch (SaveResult)
    {
        case clsBankClient::enSaveResulte::svSucceeded :
        {
            cout<<"\nAccount Updated Successfully :-)\n";
            Client1.Print();
            break;
        }
        case clsBankClient::enSaveResulte::svFaildEmptyObject : 
        {
            cout<<"\nError Account Wasn't Saved Because It's Empty :-( \n";   
            break;
        }
    }


}



int main()
{
    UpdateClient();
    return 0;
}