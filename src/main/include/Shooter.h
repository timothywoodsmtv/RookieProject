#include <rev/CANSparkMax.h>
#include <units/length.h>

class Shooter {

    public:
        void shoot(units::meter_t distance);

    private:
        rev::CANSparkMax m_left{1, rev::CANSparkMax::MotorType::kBrushless};
};