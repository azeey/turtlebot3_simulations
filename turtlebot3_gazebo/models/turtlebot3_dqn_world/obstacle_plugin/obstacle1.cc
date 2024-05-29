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

namespace gazebo {
class Obstacle1 : public ObstacleAnimator {
public:
  Obstacle1() : ObstacleAnimator(CreateAnimation()) {}

  gz::common::PoseAnimation CreateAnimation() {
    // create the animation
    // name the animation "move_1",
    // make it last 260 seconds,
    // and set it on a repeat loop
    gz::common::PoseAnimation anim("move1", 160.0, true);

    gz::common::PoseKeyFrame *key;

    // set starting location of the box
    key = anim.CreateKeyFrame(0);
    key->Translation(gz::math::Vector3d(0.0, 0.0, 0.0));
    key->Rotation(gz::math::Quaterniond(0, 0, 0));

    key = anim.CreateKeyFrame(10);
    key->Translation(gz::math::Vector3d(-0.5, -1.0, 0.0));
    key->Rotation(gz::math::Quaterniond(0, 0, 0));

    key = anim.CreateKeyFrame(50);
    key->Translation(gz::math::Vector3d(-3.5, -1.0, 0.0));
    key->Rotation(gz::math::Quaterniond(0, 0, 0));

    key = anim.CreateKeyFrame(70);
    key->Translation(gz::math::Vector3d(-3.7, -3.0, 0.0));
    key->Rotation(gz::math::Quaterniond(0, 0, 0));

    key = anim.CreateKeyFrame(90);
    key->Translation(gz::math::Vector3d(-3.5, -1.0, 0.0));
    key->Rotation(gz::math::Quaterniond(0, 0, 0));

    key = anim.CreateKeyFrame(130);
    key->Translation(gz::math::Vector3d(-0.5, -1.0, 0.0));
    key->Rotation(gz::math::Quaterniond(0, 0, 0));

    key = anim.CreateKeyFrame(140);
    key->Translation(gz::math::Vector3d(0.0, 0.0, 0.0));
    key->Rotation(gz::math::Quaterniond(0, 0, 0));

    key = anim.CreateKeyFrame(160);
    key->Translation(gz::math::Vector3d(0.0, 0.0, 0.0));
    key->Rotation(gz::math::Quaterniond(0, 0, 0));

    return anim;
  }
};
// Register this plugin with the simulator
GZ_ADD_PLUGIN(Obstacle1, ::gz::sim::System, ::gz::sim::ISystemConfigure,
              ::gz::sim::ISystemPreUpdate)
GZ_ADD_PLUGIN_ALIAS(Obstacle1, "obstacle1")
} // namespace gazebo
