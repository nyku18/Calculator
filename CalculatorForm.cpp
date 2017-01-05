//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CalculatorForm.h"
#include <Sum.h>
#include <string.h>
#include <Number.h>

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

        Number FirstNumber;   //creez obiectul in memorie
        Number SecondNumber;

        FirstNumber.StringToInt(SFirstNumber);
        SecondNumber.StringToInt(SSecondNumber);

        FirstNumber.Overturn();
        SecondNumber.Overturn();

        Sum SumResult = Sum();     //creez obiectul in memorie

        SumResult.FirstNumber = FirstNumber;
        SumResult.SecondNumber = SecondNumber;

        int ResultLength = SumResult.Calculate();

        int i;

        String text = " ";
        for(i = 0; i < ResultLength; i++)
        {
                text += SumResult.Result.NumberDigits[i];
        }
        eResult->Text = text;

}
//---------------------------------------------------------------------------

void __fastcall TfCalculator::btnExitClick(TObject *Sender)
{
        exit(0);        
}
//---------------------------------------------------------------------------

