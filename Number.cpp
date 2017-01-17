//---------------------------------------------------------------------------


#pragma hdrstop

#include "Number.h"
#include <vcl.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)

Number::Number()
{
        NumberDigitsLength = 0;
        NumberSign = 1;
        for(int i = 0; i < 100; i++)
        {
                NumberDigits[i] = 0;
        }
}

char* Number::StringToChar(String SNumberDigits)
{
        char CNumberDigits[100] = "";
        strcpy(CNumberDigits, SNumberDigits.c_str());

        return CNumberDigits;
}

int* Number::CharToInt(char* CNumberDigits)
{
        int i;

        for(i = 0; i < NumberDigitsLength; i++)
        {
                NumberDigits[i] = CNumberDigits[i] - '0';
        }

        return NumberDigits;
}

void Number::StringToInt(String SNumberDigits)
{
        NumberDigitsLength = strlen(SNumberDigits.c_str());

        char CNumberDigits[100];
        memcpy(CNumberDigits, StringToChar(SNumberDigits), sizeof(CNumberDigits));
        memcpy(NumberDigits, CharToInt(CNumberDigits), sizeof(NumberDigits));

}

String Number::IntToString(int DotPosition)
{
        int i;

        String SNumberDigits = "";
        for(i = 0; i < NumberDigitsLength; i++)
        {
                if( i == DotPosition && DotPosition != 0)
                {
                  SNumberDigits += ".";
                }

                SNumberDigits += NumberDigits[i];
        }

        return SNumberDigits;
}

void Number::Overturn()
{
        int i;
        int OverturnedNumberDigits[100];

        for(int i = 0; i < 100; i++)
        {
                OverturnedNumberDigits[i] = 0;
        }

        for(i = 0; i < NumberDigitsLength; i++)
        {
                OverturnedNumberDigits[NumberDigitsLength - i - 1] = NumberDigits[i];
        }

        memcpy(NumberDigits, OverturnedNumberDigits, sizeof(NumberDigits));

        //return OverturnedNumberDigits;
}

void Number::ChangeSizeForZero()
{
        for(int i = 0; i < NumberDigitsLength; i++)
        {
                if(NumberDigits[i] != 0)
                {
                        return;
                }
        }

        NumberDigitsLength = 1;
}

