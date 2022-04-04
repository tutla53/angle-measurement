# Soft Robot Angle Measurement Program with OpenCV
***
This repository is associated with the research collaboration program between Imperial College London and Institut Teknologi Bandung in the field of `affordable medical devices` based on `soft robotics`.
***

## Introduction
In this work we present a soft continuum manipulator with two actuated DOFs: <br> 
1. Bending on an arbitrary plane <i>(&theta;)</i>.
2. Rotation of the bending plane with respect to a fixed reference frame <i>(&gamma;)</i> (see Fig. 1).

<p align="center">
<img
  src="https://github.com/tutla53/angle-measurement/blob/master/img/Robot_Two_DoF_2.jpg"
  alt="soft robot's angle"
  title="Soft Robot Measurement Setup"
  style="display: inline-block; margin: 0 auto; width: 400px"> <br>
  Fig. 1. Two DOFs of the soft manipulator prototype.
</p>

In the medical application, the bending angle <i>(&theta;)</i> and the bending plane angle <i>(&gamma;)</i> can be measured by attaching a sensor (e.g. [electromagnetic tracking](https://www.ndigital.com/technology/em-overview/)) to the tip of the robot. It has good capabilities to localize and visualize the instrument as it's navigated through the various anatomical tracts. However, the sensor is relatively expensive in the early stage of development, with estimated costs ranging from $5000 - $150,000 [^1], especially for lower and middle-income countries (LMIC). Therefore, this project will present affordable method to measure the angles of the robot by using the camera and `OpenCV`.

---

## Measurement Method
### 1. Bending Angle (<i>&theta;</i>)
### 2. Rotation of Bending Plane Angle (<i>&gamma;</i>)

---

## Measurement Setup
  <table align = "center">
  <tr>
    <th align="center">
      <img
        src="https://github.com/tutla53/angle-measurement/blob/master/img/Measurement%20Setup%20Concept.jpeg"
        alt="Measurement Setup - concept"
        title="Measurement Setup - concept"
        style="display: inline-block; margin: 0 auto; width: 375px">
    </th>
    <th align="center">
      <img
        src="https://github.com/tutla53/angle-measurement/blob/master/img/Measurement%20Setup.jpeg"
        alt="Measurement Setup"
        title="Measurement Setup"
        style="display: inline-block; margin: 0 auto; width: 400px">
     </th>
  </tr>
  <tr>
    <td align="center">
      (a)
    </td>
    <td align="center">
      (b)
     </td>
</tr>
  
  </table>
  
 <p align="center"> 
  Fig. 2. Measurement setup with GoPro Hero 5: (a) concept design and (b) prototype.
 </p>

---

## Result
<p align="center">
<img
  src="https://github.com/tutla53/angle-measurement/blob/master/img/result/P070_final.JPG"
  alt="Measurement Result"
  title="Measurement Result"
  style="display: inline-block; margin: 0 auto; width: 500px"> <br>
  Fig. 3. Measurement result of bending angle <i>(&theta;)</i>.
</p>

---

## Future Works


### Reference
[^1]: A. Menache, “1 - Motion Capture Primer,” in Understanding Motion Capture for Computer Animation (Second Edition), Second Edition., A. Menache, Ed. Boston: Morgan Kaufmann, 2011, pp. 1–46. doi: https://doi.org/10.1016/B978-0-12-381496-8.00001-9.

