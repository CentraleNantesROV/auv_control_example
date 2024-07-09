
This package contains an example of using `auv_control` as an external library with a custom control law.

## Dependencies

- [auv_control](https://github.com/CentraleNantesROV/auv_control) for the underlying framework
- [thruster_manager](https://github.com/CentraleNantesROV/thruster_manager) for the thrust allocation
- [simple_launch](https://github.com/oKermorgant/simple_launch) for the launch files
- [slider_publisher](https://github.com/oKermorgant/slider_publisher) for basic GUI to run tests

## Common properties

All controllers subscribe to the following:

- `cmd_pos` (`PoseStamped`): the pose setpoint expressed in the header frame
- `cmd_vel` (`TwistStamped`): the velocity setpoint expressed in the header frame
- `state` (`Odometry`): an estimation of the current state (pose + velocity) of the vehicle
- `/tf`: to get the transforms between all frames

The output may be:

- `cmd_thrust` (`JointState`): only the `effort` field is populated with the corresponding thrust for this thruster
- `<thruster>_cmd` (`Double`): the desired thrust for this thruster. This output is compatible with Gazebo thruster plugin.
