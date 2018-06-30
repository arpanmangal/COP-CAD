# COP-CAD
## The Engineering Drawing Visualization and Design Tool

------------------------------------------------------------------------

<b>COP-CAD</b> is an out-of-the-box ready to use Engineering Drawing tool. The tool provides an easy-to-use and fast way for user to render any three dimensional object as wireframe and visualise its orthographic projections.
Also, given the three orthographic projections user can generate a wireframe to check the prototype of his/her model.
The tool also allows user to rotate the object with easy to use sliders, and view orthographic projections of the rotated object.<br>

The software expects the projection drawing or the three dimensional model to be input in the form of its vertex set and edge set.<br>

<small>Known issues : Extra coplanar edges when given only two projection views which are insufficient to determine a unique wireframe.
(When given only two views it returns the maximally connected wireframe that projects the given two views)</small><br>

### *Components*:
1. Source Code: `./`
2. Mathematical Model: `/doc/Mathematical_Model`  
3. UML Design: `/doc/UML_Design`
4. Documentation: `/doc/Documentation`

### *Running*:
```
$ qmake EnngDrawing.pro
$ make
$ bin/CopCAD
```
