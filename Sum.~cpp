//---------------------------------------------------------------------------


#pragma hdrstop

#include "Sum.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Sum::Sum()
{

}

int Sum::Calculate()
{
        int Carry = 0;
	int i = 0;
        int Aux;
        int FirstNumberLength =  FirstNumber.NumberDigitsLength;
        int SecondNumberLength = SecondNumber.NumberDigitsLength;
	while(FirstNumberLength != 0 && SecondNumberLength != 0)
	{
                Result.NumberDigits[i] = FirstNumber.NumberDigits[i] + SecondNumber.NumberDigits[i] + Carry;
		Carry = 0;
		if(Result.NumberDigits[i] >= 10)
		{
			Result.NumberDigits[i] = Result.NumberDigits[i] % 10;
			Carry = 1;
		}
		i++;
		FirstNumberLength--;
		SecondNumberLength--;
	}
	
	while(FirstNumberLength != 0)
	{
		Result.NumberDigits[i] =  FirstNumber.NumberDigits[i] + Carry;
		Carry = 0;
		if(Result.NumberDigits[i] >= 10)
		{
			Result.NumberDigits[i] = Result.NumberDigits[i] % 10;
			Carry = 1;
		}
		FirstNumberLength--;
		i++;
	}
	
	while(SecondNumberLength != 0)
	{
		Result.NumberDigits[i] = SecondNumber.NumberDigits[i] + Carry;
		Carry = 0;
		if(Result.NumberDigits[i] >= 10)
		{
			Result.NumberDigits[i] = Result.NumberDigits[i] % 10;
			Carry = 1;
		}
		SecondNumberLength--;
		i++;
	}
	
	int SumLength = i;

        if(Carry != 0)
        {
                Result.NumberDigits[SumLength] = 1;
                SumLength++;
        }

        for(i = 0; i < SumLength/2; i++)
	{
		Aux = Result.NumberDigits[i];
		Result.NumberDigits[i] = Result.NumberDigits[SumLength - i - 1];
		Result.NumberDigits[SumLength - i - 1] = Aux;
	}

        return SumLength;

}

