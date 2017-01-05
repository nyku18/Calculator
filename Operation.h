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
                void Swap();
};

//---------------------------------------------------------------------------
#endif
