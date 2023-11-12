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

std::string selectedColor(int mouseX, int mouseY, int squareSide, int moneyStars)
{

    if (mouseY >= 1200 && mouseY <= 1200 + squareSide)
    {
        if (mouseX >= 100 && mouseX <= 100 + squareSide && moneyStars >= 1)
        {
            return "orangeRhombus";
        }
        else if (mouseX >= 450 && mouseX <= 450 + squareSide && moneyStars >= 2)
        {
            return "blueRhombus";
        }
        else if (mouseX >= 800 && mouseX <= 800 + squareSide && moneyStars >= 2)
        {
            return "yellowRhombus";
        }
        else if (mouseX >= 1150 && mouseX <= 1150 + squareSide && moneyStars >= 4)
        {
            return "purpleRhombus";
        }
    }
    return "";
}

void placeRhombus(int mouseX, int mouseY, int squareSide,
                  int &moneyStars, RhombusData selectedRhombus,
                  RhombusData attackRhombus[3][3])
{
    float fit = squareSide / 6; // in order to place rhombus right in the center of square

    // checking for each square
    if (mouseX >= 150 && mouseX <= 150 + squareSide &&
        mouseY >= 50 && mouseY <= 50 + squareSide &&
        !attackRhombus[0][0].isPlaced)
    {
        selectedRhombus.scaleX = 1.0f;
        selectedRhombus.scaleY = 1.0f;
        selectedRhombus.mustBeDestroyed = 0;
        selectedRhombus.isPlaced = 1;
        selectedRhombus.setCoordinates(150 + fit, 50 + fit);
        attackRhombus[0][0] = selectedRhombus;
        moneyStars -= selectedRhombus.cost;
        return;
    }
    else if (mouseX >= 420 && mouseX <= 420 + squareSide &&
             mouseY >= 50 && mouseY <= 50 + squareSide &&
             !attackRhombus[0][1].isPlaced)
    {
        selectedRhombus.scaleX = 1.0f;
        selectedRhombus.scaleY = 1.0f;
        selectedRhombus.mustBeDestroyed = 0;
        selectedRhombus.isPlaced = 1;
        selectedRhombus.setCoordinates(420 + fit, 50 + fit);
        attackRhombus[0][1] = selectedRhombus;
        moneyStars -= selectedRhombus.cost;
        return;
    }
    else if (mouseX >= 690 && mouseX <= 690 + squareSide &&
             mouseY >= 50 && mouseY <= 50 + squareSide &&
             !attackRhombus[0][2].isPlaced)
    {
        selectedRhombus.scaleX = 1.0f;
        selectedRhombus.scaleY = 1.0f;
        selectedRhombus.mustBeDestroyed = 0;
        selectedRhombus.isPlaced = 1;
        selectedRhombus.setCoordinates(690 + fit, 50 + fit);
        attackRhombus[0][2] = selectedRhombus;
        moneyStars -= selectedRhombus.cost;
        return;
    }
    else if (mouseX >= 150 && mouseX <= 150 + squareSide &&
             mouseY >= 320 && mouseY <= 320 + squareSide &&
             !attackRhombus[1][0].isPlaced)
    {
        selectedRhombus.scaleX = 1.0f;
        selectedRhombus.scaleY = 1.0f;
        selectedRhombus.mustBeDestroyed = 0;
        selectedRhombus.isPlaced = 1;
        selectedRhombus.setCoordinates(150 + fit, 320 + fit);
        attackRhombus[1][0] = selectedRhombus;
        moneyStars -= selectedRhombus.cost;
        return;
    }
    else if (mouseX >= 420 && mouseX <= 420 + squareSide &&
             mouseY >= 320 && mouseY <= 320 + squareSide &&
             !attackRhombus[1][1].isPlaced)
    {
        selectedRhombus.scaleX = 1.0f;
        selectedRhombus.scaleY = 1.0f;
        selectedRhombus.mustBeDestroyed = 0;
        selectedRhombus.isPlaced = 1;
        selectedRhombus.setCoordinates(420 + fit, 320 + fit);
        attackRhombus[1][1] = selectedRhombus;
        moneyStars -= selectedRhombus.cost;
        return;
    }
    else if (mouseX >= 690 && mouseX <= 690 + squareSide &&
             mouseY >= 320 && mouseY <= 320 + squareSide &&
             !attackRhombus[1][2].isPlaced)
    {
        selectedRhombus.scaleX = 1.0f;
        selectedRhombus.scaleY = 1.0f;
        selectedRhombus.mustBeDestroyed = 0;
        selectedRhombus.isPlaced = 1;
        selectedRhombus.setCoordinates(690 + fit, 320 + fit);
        attackRhombus[1][2] = selectedRhombus;
        moneyStars -= selectedRhombus.cost;
        return;
    }
    else if (mouseX >= 150 && mouseX <= 150 + squareSide &&
             mouseY >= 590 && mouseY <= 590 + squareSide &&
             !attackRhombus[2][0].isPlaced)
    {
        selectedRhombus.scaleX = 1.0f;
        selectedRhombus.scaleY = 1.0f;
        selectedRhombus.mustBeDestroyed = 0;
        selectedRhombus.isPlaced = 1;
        selectedRhombus.setCoordinates(150 + fit, 590 + fit);
        attackRhombus[2][0] = selectedRhombus;
        moneyStars -= selectedRhombus.cost;
        return;
    }
    else if (mouseX >= 420 && mouseX <= 420 + squareSide &&
             mouseY >= 590 && mouseY <= 590 + squareSide &&
             !attackRhombus[2][1].isPlaced)
    {
        selectedRhombus.scaleX = 1.0f;
        selectedRhombus.scaleY = 1.0f;
        selectedRhombus.mustBeDestroyed = 0;
        selectedRhombus.isPlaced = 1;
        selectedRhombus.setCoordinates(420 + fit, 590 + fit);
        attackRhombus[2][1] = selectedRhombus;
        moneyStars -= selectedRhombus.cost;
        return;
    }
    else if (mouseX >= 690 && mouseX <= 690 + squareSide &&
             mouseY >= 590 && mouseY <= 590 + squareSide &&
             !attackRhombus[2][2].isPlaced)
    {
        selectedRhombus.scaleX = 1.0f;
        selectedRhombus.scaleY = 1.0f;
        selectedRhombus.mustBeDestroyed = 0;
        selectedRhombus.isPlaced = 1;
        selectedRhombus.setCoordinates(690 + fit, 590 + fit);
        attackRhombus[2][2] = selectedRhombus;
        moneyStars -= selectedRhombus.cost;
        return;
    }
}

void checkIfDestroyRhombus(int mouseX, int mouseY, int squareSide,
                           RhombusData attackRhombus[3][3])
{
    if (mouseX >= 150 && mouseX <= 150 + squareSide &&
        mouseY >= 50 && mouseY <= 50 + squareSide &&
        attackRhombus[0][0].isPlaced)
    {
        attackRhombus[0][0].mustBeDestroyed = 1;
        return;
    }
    else if (mouseX >= 420 && mouseX <= 420 + squareSide &&
             mouseY >= 50 && mouseY <= 50 + squareSide &&
             attackRhombus[0][1].isPlaced)
    {
       attackRhombus[0][1].mustBeDestroyed = 1;
        return;
    }
    else if (mouseX >= 690 && mouseX <= 690 + squareSide &&
             mouseY >= 50 && mouseY <= 50 + squareSide &&
             attackRhombus[0][2].isPlaced)
    {
        attackRhombus[0][2].mustBeDestroyed = 1;
        return;
    }
    else if (mouseX >= 150 && mouseX <= 150 + squareSide &&
             mouseY >= 320 && mouseY <= 320 + squareSide &&
             attackRhombus[1][0].isPlaced)
    {
        attackRhombus[1][0].mustBeDestroyed = 1;
        return;
    }
    else if (mouseX >= 420 && mouseX <= 420 + squareSide &&
             mouseY >= 320 && mouseY <= 320 + squareSide &&
             attackRhombus[1][1].isPlaced)
    {
        attackRhombus[1][1].mustBeDestroyed = 1;
        return;
    }
    else if (mouseX >= 690 && mouseX <= 690 + squareSide &&
             mouseY >= 320 && mouseY <= 320 + squareSide &&
             attackRhombus[1][2].isPlaced)
    {
        attackRhombus[1][2].mustBeDestroyed = 1;
        return;
    }
    else if (mouseX >= 150 && mouseX <= 150 + squareSide &&
             mouseY >= 590 && mouseY <= 590 + squareSide &&
             attackRhombus[2][0].isPlaced)
    {
        attackRhombus[2][0].mustBeDestroyed = 1;
        return;
    }
    else if (mouseX >= 420 && mouseX <= 420 + squareSide &&
             mouseY >= 590 && mouseY <= 590 + squareSide &&
             attackRhombus[2][1].isPlaced)
    {
        attackRhombus[2][1].mustBeDestroyed = 1;
        return;
    }
    else if (mouseX >= 690 && mouseX <= 690 + squareSide &&
             mouseY >= 590 && mouseY <= 590 + squareSide &&
             attackRhombus[2][2].isPlaced)
    {
        attackRhombus[2][2].mustBeDestroyed = 1;
        return;
    }
}