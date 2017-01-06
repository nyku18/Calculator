//---------------------------------------------------------------------------


#pragma hdrstop

#include "Quotient.h"
#include <math.h>

//---------------------------------------------------------------------------

#pragma package(smart_init)

Quotient::Quotient()
{

}

void Quotient::Calculate()
{
        int Carry1 = 0;
        int Carry2 = 0;
	int i = 0;
        int j = 0;
        int QuotientLength = 0;
        int Aux;
        int Equal;

        Equal = Compare();

        if(Equal == 0)
        {
                for(int i = 0; i <  FirstNumber.NumberDigitsLength; i++)
                {
                        Result.NumberDigits[i] = 1;
                }
                Result.NumberDigitsLength = 1;
                return;
        }

        int FirstNumberLength =  FirstNumber.NumberDigitsLength;
        int SecondNumberLength = SecondNumber.NumberDigitsLength;

        Result.NumberDigits[i] = 0;

        Equal = Compare();

        while(Equal >= 0)
        {
                while(FirstNumberLength != 0 && SecondNumberLength != 0)
	        {
                        FirstNumber.NumberDigits[i] = FirstNumber.NumberDigits[i] - SecondNumber.NumberDigits[i] - Carry1;
		        Carry1 = 0;
		        if(FirstNumber.NumberDigits[i] < 0)
		        {
			        FirstNumber.NumberDigits[i] = 10 - abs(FirstNumber.NumberDigits[i]);
			        Carry1 = 1;
		        }
		        i++;
		        FirstNumberLength--;
		        SecondNumberLength--;
	        }

                while(FirstNumberLength != 0)
	        {
		        FirstNumber.NumberDigits[i] = FirstNumber.NumberDigits[i] - Carry1;
		        Carry1 = 0;
		        if(FirstNumber.NumberDigits[i] < 0)
		        {
			        FirstNumber.NumberDigits[i] = 10 - abs(FirstNumber.NumberDigits[i]);
			        Carry1 = 1;
		        }
		        FirstNumberLength--;
		        i++;
	        }

                Result.NumberDigits[QuotientLength] = Result.NumberDigits[QuotientLength] + 1 + Carry2;
                Carry2 = 0;
		if(Result.NumberDigits[QuotientLength] >= 10)
		{
			Result.NumberDigits[QuotientLength] = Result.NumberDigits[QuotientLength] % 10;
			Carry2 = 1;
                        QuotientLength++;
		}

                FirstNumberLength =  FirstNumber.NumberDigitsLength;
                SecondNumberLength = SecondNumber.NumberDigitsLength;

                while(FirstNumber.NumberDigits[0] == 0)
	        {
		        for (i = 0; i < FirstNumberLength - 1; i++)
		        {
			        FirstNumber.NumberDigits[i] = FirstNumber.NumberDigits[i+1];
		        }
		        FirstNumberLength--;
                        FirstNumber.NumberDigitsLength--;
	        }

                i = 0;

                Equal = Compare();
        }

        QuotientLength++;
        Result.NumberDigits[QuotientLength - 1] = 0;
        Result.NumberSign = QuotientLength;
        QuotientLength++;

        for(j = 0; j < SecondNumber.NumberDigitsLength; j++)
        {
                while(Equal == -1)
                {
                        FirstNumberLength++;
                        for(i = FirstNumberLength - 1; i >= 1; i--)
                        {
                                FirstNumber.NumberDigits[i] = FirstNumber.NumberDigits[i-1];
                        }
                        FirstNumber.NumberDigits[0] = 0;

                        Equal = Compare();
                }

                while(Equal >= 0)
                {
                        while(FirstNumberLength != 0 && SecondNumberLength != 0)
	                {
                                FirstNumber.NumberDigits[i] = FirstNumber.NumberDigits[i] - SecondNumber.NumberDigits[i] - Carry1;
		                Carry1 = 0;
		                if(FirstNumber.NumberDigits[i] < 0)
		                {
			                FirstNumber.NumberDigits[i] = 10 - abs(FirstNumber.NumberDigits[i]);
			                Carry1 = 1;
		                }
		                i++;
		                FirstNumberLength--;
		                SecondNumberLength--;
	                }

                        while(FirstNumberLength != 0)
	                {
		                FirstNumber.NumberDigits[i] = FirstNumber.NumberDigits[i] - Carry1;
		                Carry1 = 0;
		                if(FirstNumber.NumberDigits[i] < 0)
		                {
                                        FirstNumber.NumberDigits[i] = 10 - abs(FirstNumber.NumberDigits[i]);
			                Carry1 = 1;
		                }
		                FirstNumberLength--;
		                i++;
	                }

                        Result.NumberDigits[QuotientLength] = Result.NumberDigits[QuotientLength] + 1 + Carry2;
                        Carry2 = 0;
		        if(Result.NumberDigits[QuotientLength] >= 10)
		        {
			        Result.NumberDigits[QuotientLength] = Result.NumberDigits[QuotientLength] % 10;
			        Carry2 = 1;
                                QuotientLength++;
		        }

                        FirstNumberLength =  FirstNumber.NumberDigitsLength;
                        SecondNumberLength = SecondNumber.NumberDigitsLength;

                        while(FirstNumber.NumberDigits[0] == 0)
	                {
		                for (i = 0; i < FirstNumberLength - 1; i++)
		                {
			                FirstNumber.NumberDigits[i] = FirstNumber.NumberDigits[i+1];
		                }
		                FirstNumberLength--;
                                FirstNumber.NumberDigitsLength--;
	                }

                        i = 0;

                        Equal = Compare();
                }
        }

        Result.NumberDigitsLength = QuotientLength;

}