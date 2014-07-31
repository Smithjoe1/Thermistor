#ifndef Thermistor_H
#define Thermistor_H
#include "Arduino.h"


class Thermistor {
  public:
    Thermistor(byte pin, int beta, long thermistorNominal, byte termperatureNominal, long seriesResistor);
    float getTemp();
    void updateTemp();
  private:
    byte _pin; 
    int _beta;
    long _ThermistorNominal;
    byte _TermperatureNominal;
    long _SeriesResistor;
    byte FastAverageSize = 50;
    int FastAverage[50];
    byte _FastIndex;
};
#endif
