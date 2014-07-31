#include "Arduino.h"
#include "Thermistor.h"

//Constructor
Thermistor::Thermistor(byte pin, int beta, long thermistorNominal, byte termperatureNominal, long seriesResistor){
  pinMode(pin, INPUT);
  _pin = pin;
  _beta = beta;  
  _ThermistorNominal = thermistorNominal;
  _TermperatureNominal = termperatureNominal;
  _SeriesResistor = seriesResistor;
  _FastIndex = 0; //Set array index
  
  Serial.println(_pin);
  Serial.println(_beta);
  Serial.println(_ThermistorNominal);
  Serial.println(_TermperatureNominal);
  Serial.println(_SeriesResistor);
}

float Thermistor::getTemp() {
  int total = 0; 
  for(int i = 0; i < FastAverageSize; i++){
    total = total + FastAverage[i];
  }
  float average =  total / FastAverageSize;  
    // convert the value to resistance
  average =  average * 5 / 1024; //voltage reference / byte length
  average =  average / (5 - average);
  average = _SeriesResistor / average;
 
  float steinhart;
  steinhart = average / _ThermistorNominal;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= _beta;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (_TermperatureNominal + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert to C
 
  return steinhart;
  
}

void Thermistor::updateTemp(){
 FastAverage[_FastIndex] = analogRead(_pin);
 _FastIndex++;
 if(_FastIndex ==  FastAverageSize){
   _FastIndex = 0; 
 }
}
