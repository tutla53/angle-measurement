# Soft Robot Angle Measurement Program with OpenCV
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

In the medical application, the bending angle <i>(&theta;)</i> and the bending plane angle <i>(&gamma;)</i> can be measured by attaching a sensor (e.g. [electromagnetic tracking](https://www.ndigital.com/technology/em-overview/)) to the tip of the robot. It has good capabilities to localize and visualize the instrument as it's navigated through the various anatomical tracts. However, the sensor is relatively expensive in the early stage of development, with estimated costs ranging from $5000 - $150,000 <sup> [[1]](https://doi.org/10.1016/B978-0-12-381496-8.00001-9) </sup>, especially for lower and middle-income countries (LMIC). Therefore, this project will present affordable method to measure the angles of the robot by using the camera and `OpenCV`.

---

## Measurement Method
### 1. Bending Angle (<i>&theta;</i>)
### 2. Rotation of Bending Plane Angle (<i>&gamma;</i>)


