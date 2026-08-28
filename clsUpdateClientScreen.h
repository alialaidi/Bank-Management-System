#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateClientScreen : protected clsScreen 
{
    private : 

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

    public : 

    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }
        _DrawScreenHeader("\t\t   Update Client Screen");
        string AccountNumber = "";

        cout<<"\nPlease Enter Client Account Number : ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout<<"\nAccount Number Is Not Found Chose Another One : ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClient(Client1);

        cout<<"\n\nUpdate Client INFO : ";
        cout<<"\n====================";

        _ReadClientInfo(Client1);

        clsBankClient::enSaveResulte SaveResult;

        SaveResult = Client1.Save();
        switch (SaveResult)
        {
            case clsBankClient::enSaveResulte::svSucceeded :
            {
                cout<<"\nAccount Updated Successfully :-)\n";
                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResulte::svFaildEmptyObject : 
            {
                cout<<"\nError Account Wasn't Saved Because It's Empty :-( \n";   
                break;
            }
        }


    }


};