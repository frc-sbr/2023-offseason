// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <numbers>

#include <frc/DataLogManager.h>
#include <wpi/DataLog.h>
#include <iostream>

#include <frc/Encoder.h>
#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include "rev/CANSparkMax.h"

#include <frc/smartdashboard/SmartDashboard.h>

#define NEO1 1

class Robot : public frc::TimedRobot {
 public:
  void TeleopPeriodic() override { 
  }
  void TeleopInit() override {
  }

  void AutonomousInit() override {
    std::cout << "initing auton..." << std::endl;
    m_motor1.Set(1);
  }

  void RobotPeriodic() override { }

  void RobotInit() override {
    std::cout << "robot init" << std::endl;
    frc::DataLogManager::Start();
    str_log = wpi::log::StringLogEntry();
  }

 private:
  rev::CANSparkMax m_motor1{NEO1, rev::CANSparkMax::MotorType::kBrushless};
  wpi::log::DataLog& log = frc::DataLogManager::GetLog();
  wpi::log::StringLogEntry str_log;
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
