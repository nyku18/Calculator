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
        int Position;
        Number Reminder = Number();
        Number TwoAsNumber = Number();   // numarul 2
        TwoAsNumber.StringToInt("2");


        Sum SumResult = Sum();
        Difference DifferenceResult = Difference();
        Product ProductResult = Product();

        if(FirstNumber.NumberDigitsLength % 2 == 1)
        {
                FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength] = 0;
                FirstNumber.NumberDigitsLength++;
                Position = 2;
        }

        Result.NumberDigitsLength++;
        Result.NumberDigits[0] = sqrt(FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength-1] * 10 + FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength-2]);
        Reminder = Result;

        // reminder * 2
        ProductResult.FirstNumber = Reminder;
        ProductResult.SecondNumber = TwoAsNumber;
        ProductResult.Calculate();


}
