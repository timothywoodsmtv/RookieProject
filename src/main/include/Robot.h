// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include "Vision.h"
#include "Shooter.h"
#include "rev/ColorSensorV3.h"

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
  Vision vision;
  Shooter shooter;

  // REV Color Sensor
  rev::ColorSensorV3 m_colorSensor {frc::I2C::Port::kMXP};

  // Get color from sensor
  frc::Color getColor() {
    return m_colorSensor.GetColor();
  };
};