//---------------------------------------------------------------------------


#pragma hdrstop

#include "Product.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Product::Product()
{

}

void Product::Calculate(int FirstNumber[], int SecondNumber[])
{
        int FirstNumberLength = sizeof(FirstNumber);
        int SecondNumberLength = sizeof(SecondNumber);
        int Carry = 0;
	int i = 0;
        int j = 0;
        int ProductResult[200];
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
		ProductResult[i] = 0;
		for(j = 0; j < SecondNumberLength ; j++)
		{
			ProductResult[i] = ProductResult[i] + ProductMatrix[j][i] + Carry;
			Carry = 0;
			if(ProductResult[i] >= 10)
			{
				Carry = 1;
				ProductResult[i] = ProductResult[i] % 10;
			}
		}
	}

        int ProductLength = i;

	if(Carry != 0)
	{
		ProductResult[ProductLength+1] = Carry;
		ProductLength++;
	}

	if(ProductResult[ProductLength] == 0)
	{
		ProductLength--;
	}

	for(i = 0; i < ProductLength/2; i++)
	{
		Aux = ProductResult[i];
		ProductResult[i] = ProductResult[ProductLength - i - 1];
		ProductResult[ProductLength - i - 1] = Aux;
	}

        //Result = ProductResult;
}
