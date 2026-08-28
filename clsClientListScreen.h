#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsClientListScreen : protected clsScreen
{
    private :
    static void PrintClientRecordLine(clsBankClient Client)
    {
        cout <<setw(10)<<""<< " | " << left << setw(15) << Client.AccountNumber();
        cout << " | " << left << setw(20) << Client.FullName();
        cout << " | " << left << setw(12) << Client.GetPhone();
        cout << " | " << left << setw(20) << Client.GetEmail();
        cout << " | " << left << setw(10) << Client.GetPhone();
        cout << " | " << left << setw(12) << Client.GetAccountBalance()<<"   | ";
    }

    public :

    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return;
        }
        
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t\t  Clients List Screen";
        string SubTitle = "     Client List ( "+ to_string(vClients.size())+" ) Client(s)\n";

        _DrawScreenHeader(Title, SubTitle);
        cout<<"\n";
        cout<<setw(10)<<""<<"_______________________________________________________";
        cout << "_______________________________________________________\n";

        cout <<setw(10)<<""<< " | " << left << setw(15) << "Accout Number";
        cout << " | " << left << setw(20) << "Client Name";
        cout << " | " << left << setw(12) << "Phone";
        cout << " | " << left << setw(20) << "Email";
        cout << " | " << left << setw(10) << "Pin Code";
        cout << " | " << left << setw(12) << "Accout Balance" << " | \n";
        cout<<setw(10)<<""<<"_______________________________________________________";
        cout << "_______________________________________________________\n";

        if (vClients.size() == 0)
        {
            cout << "\t\t\t\tNo Clients Available In The System !";
        }
        else 
            for(clsBankClient& Client : vClients)
            {
                PrintClientRecordLine(Client);
                cout<<endl;
            }

        cout<<setw(10)<<""<<"_______________________________________________________";
        cout << "_______________________________________________________\n" << endl;
    }


};