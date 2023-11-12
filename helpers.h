#pragma once
#include "bonusStar.h"
#include <string>

// check if a star was picked
void checkIfPickedStar(int mouseX, int mouseY,
                       BonusStar *bonusStars, int &numberOfGeneratedStars,
                       int bonusStarDimension, int &moneyStars);

// return the Rhombus color that has been picked
std::string selectedColor(int mouseX, int mouseY, int squareSide);
