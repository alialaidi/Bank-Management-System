#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"


using namespace std;

class clsCurrencyExchangeScreen : protected clsScreen 
{
    private :
    enum enCurrencyExchangeMenue
    {
        enListCurrencies = 1,
        enFindCurrency = 2,
        enUpdateRate = 3,
        enCurrencyCalculator = 4,
        enMainMenue = 5,
        
    };
    static short _ReadMainMenueOption(string Message)
    {
        cout << setw(37) << left << "" << Message ;
        short Choice = clsInputValidate::ReadshortNumberBetween(1,5,"Wrong Choice , Enter Number Between [1 To 5] : ");

        return Choice;
    }

    static void _GoBackToCurrencyMenue()
    {
        cout << setw(37) << left << ""<<"\n\tPress any key to go back to Currency Menue...";
           
        system("pause>0");
        ShowCurrencyExchangeMenue();
    }

    static void _ShowListCurrenciesSecreen()
    {
        //cout<<"\nList Currencies Screen Will Be Here . . . \n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencySecreen()
    {
        //cout<<"\nFind Currency Screen Will Be Here . . . \n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
        
    }
    static void _ShowUpdateRateSecreen()
    {
        //cout<<"\nUpdate Rate Screen Will Be Here . . . \n";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
        
    }

    static void _ShowCurrencyCalculatorSecreen()
    {
        //cout<<"\nCurrency Calculator Screen Will Be Here . . . \n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }
    
    static void _PerformCurrencyMenueOption(enCurrencyExchangeMenue CurrencyMenueOption)
    {
        switch (CurrencyMenueOption)
        {
        case enCurrencyExchangeMenue::enListCurrencies :
            system("cls");
            _ShowListCurrenciesSecreen();
            _GoBackToCurrencyMenue();
            break;
        case enCurrencyExchangeMenue::enFindCurrency :
            system("cls");
            _ShowFindCurrencySecreen();
            _GoBackToCurrencyMenue();
            break;
        case enCurrencyExchangeMenue::enUpdateRate :
            system("cls");
            _ShowUpdateRateSecreen();
            _GoBackToCurrencyMenue();
            break;
        case enCurrencyExchangeMenue::enCurrencyCalculator :
            system("cls");
            _ShowCurrencyCalculatorSecreen();
            _GoBackToCurrencyMenue();
            break;
        case enCurrencyExchangeMenue::enMainMenue :
            system("cls");
            
            break;
        }

    }
    public :

    static void ShowCurrencyExchangeMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
        {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t\t Currency Exchange Screen");
        cout << setw(37)<<left<< "" <<"|\t\t   |== BANK SYSTEM ==|\t\t   |\n";
        cout << setw(37)<<left<< "" <<"================================================\n";
        cout << setw(37)<<left<< "" <<"\t\t Currency Exchange Menue\n";
        cout << setw(37)<<left<< "" <<"================================================\n";
        cout << setw(37)<<left<< "" <<"\t\t[1] List Currencies.\n";
        cout << setw(37)<<left<< "" <<"\t\t[2] Find Currency.\n";
        cout << setw(37)<<left<< "" <<"\t\t[3] Update Rate.\n";
        cout << setw(37)<<left<< "" <<"\t\t[4] Currency Calculator.\n";
        cout << setw(37)<<left<< "" <<"\t\t[5] Main Menue.\n";
        cout << setw(37)<<left<< "" <<"================================================\n";
        _PerformCurrencyMenueOption((enCurrencyExchangeMenue)_ReadMainMenueOption("Choose What Do You Want To Do [1 - 5] : "));
    }

};