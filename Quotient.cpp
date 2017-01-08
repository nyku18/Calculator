//---------------------------------------------------------------------------


#pragma hdrstop

#include "Quotient.h"
#include <math.h>

#include "Sum.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)

Quotient::Quotient()
{

}

void Quotient::Calculate()
{
        int Carry = 0;
	int i = 0;
        int j = 0;
        int QuotientLength = 1;
        int Aux;
        int Equal;
       /*
        Difference DifferenceR = Difference();

        memcpy(DifferenceR.FirstNumber, FirstNumber, sizeof(DifferenceR.FirstNumber));
        memcpy(DifferenceR.SecondNumber, SecondNumber, sizeof(DifferenceR.SecondNumber));

        Equal = Compare();
        Result.NumberDigits[i] = 0;

        while(Equal >= 0)
        {
                DifferenceR.Calculate();
                memcpy(DifferenceR.FirstNumber, DifferenceR.Result, sizeof(DifferenceR.FirstNumber));
                Equal = Compare();

                Result.NumberDigits[i]++;

        } */

        if(SecondNumber.NumberDigitsLength == 1 && SecondNumber.NumberDigits[0] == 1)
        {
                for(int i = 0; i <  FirstNumber.NumberDigitsLength; i++)
                {
                        Result.NumberDigits[i] = FirstNumber.NumberDigits[i];
                }
                Result.NumberDigitsLength = FirstNumber.NumberDigitsLength;
                for(i = 0; i < FirstNumber.NumberDigitsLength/2; i++)
                {
                        Aux = Result.NumberDigits[i];
                        Result.NumberDigits[i] = Result.NumberDigits[FirstNumber.NumberDigitsLength - i - 1];
                        Result.NumberDigits[FirstNumber.NumberDigitsLength - i - 1] = Aux;
                }
                return;
        }

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

        for(i = 0; i < 100; i++)
        {
                Result.NumberDigits[i] = 0;
        }

        while(Equal >= 0)
        {
                i = 0;
                while(FirstNumberLength != 0 && SecondNumberLength != 0)
	        {
                        FirstNumber.NumberDigits[i] = FirstNumber.NumberDigits[i] - SecondNumber.NumberDigits[i] - Carry;
		        Carry = 0;
		        if(FirstNumber.NumberDigits[i] < 0)
		        {
			        FirstNumber.NumberDigits[i] = 10 - abs(FirstNumber.NumberDigits[i]);
			        Carry = 1;
		        }
		        i++;
		        FirstNumberLength--;
		        SecondNumberLength--;
	        }

                while(FirstNumberLength != 0)
	        {
		        FirstNumber.NumberDigits[i] = FirstNumber.NumberDigits[i] - Carry;
		        Carry = 0;
		        if(FirstNumber.NumberDigits[i] < 0)
		        {
			        FirstNumber.NumberDigits[i] = 10 - abs(FirstNumber.NumberDigits[i]);
			        Carry = 1;
		        }
		        FirstNumberLength--;
		        i++;
	        }
                Result.NumberDigits[0] = Result.NumberDigits[0] + 1;
                for(i = 0; i < QuotientLength - 1; i++)
                {
		        if(Result.NumberDigits[i] >= 10)
		        {
			        Result.NumberDigits[i] = 0;
                                Result.NumberDigits[i + 1] = Result.NumberDigits[i+1] + 1;
		        }
                }

                while(Result.NumberDigits[QuotientLength - 1] >= 10)
                {
                        Result.NumberDigits[QuotientLength - 1] = 0;
                        Result.NumberDigits[QuotientLength] = Result.NumberDigits[QuotientLength] + 1;
                        QuotientLength++;
                }


                FirstNumberLength =  FirstNumber.NumberDigitsLength;
                SecondNumberLength = SecondNumber.NumberDigitsLength;

                if(FirstNumber.NumberDigits[FirstNumberLength - 1] == 0)
	        {
		        FirstNumberLength--;
                        FirstNumber.NumberDigitsLength--;
	        }

                Equal = Compare();

        }

        if(FirstNumber.NumberDigitsLength == 0)
        {
                FirstNumber.NumberDigitsLength++;
        }

        Equal = Compare();

        for(i = 0; i < QuotientLength/2; i++)
        {
                Aux = Result.NumberDigits[i];
                Result.NumberDigits[i] = Result.NumberDigits[QuotientLength - i - 1];
                Result.NumberDigits[QuotientLength - i - 1] = Aux;
        }

        if(Equal == -1 && FirstNumber.NumberDigitsLength == 1 && FirstNumber.NumberDigits[0] == 0)
        {


                while(Result.NumberDigits[0] == 0)
	        {
		        for (i = 0; i < QuotientLength - 1; i++)
		        {
			        Result.NumberDigits[i] = Result.NumberDigits[i+1];
		        }
		        QuotientLength--;
	        }
                Result.NumberDigitsLength = QuotientLength;
                return;
        }

        //Result.NumberDigitsLength = QuotientLength;

        //dupa virgula
        Result.NumberSign = QuotientLength;
        QuotientLength++;

        for(j = 0; j < SecondNumber.NumberDigitsLength; j++)
        {
                while(Equal == -1)
                {
                        FirstNumberLength++;
                        FirstNumber.NumberDigitsLength++;
                        for(i = FirstNumberLength; i > 0; i--)
                        {
                                FirstNumber.NumberDigits[i] = FirstNumber.NumberDigits[i-1];
                        }
                        FirstNumber.NumberDigits[0] = 0;

                        Equal = Compare();

                }

                while(Equal >= 0)
                {
                        i = 0;
                        while(FirstNumberLength != 0 && SecondNumberLength != 0)
	                {
                                FirstNumber.NumberDigits[i] = FirstNumber.NumberDigits[i] - SecondNumber.NumberDigits[i] - Carry;
		                Carry = 0;
		                if(FirstNumber.NumberDigits[i] < 0)
		                {
			                FirstNumber.NumberDigits[i] = 10 - abs(FirstNumber.NumberDigits[i]);
			                Carry = 1;
		                }
		                i++;
		                FirstNumberLength--;
		                SecondNumberLength--;
	                }

                        while(FirstNumberLength != 0)
	                {
		                FirstNumber.NumberDigits[i] = FirstNumber.NumberDigits[i] - Carry;
		                Carry = 0;
		                if(FirstNumber.NumberDigits[i] < 0)
		                {
			                FirstNumber.NumberDigits[i] = 10 - abs(FirstNumber.NumberDigits[i]);
			                Carry = 1;
		                }
		                FirstNumberLength--;
		                i++;
	                }

                        Result.NumberDigits[Result.NumberSign] = Result.NumberDigits[Result.NumberSign] + 1;
                        for(i = Result.NumberSign; i < QuotientLength - 1; i++)
                        {
		                if(Result.NumberDigits[i] >= 10)
		                {
			                Result.NumberDigits[i] = 0;
                                        Result.NumberDigits[i + 1] = Result.NumberDigits[i+1] + 1;
		                }
                        }

                        while(Result.NumberDigits[QuotientLength - 1] >= 10)
                        {
                                Result.NumberDigits[QuotientLength - 1] = 0;
                                Result.NumberDigits[QuotientLength] = Result.NumberDigits[QuotientLength] + 1;
                                QuotientLength++;
                        }

                        FirstNumberLength =  FirstNumber.NumberDigitsLength;
                        SecondNumberLength = SecondNumber.NumberDigitsLength;

                        if(FirstNumber.NumberDigits[FirstNumberLength - 1] == 0)
	                {
		                FirstNumberLength--;
                                FirstNumber.NumberDigitsLength--;
	                }

                        Equal = Compare();

                }

                int Contor = 0;
                for(i = 0; i < FirstNumber.NumberDigitsLength; i++)
                {
                        if(FirstNumber.NumberDigits[i] == 0)
                        {
                                Contor++;
                        }
                }

                if(Contor == FirstNumber.NumberDigitsLength)
                {
                        Result.NumberDigitsLength = QuotientLength;
                        j = SecondNumber.NumberDigitsLength;
                        return;
                }
                Result.NumberSign++;
                QuotientLength++;
        }

        while(Result.NumberDigits[0] == 0)
	{
		for (i = 0; i < QuotientLength - 1; i++)
		{
			Result.NumberDigits[i] = Result.NumberDigits[i+1];
		}
		QuotientLength--;
	}

        Result.NumberDigitsLength = QuotientLength;

}
