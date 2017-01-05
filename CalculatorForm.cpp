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

        Sum SumResult = Sum();     //creez obiectul in memorie

        SumResult.FirstNumber.StringToInt(SFirstNumber);
        SumResult.SecondNumber.StringToInt(SSecondNumber);

        SumResult.FirstNumber.Overturn();
        SumResult.SecondNumber.Overturn();

        SumResult.Calculate();

        eResult->Text = SumResult.Result.IntToString();

}
//---------------------------------------------------------------------------

void __fastcall TfCalculator::btnExitClick(TObject *Sender)
{
        exit(0);        
}
//---------------------------------------------------------------------------

