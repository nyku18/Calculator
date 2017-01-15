//---------------------------------------------------------------------------

#ifndef OperationH
#define OperationH

#include "Number.h"
//---------------------------------------------------------------------------

class Operation
{
        public:
                Number FirstNumber;
                Number SecondNumber;
                Number Result;
                Operation();
                void Calculate();
                int Compare();
                int Compare(Number FirstNumber, Number SecondNumber);
                void Swap();
};

//---------------------------------------------------------------------------
#endif
