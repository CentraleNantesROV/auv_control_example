#include <auv_control/controller_io.h>

using namespace auv_control;

class TrivialController : public ControllerIO
{
public:

  TrivialController() : ControllerIO("trivial")
  {

  }

  Vector6d computeWrench(const Vector6d &se3_error,
                           const Vector6d &vel,
                           const Vector6d &vel_setpoint) override
    {    
      Vector6d S{vel_setpoint-vel};

      // orientation from odometry
      [[maybe_unused]] const auto q{orientation};

      // pose with regards to some frame
      [[maybe_unused]] const auto pose{relPose("world")};

      // pose + velocity error to wrench
      return 0.5*S + 1.5*se3_error;
    }

private:

};


int main(int argc, char** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TrivialController>());
  rclcpp::shutdown();
  return 0;
}
