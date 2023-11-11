// BonusStar.h
#ifndef BonusStar_H
#define BonusStar_H

class BonusStar
{
  

public:
  BonusStar() = default;
  BonusStar(float _x, float _y, int p);
  float x;
  float y;
  int hasBeenPicked;

};

#endif