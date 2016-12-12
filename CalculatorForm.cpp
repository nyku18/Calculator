//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CalculatorForm.h"
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
