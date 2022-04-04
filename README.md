# Soft Robot's Angle Measurement Program with OpenCV
***
This repository is associated with the research collaboration program between Imperial College London and Institut Teknologi Bandung in the field of `affordable medical devices` based on `soft robotics`.
***

## Introduction
In this work we present a soft continuum manipulator with two actuated DOFs: <br> 
1. Bending on an arbitrary plane (<i>&theta;</i>).
2. Rotation of the bending plane with respect to a fixed reference frame (<i>&gamma;</i>).

<p align="center">
<img
  src="https://github.com/tutla53/angle-measurement/blob/master/img/Robot_Two_DoF_2.jpg"
  alt="soft robot's angle"
  title="Soft Robot Measurement Setup"
  style="display: inline-block; margin: 0 auto; width: 400px">
</p>

Typically, bending angle (<i>&theta;</i>) and rotation of bending plane angle (<i>&gamma;</i>) are measured by attaching a sensor 
(e.g. [electromagnetic tracking](https://www.ndigital.com/technology/em-overview/))
at the tip of the continuum robot, usually called as proprioceptive sensor. However, that method still has several challenges including the installation of the sensor in the robot and also has an expensive price with costs ranging from $5000 - $150,000  <sup> [[1]](https://doi.org/10.1016/B978-0-12-381496-8.00001-9) </sup>.
And also, the instalment of the sensor could affect the stiffness of the robot, which is not desirable at the prototyping stage to get the optimum design of the robot.
Therefore, the use of a non-contact measurement type (e.g. camera) will resolve the problem of the proprioceptive sensor.

---

## Measurement Method
### 1. Bending Angle (<i>&theta;</i>)
### 2. Rotation of Bending Plane Angle (<i>&gamma;</i>)


