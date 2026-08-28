#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : public clsScreen 
{
    private : 
    enum enManageUsersScreen
    {
        enListUsers = 1,
        enAddUser = 2,
        enDeleteUser = 3,
        enUpdateUser = 4,
        enFindUser = 5,
        enExitUsers = 6,
    };
    static short _ReadManageUsersMenueOption(string Message)
    {
        cout << setw(37) << left << "" << Message ;
        short Choice = clsInputValidate::ReadshortNumberBetween(1,6,"Wrong Choice , Enter Number Between [1 To 6] : ");

        return Choice;
    }


    static void _GoBackToManageUsersScreen()
    {
        cout << setw(37) << left << ""<<"\n\tPress any key to go back to Manage Users Menue...";
           
        system("pause>0");
        ShowManageUsersMenue();
    }


    static void  _ShowUsersListScreen()
    {
        //cout<<"\nUsers List Screen Will Be Here . . . \n";
        clsListUsersScreen::ShowUsersList();

    }
    static void _ShowAddNewUserScreen()
    {
        //cout<<"\nAdd New User Screen Will Be Here . . . \n";
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }
    static void _ShowDeleteUserScreen()
    {
        //cout<<"\nDelete User Screen Will Be Here . . . \n";
        clsDeleteUserScreen::ShowDeleteUserScreen();

    }
    static void _ShowUpdateUserScreen()
    {
       //cout<<"\nUpdate User Screen Will Be Here . . . \n";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        //cout<<"\nFind User Screen Will Be Here . . . \n";
        clsFindUserScreen::ShowFindUserScreen();
    }


    static void _PerformManageUsersMenueOption(enManageUsersScreen ManagmentMenueOption)
    {
        switch (ManagmentMenueOption)
        {
        case enManageUsersScreen::enListUsers : 
            system("cls");
            _ShowUsersListScreen();
            _GoBackToManageUsersScreen();
            break;

        case enManageUsersScreen::enAddUser : 
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersScreen();
            break;
        case enManageUsersScreen::enDeleteUser :
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersScreen();
            break;
        case enManageUsersScreen::enUpdateUser : 
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersScreen();
            break;
        case enManageUsersScreen::enFindUser :
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersScreen();
            break;
        case enManageUsersScreen::enExitUsers :
            system("cls");
            break;
        }
    }



    public :
    static void ShowManageUsersMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t\t   Manage Users Screen");
        cout << setw(37)<<left<< "" << "|\t\t    |== BANK SYSTEM ==|\t\t    |\n";
        cout << setw(37)<<left<< "" <<"================================================\n";
        cout << setw(37)<<left<< "" <<"\t\t     Main Menue Screen\n";
        cout << setw(37)<<left<< "" <<"================================================\n";
        cout << setw(37)<<left<< "" <<"\t\t[1] List Users.\n";
        cout << setw(37)<<left<< "" <<"\t\t[2] Add New User.\n";
        cout << setw(37)<<left<< "" <<"\t\t[3] Delete User.\n";
        cout << setw(37)<<left<< "" <<"\t\t[4] Update User.\n";
        cout << setw(37)<<left<< "" <<"\t\t[5] Find User.\n";
        cout << setw(37)<<left<< "" <<"\t\t[6] Main Menue.\n";
        cout << setw(37)<<left<< "" <<"================================================\n";

        _PerformManageUsersMenueOption((enManageUsersScreen)_ReadManageUsersMenueOption("Choose What Do You Want To Do [1 - 6] : "));
    }
};
