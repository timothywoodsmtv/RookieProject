// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  // Calculate distance to target and shoot
  auto distance = getDistanceToTarget();
  shoot(distance);
}

units::meter_t Robot::getDistanceToTarget()
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

void Robot::shoot(units::meter_t distance)
{
  // Run motor if target is within range
  auto throttle = distance / 10.0_ft;
  if ((distance < 5.0_ft) && (distance > 10.0_ft))
  {
    m_left.Set(throttle);
  }
  else
  {
    m_left.Set(0.0);
  }
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {
}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
