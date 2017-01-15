//---------------------------------------------------------------------------


#pragma hdrstop

#include "Operation.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Operation::Operation()
{

}

int Operation::Compare()
{
        int Equal = 1;
        if(FirstNumber.NumberDigitsLength < SecondNumber.NumberDigitsLength)
        {
                Equal = -1;
        }
        else
        {
                if(FirstNumber.NumberDigitsLength == SecondNumber.NumberDigitsLength)
                {
                        Equal = 0;
                        int i =  FirstNumber.NumberDigitsLength - 1;
                        while(Equal == 0 && i != -1)
                        {
                                if(FirstNumber.NumberDigits[i] > SecondNumber.NumberDigits[i])
                                {
                                        Equal = 1;
                                }
                                else
                                {
                                        if(FirstNumber.NumberDigits[i] < SecondNumber.NumberDigits[i])
                                        {
                                                Equal = -1;
                                        }
                                }
                                i--;
                        }
                }
                else
                {
                        if(FirstNumber.NumberDigitsLength > SecondNumber.NumberDigitsLength)
                        {
                                Equal = 1;
                        }
                }
        }

        return Equal;

}

int Operation::Compare(Number FirstNumber, Number SecondNumber)
{
        int Equal = 1;
        if(FirstNumber.NumberDigitsLength < SecondNumber.NumberDigitsLength)
        {
                Equal = -1;
        }
        else
        {
                if(FirstNumber.NumberDigitsLength == SecondNumber.NumberDigitsLength)
                {
                        Equal = 0;
                        int i =  FirstNumber.NumberDigitsLength - 1;
                        while(Equal == 0 && i != -1)
                        {
                                if(FirstNumber.NumberDigits[i] > SecondNumber.NumberDigits[i])
                                {
                                        Equal = 1;
                                }
                                else
                                {
                                        if(FirstNumber.NumberDigits[i] < SecondNumber.NumberDigits[i])
                                        {
                                                Equal = -1;
                                        }
                                }
                                i--;
                        }
                }
                else
                {
                        if(FirstNumber.NumberDigitsLength > SecondNumber.NumberDigitsLength)
                        {
                                Equal = 1;
                        }
                }
        }

        return Equal;

}

void Operation::Swap()
{
	 int i;
         int AAux[100];

	 for (i = 0; i < FirstNumber.NumberDigitsLength; i++)
         {
                AAux[i] = FirstNumber.NumberDigits[i];
         }
         for (i = 0; i < SecondNumber.NumberDigitsLength; i++)
         {
                FirstNumber.NumberDigits[i] = SecondNumber.NumberDigits[i];
         }
         for (i = 0; i < FirstNumber.NumberDigitsLength; i++)
         {
                SecondNumber.NumberDigits[i] = AAux[i];
         }

         int Aux;

         Aux = FirstNumber.NumberDigitsLength;
         FirstNumber.NumberDigitsLength = SecondNumber.NumberDigitsLength;
         SecondNumber.NumberDigitsLength = Aux;

}
