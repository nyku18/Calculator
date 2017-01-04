//---------------------------------------------------------------------------


#pragma hdrstop

#include "Sum.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Sum::Sum()
{

}

int Sum::Calculate(int FirstNumberLength, int SecondNumberLength)
{
        int Carry = 0;
	int i = 0;
        int Aux;
	while(FirstNumberLength != 0 && SecondNumberLength != 0)
	{
		Result[i] = FirstNumber[i] + SecondNumber[i] + Carry;
                int cc = Result[i];
		Carry = 0;
		if(Result[i] >= 10)
		{
			Result[i] = Result[i] % 10;
			Carry = 1;
		}
		i++;
		FirstNumberLength--;
		SecondNumberLength--;
	}
	
	while(FirstNumberLength != 0)
	{
		Result[i] =  FirstNumber[i] + Carry;
		Carry = 0;
		if(Result[i] >= 10)
		{
			Result[i] = Result[i] % 10;
			Carry = 1;
		}
		FirstNumberLength--;
		i++;
	}
	
	while(SecondNumberLength != 0)
	{
		Result[i] = SecondNumber[i] + Carry;
		Carry = 0;
		if(Result[i] >= 10)
		{
			Result[i] = Result[i] % 10;
			Carry = 1;
		}
		SecondNumberLength--;
		i++;
	}
	
	int SumLength = i;

        if(Carry != 0)
        {
                Result[SumLength] = 1;
                SumLength++;
        }

        for(i = 0; i < SumLength/2; i++)
	{
		Aux = Result[i];
		Result[i] = Result[SumLength - i - 1];
		Result[SumLength - i - 1] = Aux;
	}

        return SumLength;

}

