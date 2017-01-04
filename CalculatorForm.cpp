//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CalculatorForm.h"
#include <Sum.h>
#include <string.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfCalculator *fCalculator;
//---------------------------------------------------------------------------
__fastcall TfCalculator::TfCalculator(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfCalculator::btnAddClick(TObject *Sender)
{
        String SFirstNumber = eFirstNumber->Text;
        String SSecondNumber = eSecondNumber->Text;
        int FirstNumber[100];
        int SecondNumber[100];

        for(int i = 0; i < 100; i++)
        {
                FirstNumber[i] = 0;
        }
        for(int i = 0; i < 100; i++)
        {
                SecondNumber[i] = 0;
        }

        
        int FirstNumberLength = strlen(SFirstNumber.c_str());
        int SecondNumberLength = strlen(SSecondNumber.c_str());

        char CFirstNumber[100] = "";
        strcpy(CFirstNumber, SFirstNumber.c_str());
        char CSecondNumber[100] = "";
        strcpy(CSecondNumber, SSecondNumber.c_str());
        int i;


        for(i = 0; i < FirstNumberLength; i++)
        {
                FirstNumber[i] = CFirstNumber[i] - '0';
        }
        for(i = 0; i < SecondNumberLength; i++)
        {
                SecondNumber[i] = CSecondNumber[i] - '0';
        }

        Sum SumResult;
        memcpy(SumResult.FirstNumber, FirstNumber, sizeof(SumResult.FirstNumber));
        memcpy(SumResult.SecondNumber, SecondNumber, sizeof(SumResult.SecondNumber));

        //SumResult.FirstNumber = FirstNumber;
        //SumResult.SecondNumber = SecondNumber;
        SumResult.Calculate(FirstNumberLength, SecondNumberLength);
        String text = " ";
        for(i = 0; i < sizeof(SumResult.Result) - 1; i++)
        {
                text += SumResult.Result[i];
        }
         eResult->Text = text;

}
//---------------------------------------------------------------------------

void __fastcall TfCalculator::btnExitClick(TObject *Sender)
{
        exit(0);        
}
//---------------------------------------------------------------------------

