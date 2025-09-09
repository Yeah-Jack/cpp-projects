#ifndef GUI_H
#define GUI_H

class Lake;

class GUI {
public:
  GUI();
  ~GUI();

  bool rentLounger();
  void parkBike();
  double viewCurrentWaterTemperature();
  unsigned short viewCurrentWaterQuality();
  int viewCurrentNumberOfVisitors();

  Lake *getLake() const;

private:
  Lake *lake;
};

#endif // GUI_H
