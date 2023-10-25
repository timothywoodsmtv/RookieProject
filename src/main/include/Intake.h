#include "rev/ColorSensorV3.h"
#include <frc/DriverStation.h>
#include <frc/Timer.h>
#include <rev/CANSparkMax.h>
#include <wpi/sendable/Sendable.h>
//#include <wpi/sendable/SendableHelper.h>
#include <wpi/sendable/SendableBuilder.h>

class Intake : public wpi::Sendable //, public wpi::SendableHelper<Intake>
{
public:
    void run(bool buttonA, frc::DriverStation::Alliance alliance);

    frc::Color getColor();
    void InitSendable(wpi::SendableBuilder& builder) override;

private:
    enum STATE
    {
        kIDLE,
        kACTIVE,
        kINTAKE,
        kEJECT
    } m_state;

    enum COLOR
    {
        kRED,
        kBLUE,
        kNONE
    };

    COLOR getBallColor();
    bool isRedColor(frc::Color color);
    bool isBlueColor(frc::Color color);

    // REV Color Sensor
    rev::ColorSensorV3 m_colorSensor{frc::I2C::Port::kMXP};
    frc::Timer m_timer;

    // Percent throttle control for this motor
    rev::CANSparkMax m_roller{1, rev::CANSparkMax::MotorType::kBrushless};

    // Position PID for this motor
    rev::CANSparkMax m_hinge{2, rev::CANSparkMax::MotorType::kBrushless};
    rev::SparkMaxPIDController m_pid = m_hinge.GetPIDController();

    // PID coefficient structure
    struct pidCoeff
    {
        double kP;
        double kI;
        double kD;
        double kIz;
        double kFF;
        double kMinOutput;
        double kMaxOutput;
    };

    void SetP(double pGain) {  m_pidCoeff.kP = pGain; }
    double GetP() { return m_pidCoeff.kP; }

    pidCoeff m_pidCoeff{0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 1.0};
};