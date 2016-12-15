//---------------------------------------------------------------------------


#pragma hdrstop

#include "Difference.h"
#include <math.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)

Difference::Difference()
{

}

void Difference::Calculate()
{
        int Carry = 0;
	int i = 0;
        int Aux;
        int Equal;

        Equal = Compare();

        if(Equal == 0)
        {
                for(int i = 0; i <  FirstNumber.NumberDigitsLength; i++)
                {
                        Result.NumberDigits[i] = 0;
                }
                Result.NumberDigitsLength = 1;
                return;
        }
        else
        {
                if(Equal == -1)
                {
                        Result.NumberSign = 0;
                        Swap();
                }
        }

        int FirstNumberLength =  FirstNumber.NumberDigitsLength;
        int SecondNumberLength = SecondNumber.NumberDigitsLength;

	while(FirstNumberLength != 0 && SecondNumberLength != 0)
	{
                Result.NumberDigits[i] = FirstNumber.NumberDigits[i] - SecondNumber.NumberDigits[i] - Carry;
		Carry = 0;
		if(Result.NumberDigits[i] < 0)
		{
			Result.NumberDigits[i] = 10 - abs(Result.NumberDigits[i]);
			Carry = 1;
		}
		i++;
		FirstNumberLength--;
		SecondNumberLength--;
	}
	
	while(FirstNumberLength != 0)
	{
		Result.NumberDigits[i] = FirstNumber.NumberDigits[i] - Carry;
		Carry = 0;
		if(Result.NumberDigits[i] < 0)
		{
			Result.NumberDigits[i] = 10 - abs(Result.NumberDigits[i]);
			Carry = 1;
		}
		FirstNumberLength--;
		i++;
	}
	
	while(SecondNumberLength != 0)
	{
		Result.NumberDigits[i] = SecondNumber.NumberDigits[i] - Carry;
		Carry = 0;
		if(Result.NumberDigits[i] < 0)
		{
			Result.NumberDigits[i] = 10 - abs(Result.NumberDigits[i]);
			Carry = 1;
		}
		SecondNumberLength--;
		i++;
	}

	int DifferenceLength = i;
	
	for(i = 0; i < DifferenceLength/2; i++)
	{
		Aux = Result.NumberDigits[i];
		Result.NumberDigits[i] = Result.NumberDigits[DifferenceLength - i - 1];
		Result.NumberDigits[DifferenceLength - i - 1] = Aux;
	}

	while(Result.NumberDigits[0] == 0)
	{
		for (i = 0; i < DifferenceLength - 1; i++)
		{
			Result.NumberDigits[i] = Result.NumberDigits[i+1];
		}
		DifferenceLength--;
	}

        Result.NumberDigitsLength = DifferenceLength;

}

