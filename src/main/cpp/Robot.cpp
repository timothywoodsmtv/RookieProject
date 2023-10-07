// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>
#include <units/length.h>
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
  // Is target valid?
  if (m_left_table->GetNumber("tv", 0.0) > 0.5) {
      // Get target data
      auto target = m_left_table->GetNumberArray("camerapose_targetspace", m_zero_vector);
      
      frc::SmartDashboard::PutNumber("tx", target[0]);
      frc::SmartDashboard::PutNumber("ty", target[1]);
      frc::SmartDashboard::PutNumber("tz", target[2]);
      frc::SmartDashboard::PutNumber("rx", target[3]);
      frc::SmartDashboard::PutNumber("ry", target[4]);
      frc::SmartDashboard::PutNumber("rz", target[5]);

      // Calculate distance to target
      // TODO
    
      // Run motor at 25% if target is within range
      // TODO
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
