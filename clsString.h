#pragma once

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

class clsString
{
    private:
    string _Value;
    

    public:
    clsString()
    {
        _Value = "";
    }
    
    clsString(string  Value)
    {
        _Value = Value;
    }
    
    void SetString(string Value)
    {
        _Value = Value;
    }
    
    string GetString()
    {
        return _Value;
    }

    static short Length(string Value)
    {
        return Value.length();
    }
    
    short Length()
    {
        return _Value.length();
    }

    short GetShort()
    {
        return _Value.length();
    }

    static void PrintFirstLetterInString(string str)
    {
        bool IsFirstLetter = true;

        cout<<"\nFirst Letter Of Each Word In String : \n";

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && IsFirstLetter)
            {
                cout<<str[i]<<endl;
            }
            IsFirstLetter = (str[i] == ' '? true : false );
        }
    
    }

    void PrintFirstLetterInString()
    {
        PrintFirstLetterInString(_Value);
    }

    static string UpperFirstLetterOfEachWord(string str)
    {
        bool IsFirstLetter = true;

        cout<<"\nString After Conversion To Upper : \n";

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && IsFirstLetter)
            {
            str[i]=toupper(str[i]);
                }
            IsFirstLetter = (str[i] == ' '? true : false );
        }
        return str;
    }

    void UpperFirstLetterOfEachWord()
    {
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    static string LowerFirstLetterOfEachWord(string str)
    {
        bool IsFirstLetter = true;


        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' && IsFirstLetter)
            {
                str[i]=tolower(str[i]);
            }
            IsFirstLetter = (str[i] == ' '? true : false );
        }
        return str;
    }

    void LowerFirstLetterOfEachWord()
    {
        _Value =  LowerFirstLetterOfEachWord(_Value);
    }

    static string UpperAllString(string str)
    {

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ' )
            {
                str[i]=toupper(str[i]);
            }

        }
        return str;
    }
    
    void UpperAllString()
    {
        _Value =  UpperAllString(_Value);
    }

    static string LowerAllString(string str)
    {
        cout<<"\nString After Conversion To Lower : \n";

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ')
            {
                str[i]=tolower(str[i]);
            }

        }
        return str;
    }

    void LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    static char InvertLetterCase(char c)/////////////////////////////////// - Note 
    {
        return (isupper(c))? tolower(c) : toupper(c);
    }

    static string  InvertAllLettersCase(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;
    }

    void  InvertAllLettersCase()
    {
        _Value = InvertAllLettersCase(_Value);
    }

    enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
   {


       if (WhatToCount == enWhatToCount::All)
       {
           return S1.length();
       }

       short Counter = 0;

       for (short i = 0; i < S1.length(); i++)
       {

           if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
               Counter++;


           if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
               Counter++;


       }

       return Counter;

   }
  
    static short CountCapitelLetters(string str)
    {
        short UpperCount = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (isupper(str[i]))
            {
                UpperCount++;
            }    
        }
        return UpperCount;
    }

    short CountCapitelLetters()
    {
        return CountCapitelLetters(_Value);
    }

    static short CountSmallLetters(string str)
    {
        short LowerCount = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (islower(str[i]))
            {
                LowerCount++;
            }    
        }
        return LowerCount;
    }

    short CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static short CountLetter(string str,char ch)
    {
        short Counter = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == ch)
            {
                Counter++;
            }

        }
        return Counter;
    }

    short CountLetter(char ch)
    {
        return CountLetter(_Value, ch);
    }

    static short CountSpecificLetters(string str,char ch,bool MatchCase = true)
    {
        short Counter = 0;
        for (short i = 0; i < str.length(); i++)
        {
            if (MatchCase)
            {
                if(str[i] == ch)
                Counter++;
            }
            else
            {
                if(tolower(str[i]) == tolower(ch))
                Counter++;
            }

        }
        return Counter;
    }
    
    short CountSpecificLetters(char ch, bool MatchCase = true)
    {
        return CountSpecificLetters(_Value, ch, MatchCase);
    }

    static bool IsVowel(char ch)
    {
        ch = tolower(ch);

        return ((ch == 'a')||(ch == 'o')||(ch == 'u')||(ch == 'i')||(ch == 'e'));
    }

    static short CountVowels(string str)
    {
        short Counter = 0;
        for (short i = 0; i < str.length(); i++)
        {
            if (IsVowel(str[i]))
            Counter++;

        }
        return Counter;
    }

    short CountVowels()
    {
        return CountVowels(_Value);
    }

    static void PrintVowelLetters(string str)
    {
        cout<<"\nVowels in String Are : ";
        for (short i = 0; i < str.length(); i++)
        {
            if (IsVowel(str[i]))
                cout<<str[i]<<"   ";


        }
        cout<<endl;
    }

    void PrintVowelLetters()
    {
        PrintVowelLetters(_Value);
    }

    static void PrintEachWordInString(string str)
    {
        string delim = " ";
        short pos = 0;
        string sWord;

        while ((pos = str.find(delim))!= string::npos)
        {
            sWord = str.substr(0, pos);

            if (sWord != "")
            cout<< sWord << "\n";

            str.erase(0, pos + delim.length());
        }
        if (str != "")
        {
            cout<<str<<endl;
        }

    }

    void PrintEachWordInString()
    {
        PrintEachWordInString(_Value);
    }

    static short CountWord(string str)
    {
        short Counter = 0;
        string delim = " ";
        short pos = 0;
        string sWord;

        while ((pos = str.find(delim))!= string::npos)
        {
            sWord = str.substr(0, pos);

            if (sWord != "")
            {
                Counter++;
            }


            str.erase(0, pos + delim.length());
        }
        if (str != "")
        {
            Counter++;
        }

        return Counter;
    

    }

    short CountWord()
    {
        return CountWord(_Value);
    }

    static vector <string> vSplitFunc(string str,string delim)
    {
        short pos = 0;
        vector <string> vString;
        string sWord;

        while ((pos = str.find(delim))!= string::npos)
        {
            sWord = str.substr(0, pos);

            vString.push_back(sWord);

            str.erase(0, pos + delim.length());
        }
        if (str != "")
            vString.push_back(str);

        return vString;

    }

    vector <string> vSplitFunc(string delim)
    {
        return vSplitFunc(_Value, delim);
    }
    static vector<string> Split(string S1, string Delim)
    {

        vector<string> vString;

        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(Delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
           // if (sWord != "")
           // {
                vString.push_back(sWord);
            //}

            S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;

    }

    vector<string> Split(string Delim)
    {
        return Split(_Value, Delim);
    }

    static string TrimRight(string str)
    {
        for (short i = str.length()-1; i >= 0; i--)
        {
            if (str[i] != ' ')
            {
                return str.substr(0, i+1);
            }

        }
        return "";
    }

    void TrimRight()
    {
        _Value =  TrimRight(_Value);
    }

    static string TrimLeft(string str)
    {
        for (short i = 0; i < str.length(); i++)
        {
            if (str[i] != ' ')
            {
                return str.substr(i, str.length() - i);
            }

        }
        return "";

    }
    
    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    static string Trim(string str)
    {
        return (TrimLeft(TrimRight(str)));
    }

    void Trim()
    {
        _Value = Trim(_Value);
    }

    static string JoinString(vector <string> vString,string delim)
    {
        string str="";
        for (string& i : vString)
        {
            str += i + delim;
        }

        return str.substr(0,str.length()-delim.length());
    }

    static string JoinStrings(string arr[],short arrLength,string delim)
    {
        string str="";
        for (short i = 0; i < arrLength; i++)
        {
            str += arr[i] + delim;
        }
    

        return str.substr(0,str.length()-delim.length());
    }

    static string ReverseWordsInString(string str)
    {
        vector <string> vWords;
        string reversedStr = "";

        vWords = vSplitFunc(str, " ");

        vector <string>::iterator iter = vWords.end();

        while (iter!= vWords.begin())
        {
            --iter;
            reversedStr += *iter+" ";
        }

        reversedStr = reversedStr.substr(0, reversedStr.length()-1);

        return reversedStr;

    }

    void ReverseWordsInString()
    {
        _Value = ReverseWordsInString(_Value);
    }

    static string ReplaceWord(string str,string StringToReplace,string sReplaceTo)
    {
        short Pos = str.find(StringToReplace);

        while (Pos!= string::npos) {
            str.replace(Pos, StringToReplace.length(), sReplaceTo);
            Pos = str.find(StringToReplace);
        }
        return str;
    }
    
    string ReplaceWord(string StringToReplace, string sReplaceTo)
    {
        return ReplaceWord(_Value, StringToReplace, sReplaceTo);
    }

    static string RemovePanctuations(string str)
    {
        string str2 = "";
        for (short i = 0; i < str.length(); i++)
        {
           if (!ispunct(str[i]))
           {
            str2 += str[i];  
           }
        }
        return str2;

    }
    
    string RemovePanctuations()
    {
        _Value = RemovePanctuations(_Value);
    }

};