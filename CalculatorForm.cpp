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
        int OverturnedFirstNumber[100];
        int OverturnedSecondNumber[100];

        /* poate lipsi */
        for(int i = 0; i < 100; i++)
        {
                FirstNumber[i] = 0;
                SecondNumber[i] = 0;
                OverturnedFirstNumber[i] = 0;
                OverturnedSecondNumber[i] = 0;
        }
        
        int FirstNumberLength = strlen(SFirstNumber.c_str());
        int SecondNumberLength = strlen(SSecondNumber.c_str());

        char CFirstNumber[100] = "";    /*  ="" -- initializeaza cu 0 vectorul de char-uri */
        strcpy(CFirstNumber, SFirstNumber.c_str());
        char CSecondNumber[100] = "";
        strcpy(CSecondNumber, SSecondNumber.c_str());
        int i;


        for(i = 0; i < FirstNumberLength; i++)
        {
                FirstNumber[i] = CFirstNumber[i] - '0'; /* conversie la int */
        }
        for(i = 0; i < SecondNumberLength; i++)
        {
                SecondNumber[i] = CSecondNumber[i] - '0';
        }

        /* calcul rasturnat */
        for(i = 0; i < FirstNumberLength; i++)
        {
                OverturnedFirstNumber[FirstNumberLength - i - 1] = FirstNumber[i];
        }
        for(i = 0; i < SecondNumberLength; i++)
        {
                OverturnedSecondNumber[SecondNumberLength - i - 1] = SecondNumber[i];
        }
 
        Sum SumResult;
        memcpy(SumResult.FirstNumber, OverturnedFirstNumber, sizeof(SumResult.FirstNumber));
        memcpy(SumResult.SecondNumber, OverturnedSecondNumber, sizeof(SumResult.SecondNumber));

        /* asta face memcpy*/
        //SumResult.FirstNumber = FirstNumber;
        //SumResult.SecondNumber = SecondNumber;

        int ResultLength = SumResult.Calculate(FirstNumberLength, SecondNumberLength);
        /* afisare */
        String text = " ";
        for(i = 0; i < ResultLength; i++)
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

