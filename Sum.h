//---------------------------------------------------------------------------

#ifndef SumH
#define SumH

#include <Operation.h>
//---------------------------------------------------------------------------

class Sum : public Operation
{
        public:
                Sum();
                int Calculate(int FirstNumberLength, int SecondNumberLength);
                //~Sum();

};

//---------------------------------------------------------------------------
#endif
