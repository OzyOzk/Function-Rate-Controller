# Function-Rate-Controller
A neat way to throttle the rate of execution of functions

## Example use

```cpp
#include "RateController.h"

void printNumber(uint32_t n){
  Serial.print("Number entered: ");
  Serial.println(n);
}

/* 
 *  Create and return an object that throttles the printNumber
 *  function with an execution rate of 2000 milliseconds
*/

auto wrapperFunc = rateControllerFactory(printNumber, 2000);

void setup() {
}

void loop() {
  wrapperFunc.run(27);
}
```
