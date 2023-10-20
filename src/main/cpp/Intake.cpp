#include "Intake.h"

// Get color from sensor
frc::Color Intake::getColor()
{
    return m_colorSensor.GetColor();
}

bool Intake::isRedColor(frc::Color color)
{
    if ((color.red > 0.60) && (color.red < 0.70) && (color.green > 0.24) && (color.green < 0.34) && (color.blue > 0.0) && (color.blue < 0.9))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Intake::isBlueColor(frc::Color color)
{
    if ((color.red > 0.15) && (color.red < 0.25) && (color.green > 0.37) && (color.green < 0.47) && (color.blue > 0.28) && (color.blue < 0.38))
    {
        return true;
    }
    else
    {
        return false;
    }
}