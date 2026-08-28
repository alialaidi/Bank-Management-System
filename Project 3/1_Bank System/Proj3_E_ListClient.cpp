#include <iostream>
#include "C:\Users\hp\OneDrive - Hashemite University\Desktop\Course C++ OOP Projects\clsBankClient.h"
#include "C:\Users\hp\OneDrive - Hashemite University\Desktop\Course C++ OOP Projects\clsInputValidate.h"
#include <iomanip>

using namespace std;

void PrintClientRecordLine(clsBankClient Client)
{
    cout << " | " << left << setw(15) << Client.AccountNumber();
    cout << " | " << left << setw(20) << Client.FullName();
    cout << " | " << left << setw(12) << Client.GetPhone();
    cout << " | " << left << setw(20) << Client.GetEmail();
    cout << " | " << left << setw(10) << Client.GetPhone();
    cout << " | " << left << setw(12) << Client.GetAccountBalance()<<"   | ";
}

void ShowClientsList()
{
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout<<"\n\t\t\t|    Client List ( "<< vClients.size()<<" ) Client(s).    |";
    cout<<"\n_______________________________________________________";
    cout << "_______________________________________________________\n";

    cout << " | " << left << setw(15) << "Accout Number";
    cout << " | " << left << setw(20) << "Client Name";
    cout << " | " << left << setw(12) << "Phone";
    cout << " | " << left << setw(20) << "Email";
    cout << " | " << left << setw(10) << "Pin Code";
    cout << " | " << left << setw(12) << "Accout Balance" << " | ";
    cout<<"\n_______________________________________________________";
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

    cout<<"_______________________________________________________";
    cout << "_______________________________________________________\n" << endl;
}

int main()
{
    ShowClientsList();

    return 0;
}