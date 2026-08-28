#pragma once
#include <iostream>
#include <iomanip>
#include "clsGlobal.h"
#include "clsDate.h"
#include "clsUser.h"


using namespace std;

class clsScreen
{
    protected :
    static void _DrawScreenHeader(string Title,string SubTitle ="")
    {
        cout << setw(37)<<left<< "" <<"================================================\n";
        cout << setw(37)<<left<< "" <<Title<<endl;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << setw(37)<<left<< "" <<"================================================\n";

        cout << setw(37)<<left<< "" <<"User : "<<CurrentUser.GetUserName()<<"\n";
        cout << setw(37)<<left<< "" <<"Date : "<<clsDate::DateToString(clsDate())<<"\n";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
     
            if (!CurrentUser.CheckAccessPermission(Permission))
            {
                cout << setw(37)<<left<< "" <<"================================================\n\n";
                cout << setw(37)<<left<< "" <<"\t    Access Denied! Contact your Admin.\n\n";   
                cout << setw(37)<<left<< "" <<"================================================\n";
                return false;
            }
            else
            {
                return true;
            }

    }


};

