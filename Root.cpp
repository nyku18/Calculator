//---------------------------------------------------------------------------


#pragma hdrstop

#include "Root.h"
#include <math.h>
#include "Sum.h"
#include "Difference.h"
#include "Product.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Root::Root()
{

}

int Root::Calculate()
{
        Number Reminder = Number();
        Number TwoAsNumber = Number();   // numarul 2
        TwoAsNumber.StringToInt("2");


        Product ProductResult = Product();
        Sum SumResult = Sum();
        Difference DifferenceResult = Difference();

        if(FirstNumber.NumberDigitsLength % 2 == 1)
        {
                FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength] = 0;
                FirstNumber.NumberDigitsLength++;
        }

        Result.NumberDigitsLength++;
        Result.NumberDigits[0] = sqrt(FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength-1] * 10 + FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength-2]);
        Reminder = Result;
        // reminder * 2

        ProductResult.FirstNumber = Reminder;
        ProductResult.SecondNumber = TwoAsNumber;
        ProductResult.Calculate();

        int a = 3;
        //Result.NumberDigitsLength++;

        /*for(int i = 0; i < Result.NumberDigitsLength; i++)
        {
                Reminder.NumberDigits[i] =
        }    */

}
