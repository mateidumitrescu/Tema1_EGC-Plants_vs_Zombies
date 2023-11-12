#include "helpers.h"
#include "lab_m1/tema1/tema1.h"
#include "lab_m1/tema1/bonusStar.h"

void checkIfPickedStar(int mouseX, int mouseY,
                       BonusStar *bonusStars, int &numberOfGeneratedStars,
                       int bonusStarDimension, int &moneyStars)
{
    int j;
    for (int i = 0; i < numberOfGeneratedStars; i++)
    {
        BonusStar star = bonusStars[i];

        if (mouseX >= star.x && mouseX <= star.x + bonusStarDimension &&
            mouseY >= star.y && mouseY <= star.y + bonusStarDimension &&
            moneyStars < 12)
        {
            // placing last picked star at the end so new coordinates can be
            // calculated in Update method
            for (j = i; j < numberOfGeneratedStars - 1; j++)
            {
                bonusStars[j] = bonusStars[j + 1];
            }
            star.hasBeenPicked = 1; // so it doesn't get rendered before new coord
            bonusStars[numberOfGeneratedStars - 1] = star;

            numberOfGeneratedStars--;
            moneyStars++;

            break;
        }
    }
}

std::string selectedColor(int mouseX, int mouseY, int squareSide)
{
    if (mouseY >= 1200 && mouseY <= 1200 + squareSide)
    {
        if (mouseX >= 100 && mouseX <= 100 + squareSide)
        {
            return "orangeRhombus";
        }
        else if (mouseX >= 450 && mouseX <= 450 + squareSide)
        {
            return "blueRhombus";
        }
        else if (mouseX >= 800 && mouseX <= 800 + squareSide)
        {
            return "yellowRhombus";
        } else if (mouseX >= 1150 && mouseX <= 1150 + squareSide) {
            return "purpleRhombus";
        }
    }
    return "";
}