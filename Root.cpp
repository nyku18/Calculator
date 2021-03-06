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
        int DotPosition = 0;
        int i;
        int j;
        int Position;
        int Equal;

        Number TwoAsNumber = Number();
        TwoAsNumber.StringToInt("2");

        Number iAsNumber = Number();

        Difference DifferenceResult = Difference();
        Product ProductResult = Product();

        Number Helper = Number();

        if(FirstNumber.NumberDigitsLength % 2 == 1)
        {
                FirstNumber.NumberDigitsLength++;
                FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength - 1] = 0;
        }

        Position = 2;

        Result.NumberDigitsLength++;
        Result.NumberDigits[0] = sqrt(FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength - 1] * 10 + FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength - 2]);

        ProductResult.FirstNumber = Result;
        ProductResult.SecondNumber = Result;
        ProductResult.Calculate();

        DifferenceResult.FirstNumber.NumberDigits[0] = FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength - 2];
        DifferenceResult.FirstNumber.NumberDigits[1] = FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength - 1];

        if(DifferenceResult.FirstNumber.NumberDigits[1] == 0)
        {
             DifferenceResult.FirstNumber.NumberDigitsLength = 1;
        }
        else
        {
             DifferenceResult.FirstNumber.NumberDigitsLength = 2;
        }


        DifferenceResult.SecondNumber = ProductResult.Result;
        DifferenceResult.SecondNumber.Overturn();
        DifferenceResult.Calculate();


        ProductResult.FirstNumber = Result;
        ProductResult.SecondNumber = TwoAsNumber;
        ProductResult.Calculate();

        Helper = ProductResult.Result;

        String NumberAsString = "";

        while((Position + 2) <= FirstNumber.NumberDigitsLength)
        {
                DifferenceResult.FirstNumber = DifferenceResult.Result;

                if((DifferenceResult.FirstNumber.NumberDigitsLength == 1) && (DifferenceResult.FirstNumber.NumberDigits[0] == 0))
                {
                        DifferenceResult.FirstNumber.NumberDigits[DifferenceResult.FirstNumber.NumberDigitsLength - 1] = FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength - Position - 1];
                        DifferenceResult.FirstNumber.NumberDigits[DifferenceResult.FirstNumber.NumberDigitsLength] = FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength - Position - 2];
                        DifferenceResult.FirstNumber.NumberDigitsLength += 1;
                }
                else
                {
                        DifferenceResult.FirstNumber.NumberDigits[DifferenceResult.FirstNumber.NumberDigitsLength] = FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength - Position - 1];
                        DifferenceResult.FirstNumber.NumberDigits[DifferenceResult.FirstNumber.NumberDigitsLength + 1] = FirstNumber.NumberDigits[FirstNumber.NumberDigitsLength - Position - 2];
                        DifferenceResult.FirstNumber.NumberDigitsLength += 2;
                }

                DifferenceResult.FirstNumber.Overturn();

                Position = Position + 2;

                i = 9;
                NumberAsString = "";
                NumberAsString += i;
                iAsNumber.StringToInt(NumberAsString);
               
                Helper.NumberDigits[Helper.NumberDigitsLength] = i;
                Helper.NumberDigitsLength++;
                Helper.Overturn();

                ProductResult.FirstNumber = Helper;
                ProductResult.FirstNumber.NumberDigitsLength = Helper.NumberDigitsLength;
                ProductResult.SecondNumber = iAsNumber;
                ProductResult.Calculate();
                ProductResult.Result.Overturn();

                Equal = Compare(DifferenceResult.FirstNumber, ProductResult.Result);

                while(Equal < 0)
                {
                        i--;
                        NumberAsString = "";
                        NumberAsString += i;
                        iAsNumber.StringToInt(NumberAsString);
                        Helper.Overturn();
                        Helper.NumberDigits[Helper.NumberDigitsLength - 1] = i;
                        Helper.Overturn();

                        ProductResult.FirstNumber = Helper;
                        ProductResult.SecondNumber = iAsNumber;
                        ProductResult.Calculate();
                        ProductResult.Result.Overturn();

                        if(i == 0)
                        {
                                ProductResult.Result.ChangeSizeForZero();
                                DifferenceResult.FirstNumber.ChangeSizeForZero();
                        }

                        Equal = Compare(DifferenceResult.FirstNumber, ProductResult.Result);
                }

                Result.NumberDigits[Result.NumberDigitsLength] = i;
                Result.NumberDigitsLength++;

                DifferenceResult.SecondNumber = ProductResult.Result;
                DifferenceResult.Calculate();

                ProductResult.FirstNumber = Result;
                ProductResult.FirstNumber.Overturn();
                ProductResult.FirstNumber.NumberDigitsLength = Result.NumberDigitsLength;
                ProductResult.SecondNumber = TwoAsNumber;
                ProductResult.Calculate();

                Helper = ProductResult.Result;
        }

        DifferenceResult.Result.ChangeSizeForZero();
        
        if((DifferenceResult.Result.NumberDigitsLength == 1) && (DifferenceResult.Result.NumberDigits[0] == 0))
        {
                return DotPosition;
        }
        else
        {
                DotPosition = Result.NumberDigitsLength;
        }

        Result.NumberSign = Result.NumberDigitsLength;

        for(j = 0; j < FirstNumber.NumberDigitsLength; j++)
        {
                DifferenceResult.FirstNumber = DifferenceResult.Result;  

                if((DifferenceResult.FirstNumber.NumberDigitsLength == 1) && (DifferenceResult.FirstNumber.NumberDigits[0] == 0))
                {
                        DifferenceResult.FirstNumber.NumberDigits[DifferenceResult.FirstNumber.NumberDigitsLength - 1] = 0;
                        DifferenceResult.FirstNumber.NumberDigits[DifferenceResult.FirstNumber.NumberDigitsLength] = 0;
                        DifferenceResult.FirstNumber.NumberDigitsLength += 1;
                }
                else
                {
                        DifferenceResult.FirstNumber.NumberDigits[DifferenceResult.FirstNumber.NumberDigitsLength] = 0;
                        DifferenceResult.FirstNumber.NumberDigits[DifferenceResult.FirstNumber.NumberDigitsLength + 1] = 0;
                        DifferenceResult.FirstNumber.NumberDigitsLength += 2;
                }
                DifferenceResult.FirstNumber.Overturn();

                Position = Position + 2;

                i = 9;
                NumberAsString = "";
                NumberAsString += i;
                iAsNumber.StringToInt(NumberAsString);
               
                Helper.NumberDigits[Helper.NumberDigitsLength] = i;
                Helper.NumberDigitsLength++;
                Helper.Overturn();

                ProductResult.FirstNumber = Helper;
                ProductResult.FirstNumber.NumberDigitsLength = Helper.NumberDigitsLength;
                ProductResult.SecondNumber = iAsNumber;
                ProductResult.Calculate();
                ProductResult.Result.Overturn();

                Equal = Compare(DifferenceResult.FirstNumber, ProductResult.Result);

                while(Equal < 0)
                {
                        i--;
                        NumberAsString = "";
                        NumberAsString += i;
                        iAsNumber.StringToInt(NumberAsString);
                        Helper.Overturn();
                        Helper.NumberDigits[Helper.NumberDigitsLength - 1] = i;
                        Helper.Overturn();

                        ProductResult.FirstNumber = Helper;
                        ProductResult.SecondNumber = iAsNumber;
                        ProductResult.Calculate();
                        ProductResult.Result.Overturn();

                        if(i == 0)
                        {
                                ProductResult.Result.ChangeSizeForZero();
                                DifferenceResult.FirstNumber.ChangeSizeForZero();
                        }

                        Equal = Compare(DifferenceResult.FirstNumber, ProductResult.Result);
                }

                Result.NumberDigits[Result.NumberDigitsLength] = i;
                Result.NumberDigitsLength++;

                DifferenceResult.SecondNumber = ProductResult.Result;
                DifferenceResult.Calculate();

                ProductResult.FirstNumber = Result;
                ProductResult.FirstNumber.Overturn();
                ProductResult.FirstNumber.NumberDigitsLength = Result.NumberDigitsLength;
                ProductResult.SecondNumber = TwoAsNumber;
                ProductResult.Calculate();

                Helper = ProductResult.Result;
        }

        return DotPosition;

}
