//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CalculatorForm.h"
#include <string.h>
#include <Number.h>
#include <Sum.h>
#include <Difference.h>
#include <Product.h>

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
void __fastcall TfCalculator::btnExitClick(TObject *Sender)
{
        exit(0);
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

void __fastcall TfCalculator::btnSubstractClick(TObject *Sender)
{
        String SFirstNumber = eFirstNumber->Text;
        String SSecondNumber = eSecondNumber->Text;

        Difference DifferenceResult = Difference();

        DifferenceResult.FirstNumber.StringToInt(SFirstNumber);
        DifferenceResult.SecondNumber.StringToInt(SSecondNumber);

        DifferenceResult.FirstNumber.Overturn();
        DifferenceResult.SecondNumber.Overturn();

        DifferenceResult.Calculate();

        String Sign = "";

        if(DifferenceResult.Result.NumberSign == 0)
        {
                Sign = "-";
        }

        eResult->Text = Sign + DifferenceResult.Result.IntToString();

}
//---------------------------------------------------------------------------

void __fastcall TfCalculator::btbMultiplyClick(TObject *Sender)
{
        String SFirstNumber = eFirstNumber->Text;
        String SSecondNumber = eSecondNumber->Text;

        Product ProductResult = Product();

        ProductResult.FirstNumber.StringToInt(SFirstNumber);
        ProductResult.SecondNumber.StringToInt(SSecondNumber);

        ProductResult.FirstNumber.Overturn();
        ProductResult.SecondNumber.Overturn();

        ProductResult.Calculate();

        eResult->Text = ProductResult.Result.IntToString();

}
//---------------------------------------------------------------------------

