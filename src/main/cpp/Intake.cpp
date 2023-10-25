#include "Intake.h"

void Intake::InitSendable(wpi::SendableBuilder &builder)
{
    builder.SetSmartDashboardType("Intake");
    builder.AddDoubleProperty(
        "pGain", [this] { return GetP(); },
        [this](double pGain) { SetP(pGain); }
    );
}

// Get color from sensor
frc::Color Intake::getColor()
{
    return m_colorSensor.GetColor();
}

bool Intake::isRedColor(frc::Color color)
{
    if ((color.red > 0.60) && (color.red < 0.70) && (color.green > 0.24) && (color.green < 0.34) && (color.blue > 0.0) && (color.blue < 0.9)) {
        return true;
    } else {
        return false;
    }
}

bool Intake::isBlueColor(frc::Color color)
{
    if ((color.red > 0.15) && (color.red < 0.25) && (color.green > 0.37) && (color.green < 0.47) && (color.blue > 0.28) && (color.blue < 0.38)) {
        return true;
    } else {
        return false;
    }
}

Intake::COLOR Intake::getBallColor()
{
    auto color = getColor();

    if (isBlueColor(color)) {
        return kBLUE;
    }
    if (isRedColor(color)) {
        return kRED;
    }

    return kNONE;
}

void Intake::run(bool buttonA, frc::DriverStation::Alliance alliance)
{
    switch (m_state)
    {
    case kIDLE:
        // Roller: Off
        m_roller.Set(0.0);
        // Hinge: Retracted
        m_pid.SetReference(0.0, rev::CANSparkMax::ControlType::kPosition);

        // Check Button A
        if (buttonA) {
            m_state = kACTIVE;
        }
        break;
    case kACTIVE:
        // Roller: On
        m_roller.Set(0.37);
        // Hinge: Deployed
        m_pid.SetReference(80.5, rev::CANSparkMax::ControlType::kPosition);

        // Check Button A
        if (buttonA) {
            m_state = kIDLE;
        }
        // Detect Color
        if (getBallColor() == kRED) {
            if (alliance == frc::DriverStation::Alliance::kRed) {
                m_state = kINTAKE;
            } else {
                m_state = kEJECT;
            }
        }
        if (getBallColor() == kBLUE) {
            if (alliance == frc::DriverStation::Alliance::kBlue) {
                m_state = kINTAKE;
            } else {
                m_state = kEJECT;
            }
        }

        if ((m_state == kINTAKE) || (m_state == kEJECT)) {
            m_timer.Reset();
            m_timer.Start();
        }
        break;
    case kINTAKE:
        // Roller: On
         m_roller.Set(0.37);
        // Hinge: Deployed
        m_pid.SetReference(80.5, rev::CANSparkMax::ControlType::kPosition);

        // Check Timer
        if (m_timer.Get() > 1.0_s) {
            m_state = kIDLE;
        }
        break;
    case kEJECT:
        // Roller: On (Reverse)
         m_roller.Set(-0.37);

        // Hinge: Deployed
        m_pid.SetReference(80.5, rev::CANSparkMax::ControlType::kPosition);

        // Check Timer
        if (m_timer.Get() > 1.0_s) {
            m_state = kACTIVE;
        }
        break;
    }
}