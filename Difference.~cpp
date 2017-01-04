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
        int DiferenceResult[100];
        int Aux;
	while(FirstNumberLength != 0 && SecondNumberLength != 0)
	{
                DiferenceResult[i] = FirstNumber[i] - SecondNumber[i] - Carry;
		Carry = 0;
		if(DiferenceResult[i] < 0)
		{
			DiferenceResult[i] = 10 - abs(DiferenceResult[i] % 10);
			Carry = 1;
		}
		i++;
		FirstNumberLength--;
		SecondNumberLength--;
	}
	
	while(FirstNumberLength != 0)
	{
		DiferenceResult[i] = FirstNumber[i] - Carry;
		Carry = 0;
		if(DiferenceResult[i] < 0)
		{
			DiferenceResult[i] = 10 - abs(DiferenceResult[i] % 10);
			Carry = 1;
		}
		FirstNumberLength--;
		i++;
	}
	
	while(SecondNumberLength != 0)
	{
		DiferenceResult[i] = SecondNumber[i] - Carry;
		Carry = 0;
		if(DiferenceResult[i] < 0)
		{
			DiferenceResult[i] = 10 - abs(DiferenceResult[i] % 10);
			Carry = 1;
		}
		SecondNumberLength--;
		i++;
	}

	int DiferenceLength = i;
	
	for(i = 0; i < DiferenceLength/2; i++)
	{
		Aux = DiferenceResult[i];
		DiferenceResult[i] = DiferenceResult[DiferenceLength - i - 1];
		DiferenceResult[DiferenceLength - i - 1] = Aux;
	}

	if(FirstNumberLength <= SecondNumberLength && FirstNumber[0] < SecondNumber[0])
	{
                DiferenceResult[0] = DiferenceResult[0] - 2 * DiferenceResult[0];
		Carry = 0;
		for (i = DiferenceLength - 1; i >= 0; i--)
		{
			DiferenceResult[i] = 10 - abs(DiferenceResult[i] % 10) - Carry;
			Carry = 1;
		}
	}
	else
	{
		if(Carry != 0 && FirstNumber[0] <= SecondNumber[0])
		{
			DiferenceResult[0] = DiferenceResult[0] - 2 * DiferenceResult[0];
			Carry = 0;
			for (i = DiferenceLength - 1; i >= 0; i--)
			{
				DiferenceResult[i] = 10 - abs(DiferenceResult[i] % 10) - Carry;
				Carry = 1;
			}
		}
	}

	while(DiferenceResult[0] == 0)
	{
		for (i = 0; i < DiferenceLength - 1; i++)
		{
			DiferenceResult[i] = DiferenceResult[i+1];
		}
		DiferenceLength--;
	}

	//Result = DiferenceResult;
}

