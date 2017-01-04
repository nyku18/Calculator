//---------------------------------------------------------------------------

#ifndef ProductH
#define ProductH

#include <Operation.h>
//---------------------------------------------------------------------------

class Product : public Operation
{
        public:
                Product();
                void Calculate(int FirstNumber[], int SecondNumber[]);
                //~Product();
};

//---------------------------------------------------------------------------
#endif
