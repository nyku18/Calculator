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
                int Calculate(int FirstNumberLength, int SecondNumberLength);
};

//---------------------------------------------------------------------------
#endif
