#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen 
{
    private :
    enum enTransactionsMenue
    {
        enDeposit = 1,
        enWithdraw = 2,
        enTotalBalance = 3,
        enTransfer = 4,
        enTransferLog = 5,
        enExitTransactions = 6,
    };
    static short _ReadMainMenueOption(string Message)
    {
        cout << setw(37) << left << "" << Message ;
        short Choice = clsInputValidate::ReadshortNumberBetween(1,6,"Wrong Choice , Enter Number Between [1 To 6] : ");

        return Choice;
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << setw(37) << left << ""<<"\n\tPress any key to go back to Transactions Menue...";
           
        system("pause>0");
        ShowTransactionsMenue();
    }

    static void _ShowDepositSecreen()
    {
        //cout<<"\nDeposit Screen Will Be Here . . . \n";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawSecreen()
    {
        //cout<<"\nWithdraw Screen Will Be Here . . . \n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _ShowTotalBalancesSecreen()
    {
        //cout<<"\nTotalBalance Screen Will Be Here . . . \n";
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }

    static void _ShowTransferSecreen()
    {
        //cout<<"\nTransfer Screen Will Be Here . . . \n";
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLogSecreen()
    {
        //cout<<"\nTransfer Screen Will Be Here . . . \n";
        clsTransferLogScreen::ShowTransferLogScreen();
    }
    
    static void _PerformTransactionMenueOption(enTransactionsMenue TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenue::enDeposit :
            system("cls");
            _ShowDepositSecreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionsMenue::enWithdraw :
            system("cls");
            _ShowWithdrawSecreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionsMenue::enTotalBalance :
            system("cls");
            _ShowTotalBalancesSecreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionsMenue::enTransfer :
            system("cls");
            _ShowTransferSecreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactionsMenue::enTransferLog :
            system("cls");
            _ShowTransferLogSecreen();
            _GoBackToTransactionsMenue();
        break;
        case enTransactionsMenue::enExitTransactions :
            system("cls");
            break;
        }

    }
    public :

    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t\t     Transactions Screen");
        cout << setw(37)<<left<< "" <<"|\t\t   |== BANK SYSTEM ==|\t\t   |\n";
        cout << setw(37)<<left<< "" <<"================================================\n";
        cout << setw(37)<<left<< "" <<"\t\t     Transactions Menue\n";
        cout << setw(37)<<left<< "" <<"================================================\n";
        cout << setw(37)<<left<< "" <<"\t\t[1] Deposit.\n";
        cout << setw(37)<<left<< "" <<"\t\t[2] Withdraw.\n";
        cout << setw(37)<<left<< "" <<"\t\t[3] Total Balances.\n";
        cout << setw(37)<<left<< "" <<"\t\t[4] Transfer.\n";
        cout << setw(37)<<left<< "" <<"\t\t[5] Transfer Log.\n";
        cout << setw(37)<<left<< "" <<"\t\t[6] Main Menue.\n";
        cout << setw(37)<<left<< "" <<"================================================\n";
        _PerformTransactionMenueOption((enTransactionsMenue)_ReadMainMenueOption("Choose What Do You Want To Do [1 - 6] : "));
    }

};