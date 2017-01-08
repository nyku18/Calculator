//---------------------------------------------------------------------------

#ifndef NumberH
#define NumberH
//---------------------------------------------------------------------------
#include <string>
#include <vcl.h>
//---------------------------------------------------------------------------
class Number
{
        public:

                int NumberDigits[100];
                int NumberDigitsLength;
                int NumberSign;
                Number();
                void StringToInt(String SNumberDigits);
                void Overturn();
                String IntToString(int DotPosition);
        private:
                char* StringToChar(String SNumberDigits);
                int* CharToInt(char* CNumberDigits);
};


//---------------------------------------------------------------------------
#endif
