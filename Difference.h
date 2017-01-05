//---------------------------------------------------------------------------

#ifndef DifferenceH
#define DifferenceH

#include <Operation.h>
//---------------------------------------------------------------------------

class Difference : public Operation
{
        public:
                Difference();
                int Calculate(int FirstNumberLength, int SecondNumberLength);
};

//---------------------------------------------------------------------------
#endif
