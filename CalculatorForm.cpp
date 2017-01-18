//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CalculatorForm.h"
#include <string.h>
#include "Number.h"
#include "Sum.h"
#include "Difference.h"
#include "Product.h"
#include "Quotient.h"
#include "Inverted.h"
#include "Root.h"

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

        Sum SumResult = Sum();

        SumResult.FirstNumber.StringToInt(SFirstNumber);
        SumResult.SecondNumber.StringToInt(SSecondNumber);

        SumResult.FirstNumber.Overturn();
        SumResult.SecondNumber.Overturn();

        SumResult.Calculate();

        eResult->Text = SumResult.Result.IntToString(0);

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

        eResult->Text = Sign + DifferenceResult.Result.IntToString(0);

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

        eResult->Text = ProductResult.Result.IntToString(0);

}
//---------------------------------------------------------------------------

void __fastcall TfCalculator::btnDivideClick(TObject *Sender)
{
        String SFirstNumber = eFirstNumber->Text;
        String SSecondNumber = eSecondNumber->Text;

        Quotient QuotientResult = Quotient();

        QuotientResult.FirstNumber.StringToInt(SFirstNumber);
        QuotientResult.SecondNumber.StringToInt(SSecondNumber);

        QuotientResult.FirstNumber.Overturn();
        QuotientResult.SecondNumber.Overturn();

        int DotPosition;
        DotPosition = QuotientResult.Calculate();

        eResult->Text = QuotientResult.Result.IntToString(DotPosition);

}
//---------------------------------------------------------------------------

void __fastcall TfCalculator::btnInverseClick(TObject *Sender)
{
        String SSecondNumber = eFirstNumber->Text;

        Inverted InvertedResult = Inverted();

        InvertedResult.SecondNumber.StringToInt(SSecondNumber);

        InvertedResult.SecondNumber.Overturn();

        InvertedResult.FirstNumber.StringToInt("1");

        int DotPosition;
        DotPosition = InvertedResult.Calculate();

        eResult->Text = InvertedResult.Result.IntToString(DotPosition);

}
//---------------------------------------------------------------------------


void __fastcall TfCalculator::btnSquareRootClick(TObject *Sender)
{
           String SFirstNumber = eFirstNumber->Text;

           Root RootResult = Root();
           RootResult.FirstNumber.StringToInt(SFirstNumber);
           RootResult.FirstNumber.Overturn();
           int DotPosition;
           DotPosition = RootResult.Calculate();

           eResult->Text = RootResult.Result.IntToString(DotPosition);

}
//---------------------------------------------------------------------------

