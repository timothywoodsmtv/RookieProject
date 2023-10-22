// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include "Vision.h"
#include "Shooter.h"
#include "Intake.h"
#include "rev/ColorSensorV3.h"
#include <frc/XboxController.h>
#include <frc/DriverStation.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

 private:
  Vision  m_vision;
  Shooter m_shooter;
  Intake  m_intake;

  frc::XboxController m_stick{0};
  frc::DriverStation::Alliance m_alliance = frc::DriverStation::Alliance::kInvalid;
};