#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsGlobal.h"
#include "clsLoginScreen.h"
#include "clsLoginRegesterScreen.h"
#include "clsCurrencyExchangeScreen.h"


using namespace std;

class clsMainScreen : protected clsScreen
{
    private :

    enum enMainMenue
    {
        ShowClientList = 1,
        AddNewInfoClient = 2,
        DeleteClient = 3,
        UpdateClient = 4,
        FindClient = 5,
        Transactions = 6,
        ManageUsers = 7,
        LoginRegister = 8,
        CurrencyExchange = 9,
        Exit = 10,
    };

    static short _ReadMainMenueOption(string Message)
    {
        cout << setw(37) << left << "" << Message ;
        short Choice = clsInputValidate::ReadshortNumberBetween(1,10,"Wrong Choice , Enter Number Between [1 To 10] : ");

        return Choice;
    }


    static void _GoBackToMainMenue()
    {
        cout << setw(37) << left << ""<<"\n\tPress any key to go back to Main Menue...";
           
        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        //cout<<"\nClient List Screen Will Be Here . . . \n";
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientScreen()
    {
        //cout<<"\nAdd New Client Screen Will Be Here . . . \n";
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        //cout<<"\nDelete Client Screen Will Be Here . . . \n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        //cout<<"\nUpdate Client Screen Will Be Here . . . \n";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        //cout<<"\nFind Client Screen Will Be Here . . . \n";
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        //cout<<"\nTransactions Menue Screen Will Be Here . . . \n";
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        //cout<<"\nUsers Menue Screen Will Be Here . . . \n";
        clsManageUsersScreen::ShowManageUsersMenue();
    }
    static void _ShowLoginRegisterScreen()
    {
        //cout<<"\nLogin Register Screen Will Be Here . . . \n";
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }
    static void _ShowCurrencyExchangeScreen()
    {
        //cout<<"\nLogin Register Screen Will Be Here . . . \n";
        clsCurrencyExchangeScreen::ShowCurrencyExchangeMenue();
        
    }

    static void  _Logout()
    {
        //cout<<"\nEnd Screen Screen Will Be Here . . . \n";
        CurrentUser = clsUser::Find("","");
    }
    

    static void _PerformMainMenueOption(enMainMenue MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenue::ShowClientList:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenue::AddNewInfoClient:
            system("cls");
            _ShowAddNewClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenue::DeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenue::UpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenue::FindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenue::Transactions : 
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break; 

        case enMainMenue::ManageUsers :
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenue::LoginRegister :
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenue::CurrencyExchange :
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenue::Exit : 
            system("cls");
            _Logout();
            break;
        }
    }

    public : 
    static void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\t       Main Screen");
        cout << setw(37)<<left<< "" << "|\t\t    |== BANK SYSTEM ==|\t\t    |\n";
        cout << setw(37)<<left<< "" <<"================================================\n";
        cout << setw(37)<<left<< "" <<"\t\t     Main Menue Screen\n";
        cout << setw(37)<<left<< "" <<"================================================\n";
        cout << setw(37)<<left<< "" <<"\t\t[1] Show Client List.\n";
        cout << setw(37)<<left<< "" <<"\t\t[2] Add New Client.\n";
        cout << setw(37)<<left<< "" <<"\t\t[3] Delete Client.\n";
        cout << setw(37)<<left<< "" <<"\t\t[4] Update Client Info.\n";
        cout << setw(37)<<left<< "" <<"\t\t[5] Find Client.\n";
        cout << setw(37)<<left<< "" <<"\t\t[6] Transactions.\n";
        cout << setw(37)<<left<< "" <<"\t\t[7] Manage Users.\n";
        cout << setw(37)<<left<< "" <<"\t\t[8] Login Register.\n";
        cout << setw(37)<<left<< "" <<"\t\t[9] Currency Exchange.\n";
        cout << setw(37)<<left<< "" <<"\t\t[10] Logout.\n";
        cout << setw(37)<<left<< "" <<"================================================\n";
        _PerformMainMenueOption((enMainMenue)_ReadMainMenueOption("Choose What Do You Want To Do [1 - 10] : "));
    }
};