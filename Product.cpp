//---------------------------------------------------------------------------


#pragma hdrstop

#include "Product.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Product::Product()
{

}

void Product::Calculate()
{
        int Carry = 0;
	int i = 0;
        int j = 0;
        int ProductMatrix[200][200];
        int Aux;
        int Equal;
        int OverFlow;
        int CarryOver;

        Equal = Compare();

        if(Equal == -1)
        {
                Swap();
        }

        int FirstNumberLength =  FirstNumber.NumberDigitsLength;
        int SecondNumberLength = SecondNumber.NumberDigitsLength;

        for(i = 0; i < 200 ; i++)
	{
		for(j = 0; j < 200 ; j++)
		{
                        ProductMatrix[i][j] = 0;
                }
        }

        for(i = 0; i < SecondNumberLength ; i++)
	{
		for(j = 0; j < FirstNumberLength ; j++)
		{
                        ProductMatrix[i][i+j] = FirstNumber.NumberDigits[j] * SecondNumber.NumberDigits[i] + Carry;
			Carry = 0;
			if(ProductMatrix[i][i+j] >= 10)
			{
				Carry = ProductMatrix[i][i+j] / 10;
				ProductMatrix[i][i+j] = ProductMatrix[i][i+j] % 10;
			}
		}
		if(Carry != 0)
		{
			ProductMatrix[i][i+j] = Carry;
                        Carry = 0;
		}
	}

	Carry = 0;
        OverFlow = 0;
        CarryOver = 0;
	for(i = 0; i <  FirstNumberLength + SecondNumberLength; i++)
	{
                OverFlow = 0;
                Result.NumberDigits[i] = 0;    
		for(j = 0; j < SecondNumberLength ; j++)
		{
			Result.NumberDigits[i] = Result.NumberDigits[i] + ProductMatrix[j][i] + Carry + CarryOver;
                        if(CarryOver == 1)
                        {
                                CarryOver = 0;
                        }
			Carry = 0;
			if(Result.NumberDigits[i] >= 10)
			{
				Carry = 1;
				Result.NumberDigits[i] = Result.NumberDigits[i] % 10;
                                OverFlow = 1;
                                
			}
                        if(OverFlow == 1)
                        {
                                Carry = 0;
                                if(j == SecondNumberLength - 1)
                                {
                                        CarryOver = 1;
                                        break;
                                }
                        }
		}
	}

        int ProductLength = i;

	if(Carry != 0)
	{
		Result.NumberDigits[ProductLength+1] = Carry;
		ProductLength++;
	}

	if(Result.NumberDigits[ProductLength - 1] == 0)
	{
		ProductLength--;
	}

	for(i = 0; i < ProductLength/2; i++)
	{
		Aux = Result.NumberDigits[i];
		Result.NumberDigits[i] = Result.NumberDigits[ProductLength - i - 1];
		Result.NumberDigits[ProductLength - i - 1] = Aux;
	}

        Result.NumberDigitsLength = ProductLength;
        Result.ChangeSizeForZero();

}
