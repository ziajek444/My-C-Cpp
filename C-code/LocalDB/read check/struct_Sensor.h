#ifndef Sensor_H
#define Sensor_H

struct Sensor {
  int ID;
  char tclass;
  double value;
  float voltage;
  char info[128];
};



#endif
