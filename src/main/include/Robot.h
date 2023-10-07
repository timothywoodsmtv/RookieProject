// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <rev/CANSparkMax.h>
#include <vector>

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
  rev::CANSparkMax m_left{1, rev::CANSparkMax::MotorType::kBrushless};

  std::shared_ptr<nt::NetworkTable> m_left_table =
    nt::NetworkTableInstance::GetDefault().GetTable("limelight-dev");

  std::vector<double> m_zero_vector = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
};