Thermistor
==========

The code from http://playground.arduino.cc/ComponentLib/Thermistor2 converted into a library for object use and multiple thermistors.

The code reverses the ADC and voltage devider values to determine the thermistors current resistance and runs that through the beta constant formula to determine the temperature of the thermistor.



Constructor:
Thermistor::Thermistor(byte pin, int beta, long thermistorNominal, byte termperatureNominal, long seriesResistor)


Methods:
getTemp() 
Returns the current termperature of the thermistor, this method runs the beta constant calculation and takes more processing time than the updateTemp method, should be called by functions using the temperature.


updateTemp()
Update the internal temperature reading of the thermisor. This method updates a lot faster than the getTemp method and can be run more frequently than getTemp().
