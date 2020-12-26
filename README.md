# Function-Rate-Controller
A neat way to throttle the rate of execution of functions on Arduinos

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

## Example use for function with non-void return type

```
#include "RateController.h"

uint32_t printNumber(uint32_t n);

/* 
 *  Create and return an object that throttles the printNumber
 *  function with an execution rate of 2000 milliseconds
*/
uint32_t number{0};

auto wrapperFunc = rateControllerFactory(printNumber, 2000);

void setup() {
}

void loop() {
  number = wrapperFunc.run(27);
  
  // Do something when the wrapped function runs
  if(number != NULL){
    Serial.print("Number Returned: ");
    Serial.println(number);
  }
}

uint32_t printNumber(uint32_t n){
  Serial.print("Number entered: ");
  Serial.println(n);
  return n;
}
```
