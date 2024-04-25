// Copyright 2012 Open Source Robotics Foundation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Author: Ryan Shim

#include "ObstacleAnimator.hh"

#include <gz/plugin/Register.hh>

#include <gz/common/Animation.hh>
#include <gz/common/KeyFrame.hh>
#include <gz/sim/System.hh>

#define PI 3.141592

namespace gazebo {
class Obstacles : public ObstacleAnimator {
public:
  Obstacles() : ObstacleAnimator(CreateAnimation()) {}

  // create the animation
  gz::common::PoseAnimation CreateAnimation() {

    // name the animation "move",
    // make it last 40 seconds,
    // and set it on a repeat loop
    gz::common::PoseAnimation anim =
        gz::common::PoseAnimation("move", 40.0, true);

    gz::common::PoseKeyFrame *key;

    // set starting location of the box
    key = anim.CreateKeyFrame(0);
    key->Translation(gz::math::Vector3d(0.0, 0.0, 0.0));
    key->Rotation(gz::math::Quaterniond(0, 0, 0));

    key = anim.CreateKeyFrame(20);
    key->Translation(gz::math::Vector3d(0.0, 0.0, 0.0));
    key->Rotation(gz::math::Quaterniond(0, 0, PI));

    key = anim.CreateKeyFrame(40);
    key->Translation(gz::math::Vector3d(0.0, 0.0, 0.0));
    key->Rotation(gz::math::Quaterniond(0, 0, 2 * PI));

    return anim;
  }
};
// Register this plugin with the simulator
GZ_ADD_PLUGIN(Obstacles, ::gz::sim::System, ::gz::sim::ISystemConfigure,
              ::gz::sim::ISystemPreUpdate)
GZ_ADD_PLUGIN_ALIAS(Obstacles, "obstacles")
} // namespace gazebo
