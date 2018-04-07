#ifndef DoubDigitOpt_hpp
#define DoubDigitOpt_hpp

#include "Options06.hpp"

class DoubDigitOpt: public EurOption
{
   private:
      double K1; //parameter 1
      double K2; //parameter 2
    
   public:
      int GetInputData();
      double Payoff(double z);
};

#endif
