#ifndef RATE_CONTROLLER
#define RATE_CONTROLLER

template <class R, class... Args>
class RateController
{
private:
    R(*_function)(Args... args);
    uint32_t _tn{0}; // Current time elapsed
    uint32_t _tp{0}; // Time elapsed since previous execution
    uint32_t _dt{0}; // Time delta

public:
    RateController(R(*function)(Args...), uint32_t dt) : _function(function), _dt(dt){
      _tp = millis() - _dt;
    }

    R run(Args... args) {
      _tn = millis();
      if(_tn - _tp >= _dt){
        _tp = millis();
        return _function(args...);  
      }
    }

};

template <class R, class... Args>
RateController<R, Args...> rateControllerFactory(R(*function)(Args...), uint32_t dt) {
    return RateController<R, Args...>(function, dt);
}

#endif
