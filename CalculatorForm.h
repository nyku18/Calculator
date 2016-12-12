//---------------------------------------------------------------------------

#ifndef CalculatorFormH
#define CalculatorFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfCalculator : public TForm
{
__published:	// IDE-managed Components
        TEdit *eFirstNumber;
        TEdit *eSecondNumber;
        TEdit *eResult;
        TButton *btnAdd;
        TButton *btnSubstract;
        TButton *btbMultiply;
        TButton *btnDivide;
        TButton *btnInverse;
        TButton *btnSquareRoot;
private:	// User declarations
public:		// User declarations
        __fastcall TfCalculator(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfCalculator *fCalculator;
//---------------------------------------------------------------------------
#endif