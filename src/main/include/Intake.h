#include "rev/ColorSensorV3.h"

class Intake
{

public:
    frc::Color getColor();
    bool isRedColor(frc::Color color);
    bool isBlueColor(frc::Color color);

private:
    // REV Color Sensor
    rev::ColorSensorV3 m_colorSensor{frc::I2C::Port::kMXP};
};