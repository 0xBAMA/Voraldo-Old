#version 450 core

in  vec4 color;
out vec4 fColor;

void main()
{

	//use gl_PointCoord used to find distance from the upper left corner of the point primitive

  fColor = color;

}
