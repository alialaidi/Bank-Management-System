#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtilLibrary.h"

using namespace std;

class clsTotalBalancesScreen : protected clsScreen 
{
    private :
    static void PrintClientRecordBalanceLine(clsBankClient Client)
    {
        cout << setw(10)<<""<<" | " << left << setw(15) << Client.AccountNumber();
        cout << " | " << left << setw(40) << Client.FullName();
        cout << " | " << left << setw(12) << Client.GetAccountBalance()<<"   | ";
    }

    

    public :

    static void ShowTotalBalancesScreen()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t\t  Balances List Screen";
        string SubTitle = "     Client List ( "+ to_string(vClients.size())+" ) Client(s)\n";

        _DrawScreenHeader(Title, SubTitle);
        cout<<"\n";
        cout<<setw(10)<<""<<"_______________________________________________________";
        cout << "_______________________________________________________\n";

        cout << setw(10)<<""<<" | " << left << setw(15) << "Accout Number";
        cout << " | " << left << setw(40) << "Client Name";
        cout << " | " << left << setw(12) << "Accout Balance" << " | \n";
        cout<<setw(10)<<""<<"_______________________________________________________";
        cout << "_______________________________________________________\n";

        double TotalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
        {
            cout << "\n\t\t\t\tNo Clients Available In The System !\n\n";
        }
        else 
            for(clsBankClient& Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
                cout<<endl;
            }

        cout<<setw(10)<<""<<"_______________________________________________________";
        cout << "_______________________________________________________\n" << endl;

        cout<<"\t\t\t\t\t\t\tTotal Balances = "<<TotalBalances << endl;
        cout<<"\t\t\t\t\t ( "<<clsUtil::NumberToText(TotalBalances)<<" ) \n\n";
    }


};