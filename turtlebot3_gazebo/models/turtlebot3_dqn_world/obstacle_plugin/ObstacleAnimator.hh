// Copyright 2024 Open Source Robotics Foundation
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

#pragma once

#include <gz/common/Animation.hh>
#include <gz/common/KeyFrame.hh>
#include <gz/sim/System.hh>
#include <gz/sim/components/PoseCmd.hh>

class ObstacleAnimator : public gz::sim::System,
                         public gz::sim::ISystemConfigure,
                         public gz::sim::ISystemPreUpdate {
public:
  ObstacleAnimator(gz::common::PoseAnimation _animator)
      : animator(std::move(_animator)) {}

  virtual void Configure(const gz::sim::Entity &_entity,
                         const std::shared_ptr<const sdf::Element> &,
                         gz::sim::EntityComponentManager &,
                         gz::sim::EventManager &) override {
    this->entity = _entity;
  }

  virtual void PreUpdate(const gz::sim::UpdateInfo &_info,
                         gz::sim::EntityComponentManager &_ecm) override {
    if (_info.paused)
      return;

    this->animator.Time(std::chrono::duration<double>(_info.simTime).count());
    gz::common::PoseKeyFrame keyFrame(0);
    this->animator.InterpolatedKeyFrame(keyFrame);
    gz::math::Pose3d newPose(keyFrame.Translation(), keyFrame.Rotation());
    _ecm.SetComponentData<gz::sim::components::WorldPoseCmd>(this->entity,
                                                             newPose);
  }

private:
  gz::sim::Entity entity;
  gz::common::PoseAnimation animator;
};
