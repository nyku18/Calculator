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
                Result[i] = FirstNumber[i] - SecondNumber[i] - Carry;
		Carry = 0;
		if(Result[i] < 0)
		{
			Result[i] = 10 - abs(Result[i] % 10);
			Carry = 1;
		}
		i++;
		FirstNumberLength--;
		SecondNumberLength--;
	}
	
	while(FirstNumberLength != 0)
	{
		Result[i] = FirstNumber[i] - Carry;
		Carry = 0;
		if(Result[i] < 0)
		{
			Result[i] = 10 - abs(Result[i] % 10);
			Carry = 1;
		}
		FirstNumberLength--;
		i++;
	}
	
	while(SecondNumberLength != 0)
	{
		Result[i] = SecondNumber[i] - Carry;
		Carry = 0;
		if(Result[i] < 0)
		{
			Result[i] = 10 - abs(Result[i] % 10);
			Carry = 1;
		}
		SecondNumberLength--;
		i++;
	}

	int DifferenceLength = i;
	
	for(i = 0; i < DifferenceLength/2; i++)
	{
		Aux = Result[i];
		Result[i] = Result[DifferenceLength - i - 1];
		Result[DifferenceLength - i - 1] = Aux;
	}

	if(FirstNumberLength <= SecondNumberLength && FirstNumber[0] < SecondNumber[0])
	{
                Result[0] = Result[0] - 2 * Result[0];
		Carry = 0;
		for (i = DifferenceLength - 1; i >= 0; i--)
		{
			Result[i] = 10 - abs(Result[i] % 10) - Carry;
			Carry = 1;
		}
	}
	else
	{
		if(Carry != 0 && FirstNumber[0] <= SecondNumber[0])
		{
			Result[0] = Result[0] - 2 * Result[0];
			Carry = 0;
			for (i = DifferenceLength - 1; i >= 0; i--)
			{
				Result[i] = 10 - abs(Result[i] % 10) - Carry;
				Carry = 1;
			}
		}
	}

	while(Result[0] == 0)
	{
		for (i = 0; i < DifferenceLength - 1; i++)
		{
			Result[i] = Result[i+1];
		}
		DifferenceLength--;
	}
        return DifferenceLength;

}

