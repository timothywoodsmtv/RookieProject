#include "Shooter.h"

void Shooter::shoot(units::meter_t distance)
{
  // Run motor if target is within range
  auto throttle = distance / 10.0_ft;
  if ((distance > 5.0_ft) && (distance < 10.0_ft))
  {
    m_left.Set(throttle);
  }
  else
  {
    m_left.Set(0.0);
  }
}