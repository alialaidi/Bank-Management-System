#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
    private :
    static void _ReadClientInfo(clsBankClient& Client)
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

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card : ";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.GetFirstName();
        cout << "\nLastName    : " << Client.GetLastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.GetEmail();
        cout << "\nPhone       : " << Client.GetPhone();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.GetPinCode();
        cout << "\nBalance     : " << Client.GetAccountBalance();
        cout << "\n___________________\n";

    }
    
    public : 

    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;
        }
        _DrawScreenHeader("\t\t   Add New Client Screen");
        string AccountNumber = "";
        cout<<"\nPlease Enter Client Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout<<"\nAccount Number Is Already Used , Choose Another One : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResulte SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
            case clsBankClient::enSaveResulte::svSucceeded :
            {
                cout<<"\nAccount Added Successfully :-)\n";
                _PrintClient(NewClient);
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

};