#include <iostream>
#include "C:\Users\hp\OneDrive - Hashemite University\Desktop\Course C++ OOP Projects\clsBankClient.h"
#include "C:\Users\hp\OneDrive - Hashemite University\Desktop\Course C++ OOP Projects\clsInputValidate.h"
#include <iomanip>
#include "C:\Users\hp\OneDrive - Hashemite University\Desktop\Course C++ OOP Projects\clsUtilLibrary.h"

using namespace std;

void PrintClientRecordBalanceLine(clsBankClient Client)
{
    cout << " | " << left << setw(15) << Client.AccountNumber();
    cout << " | " << left << setw(40) << Client.FullName();
    cout << " | " << left << setw(12) << Client.GetAccountBalance()<<"   | ";
}

void ShowTotalBalances()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout<<"\n\t\t\t|    Client List ( "<< vClients.size()<<" ) Client(s).    |";
    cout<<"\n_______________________________________________________";
    cout << "_______________________________________________________\n";

    cout << " | " << left << setw(15) << "Accout Number";
    cout << " | " << left << setw(40) << "Client Name";
    cout << " | " << left << setw(12) << "Accout Balance" << " | ";
    cout<<"\n_______________________________________________________";
    cout << "_______________________________________________________\n";

    double TotalBalances = clsBankClient::GetTotalBalances();

    if (vClients.size() == 0)
    {
        cout << "\t\t\t\tNo Clients Available In The System !";
    }
    else 
        for(clsBankClient& Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout<<endl;
        }

    cout<<"_______________________________________________________";
    cout << "_______________________________________________________\n" << endl;

    cout<<"\t\t\t\t\t Total Balances = "<<TotalBalances << endl;
    cout<<"\t\t\t\t\t ( "<<clsUtil::NumberToText(TotalBalances)<<" ) \n\n";


}

int main()
{
    ShowTotalBalances();

    return 0;
}