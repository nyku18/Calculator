//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CalculatorForm.h"
#include <Sum.h>

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
        char CFirstNumber[100];
        strcpy(CFirstNumber, SFirstNumber.c_str());
        char CSecondNumber[100];
        strcpy(CSecondNumber, SSecondNumber.c_str());
        int i;
        for(i = 0; i < sizeof(CFirstNumber) - 1; i++)
        {
                FirstNumber[i] = CFirstNumber[i];
        }
        for(i = 0; i < sizeof(CSecondNumber) - 1; i++)
        {
                SecondNumber[i] = CSecondNumber[i];
        }

        Sum SumResult;
        SumResult.Calculate(FirstNumber, SecondNumber);
        
        eResult->Text = SumResult.Result;
}
//---------------------------------------------------------------------------

void __fastcall TfCalculator::btnExitClick(TObject *Sender)
{
        exit(0);        
}
//---------------------------------------------------------------------------

