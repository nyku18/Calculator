//---------------------------------------------------------------------------

#ifndef SumH
#define SumH

#include <Operation.h>
//---------------------------------------------------------------------------

class Sum : public Operation
{
        public:
                Sum();
                void Calculate(int OverturnedFirstNumber, int OverturnedSecondNumber);
                //~Sum();

};

//---------------------------------------------------------------------------
#endif
