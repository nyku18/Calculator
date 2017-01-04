//---------------------------------------------------------------------------

#ifndef OperationH
#define OperationH
//---------------------------------------------------------------------------

class Operation
{
        public:
                int FirstNumber[100];
                int SecondNumber[100];
                int Result[100];
                Operation();
                void Calculate(int FirstNumberLength, int SecondNumberLength);
                //~Operation();
};


//---------------------------------------------------------------------------
#endif
