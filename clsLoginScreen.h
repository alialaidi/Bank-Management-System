#pragma once

#include "clsUser.h"
#include <iostream>
#include <iomanip>
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsGlobal.h"

using namespace std;

class clsLoginScreen : protected clsScreen 
{
    private :

    static  bool _Login()
    {
        bool LoginFaild = false;
        short FaildLoginCounter = 0;

        string Username, Password;
        do
        {
     
            if (LoginFaild)
            {
                cout << "\n-> Invlaid Username/Password!\n\n";
                FaildLoginCounter++;
                cout << "--> You Have "<<(3-FaildLoginCounter)<<" Trial(s) To Login\n";
            }

            if (FaildLoginCounter == 3)
            {
                cout<<"\n--> Your Are Locked After 3 Faild Trails \n\n";
                return false;
            }

            cout << setw(37)<<""<<"\t\tEnter Username : ";
            cin >> Username;

            cout << setw(37)<<""<<"\t\tEnter Password : ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;

    }

    void _Log()
    {
        
    }

    public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t\t     Login Screen");
        _Login();

    }




};