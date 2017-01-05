//---------------------------------------------------------------------------


#pragma hdrstop

#include "Product.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Product::Product()
{

}

int Product::Calculate(int FirstNumberLength, int SecondNumberLength)
{
        int Carry = 0;
	int i = 0;
        int j = 0;
        int ProductMatrix[100][100];
        int Aux;
        for(i = 0; i < SecondNumberLength ; i++)
	{
		for(j = 0; j < FirstNumberLength ; j++)
		{
                        ProductMatrix[i][i+j] = FirstNumber[j] * SecondNumber[i] + Carry;
			Carry = 0;
			if(ProductMatrix[i][i+j] >= 10)
			{
				Carry = ProductMatrix[i][i+j] / 10;
				ProductMatrix[i][i+j] = ProductMatrix[i][i+j] % 10;
			}
		}
		if(Carry != 0)
		{
			ProductMatrix[i][j+1] = Carry;
		}
	}
	
	for(i = 0; i < SecondNumberLength; i++)
	{
		for(j = 0; j < FirstNumberLength + SecondNumberLength ; j++)
		{
			if(!(ProductMatrix[i][j] != 0))
			{
				ProductMatrix[i][j] = 0;
			}
		}
	}

	Carry = 0;
	for(i = 0; i <  FirstNumberLength + SecondNumberLength; i++)
	{
		Result[i] = 0;
		for(j = 0; j < SecondNumberLength ; j++)
		{
			Result[i] = Result[i] + ProductMatrix[j][i] + Carry;
			Carry = 0;
			if(Result[i] >= 10)
			{
				Carry = 1;
				Result[i] = Result[i] % 10;
			}
		}
	}

        int ProductLength = i;

	if(Carry != 0)
	{
		Result[ProductLength+1] = Carry;
		ProductLength++;
	}

	if(Result[ProductLength] == 0)
	{
		ProductLength--;
	}

	for(i = 0; i < ProductLength/2; i++)
	{
		Aux = Result[i];
		Result[i] = Result[ProductLength - i - 1];
		Result[ProductLength - i - 1] = Aux;
	}

        return ProductLength;
}
