#pragma once
#include "bonusStar.h"
#include "rhombusData.h"

#include <string>

// check if a star was picked
void checkIfPickedStar(int mouseX, int mouseY,
                       BonusStar *bonusStars, int &numberOfGeneratedStars,
                       int bonusStarDimension, int &moneyStars);

// return the Rhombus color that has been picked
std::string selectedColor(int mouseX, int mouseY, int squareSide,
                          int moneyStars);

// check if user wants to place the Rhombus in a good square and place it if good
void placeRhombus(int mouseX, int mouseY, int squareSide,
                  int &moneyStars, RhombusData selectedRhombus,
                  RhombusData attackRhombus[3][3]);

// check if a rhombus must be destroyed by clicking it
void checkIfDestroyRhombus(int mouseX, int mouseY, int squareSide,
                           RhombusData attackRhombus[3][3]);