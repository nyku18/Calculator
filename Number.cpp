//---------------------------------------------------------------------------


#pragma hdrstop

#include "Number.h"
//#include <string.h>
#include <vcl.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)

Number::Number()
{

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

        //return NumberDigits;
}

void Number::Overturn()
{
        int i;

        int OverturnedNumberDigits[100];

        for(i = 0; i < NumberDigitsLength; i++)
        {
                OverturnedNumberDigits[NumberDigitsLength - i - 1] = NumberDigits[i];
        }

        memcpy(NumberDigits, OverturnedNumberDigits, sizeof(NumberDigits));
        //return OverturnedNumberDigits;
}
