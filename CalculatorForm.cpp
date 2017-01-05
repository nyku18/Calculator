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

        int FirstNumberDigits[100];
        int SecondNumberDigits[100];

        Number FirstNumber;
        Number SecondNumber;

        FirstNumber.StringToInt(SFirstNumber);
        SecondNumber.StringToInt(SSecondNumber);




}
//---------------------------------------------------------------------------

void __fastcall TfCalculator::btnExitClick(TObject *Sender)
{
        exit(0);        
}
//---------------------------------------------------------------------------

