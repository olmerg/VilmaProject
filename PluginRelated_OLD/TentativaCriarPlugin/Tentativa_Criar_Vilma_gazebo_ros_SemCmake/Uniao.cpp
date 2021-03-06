/*
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/


/*
has code from:
 raycar https://github.com/jwatte/ode-0.12
	programa demos/raycar/car.cpp
 VilmaPlugin de gazebo-1.4.0
	codigo VehiclePlugin.cc
 carworld  http://www.mindcontrol.org/~hplus/carworld.html
	programa mywheeledcar.cpp

*/
#include "physics/physics.hh"
#include "transport/transport.hh"
#include "VilmaPlugin.hh"

using namespace gazebo;
GZ_REGISTER_MODEL_PLUGIN(VilmaPlugin)

/////////////////////////////////////////////////
VilmaPlugin::VilmaPlugin()
{
  this->joints.resize(4);

  this->aeroLoad = 0.1;
  this->swayForce = 10;

  this->maxSpeed = 10;
  this->frontPower = 50;
  this->rearPower = 50;
  this->wheelRadius = 0.3;




  std::string name = "ros_model_plugin_node";
      int argc = 0;
      ros::init(argc, NULL, name);





}

/////// //////////////////////////////////////////
void VilmaPlugin::Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
{
  this->model = _model;




  this->node1 = new ros::NodeHandle("~");
  this->sub = this->node1->subscribe<std_msgs::Float64>("x", 1000, &VilmaPlugin::ROSCallback, this );
  this->updateConnection = event::Events::ConnectWorldUpdateStart(
          boost::bind(&VilmaPlugin::OnUpdate, this));




  // this->physics = this->model->GetWorld()->GetPhysicsEngine();
//TODO: look if this is neccesary
//http://ode-wiki.org/wiki/index.php?title=FAQ#I.27ve_made_a_car.2C_but_the_wheels_don.27t_stay_on_properly.21

  this->joints[0] = this->model->GetJoint(_sdf->GetValueString("front_left"));
  this->joints[1] = this->model->GetJoint(_sdf->GetValueString("front_right"));
  this->joints[2] = this->model->GetJoint(_sdf->GetValueString("back_left"));
  this->joints[3] = this->model->GetJoint(_sdf->GetValueString("back_right"));

//http://www.ode.org/ode-0.5-userguide.html#sec_3_7_0
  this->joints[0]->SetAttribute("suspension_erp", 0, 0.15);
  this->joints[0]->SetAttribute("suspension_cfm", 0, 0.04);

  this->joints[1]->SetAttribute("suspension_erp", 0, 0.15);
  this->joints[1]->SetAttribute("suspension_cfm", 0, 0.04);

  this->joints[2]->SetAttribute("suspension_erp", 0, 0.15);
  this->joints[2]->SetAttribute("suspension_cfm", 0, 0.04);

  this->joints[3]->SetAttribute("suspension_erp", 0, 0.15);
  this->joints[3]->SetAttribute("suspension_cfm", 0, 0.04);

  this->gasJoint = this->model->GetJoint(_sdf->GetValueString("gas"));
  this->brakeJoint = this->model->GetJoint(_sdf->GetValueString("brake"));
  this->steeringJoint = this->model->GetJoint(_sdf->GetValueString("steering"));

  if (!this->gasJoint)
  {
    gzerr << "Unable to find gas joint["
          << _sdf->GetValueString("gas") << "]\n";
    return;
  }

  if (!this->steeringJoint)
  {
    gzerr << "Unable to find steering joint["
          << _sdf->GetValueString("steering") << "]\n";
    return;
  }

  if (!this->joints[0])
  {
    gzerr << "Unable to find front_left joint["
          << _sdf->GetElement("front_left") << "]\n";
    return;
  }

  if (!this->joints[1])
  {
    gzerr << "Unable to find front_right joint["
          << _sdf->GetElement("front_right") << "]\n";
    return;
  }

  if (!this->joints[2])
  {
    gzerr << "Unable to find back_left joint["
          << _sdf->GetElement("back_left") << "]\n";
    return;
  }

  if (!this->joints[3])
  {
    gzerr << "Unable to find back_right joint["
          << _sdf->GetElement("back_right") << "]\n";
    return;
  }

  this->maxSpeed = _sdf->GetValueDouble("max_speed");
  this->aeroLoad = _sdf->GetValueDouble("aero_load");
  this->tireAngleRange = _sdf->GetValueDouble("tire_angle_range");
  this->frontPower = _sdf->GetValueDouble("front_power");
  this->rearPower = _sdf->GetValueDouble("rear_power");

  this->connections.push_back(event::Events::ConnectWorldUpdateStart(
          boost::bind(&VilmaPlugin::OnUpdate, this)));

  this->node = transport::NodePtr(new transport::Node());
  this->node->Init(this->model->GetWorld()->GetName());

  this->velSub = this->node->Subscribe(std::string("~/") +
      this->model->GetName() + "/vel_cmd", &VilmaPlugin::OnVelMsg, this);
}

/////////////////////////////////////////////////
void VilmaPlugin::Init()
{
  this->chassis = this->joints[0]->GetParent();

  // This assumes that the largest dimension of the wheel is the diameter
  physics::EntityPtr parent = boost::shared_dynamic_cast<physics::Entity>(
      this->joints[0]->GetChild());
  math::Box bb = parent->GetBoundingBox();
  this->wheelRadius = bb.GetSize().GetMax() * 0.5;

  // The total range the steering wheel can rotate
  double steeringRange = this->steeringJoint->GetHighStop(0).Radian() -
                         this->steeringJoint->GetLowStop(0).Radian();

  // Compute the angle ratio between the steering wheel and the tires
//  this->steeringRatio = steeringRange / this->tireAngleRange;
  this->steeringRatio =16;

  // Maximum gas is the upper limit of the gas joint
  this->maxGas = this->gasJoint->GetHighStop(0).Radian();

  // Maximum brake is the upper limit of the gas joint
  this->maxBrake = this->gasJoint->GetHighStop(0).Radian();

  printf("SteeringRation[%f] MaxGa[%f]\n", this->steeringRatio, this->maxGas);
}

/////////////////////////////////////////////////


void VilmaPlugin::OnUpdate()
{


    ros::spinOnce();





  // Get the normalized gas and brake amount
  double gas = this->gasJoint->GetAngle(0).Radian() / this->maxGas;
  double brake = this->brakeJoint->GetAngle(0).Radian() / this->maxBrake;

  // A little force to push back on the pedals
  this->gasJoint->SetForce(0, -0.1);
  this->brakeJoint->SetForce(0, -0.1);
  //hysteres a los pedales ???? https://github.com/jwatte/ode-0.12/blob/master/demos/raycar/car.cpp linha 226


  // Get the steering angle




// ojo aca simular la dinamica del steering
/*de acuerdo al PID de gazebo-1.4 podemos intertar algo asi
  common::Time currTime = this->model->GetWorld()->GetSimTime();
  common::Time stepTime = currTime - this->prevUpdateTime;
  this->prevUpdateTime = currTime;

 if (stepTime > 0)
  {
    physics::JointWrench jw = this->steeringJoint->GetForceTorque(0);
    gzdbg
          << "] joint [" << this->steeringJoint->GetName()
          << "] b1f [" << jw.body1Force
          << "] b1t [" << jw.body1Torque
          << "] b2f [" << jw.body2Force
          << "] b2t [" << jw.body2Torque
          << "] link1f [" << this->steeringJoint->GetLinkForce(0)
          << "] link1t [" << this->steeringJoint->GetLinkTorque(0)
          << "] link2f [" << this->steeringJoint->GetLinkForce(1)
          << "] link2t [" << this->steeringJoint->GetLinkTorque(1)
          << "]\n";
		TODO: cual de estos meto????????????
	torquedeentrada=this->steeringJoint->GetForce(0);
	SteeringAngle = update sistemadinamico(torquedeentrada,stepTime);

}
*/
  double steeringAngle = this->steeringJoint->GetAngle(0).Radian();
////

  // Compute the angle of the front wheels.
  double wheelAngle = steeringAngle / this->steeringRatio;

  // double idleSpeed = 0.5;

  // Compute the rotational velocity of the wheels
  double jointVel = (std::max(0.0, gas-brake) * this->maxSpeed) /
                    this->wheelRadius;

  // Set velocity and max force for each wheel
  this->joints[0]->SetVelocity(1, -jointVel);
  this->joints[0]->SetMaxForce(1, (gas + brake) * this->frontPower);

  this->joints[1]->SetVelocity(1, -jointVel);
  this->joints[1]->SetMaxForce(1, (gas + brake) * this->frontPower);

  this->joints[2]->SetVelocity(1, -jointVel);
  this->joints[2]->SetMaxForce(1, (gas + brake) * this->rearPower);

  this->joints[3]->SetVelocity(1, -jointVel);
  this->joints[3]->SetMaxForce(1, (gas + brake) * this->rearPower);

  // Set the front-left wheel angle
  this->joints[0]->SetLowStop(0, wheelAngle);
  this->joints[0]->SetHighStop(0, wheelAngle);
  this->joints[0]->SetLowStop(0, wheelAngle);
  this->joints[0]->SetHighStop(0, wheelAngle);

  // Set the front-right wheel angle
  this->joints[1]->SetHighStop(0, wheelAngle);
  this->joints[1]->SetLowStop(0, wheelAngle);
  this->joints[1]->SetHighStop(0, wheelAngle);
  this->joints[1]->SetLowStop(0, wheelAngle);

  // Get the current velocity of the car
  this->velocity = this->chassis->GetWorldLinearVel();

  //  aerodynamics
  this->chassis->AddForce(
      math::Vector3(0, 0, this->aeroLoad * this->velocity.GetSquaredLength()));

  // Sway bars  //http://ode-wiki.org/wiki/index.php?title=HOWTO_4_wheel_vehicle
  math::Vector3 bodyPoint;
  math::Vector3 hingePoint;
  math::Vector3 axis;

  double displacement;

  for (int ix = 0; ix < 4; ++ix)
  {
    hingePoint = this->joints[ix]->GetAnchor(0);
    bodyPoint = this->joints[ix]->GetAnchor(1);

    axis = this->joints[ix]->GetGlobalAxis(0).Round();
    displacement = (bodyPoint - hingePoint).Dot(axis);

    float amt = displacement * this->swayForce;
    if (displacement > 0)
    {
      if (amt > 15)
        amt = 15;

      math::Pose p = this->joints[ix]->GetChild()->GetWorldPose();
      this->joints[ix]->GetChild()->AddForce(axis * -amt);
      this->chassis->AddForceAtWorldPosition(axis * amt, p.pos);

      p = this->joints[ix^1]->GetChild()->GetWorldPose();
      this->joints[ix^1]->GetChild()->AddForce(axis * amt);
      this->chassis->AddForceAtWorldPosition(axis * -amt, p.pos);
    }
  }
}

/////////////////////////////////////////////////
void VilmaPlugin::OnVelMsg(ConstPosePtr &/*_msg*/)
{
}

