//---------------------------------------------------------------------------

#ifndef SumH
#define SumH

#include <Operation.h>
//---------------------------------------------------------------------------

class Sum : public Operation
{
        public:
                Sum();
                void Calculate(int FirstNumber[], int SecondNumber[]);
                //~Sum();
};

//---------------------------------------------------------------------------
#endif
