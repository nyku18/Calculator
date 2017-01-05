//---------------------------------------------------------------------------


#pragma hdrstop

#include "Difference.h"
#include <math.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)

Difference::Difference()
{

}

int Difference::Calculate(int FirstNumberLength, int SecondNumberLength)
{
        int Carry = 0;
	int i = 0;
        int Aux;
	while(FirstNumberLength != 0 && SecondNumberLength != 0)
	{
                Result.NumberDigits[i] = FirstNumber.NumberDigits[i] - SecondNumber.NumberDigits[i] - Carry;
		Carry = 0;
		if(Result.NumberDigits[i] < 0)
		{
			Result.NumberDigits[i] = 10 - abs(Result.NumberDigits[i] % 10);
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
			Result.NumberDigits[i] = 10 - abs(Result.NumberDigits[i] % 10);
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
			Result.NumberDigits[i] = 10 - abs(Result.NumberDigits[i] % 10);
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

	if(FirstNumberLength <= SecondNumberLength && FirstNumber.NumberDigits[0] < SecondNumber.NumberDigits[0])
	{
                Result.NumberDigits[0] = Result.NumberDigits[0] - 2 * Result.NumberDigits[0];
		Carry = 0;
		for (i = DifferenceLength - 1; i >= 0; i--)
		{
			Result.NumberDigits[i] = 10 - abs(Result.NumberDigits[i] % 10) - Carry;
			Carry = 1;
		}
	}
	else
	{
		if(Carry != 0 && FirstNumber.NumberDigits[0] <= SecondNumber.NumberDigits[0])
		{
			Result.NumberDigits[0] = Result.NumberDigits[0] - 2 * Result.NumberDigits[0];
			Carry = 0;
			for (i = DifferenceLength - 1; i >= 0; i--)
			{
				Result.NumberDigits[i] = 10 - abs(Result.NumberDigits[i] % 10) - Carry;
				Carry = 1;
			}
		}
	}

	while(Result.NumberDigits[0] == 0)
	{
		for (i = 0; i < DifferenceLength - 1; i++)
		{
			Result.NumberDigits[i] = Result.NumberDigits[i+1];
		}
		DifferenceLength--;
	}
        return DifferenceLength;

}

