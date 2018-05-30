#include <string>
#include "Coordination.h"

using namespace std;

class IllegalCoordinateException {
  private:
    const Coordination& _Coordination;
    
  public:
	  IllegalCoordinateException(const Coordination& illegalCoordination): _Coordination(illegalCoordination) { }
      
      string theCoordination() const{
		  string s = to_string(_Coordination.getXCoordination()) + "," + to_string(_Coordination.getYCoordination());
          return string(s + " is an illegitimate move");
      }  
};