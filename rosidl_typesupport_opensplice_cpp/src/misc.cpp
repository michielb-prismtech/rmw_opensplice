// Copyright 2017 Open Source Robotics Foundation, Inc.
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

#include <string>
#include "rosidl_typesupport_opensplice_cpp/misc.hpp"

namespace rosidl_typesupport_opensplice_cpp
{
static const char * const ros_topic_prefix = "rt";

bool
process_topic_name(
  const char * topic_name,
  bool avoid_ros_namespace_conventions,
  std::string & topic_str,
  std::string & partition_str)
{
  const std::string topic_name_ = topic_name;
  size_t pos;

  pos = topic_name_.find_last_of('/');

  partition_str.clear();
  if (!avoid_ros_namespace_conventions) {
    partition_str = ros_topic_prefix;
    if (0 != topic_name_.substr(0, pos).size()) {
      partition_str += '/';
    }
  }
  partition_str += topic_name_.substr(0, pos);
  topic_str = topic_name_.substr(pos + 1);

  return true;
}

}  // namespace rosidl_typesupport_opensplice_cpp
