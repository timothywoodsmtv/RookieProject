#include "Vision.h"
#include <frc/smartdashboard/SmartDashboard.h>

units::meter_t Vision::getDistanceToTarget()
{
  // Is target valid?
  if ((m_left_table->GetNumber("tv", 0.0) > 0.5) and (m_left_table->GetNumber("tid", 0.0) == 8))
  {
    // Get target data
    auto target = m_left_table->GetNumberArray("camerapose_targetspace", m_zero_vector);

    frc::SmartDashboard::PutNumber("tx", target[0]);
    frc::SmartDashboard::PutNumber("ty", target[1]);
    frc::SmartDashboard::PutNumber("tz", target[2]);
    frc::SmartDashboard::PutNumber("rx", target[3]);
    frc::SmartDashboard::PutNumber("ry", target[4]);
    frc::SmartDashboard::PutNumber("rz", target[5]);

    // Calculate distance to target
    auto distance = units::meter_t{sqrt(target[0] * target[0] + target[1] * target[1] + target[2] * target[2])};
    frc::SmartDashboard::PutNumber("distance", distance.value());

    return distance;
  }
  else
  {
    return 0.0_m;
  }
}