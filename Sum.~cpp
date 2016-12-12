//---------------------------------------------------------------------------


#pragma hdrstop

#include "Sum.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Sum::Sum()
{

}

void Sum::Calculate(int FirstNumber[], int SecondNumber[])
{
        int FirstNumberLength = sizeof(FirstNumber);
        int SecondNumberLength = sizeof(SecondNumber);
        int Carry = 0;
	int i = 0;
        int SumResult[100];
        int Aux;
	while(FirstNumberLength != 0 && SecondNumberLength != 0)
	{
		SumResult[i] = FirstNumber[i] + SecondNumber[i] + Carry;
		Carry = 0;
		if(SumResult[i] >= 10)
		{
			SumResult[i] = SumResult[i] % 10;
			Carry = 1;
		}
		i++;
		FirstNumberLength--;
		SecondNumberLength--;
	}
	
	while(FirstNumberLength != 0)
	{
		SumResult[i] =  FirstNumber[i] + Carry;
		Carry = 0;
		if(SumResult[i] >= 10)
		{
			SumResult[i] = SumResult[i] % 10;
			Carry = 1;
		}
		FirstNumberLength--;
		i++;
	}
	
	while(SecondNumberLength != 0)
	{
		SumResult[i] = SecondNumber[i] + Carry;
		Carry = 0;
		if(SumResult[i] >= 10)
		{
			SumResult[i] = SumResult[i] % 10;
			Carry = 1;
		}
		SecondNumberLength--;
		i++;
	}
	
	int SumLength = i;

        if(Carry != 0)
        {
                SumResult[SumLength + 1] = 1;
                SumLength++;
        }

        for(i = 0; i < SumLength/2; i++)
	{
		Aux = SumResult[i];
		SumResult[i] = SumResult[SumLength - i - 1];
		SumResult[SumLength - i - 1] = Aux;
	}

        Result = SumResult;
}

