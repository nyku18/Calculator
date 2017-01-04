//---------------------------------------------------------------------------


#pragma hdrstop

#include "Difference.h"
#include <math.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)

Difference::Difference()
{

}

void Difference::Calculate(int FirstNumber[], int SecondNumber[])
{
        int FirstNumberLength = sizeof(FirstNumber);
        int SecondNumberLength = sizeof(SecondNumber);
        int Carry = 0;
	int i = 0;
        int DifferenceResult[100];
        int Aux;
	while(FirstNumberLength != 0 && SecondNumberLength != 0)
	{
                DifferenceResult[i] = FirstNumber[i] - SecondNumber[i] - Carry;
		Carry = 0;
		if(DifferenceResult[i] < 0)
		{
			DifferenceResult[i] = 10 - abs(DifferenceResult[i] % 10);
			Carry = 1;
		}
		i++;
		FirstNumberLength--;
		SecondNumberLength--;
	}
	
	while(FirstNumberLength != 0)
	{
		DifferenceResult[i] = FirstNumber[i] - Carry;
		Carry = 0;
		if(DifferenceResult[i] < 0)
		{
			DifferenceResult[i] = 10 - abs(DifferenceResult[i] % 10);
			Carry = 1;
		}
		FirstNumberLength--;
		i++;
	}
	
	while(SecondNumberLength != 0)
	{
		DifferenceResult[i] = SecondNumber[i] - Carry;
		Carry = 0;
		if(DifferenceResult[i] < 0)
		{
			DifferenceResult[i] = 10 - abs(DifferenceResult[i] % 10);
			Carry = 1;
		}
		SecondNumberLength--;
		i++;
	}

	int DifferenceLength = i;
	
	for(i = 0; i < DifferenceLength/2; i++)
	{
		Aux = DifferenceResult[i];
		DifferenceResult[i] = DifferenceResult[DifferenceLength - i - 1];
		DifferenceResult[DifferenceLength - i - 1] = Aux;
	}

	if(FirstNumberLength <= SecondNumberLength && FirstNumber[0] < SecondNumber[0])
	{
                DifferenceResult[0] = DifferenceResult[0] - 2 * DifferenceResult[0];
		Carry = 0;
		for (i = DifferenceLength - 1; i >= 0; i--)
		{
			DifferenceResult[i] = 10 - abs(DifferenceResult[i] % 10) - Carry;
			Carry = 1;
		}
	}
	else
	{
		if(Carry != 0 && FirstNumber[0] <= SecondNumber[0])
		{
			DifferenceResult[0] = DifferenceResult[0] - 2 * DifferenceResult[0];
			Carry = 0;
			for (i = DifferenceLength - 1; i >= 0; i--)
			{
				DifferenceResult[i] = 10 - abs(DifferenceResult[i] % 10) - Carry;
				Carry = 1;
			}
		}
	}

	while(DifferenceResult[0] == 0)
	{
		for (i = 0; i < DifferenceLength - 1; i++)
		{
			DifferenceResult[i] = DifferenceResult[i+1];
		}
		DifferenceLength--;
	}

	//Result = DifferenceResult;
}

