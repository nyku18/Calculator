//---------------------------------------------------------------------------

#ifndef OperationH
#define OperationH
//---------------------------------------------------------------------------

class Operation
{
        public:
                int FirstNumber[];
                int SecondNumber[];
                int Result[];
                Operation();
                int Calculate(int FirstNumber[], int SecondNumber[]);
                ~Operation();
};


//---------------------------------------------------------------------------
#endif