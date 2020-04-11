#include "../voraldo/V4.h"

using std::cout;
using std::endl;

#define VORALDO_DEBUG false


Voraldo::Voraldo()
{

	data = NULL;  //declare with an empty block
//call Voraldo::init_block(int x, int y, int z) to populate it
}

Voraldo::~Voraldo()
{
	cout << "deleting block" << endl;
	delete[] data;
}

void Voraldo::init_block(int x, int y, int z, bool noise_fill)
{
	if(data != NULL)
	{
		delete[] data;
	}

	RGB black = {0,0,0};
	name_to_RGB_map["black"] = black;

	RGB dark_dark_grey = {12,12,12};
	name_to_RGB_map["dark_dark_grey"] = dark_dark_grey;

	RGB dark_grey = {24,24,24};
	name_to_RGB_map["dark_grey"] = dark_grey;

	RGB medium_grey = {128,128,128};
	name_to_RGB_map["medium_grey"] = medium_grey;

	RGB light_grey = {240,240,240};
	name_to_RGB_map["light_grey"] = light_grey;

	RGB white = {255,255,255};
	name_to_RGB_map["white"] = white;

	RGB bright_red = {255,0,0};
	name_to_RGB_map["bright_red"] = bright_red;

	RGB red = {196,0,0};
	name_to_RGB_map["red"] = red;

	RGB medium_red = {128,0,0};
	name_to_RGB_map["medium_red"] = medium_red;

	RGB bright_green = {0,255,0};
	name_to_RGB_map["bright_green"] = bright_green;

	RGB bright_blue = {0,0,255};
	name_to_RGB_map["bright_blue"] = bright_blue;

	RGB bright_cyan = {0,255,255};
	name_to_RGB_map["bright_cyan"] = bright_cyan;

	RGB bright_magenta = {255,0,255};
	name_to_RGB_map["bright_magenta"] = bright_magenta;

	RGB bright_yellow = {255,255,0};
	name_to_RGB_map["bright_yellow"] = bright_yellow;

	RGB maroon = {128,0,0};
	name_to_RGB_map["maroon"] = maroon;

	RGB olive = {128,128,0};
	name_to_RGB_map["olive"] = olive;

	RGB green = {0,128,0};
	name_to_RGB_map["green"] = green;

	RGB purple = {128,0,128};
	name_to_RGB_map["purple"] = purple;

	RGB teal = {0,128,128};
	name_to_RGB_map["teal"] = teal;

	RGB navy = {0,0,128};
	name_to_RGB_map["navy"] = navy;

	RGB coral = {255,127,80};
	name_to_RGB_map["coral"] = coral;

	RGB tomato = {255,99,71};
	name_to_RGB_map["tomato"] = tomato;

	RGB salmon = {250,128,114};
	name_to_RGB_map["salmon"] = salmon;

	RGB orange = {255,165,0};
	name_to_RGB_map["orange"] = orange;

	RGB dark_orange = {135,66,0};
	name_to_RGB_map["dark_orange"] = dark_orange;

	RGB gold = {255,215,0};
	name_to_RGB_map["gold"] = gold;

//Dawnbringer 16 color palette
	//http://pixeljoint.com/forum/forum_posts.asp?TID=12795

	RGB Dawnbringer00 = {20, 12, 28};
	name_to_RGB_map["Dawnbringer00"] = Dawnbringer00;
	RGB Dawnbringer01 = {68, 36, 52};
	name_to_RGB_map["Dawnbringer01"] = Dawnbringer01;
	RGB Dawnbringer02 = {48, 52, 109};
	name_to_RGB_map["Dawnbringer02"] = Dawnbringer02;
	RGB Dawnbringer03 = {78, 74, 78};
	name_to_RGB_map["Dawnbringer03"] = Dawnbringer03;
	RGB Dawnbringer04 = {133, 76, 48};
	name_to_RGB_map["Dawnbringer04"] = Dawnbringer04;
	RGB Dawnbringer05 = {52, 101, 36};
	name_to_RGB_map["Dawnbringer05"] = Dawnbringer05;
	RGB Dawnbringer06 = {208, 70, 72};
	name_to_RGB_map["Dawnbringer06"] = Dawnbringer06;
	RGB Dawnbringer07 = {117, 113, 97};
	name_to_RGB_map["Dawnbringer07"] = Dawnbringer07;
	RGB Dawnbringer08 = {89, 125, 206};
	name_to_RGB_map["Dawnbringer08"] = Dawnbringer08;
	RGB Dawnbringer09 = {210, 125, 44};
	name_to_RGB_map["Dawnbringer09"] = Dawnbringer09;
	RGB Dawnbringer10 = {133, 149, 161};
	name_to_RGB_map["Dawnbringer10"] = Dawnbringer10;
	RGB Dawnbringer11 = {109, 170, 44};
	name_to_RGB_map["Dawnbringer11"] = Dawnbringer11;
	RGB Dawnbringer12 = {210, 170, 153};
	name_to_RGB_map["Dawnbringer12"] = Dawnbringer12;
	RGB Dawnbringer13 = {109, 194, 202};
	name_to_RGB_map["Dawnbringer13"] = Dawnbringer13;
	RGB Dawnbringer14 = {218, 212, 94};
	name_to_RGB_map["Dawnbringer14"] = Dawnbringer14;
	RGB Dawnbringer15 = {222, 238, 214};
	name_to_RGB_map["Dawnbringer15"] = Dawnbringer15;



//Voxel types begin here

	//states - limited number for now

	//	0 - empty - black
	//	1 - armor - dark grey
	//	2 - frame - dark orange
	//	3 - hull - olive
	//	4 - electrical - gold
	//	5 - red light - bright red
	//	6 - space gas
	if(VORALDO_DEBUG)
		cout << "bing" << endl;

	Vox empty;
	empty.mask = false;
	empty.color = name_to_RGB_map.at("black");
	empty.alpha = 0.0;
	empty.size = 0;
	empty.state = 0;

	name_to_Vox_map["empty"] = empty;

	Vox armor_0;
	armor_0.mask = false;
	armor_0.color = name_to_RGB_map.at("dark_grey");
	armor_0.alpha = 1.0;
	armor_0.size = 1;
	armor_0.state = 1;

	name_to_Vox_map["armor_0"] = armor_0;

	Vox armor_1;
	armor_1.mask = false;
	armor_1.color = name_to_RGB_map.at("medium_grey");
	armor_1.alpha = 1.0;
	armor_1.size = 1;
	armor_1.state = 1;

	name_to_Vox_map["armor_1"] = armor_1;

	Vox frame;
	frame.mask = false;
	frame.color = name_to_RGB_map.at("dark_orange");
	frame.alpha = 1.0;
	frame.size = 2;
	frame.state = 2;

	name_to_Vox_map["frame"] = frame;

	Vox hull;
	hull.mask = false;
	hull.color = name_to_RGB_map.at("olive");
	hull.alpha = 1.0;
	hull.size = 2;
	hull.state = 3;

	name_to_Vox_map["hull"] = hull;

	Vox electrical;
	electrical.mask = false;
	electrical.color = name_to_RGB_map.at("gold");
	electrical.alpha = 0.87;
	electrical.size = 2;
	electrical.state = 4;

	name_to_Vox_map["electrical"] = electrical;

	Vox diff;
	diff.mask = false;
	diff.color = name_to_RGB_map.at("gold");
	diff.alpha = 0.87;
	diff.size = 2;
	diff.state = 4;

	name_to_Vox_map["diff"] = diff;

	Vox red_light;
	red_light.mask = false;
	red_light.color = name_to_RGB_map.at("bright_red");
	red_light.alpha = 0.9;
	red_light.size = 2;
	red_light.state = 5;

	name_to_Vox_map["red_light"] = red_light;

	Vox red_light_big;
	red_light_big.mask = false;
	red_light_big.color = name_to_RGB_map.at("bright_red");
	red_light_big.alpha = 0.9;
	red_light_big.size = 3;
	red_light_big.state = 5;

	name_to_Vox_map["red_light_big"] = red_light_big;

	Vox green_light;
	green_light.mask = false;
	green_light.color = name_to_RGB_map.at("bright_green");
	green_light.alpha = 0.9;
	green_light.size = 2;
	green_light.state = 5;

	name_to_Vox_map["green_light"] = green_light;

	Vox blue_light;
	blue_light.mask = false;
	blue_light.color = name_to_RGB_map.at("bright_blue");
	blue_light.alpha = 0.9;
	blue_light.size = 2;
	blue_light.state = 5;

	name_to_Vox_map["blue_light"] = blue_light;

	Vox red_light_clear;
	red_light_clear.mask = false;
	red_light_clear.color = name_to_RGB_map.at("bright_red");
	red_light_clear.alpha = 0.18;
	red_light_clear.size = 2;
	red_light_clear.state = 5;

	name_to_Vox_map["red_light_clear"] = red_light_clear;

	Vox green_light_clear;
	green_light_clear.mask = false;
	green_light_clear.color = name_to_RGB_map.at("bright_green");
	green_light_clear.alpha = 0.18;
	green_light_clear.size = 2;
	green_light_clear.state = 5;

	name_to_Vox_map["green_light_clear"] = green_light_clear;

	Vox blue_light_clear;
	blue_light_clear.mask = false;
	blue_light_clear.color = name_to_RGB_map.at("bright_blue");
	blue_light_clear.alpha = 0.18;
	blue_light_clear.size = 2;
	blue_light_clear.state = 5;

	name_to_Vox_map["blue_light_clear"] = blue_light_clear;

	Vox solid_black;
	solid_black.mask = false;
	solid_black.color = name_to_RGB_map.at("black");
	solid_black.alpha = 1.0;
	solid_black.size = 2;
	solid_black.state = 5;

	name_to_Vox_map["solid_black"] = solid_black;

	Vox clear_blue_glass;
	clear_blue_glass.mask = false;
	clear_blue_glass.color = name_to_RGB_map.at("teal");
	clear_blue_glass.alpha = 0.02;
	clear_blue_glass.size = 2;
	clear_blue_glass.state = 5;

	name_to_Vox_map["clear_blue_glass"] = clear_blue_glass;


	Vox space_gas_solid;
	space_gas_solid.mask = false;
	space_gas_solid.color = name_to_RGB_map.at("dark_grey");
	space_gas_solid.alpha = 1.0;
	space_gas_solid.size = 1;
	space_gas_solid.state = 6;

	name_to_Vox_map["space_gas_solid"] = space_gas_solid;



	Vox space_gas_0;
	space_gas_0.mask = false;
	space_gas_0.color = name_to_RGB_map.at("dark_grey");
	space_gas_0.alpha = 0.3;
	space_gas_0.size = 1;
	space_gas_0.state = 6;

	name_to_Vox_map["space_gas_0"] = space_gas_0;

	Vox space_gas_1;
	space_gas_1.mask = false;
	space_gas_1.color = name_to_RGB_map.at("medium_grey");
	space_gas_1.alpha = 0.3;
	space_gas_1.size = 1;
	space_gas_1.state = 6;

	name_to_Vox_map["space_gas_1"] = space_gas_1;

	Vox space_gas_2;
	space_gas_2.mask = false;
	space_gas_2.color = name_to_RGB_map.at("light_grey");
	space_gas_2.alpha = 0.3;
	space_gas_2.size = 1;
	space_gas_2.state = 6;

	name_to_Vox_map["space_gas_2"] = space_gas_2;

	Vox space_gas_3;
	space_gas_3.mask = false;
	space_gas_3.color = name_to_RGB_map.at("dark_grey");
	space_gas_3.alpha = 0.3;
	space_gas_3.size = 2;
	space_gas_3.state = 6;

	name_to_Vox_map["space_gas_3"] = space_gas_3;

	Vox space_gas_4;
	space_gas_4.mask = false;
	space_gas_4.color = name_to_RGB_map.at("medium_grey");
	space_gas_4.alpha = 0.3;
	space_gas_4.size = 2;
	space_gas_4.state = 6;

	name_to_Vox_map["space_gas_4"] = space_gas_4;

	Vox space_gas_5;
	space_gas_5.mask = false;
	space_gas_5.color = name_to_RGB_map.at("gold");
	space_gas_5.alpha = 0.11;
	space_gas_5.size = 2;
	space_gas_5.state = 6;

	name_to_Vox_map["space_gas_5"] = space_gas_5;

	Vox engine_block;
	engine_block.mask = false;
	engine_block.color = name_to_RGB_map.at("dark_grey");
	engine_block.alpha = 1.0;
	engine_block.size = 2;
	engine_block.state = 6;

	name_to_Vox_map["engine_block"] = engine_block;

	Vox body_light;
	body_light.mask = false;
	body_light.color = name_to_RGB_map.at("bright_red");
	body_light.alpha = 1.0;
	body_light.size = 2;
	body_light.state = 6;

	name_to_Vox_map["body_light"] = body_light;

	Vox body;
	body.mask = false;
	body.color = name_to_RGB_map.at("red");
	body.alpha = 1.0;
	body.size = 2;
	body.state = 6;

	name_to_Vox_map["body"] = body;

	Vox body_dark;
	body_dark.mask = false;
	body_dark.color = name_to_RGB_map.at("medium_red");
	body_dark.alpha = 1.0;
	body_dark.size = 2;
	body_dark.state = 6;

	name_to_Vox_map["body_dark"] = body_dark;

	x_res = x;
	y_res = y;
	z_res = z;

	num_cells = x_res * y_res * z_res;

	data = new Vox[num_cells];

	for(int i = 0; i < num_cells; i++)
	{ //initialize array

		if(!noise_fill)
		{
			data[i] = name_to_Vox_map.at("empty");
		}
		else
		{
			//this makes nice noise, it's inspired by something from the first iteration.
			int randcheck = std::rand()%696;
			if(randcheck == 69)
			{

				int s = rand()%256;
				switch(s)
				{
					case 0:
						data[i] = name_to_Vox_map.at("space_gas_0");
						break;
					case 1:
						data[i] = name_to_Vox_map.at("space_gas_1");
						break;
					case 2:
						data[i] = name_to_Vox_map.at("space_gas_2");
						break;
					case 3:
						data[i] = name_to_Vox_map.at("space_gas_3");
						break;
					case 4:
						data[i] = name_to_Vox_map.at("space_gas_4");
						break;
					case 5:
						data[i] = name_to_Vox_map.at("space_gas_5");
						break;
					default:
						break;
				}
			}
		}
	}
}

//draw at point
void Voraldo::draw_point(vec point, Vox set)
{
	set_data_by_3D_index(point[0],point[1],point[2],set);
}

//draw along 3 dimensional line segment
void Voraldo::draw_line_segment(vec v1, vec v2, Vox set)
{
	vec starting_point = v1;
	vec current_point = starting_point;
	vec line_vector = (v2-v1);

	int length = std::floor(linalg::length(line_vector));

	for(int i = 0; i < length; i++)
	{
		current_point[0] = starting_point[0] + i*(line_vector[0]/length);
		current_point[1] = starting_point[1] + i*(line_vector[1]/length);
		current_point[2] = starting_point[2] + i*(line_vector[2]/length);
		draw_point(current_point,set);
	}
}

//draw 3 dimensional triangle, with verticies  v0,  v1,  v2
void Voraldo::draw_triangle(vec v0, vec v1, vec v2, Vox set)
{
	//point zero is the origin point

	vec side1 = v1-v0;
	vec side2 = v2-v0;

	vec c1(0,0,0);
	vec c2(0,0,0);

	double length;

	if(linalg::length(side1) > linalg::length(side2))
	{
		length = std::floor(linalg::length(side1));
	}
	else
	{
		length = std::floor(linalg::length(side2));
	}

	if(length <= 2){
		draw_point(v0,set);
		draw_point(v1,set);
		draw_point(v2,set);
	}else{

		side1 = side1/length;
		side2 = side2/length;

		for(int i = 0; i < length; i++)
		{
			c1[0] = v0[0] + i*side1[0];
			c1[1] = v0[1] + i*side1[1];
			c1[2] = v0[2] + i*side1[2];

			c2[0] = v0[0] + i*side2[0];
			c2[1] = v0[1] + i*side2[1];
			c2[2] = v0[2] + i*side2[2];

			draw_line_segment(c1,c2,set);
		}
	}
}

//draw sphere - centered at center_point, of radius radius
void Voraldo::draw_sphere(vec center_point, double radius, Vox set)
{
	for(int i = 0; i < get_x_res(); i++)
	{
		for(int j = 0; j < get_y_res(); j++)
		{
			for(int k = 0; k < get_z_res(); k++)
			{
				double testx = (i-center_point[0])*(i-center_point[0]);	//apply offsets and square
				double testy = (j-center_point[1])*(j-center_point[1]);
				double testz = (k-center_point[2])*(k-center_point[2]);

				if((testx + testy + testz) < radius*radius)
				{	//pretty self explainatory, equation of sphere
					set_data_by_3D_index(i,j,k,set);
				}
			}
		}
	}
}

//draw ellipsoid - centered at center_point, radii in radii
void Voraldo::draw_ellipsoid(vec center_point, vec radii, Vox set)
{
	for(int i = 0; i < get_x_res(); i++)
	{
		for(int j = 0; j < get_y_res(); j++)
		{
			for(int k = 0; k < get_z_res(); k++)
			{
				double testx = (i-center_point[0])*(i-center_point[0]);	//apply offsets and square
				double testy = (j-center_point[1])*(j-center_point[1]);
				double testz = (k-center_point[2])*(k-center_point[2]);

				double radx = radii[0]*radii[0];
				double rady = radii[1]*radii[1];
				double radz = radii[2]*radii[2];

				double result = testx/radx + testy/rady + testz/radz;

				if(result <= 1){	//point inside ellipsoid - do we want to be able to invert this?
					//(outside, or on the surface, with >= and ==, respectively)
					set_data_by_3D_index(i,j,k,set);
				}
			}
		}
	}
}

//draw cylinder - bvec and tvec establish the endpoints, by center, and radius is the radius
void Voraldo::draw_cylinder(vec bvec, vec tvec, double radius, Vox set)
{
	vec ndirection = tvec - bvec;

	auto bx0 = bvec[0]; auto ba = ndirection[0];	auto tx0 = tvec[0]; auto ta = ndirection[0];
	auto by0 = bvec[1]; auto bb = ndirection[1];	auto ty0 = tvec[1]; auto tb = ndirection[1];
	auto bz0 = bvec[2]; auto bc = ndirection[2];	auto tz0 = tvec[2]; auto tc = ndirection[2];

	//I did this on a whiteboard

	double bplanetest = 0.0;
	double tplanetest = 0.0;

	double point_to_line_distance = 0.0;

	for(int i = 0; i < get_x_res(); i++){
		for(int j = 0; j < get_y_res(); j++){
			for(int k = 0; k < get_z_res(); k++){
				//planetests
				bplanetest = ba * (i - bx0) + bb * (j - by0) + bc * (k - bz0);
				tplanetest = ta * (i - tx0) + tb * (j - ty0) + tc * (k - tz0);

				//using the basic equation for a plane, we can do an interesting test

				//These variables will be greater than zero if the test point is on the side of the plane
				//that the normal vector is pointing towards, and less than zero if the test point is on
				//the side of the plane that the normal vector is not pointing towards. That is to say, in
				//my case - bplanetest tells me whether the point is above the bottom plane, and tplanetest
				//tells me whether the point is above the top plane. If it is above the bottom, and below
				//the top - we are within the ends of the cylinder, and can proceed. Thus, the condition
				//for the following if statement:

				if(bplanetest >= 0 && tplanetest <= 0){
					//do the point to line distance thing
					//algorithm from http://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html

					//This test takes as a precondition that the point is determined to be within the slice
					//of space established by two parallel planes. Now that this is known, we will see how
					//far they are from the line, which runs perpendicular to both planes. If both of these
					//sequential tests evaluate positively, we know we are within the extents of the cylinder.

					point_to_line_distance = linalg::length(cross(tvec-bvec,bvec-vec(i,j,k)))/linalg::length(tvec-bvec);
					if(point_to_line_distance <= radius){
						set_data_by_3D_index(i,j,k,set);
					}
				}
			}
		}
	}
}

//draw tube - just like a cylinder, but with an inner radius that will establish thickness
void Voraldo::draw_tube(vec bvec, vec tvec, double inner_radius, double outer_radius, Vox set)
{
	vec ndirection = tvec - bvec;

	auto bx0 = bvec[0]; auto ba = ndirection[0];	auto tx0 = tvec[0]; auto ta = ndirection[0];
	auto by0 = bvec[1]; auto bb = ndirection[1];	auto ty0 = tvec[1]; auto tb = ndirection[1];
	auto bz0 = bvec[2]; auto bc = ndirection[2];	auto tz0 = tvec[2]; auto tc = ndirection[2];

	//I did this on a whiteboard

	double bplanetest = 0.0;
	double tplanetest = 0.0;

	double point_to_line_distance = 0.0;

	for(int i = 0; i < get_x_res(); i++){
		for(int j = 0; j < get_y_res(); j++){
			for(int k = 0; k < get_z_res(); k++){
				//planetests
				bplanetest = ba * (i - bx0) + bb * (j - by0) + bc * (k - bz0);
				tplanetest = ta * (i - tx0) + tb * (j - ty0) + tc * (k - tz0);

				//using the basic equation for a plane, we can do an interesting test

				//These variables will be greater than zero if the test point is on the side of the plane
				//that the normal vector is pointing towards, and less than zero if the test point is on
				//the side of the plane that the normal vector is not pointing towards. That is to say, in
				//my case - bplanetest tells me whether the point is above the bottom plane, and tplanetest
				//tells me whether the point is above the top plane. If it is above the bottom, and below
				//the top - we are within the ends of the cylinder, and can proceed. Thus, the condition
				//for the following if statement:

				if(bplanetest >= 0 && tplanetest <= 0){
					//do the point to line distance thing
					//algorithm from http://mathworld.wolfram.com/Point-LineDistance3-Dimensional.html

					//This test takes as a precondition that the point is determined to be within the slice
					//of space established by two parallel planes. Now that this is known, we will see how
					//far they are from the line, which runs perpendicular to both planes. If both of these
					//sequential tests evaluate positively, we know we are within the extents of the cylinder.

					point_to_line_distance = linalg::length(cross(tvec-bvec,bvec-vec(i,j,k)))/linalg::length(tvec-bvec);

					if(point_to_line_distance <= outer_radius && point_to_line_distance >= inner_radius){
						set_data_by_3D_index(i,j,k,set);
					}
				}
			}
		}
	}

}

//draw blockoid - draw all voxels within the axis-aligned block defined by mindex and maxdex
void Voraldo::draw_blockoid(vec mindex, vec maxdex, Vox set)
{
	for(int i = 0; i < get_x_res(); i++)
	{
		for(int j = 0; j < get_y_res(); j++)
		{
			for(int k = 0; k < get_z_res(); k++)
			{

				bool xtest = i <= maxdex[0] && i >= mindex[0];
				bool ytest = j <= maxdex[1] && j >= mindex[1];
				bool ztest = k <= maxdex[2] && k >= mindex[2];

				if(xtest && ytest && ztest){
					set_data_by_3D_index(i,j,k,set);
				}
			}
		}
	}
}

//draw quadrilateral hexahedron - fill the space defined by 8 points - refer to docs
void Voraldo::draw_quadrilateral_hexahedron(vec a, vec b, vec c, vec d, vec e, vec f, vec g, vec h, Vox set)
{
	vec center = a + b + c + d + e + f + g + h;
	center = vec(center[0]/8, center[1]/8, center[2]/8);

	bool plusx1 = false;
	bool plusx2 = false;

//    888   Y88b  /
//  __888__  Y88b/
//    888     Y88b
//    888     /Y88b
//           /  Y88b

	//CDGH

	//TRIANGLES ARE CDH, CGH

	vec plusx_side1 = vec(c[0]-d[0],c[1]-d[1],c[2]-d[2]);
	vec plusx_side2 = vec(h[0]-d[0],h[1]-d[1],h[2]-d[2]);

	vec plusx_side3 = vec(c[0]-g[0],c[1]-g[1],c[2]-g[2]);
	vec plusx_side4 = vec(h[0]-g[0],h[1]-g[1],h[2]-g[2]);

	vec plusx_planevec1 = cross(plusx_side1,plusx_side2);
	vec plusx_planept1 = d;

	vec plusx_planevec2 = cross(plusx_side3,plusx_side4);
	vec plusx_planept2 = g;

	if(!planetest(plusx_planept1,plusx_planevec1,center))
	{	//if the center fails the plane test, flip the normal
		plusx_planevec1 = vec(-1*plusx_planevec1[0],-1*plusx_planevec1[1],-1*plusx_planevec1[2]);
	}

	if(!planetest(plusx_planept2,plusx_planevec2,center))
	{	//if the center fails the plane test, flip the normal
		plusx_planevec2 = vec(-1*plusx_planevec2[0],-1*plusx_planevec2[1],-1*plusx_planevec2[2]);
	}

//-------------------------------------------


	bool minusx1 = false;
	bool minusx2 = false;

//       Y88b  /
//  ____  Y88b/
//         Y88b
//         /Y88b
//        /  Y88b

	//ABEF

	//TRIANGLES ARE ABF, AEF

	vec minusx_side1 = vec(a[0]-b[0],a[1]-b[1],a[2]-b[2]);
	vec minusx_side2 = vec(f[0]-b[0],f[1]-b[1],f[2]-b[2]);

	vec minusx_side3 = vec(a[0]-e[0],a[1]-e[1],a[2]-e[2]);
	vec minusx_side4 = vec(f[0]-e[0],f[1]-e[1],f[2]-e[2]);

	vec minusx_planevec1 = cross(minusx_side1,minusx_side2);
	vec minusx_planept1 = b;

	vec minusx_planevec2 = cross(minusx_side3,minusx_side4);
	vec minusx_planept2 = e;

	if(!planetest(minusx_planept1,minusx_planevec1,center))
	{	//if the center fails the plane test, flip the normal
		minusx_planevec1 = vec(-1*minusx_planevec1[0],-1*minusx_planevec1[1],-1*minusx_planevec1[2]);
	}

	if(!planetest(minusx_planept2,minusx_planevec2,center))
	{	//if the center fails the plane test, flip the normal
		minusx_planevec2 = vec(-1*minusx_planevec2[0],-1*minusx_planevec2[1],-1*minusx_planevec2[2]);
	}

//-------------------------------------------


	bool plusy1 = false;
	bool plusy2 = false;

//    888   Y88b  /
//  __888__  Y888/
//    888     Y8/
//    888      Y
//            /
//          _/

	//ACEG

	//TRIANGLES ARE ACG, AEG

	vec plusy_side1 = vec(a[0]-c[0],a[1]-c[1],a[2]-c[2]);
	vec plusy_side2 = vec(g[0]-c[0],g[1]-c[1],g[2]-c[2]);

	vec plusy_side3 = vec(a[0]-e[0],a[1]-e[1],a[2]-e[2]);
	vec plusy_side4 = vec(g[0]-e[0],g[1]-e[1],g[2]-e[2]);

	vec plusy_planevec1 = cross(plusy_side1,plusy_side2);
	vec plusy_planept1 = c;

	vec plusy_planevec2 = cross(plusy_side3,plusy_side4);
	vec plusy_planept2 = e;

	if(!planetest(plusy_planept1,plusy_planevec1,center))
	{	//if the center fails the plane test, flip the normal
		plusy_planevec1 = vec(-1*plusy_planevec1[0],-1*plusy_planevec1[1],-1*plusy_planevec1[2]);
	}

	if(!planetest(plusy_planept2,plusy_planevec2,center))
	{	//if the center fails the plane test, flip the normal
		plusy_planevec2 = vec(-1*plusy_planevec2[0],-1*plusy_planevec2[1],-1*plusy_planevec2[2]);
	}

//-------------------------------------------


	bool minusy1 = false;
	bool minusy2 = false;

//       Y88b  /
//  ____  Y888/
//         Y8/
//          Y
//         /
//       _/

	//BDFH

	//TRIANGLES ARE BDH, BFH
	vec minusy_side1 = vec(b[0]-d[0],b[1]-d[1],b[2]-d[2]);
	vec minusy_side2 = vec(h[0]-d[0],h[1]-d[1],h[2]-d[2]);

	vec minusy_side3 = vec(b[0]-f[0],b[1]-f[1],b[2]-f[2]);
	vec minusy_side4 = vec(h[0]-f[0],h[1]-f[1],h[2]-f[2]);

	vec minusy_planevec1 = cross(minusy_side1,minusy_side2);
	vec minusy_planept1 = d;

	vec minusy_planevec2 = cross(minusy_side3,minusy_side4);
	vec minusy_planept2 = f;

	if(!planetest(minusy_planept1,minusy_planevec1,center))
	{	//if the center fails the plane test, flip the normal
		minusy_planevec1 = vec(-1*minusy_planevec1[0],-1*minusy_planevec1[1],-1*minusy_planevec1[2]);
	}

	if(!planetest(minusy_planept2,minusy_planevec2,center))
	{	//if the center fails the plane test, flip the normal
		minusy_planevec2 = vec(-1*minusy_planevec2[0],-1*minusy_planevec2[1],-1*minusy_planevec2[2]);
	}


//-------------------------------------------


	bool plusz1 = false;
	bool plusz2 = false;


//    888    ~~~d88P
//  __888__    d88P
//    888     d88P
//    888    d88P
//          d88P___

	//ABCD

	//TRIANGLES ARE ABD, ACD

	vec plusz_side1 = vec(a[0]-b[0],a[1]-b[1],a[2]-b[2]);
	vec plusz_side2 = vec(d[0]-b[0],d[1]-b[1],d[2]-b[2]);

	vec plusz_side3 = vec(a[0]-c[0],a[1]-c[1],a[2]-c[2]);
	vec plusz_side4 = vec(d[0]-c[0],d[1]-c[1],d[2]-c[2]);

	vec plusz_planevec1 = cross(plusz_side1,plusz_side2);
	vec plusz_planept1 = b;

	vec plusz_planevec2 = cross(plusz_side3,plusz_side4);
	vec plusz_planept2 = c;

	if(!planetest(plusz_planept1,plusz_planevec1,center))
	{	//if the center fails the plane test, flip the normal
		plusz_planevec1 = vec(-1*plusz_planevec1[0],-1*plusz_planevec1[1],-1*plusz_planevec1[2]);
	}

	if(!planetest(plusz_planept2,plusz_planevec2,center))
	{	//if the center fails the plane test, flip the normal
		plusz_planevec2 = vec(-1*plusz_planevec2[0],-1*plusz_planevec2[1],-1*plusz_planevec2[2]);
	}

//-------------------------------------------


	bool minusz1 = false;
	bool minusz2 = false;

//        ~~~d88P
//  ____    d88P
//         d88P
//        d88P
//       d88P___

	//EFGH

	//TRIANGLES ARE EFH, EGH
	vec minusz_side1 = vec(e[0]-f[0],e[1]-f[1],e[2]-f[2]);
	vec minusz_side2 = vec(h[0]-f[0],h[1]-f[1],h[2]-f[2]);

	vec minusz_side3 = vec(e[0]-g[0],e[1]-g[1],e[2]-g[2]);
	vec minusz_side4 = vec(h[0]-g[0],h[1]-g[1],h[2]-g[2]);

	vec minusz_planevec1 = cross(minusz_side1,minusz_side2);
	vec minusz_planept1 = f;

	vec minusz_planevec2 = cross(minusz_side3,minusz_side4);
	vec minusz_planept2 = g;

	if(!planetest(minusz_planept1,minusz_planevec1,center))
	{	//if the center fails the plane test, flip the normal
		minusz_planevec1 = vec(-1*minusz_planevec1[0],-1*minusz_planevec1[1],-1*minusz_planevec1[2]);
	}

	if(!planetest(minusz_planept2,minusz_planevec2,center))
	{	//if the center fails the plane test, flip the normal
		minusz_planevec2 = vec(-1*minusz_planevec2[0],-1*minusz_planevec2[1],-1*minusz_planevec2[2]);
	}


//-------------------------------------------

//  ╔╦╗┌─┐┌─┐┌┬┐  ╦  ┌─┐┌─┐┌─┐
//   ║ ├┤ └─┐ │   ║  │ ││ │├─┘
//   ╩ └─┘└─┘ ┴   ╩═╝└─┘└─┘┴

	vec current;

	for(int i = 0; i < get_x_res(); i++)
	{
		for(int j = 0; j < get_y_res(); j++)
		{
			for(int k = 0; k < get_z_res(); k++)
			{

				current = vec(i,j,k);

				bool plusxtest = planetest(plusx_planept1,plusx_planevec1,current)&&planetest(plusx_planept2,plusx_planevec2,current);
				bool minusxtest = planetest(minusx_planept1,minusx_planevec1,current)&&planetest(minusx_planept2,minusx_planevec2,current);
				bool plusytest = planetest(plusy_planept1,plusy_planevec1,current)&&planetest(plusy_planept2,plusy_planevec2,current);
				bool minusytest = planetest(minusy_planept1,minusy_planevec1,current)&&planetest(minusy_planept2,minusy_planevec2,current);
				bool plusztest = planetest(plusz_planept1,plusz_planevec1,current)&&planetest(plusz_planept2,plusz_planevec2,current);
				bool minusztest = planetest(minusz_planept1,minusz_planevec1,current)&&planetest(minusz_planept2,minusz_planevec2,current);

				bool xtest = plusxtest&&minusxtest;
				bool ytest = plusytest&&minusytest;
				bool ztest = plusztest&&minusztest;


				if(xtest && ytest && ztest)
				{
					set_data_by_3D_index(i,j,k,set);
				}
			}
		}
	}
}

//...


//array access functions

void Voraldo::set_data_by_3D_index(int x, int y, int z, Vox set)
{
	//validate the input - make sure you are in the block
	bool x_valid = x < x_res && x >= 0;
	bool y_valid = y < y_res && y >= 0;
	bool z_valid = z < z_res && z >= 0;

	bool masked = data[get_array_index_for_3D_index(x,y,z)].mask;

	//all dimensions valid, do as the user asks
	if(x_valid && y_valid && z_valid && !masked)
	{
		if(set.color.red <= 255&&set.color.green <= 255&&set.color.blue <= 255)
		{
			data[get_array_index_for_3D_index(x,y,z)] = set;
		}
		else
		{
			data[get_array_index_for_3D_index(x,y,z)] = name_to_Vox_map.at("empty");
			//clipping
		}
	}
	else
	{
		if(!masked)
		{
			if(VORALDO_DEBUG)
			{
				std::cout << std::endl << "Invalid index for set_data_by_index()" << std::endl;

				std::cout << "you used " << std::to_string(x) << " for x which should be between 0 and ";
				std::cout << std::to_string(x_res) << std::endl;

				std::cout << "you used " << std::to_string(y) << " for y which should be between 0 and ";
				std::cout << std::to_string(y_res) << std::endl;

				std::cout << "you used " << std::to_string(z) << " for z which should be between 0 and ";
				std::cout << std::to_string(z_res) << std::endl;
			}
		}
		else
		{
			if(VORALDO_DEBUG)
			{
				std::cout << "Cell "
					<< std::to_string(x) << " "
					<< std::to_string(y) << " "
					<< std::to_string(z) << " is masked";
			}
		}
	}

	return;
}



Vox  Voraldo::get_data_by_3D_index(int x, int y, int z)
{
	//validate the input
	bool x_valid = (x < x_res) && x >= 0;
	bool y_valid = (y < y_res) && y >= 0;
	bool z_valid = (z < z_res) && z >= 0;

	if(x_valid && y_valid && z_valid)
	{
		return(data[get_array_index_for_3D_index(x,y,z)]); //grab the data from the long 1d array
	}
	else
	{
		if(VORALDO_DEBUG)
			std::cout << std::endl << "Invalid index for get_data_by_3d_index()" << std::endl;

		Vox temp = name_to_Vox_map.at("empty");

		return(temp); //if it is outside, return an empty state
	}
}

Vox  Voraldo::get_data_by_vector_index(vec index)
{

	int x = std::floor(index[0]);
	int y = std::floor(index[1]);
	int z = std::floor(index[2]);

	//validate the input
	bool x_valid = (x < x_res) && (x >= 0);
	bool y_valid = (y < y_res) && (y >= 0);
	bool z_valid = (z < z_res) && (z >= 0);


	if(x_valid && y_valid && z_valid)
	{
		return(data[get_array_index_for_3D_index(x,y,z)]); //grab the data from the long 1d array
	}
	else
	{
		if(VORALDO_DEBUG)
			std::cout << std::endl << "Invalid index for get_data_by_3d_index()" << std::endl;

		Vox temp = name_to_Vox_map.at("empty");

		return(temp); //if it is outside, return an empty state
	}
}

int Voraldo::get_array_index_for_3D_index(int x, int y, int z)
{
	return z*(y_res*x_res) + y*(x_res) + x; //this mapping was figured out on paper, but can be
}	//described pretty succinctly - the z dimension is like pages, each of dimension x * y, then
	//the y dimension is like rows, each of dimension x, and the x dimension is the location
	//within the row that has been specified by the z and y coordinates.

void Voraldo::clear_all()
{
	Vox temp = name_to_Vox_map.at("empty");
	for(int i = 0; i < num_cells; i++)
	{
		data[i] = temp;
	}
}

//mask functions

void Voraldo::unmask_all()
{//sets all mask values to false
	for(int i = 0; i < num_cells; i++)
	{
		data[i].mask = false;
	}

}

void Voraldo::invert_mask()
{//inverts every cell's mask value
	for(int i = 0; i < num_cells; i++)
	{
		data[i].mask = data[i].mask ? false : true;
	}
}

void Voraldo::mask_all_nonzero()
{
	for(int i = 0; i < num_cells; i++)
	{
		data[i].mask = data[i].state ? true : false;
	}	//nonzero cells will be masked, with all zero cells then being allowed to change freely
}

//display

void Voraldo::display(std::string filename, double x_rot, double y_rot, double z_rot, double scale, bool perspective)
{
	using namespace cimg_library;

	int image_x_dimension = 1921;
	int image_y_dimension = 1081;

	CImg<unsigned char> img(image_x_dimension,image_y_dimension,1,3,0);

	const unsigned char	gold[3] = {255,215,0};
	const unsigned char dark_gold[3] = {127,107,0};
	const unsigned char white[3] = {255,255,255};
	const unsigned char black[3] = {0,0,0};
	const unsigned char pink[3] = {255,0,255};


	//frame top
	img.draw_line(0,1,image_x_dimension,1,gold);
	img.draw_line(0,2,image_x_dimension,2,dark_gold);

	//frame bottom
	img.draw_line(0,image_y_dimension-2,image_x_dimension,image_y_dimension-2,dark_gold);
	img.draw_line(0,image_y_dimension-1,image_x_dimension,image_y_dimension-1,gold);

	//frame left from low x low y to low x high y
	img.draw_line(1,0,1,image_y_dimension,gold);
	img.draw_line(2,0,2,image_y_dimension,dark_gold);

	//frame right from high x low y to high x high y
	img.draw_line(image_x_dimension-2,0,image_x_dimension-2,image_y_dimension,dark_gold);
	img.draw_line(image_x_dimension-2,0,image_x_dimension-2,image_y_dimension,gold);


	int block_xdim = get_x_res();
	int block_ydim = get_y_res();
	int block_zdim = get_z_res();

	int block_xdim_squared = block_xdim*block_xdim;
	int block_ydim_squared = block_ydim*block_ydim;
	int block_zdim_squared = block_zdim*block_zdim;

	vec d_center = vec(block_xdim/2.0,block_ydim/2.0,block_zdim/2.0);

	mat rotation_x_axis;
//refernces [column][row]
		rotation_x_axis[0][0] = 1;
		rotation_x_axis[0][1] = 0;
		rotation_x_axis[0][2] = 0;
		rotation_x_axis[1][0] = 0;
		rotation_x_axis[1][1] = std::cos(x_rot);
		rotation_x_axis[1][2] = std::sin(x_rot);
		rotation_x_axis[2][0] = 0;
		rotation_x_axis[2][1] = -1.0*std::sin(x_rot);
		rotation_x_axis[2][2] = std::cos(x_rot);

	mat rotation_y_axis;
		rotation_y_axis[0][0] = std::cos(y_rot);
		rotation_y_axis[0][1] = 0;
		rotation_y_axis[0][2] = -1.0*std::sin(y_rot);
		rotation_y_axis[1][0] = 0;
		rotation_y_axis[1][1] = 1;
		rotation_y_axis[1][2] = 0;
		rotation_y_axis[2][0] = std::sin(y_rot);
		rotation_y_axis[2][1] = 0;
		rotation_y_axis[2][2] = std::cos(y_rot);

	mat rotation_z_axis;
		rotation_z_axis[0][0] = std::cos(z_rot);
		rotation_z_axis[0][1] = std::sin(z_rot);
		rotation_z_axis[0][2] = 0;
		rotation_z_axis[1][0] = -1.0*std::sin(z_rot);
		rotation_z_axis[1][1] = std::cos(z_rot);
		rotation_z_axis[1][2] = 0;
		rotation_z_axis[2][0] = 0;
		rotation_z_axis[2][1] = 0;
		rotation_z_axis[2][2] = 1;

	vec d_xvec = mul(rotation_x_axis,mul(rotation_y_axis,mul(rotation_z_axis,vec(1,0,0))));
	vec d_yvec = mul(rotation_x_axis,mul(rotation_y_axis,mul(rotation_z_axis,vec(0,1,0))));
	vec d_zvec = mul(rotation_x_axis,mul(rotation_y_axis,mul(rotation_z_axis,vec(0,0,1))));

	//tip radius is the radius of the sphere that touches the tips of the block's corners
	double tip_radius = std::sqrt(block_xdim_squared+block_ydim_squared+block_zdim_squared)/2.0;
	double max_dist = 2*2.2*tip_radius;
	double min_dist = 0.2*tip_radius;
	//factor of two is for the incremental step of length 0.5
	//factor of 2.2 is for the tip radius plus the camera sphere radius, 1+1.2

	vec cam_position = d_center - 1.2*tip_radius*d_yvec;

	vec cam_up = scale*d_zvec; //may need to change the scaling
	vec cam_right = scale*d_xvec;



	int image_center_x = (image_x_dimension-1)/2;;
	int image_center_y = (image_y_dimension-1)/2;;

	int image_current_x, image_current_y;

	vec vector_starting_point;
	vec vector_increment = 0.5*normalize(-1.0*(cam_position-d_center));

	vec vector_test_point;

	vec block_min = vec(0,0,0);
	vec block_max = vec(get_x_res(),get_y_res(),get_z_res());

	Vox temp_vox;
	unsigned char	point_color[3];

	bool xtest,ytest,ztest;
	bool line_box_intersection;
	bool color_set;

	double t0 = -999;
	double t1 = 999;
	double tmin, tmax;

	double tintersect; //for line/box intersection

	for(double x = -(image_x_dimension/2-5); x <= (image_x_dimension/2-5); x++)
		for(double y = -(image_y_dimension/2-5); y <= (image_y_dimension/2-5); y++)
		{//init (reset)
			line_box_intersection = false;
			color_set=false;




			image_current_x = image_center_x + x;
			image_current_y = image_center_y + y;


			// if(perspective == true) //this gets added inside the loop - note that the linetest will have to consider the perspective corrected ray
			// 	vector_increment_perspective = vector_increment + x*0.1*cam_right - y*0.1*cam_up;


			vector_starting_point = cam_position + x*cam_up + y*cam_right;

			//figure out if the parametric line established by parameter z and
			//	L = vector_starting_point + z*vector_increment
			//intersects with the box established by (0,0,0) (x,y,z)
			//i.e. block_min and block_max

			//The goal here is to achieve some level of speedup when compared to
			//doing an exhaustive check through all points on all vectors from
			//the pixels in the image.
			line_box_intersection = intersect_bbox(block_min,block_max,vector_starting_point,vector_increment,t0,t1,tmin,tmax);

			if(line_box_intersection)
			{
			//	img.draw_point(image_current_x,image_current_y,dark_gold);
			//	for(double z = min_dist; z <= max_dist; z+=0.5) //from the old code
				for(double z = tmin; z <= tmax; z+=0.5) //go from close intersection point to far intersection point
				{
					vector_test_point = vector_starting_point + z*vector_increment;
					temp_vox = get_data_by_vector_index(vector_test_point);
					if(temp_vox.state!=0)
					{
						point_color[0] = temp_vox.color.red;
						point_color[1] = temp_vox.color.green;
						point_color[2] = temp_vox.color.blue;

						img.draw_point(image_current_x,image_current_y,point_color);
						color_set = true;

						break;
					}
				}
				if(!color_set)
					img.draw_point(image_current_x,image_current_y,pink);
			}
			else
			{
				img.draw_point(image_current_x,image_current_y,black);
			}
		}

	img.save_bmp(filename.c_str());
}

void Voraldo::legacy_display(std::string filename)
{
	double y_upper = -1.618;

	double y_lower_long = 1.0;
	double y_lower_short = 0.8;

	double x_short = 1.0;
	double x_mid = 1.618;
	double x_long = 2.26;

	using namespace cimg_library;

	CImg<unsigned char> img(3005,3005,1,3,0);

	const unsigned char	gold[3] = {255,215,0};
	const unsigned char dark_gold[3] = {127,107,0};
	const unsigned char white[3] = {255,255,255};

//vertical dividers
	img.draw_line(1001,0,1001,3004,gold);
	img.draw_line(2003,0,2003,3004,gold);

	img.draw_line(999,5,999,2999,dark_gold);
	img.draw_line(1003,5,1003,2999,dark_gold);
	img.draw_line(2001,5,2001,2999,dark_gold);
	img.draw_line(2005,5,2005,2999,dark_gold);

//horizontal dividers
	img.draw_line(0,1001,3004,1001,gold);
	img.draw_line(0,2003,3004,2003,gold);

	img.draw_line(5,999,2999,999,dark_gold);
	img.draw_line(5,1003,2999,1003,dark_gold);
	img.draw_line(5,2001,2999,2001,dark_gold);
	img.draw_line(5,2005,2999,2005,dark_gold);

//centers

	vec2 centers[9];
	vec2 center_x_vecs[9];
	vec2 center_y_vecs[9];
	vec2 center_z_vecs[9];

	//first row
	img.draw_point( 500, 500,white); //center #1
	centers[0] = vec2(400,700);
	center_x_vecs[0] = vec2(x_long,0);
	center_y_vecs[0] = vec2(0,y_upper);
	center_z_vecs[0] = vec2(-1.0*x_short,y_lower_long);

	img.draw_point(1501, 500,white); //center #2
	centers[1] = vec2(1501,500);
	center_x_vecs[1] = vec2(-1.0*x_mid,y_lower_long);
	center_y_vecs[1] = vec2(0,y_upper);
	center_z_vecs[1] = vec2(x_mid,y_lower_long);

	img.draw_point(2503, 500,white); //center #3
	centers[2] = vec2(2603,700);
	center_x_vecs[2] = vec2(x_short,y_lower_long);
	center_y_vecs[2] = vec2(0,y_upper);
	center_z_vecs[2] = vec2(-1.0*x_long,0);

	//second row
	img.draw_point( 500,1501,white); //center #4
	centers[3] = vec2(400,1701);
	center_x_vecs[3] = vec2(x_long,0);
	center_y_vecs[3] = vec2(0,y_upper);
	center_z_vecs[3] = vec2(-1.0*x_short,y_lower_short);

	img.draw_point(1501,1501,white); //center #5
	centers[4] = vec2(1501,1576);
	center_x_vecs[4] = vec2(x_mid,y_lower_short);
	center_y_vecs[4] = vec2(0,y_upper);
	center_z_vecs[4] = vec2(-1.0*x_mid,y_lower_short);

	img.draw_point(2503,1501,white); //center #6
	centers[5] = vec2(2603,1701);
	center_x_vecs[5] = vec2(x_short,y_lower_short);
	center_y_vecs[5] = vec2(0,y_upper);
	center_z_vecs[5] = vec2(-1.0*x_long,0);

	//third row
	img.draw_point( 500,2503,white); //center #7
	centers[6] = vec2(400,2803);
	center_x_vecs[6] = vec2(x_long,0);
	center_y_vecs[6] = vec2(0,y_upper);
	center_z_vecs[6] = vec2(-1.0*x_short,0);

	img.draw_point(1501,2503,white); //center #8
	centers[7] = vec2(1501,2803);
	center_x_vecs[7] = vec2(x_mid,0);
	center_y_vecs[7] = vec2(0,y_upper);
	center_z_vecs[7] = vec2(-1.0*x_mid,0);

	img.draw_point(2503,2503,white); //center #9
	centers[8] = vec2(2603,2803);
	center_x_vecs[8] = vec2(x_short,0);
	center_y_vecs[8] = vec2(0,y_upper);
	center_z_vecs[8] = vec2(-1.0*x_long,0);

	int curr_x = 0;
	int curr_y = 0;

	RGB color;
	unsigned char size = 0;
	float alpha;

	for(int x = 0; x < get_x_res(); x++)
	{
		for(int y = 0; y < get_y_res(); y++)
		{
			for(int z = 0; z < get_z_res(); z++)
			{
				Vox temp = get_data_by_3D_index(x,y,z);
				color = temp.color;
				size = temp.size;
				alpha = temp.alpha;

				for(int w = 0; w <= 8; w++)
				{
					unsigned char color_char[3] = {color.red,color.green,color.blue};

					curr_x = int(floor(centers[w][0]+x*center_x_vecs[w][0]+y*center_y_vecs[w][0]+z*center_z_vecs[w][0]));
					curr_y = int(floor(centers[w][1]+x*center_x_vecs[w][1]+y*center_y_vecs[w][1]+z*center_z_vecs[w][1]));

					switch(size)
					{
						case 1://point
							img.draw_point(curr_x,curr_y,color_char,alpha);
							break;
						case 2://circle size 1
							img.draw_circle(curr_x,curr_y,1,color_char,alpha);
							break;
						case 3://circle size 2
							img.draw_circle(curr_x,curr_y,2,color_char,alpha);
							break;
						default://do not draw;
							break;
					}

					// unsigned char point_color[3] = {c.point_color.red,c.point_color.green,c.point_color.blue};
					// unsigned char first_circle_color[3] = {c.first_circle_color.red,c.first_circle_color.green,c.first_circle_color.blue};
					// unsigned char second_circle_color[3] = {c.second_circle_color.red,c.second_circle_color.green,c.second_circle_color.blue};

					// if(c.draw_second_circle){
					// 	img.draw_circle(curr_x,curr_y,c.second_circle_radius,second_circle_color,c.second_circle_alpha);
					// }

					// if(c.draw_first_circle){
					// 	img.draw_circle(curr_x,curr_y,c.first_circle_radius,first_circle_color,c.first_circle_alpha);
					// }

					// if(c.draw_point){
					// 	img.draw_point(curr_x,curr_y,point_color,c.point_alpha);
					// }
				}
			}
		}
	}

	img.save_bmp(filename.c_str());
}

bool Voraldo::planetest(vec plane_point, vec plane_normal, vec test_point)
{//return false if the point is above the plane
	//return true if the point is below the plane

	double result = 0.0;

	//equation of plane

	// a (x-x1) + b (y-y1) + c (z-z1) = 0

	double a = plane_normal[0];
	double b = plane_normal[1];
	double c = plane_normal[2];

	double x1 = plane_point[0];
	double y1 = plane_point[1];
	double z1 = plane_point[2];

	double x = test_point[0];
	double y = test_point[1];
	double z = test_point[2];

	result = a * (x - x1) + b * (y - y1) + c * (z - z1);

	return (result < 0)?true:false;

}

/*
 * Ray-box intersection using IEEE numerical properties to ensure that the
 * test is both robust and efficient, as described in:
 *
 *      Amy Williams, Steve Barrus, R. Keith Morley, and Peter Shirley
 *      "An Efficient and Robust Ray-Box Intersection Algorithm"
 *      Journal of graphics tools, 10(1):49-54, 2005
 *
 */
//I pulled this code after three attempts at my own implementation didn't work
bool Voraldo::intersect_bbox(vec bbox_min, vec bbox_max, vec ray_org, vec ray_dir, double t0, double t1, double &tmin, double &tmax)
{
	vec bbox[2];
	int sign[3];

	vec inv_direction = vec(1/ray_dir[0],1/ray_dir[1],1/ray_dir[2]);

	sign[0] = (inv_direction[0] < 0);
	sign[1] = (inv_direction[1] < 0);
	sign[2] = (inv_direction[2] < 0);

	bbox[0] = bbox_min;
	bbox[1] = bbox_max;


	//already declared (passed in by reference so that they can be used)
  tmin = (bbox[sign[0]][0] - ray_org[0]) * inv_direction[0];
  tmax = (bbox[1-sign[0]][0] - ray_org[0]) * inv_direction[0];

  double tymin = (bbox[sign[1]][1] - ray_org[1]) * inv_direction[1];
  double tymax = (bbox[1-sign[1]][1] - ray_org[1]) * inv_direction[1];

  if ( (tmin > tymax) || (tymin > tmax) )
    return false;
  if (tymin > tmin)
    tmin = tymin;
  if (tymax < tmax)
    tmax = tymax;

  double tzmin = (bbox[sign[2]][2] - ray_org[2]) * inv_direction[2];
  double tzmax = (bbox[1-sign[2]][2] - ray_org[2]) * inv_direction[2];

  if ( (tmin > tzmax) || (tzmin > tmax) )
    return false;
  if (tzmin > tmin)
    tmin = tzmin;
  if (tzmax < tmax)
    tmax = tzmax;
  return ( (tmin < t1) && (tmax > t0) );

}

Car::Car()
{

}

void Car::init(Voraldo *block)
{
	//default values
	center = vec(128,128,128);

	car_x_vec = vec(1,0,0);
	car_y_vec = vec(0,1,0);
	car_z_vec = vec(0,0,1);

	RRhub = vec(-50,0,30);
	RRinner = vec(-50,0,25);
	RRouter = vec(-50,0,35);

	LRhub = vec(-50,0,-30);
	LRinner = vec(-50,0,-25);
	LRouter = vec(-50,0,-35);

	RFhub = vec(50,0,30);
	RFinner = vec(50,0,25);
	RFouter = vec(50,0,35);

	LFhub = vec(50,0,-30);
	LFinner = vec(50,0,-25);
	LFouter = vec(50,0,-35);

	Rdiff = vec(-50,0,0);
	Rdiff_Roffset = vec(-50,0,10);
	Rdiff_Loffset = vec(-50,0,-10);
	Rdiff_Foffset = vec(-44,0,0);

	Fdiff = vec(50,0,0);
	Fdiff_Roffset = vec(50,0,10);
	Fdiff_Loffset = vec(50,0,-10);
	Fdiff_Boffset = vec(44,0,0);

	engine_block_a = vec(18,12,12);
	engine_block_b = vec(18,-4,10);
	engine_block_c = vec(45,12,12);
	engine_block_d = vec(45,-4,10);
	engine_block_e = vec(18,12,-12);
	engine_block_f = vec(18,-4,-10);
	engine_block_g = vec(45,12,-12);
	engine_block_h = vec(45,-4,-10);

	left_sill_front = vec(36,0,-34);
	left_front_fender_0 = vec(38,8,-34);
	left_front_fender_1 = vec(42,12,-34);



	left_sill_back = vec(-36,0,-34);
	left_back_fender_0 = vec(-38,8,-34);
	left_back_fender_1 = vec(-42,12,-34);



	right_sill_front = vec(36,0,34);
	right_front_fender_0 = vec(38,8,34);
	right_front_fender_1 = vec(42,12,34);



	right_sill_back = vec(-36,0,34);
	right_back_fender_0 = vec(-38,8,34);
	right_back_fender_1 = vec(-42,12,34);




	V_object = block;

	if(VORALDO_DEBUG)
		cout << "finished all initialization" << endl;
}

void Car::draw(bool platform, double x_rot, double y_rot, double z_rot)
{

	if(platform)
	{
		draw_platform(true);
	}

	vec d_center = vec(128,128,128);


	mat rotation_x_axis;
//refernces [column][row]
	rotation_x_axis[0][0] = 1;
	rotation_x_axis[0][1] = 0;
	rotation_x_axis[0][2] = 0;
	rotation_x_axis[1][0] = 0;
	rotation_x_axis[1][1] = std::cos(x_rot);
	rotation_x_axis[1][2] = std::sin(x_rot);
	rotation_x_axis[2][0] = 0;
	rotation_x_axis[2][1] = -1.0*std::sin(x_rot);
	rotation_x_axis[2][2] = std::cos(x_rot);

	mat rotation_y_axis;
	rotation_y_axis[0][0] = std::cos(y_rot);
	rotation_y_axis[0][1] = 0;
	rotation_y_axis[0][2] = -1.0*std::sin(y_rot);
	rotation_y_axis[1][0] = 0;
	rotation_y_axis[1][1] = 1;
	rotation_y_axis[1][2] = 0;
	rotation_y_axis[2][0] = std::sin(y_rot);
	rotation_y_axis[2][1] = 0;
	rotation_y_axis[2][2] = std::cos(y_rot);

	mat rotation_z_axis;
	rotation_z_axis[0][0] = std::cos(z_rot);
	rotation_z_axis[0][1] = std::sin(z_rot);
	rotation_z_axis[0][2] = 0;
	rotation_z_axis[1][0] = -1.0*std::sin(z_rot);
	rotation_z_axis[1][1] = std::cos(z_rot);
	rotation_z_axis[1][2] = 0;
	rotation_z_axis[2][0] = 0;
	rotation_z_axis[2][1] = 0;
	rotation_z_axis[2][2] = 1;

	vec d_car_x_vec = mul(rotation_x_axis,mul(rotation_y_axis,mul(rotation_z_axis,car_x_vec)));
	vec d_car_y_vec = mul(rotation_x_axis,mul(rotation_y_axis,mul(rotation_z_axis,car_y_vec)));
	vec d_car_z_vec = mul(rotation_x_axis,mul(rotation_y_axis,mul(rotation_z_axis,car_z_vec)));


	/*these vectors define the xyz of the car

I need to calculate a transformed offset for all of vector values
 - each vector (RRhub, RRinner, etc) is used to get (d_RRhub, d_RRinner, etc)
 - d_blah = x_vec*blah[0] + y_vec*blah[1] + z_vec*blah[2];

 x_vec is the model's x vector, y is the y, z the z, so rotation
 can take place.

	*/


	d_RRhub = d_car_x_vec*RRhub[0] + d_car_y_vec*RRhub[1] + d_car_z_vec*RRhub[2];
	d_RRinner = d_car_x_vec*RRinner[0] + d_car_y_vec*RRinner[1] + d_car_z_vec*RRinner[2];
	d_RRouter = d_car_x_vec*RRouter[0] + d_car_y_vec*RRouter[1] + d_car_z_vec*RRouter[2];

	d_LRhub = d_car_x_vec*LRhub[0] + d_car_y_vec*LRhub[1] + d_car_z_vec*LRhub[2];
	d_LRinner = d_car_x_vec*LRinner[0] + d_car_y_vec*LRinner[1] + d_car_z_vec*LRinner[2];
	d_LRouter = d_car_x_vec*LRouter[0] + d_car_y_vec*LRouter[1] + d_car_z_vec*LRouter[2];

	d_RFhub = d_car_x_vec*RFhub[0] + d_car_y_vec*RFhub[1] + d_car_z_vec*RFhub[2];
	d_RFinner = d_car_x_vec*RFinner[0] + d_car_y_vec*RFinner[1] + d_car_z_vec*RFinner[2];
	d_RFouter = d_car_x_vec*RFouter[0] + d_car_y_vec*RFouter[1] + d_car_z_vec*RFouter[2];

	d_LFhub = d_car_x_vec*LFhub[0] + d_car_y_vec*LFhub[1] + d_car_z_vec*LFhub[2];
	d_LFinner = d_car_x_vec*LFinner[0] + d_car_y_vec*LFinner[1] + d_car_z_vec*LFinner[2];
	d_LFouter = d_car_x_vec*LFouter[0] + d_car_y_vec*LFouter[1] + d_car_z_vec*LFouter[2];

	d_Rdiff = d_car_x_vec*Rdiff[0] + d_car_y_vec*Rdiff[1] + d_car_z_vec*Rdiff[2];
	d_Rdiff_Roffset = d_car_x_vec*Rdiff_Roffset[0] + d_car_y_vec*Rdiff_Roffset[1] + d_car_z_vec*Rdiff_Roffset[2];
	d_Rdiff_Loffset = d_car_x_vec*Rdiff_Loffset[0] + d_car_y_vec*Rdiff_Loffset[1] + d_car_z_vec*Rdiff_Loffset[2];
	d_Rdiff_Foffset = d_car_x_vec*Rdiff_Foffset[0] + d_car_y_vec*Rdiff_Foffset[1] + d_car_z_vec*Rdiff_Foffset[2];

	d_Fdiff = d_car_x_vec*Fdiff[0] + d_car_y_vec*Fdiff[1] + d_car_z_vec*Fdiff[2];
	d_Fdiff_Roffset = d_car_x_vec*Fdiff_Roffset[0] + d_car_y_vec*Fdiff_Roffset[1] + d_car_z_vec*Fdiff_Roffset[2];
	d_Fdiff_Loffset = d_car_x_vec*Fdiff_Loffset[0] + d_car_y_vec*Fdiff_Loffset[1] + d_car_z_vec*Fdiff_Loffset[2];
	d_Fdiff_Boffset = d_car_x_vec*Fdiff_Boffset[0] + d_car_y_vec*Fdiff_Boffset[1] + d_car_z_vec*Fdiff_Boffset[2];

	d_engine_block_a = d_car_x_vec*engine_block_a[0] + d_car_y_vec*engine_block_a[1] + d_car_z_vec*engine_block_a[2];
	d_engine_block_b = d_car_x_vec*engine_block_b[0] + d_car_y_vec*engine_block_b[1] + d_car_z_vec*engine_block_b[2];
	d_engine_block_c = d_car_x_vec*engine_block_c[0] + d_car_y_vec*engine_block_c[1] + d_car_z_vec*engine_block_c[2];
	d_engine_block_d = d_car_x_vec*engine_block_d[0] + d_car_y_vec*engine_block_d[1] + d_car_z_vec*engine_block_d[2];
	d_engine_block_e = d_car_x_vec*engine_block_e[0] + d_car_y_vec*engine_block_e[1] + d_car_z_vec*engine_block_e[2];
	d_engine_block_f = d_car_x_vec*engine_block_f[0] + d_car_y_vec*engine_block_f[1] + d_car_z_vec*engine_block_f[2];
	d_engine_block_g = d_car_x_vec*engine_block_g[0] + d_car_y_vec*engine_block_g[1] + d_car_z_vec*engine_block_g[2];
	d_engine_block_h = d_car_x_vec*engine_block_h[0] + d_car_y_vec*engine_block_h[1] + d_car_z_vec*engine_block_h[2];

	d_left_sill_front = d_car_x_vec*left_sill_front[0] + d_car_y_vec*left_sill_front[1] + d_car_z_vec*left_sill_front[2];
	d_left_sill_back = d_car_x_vec*left_sill_back[0] + d_car_y_vec*left_sill_back[1] + d_car_z_vec*left_sill_back[2];
	d_right_sill_front = d_car_x_vec*right_sill_front[0] + d_car_y_vec*right_sill_front[1] + d_car_z_vec*right_sill_front[2];
	d_right_sill_back = d_car_x_vec*right_sill_back[0] + d_car_y_vec*right_sill_back[1] + d_car_z_vec*right_sill_back[2];

	d_left_front_fender_0 = d_car_x_vec*left_front_fender_0[0] + d_car_y_vec*left_front_fender_0[1] + d_car_z_vec*left_front_fender_0[2];
	d_left_back_fender_0 = d_car_x_vec*left_back_fender_0[0] + d_car_y_vec*left_back_fender_0[1] + d_car_z_vec*left_back_fender_0[2];
	d_right_front_fender_0 = d_car_x_vec*right_front_fender_0[0] + d_car_y_vec*right_front_fender_0[1] + d_car_z_vec*right_front_fender_0[2];
	d_right_back_fender_0 = d_car_x_vec*right_back_fender_0[0] + d_car_y_vec*right_back_fender_0[1] + d_car_z_vec*right_back_fender_0[2];

	d_left_front_fender_1 = d_car_x_vec*left_front_fender_1[0] + d_car_y_vec*left_front_fender_1[1] + d_car_z_vec*left_front_fender_1[2];
	d_left_back_fender_1 = d_car_x_vec*left_back_fender_1[0] + d_car_y_vec*left_back_fender_1[1] + d_car_z_vec*left_back_fender_1[2];
	d_right_front_fender_1 = d_car_x_vec*right_front_fender_1[0] + d_car_y_vec*right_front_fender_1[1] + d_car_z_vec*right_front_fender_1[2];
	d_right_back_fender_1 = d_car_x_vec*right_back_fender_1[0] + d_car_y_vec*right_back_fender_1[1] + d_car_z_vec*right_back_fender_1[2];


	draw_driveline_and_axles();
	draw_hubs();
	draw_rear_diff();
	draw_front_diff();
	draw_wheels_and_tires();
	draw_engine_block();
	draw_body_sills();

	if(VORALDO_DEBUG)
		cout << "finished all drawing" << endl;
}

void Car::draw_platform(bool frame)
{

	if(VORALDO_DEBUG)
		cout << "drawing platform" << endl;

	V_object->draw_ellipsoid(vec(128,118,128),vec(100,75,75),V_object->name_to_Vox_map.at("space_gas_5"));
	V_object->draw_ellipsoid(vec(128,118,128),vec(78,72,200),V_object->name_to_Vox_map.at("empty"));
	V_object->draw_ellipsoid(vec(128,118,128),vec(200,72,50),V_object->name_to_Vox_map.at("empty"));

	V_object->mask_all_nonzero();
	V_object->invert_mask();

	V_object->draw_ellipsoid(vec(128,118,128),vec(79,73,201),V_object->name_to_Vox_map.at("clear_blue_glass"));



	V_object->unmask_all();

	V_object->draw_blockoid(vec(0,0,0),vec(257,118,257),V_object->name_to_Vox_map.at("armor_0"));
	V_object->draw_ellipsoid(vec(128,118,128),vec(75,25,50),V_object->name_to_Vox_map.at("empty"));

	V_object->mask_all_nonzero();

	V_object->draw_blockoid(vec(0,112,0),vec(257,118,257),V_object->name_to_Vox_map.at("clear_blue_glass"));
	V_object->draw_blockoid(vec(70,114,0),vec(86,116,257),V_object->name_to_Vox_map.at("space_gas_5"));
	V_object->draw_blockoid(vec(170,114,0),vec(186,116,257),V_object->name_to_Vox_map.at("space_gas_5"));


	V_object->draw_tube(vec(128,118+74,128),vec(128,118+78,128),5,10,V_object->name_to_Vox_map.at("red_light"));
	V_object->draw_tube(vec(128,118+78,128),vec(128,118+80,128),2,12,V_object->name_to_Vox_map.at("hull"));


	V_object->unmask_all();

	if(frame)
	{

		int x = V_object->get_x_res()-1;
		int y = V_object->get_y_res()-1;
		int z = V_object->get_z_res()-1;

		vec zerozerozero = vec(0,0,0);
		vec Xreszerozero = vec(x,0,0);
		vec zeroYreszero = vec(0,y,0);
		vec XresYreszero = vec(x,y,0);
		vec zerozeroZres = vec(0,0,z);
		vec XreszeroZres = vec(x,0,z);
		vec zeroYresZres = vec(0,y,z);
		vec XresYresZres = vec(x,y,z);

		V_object->draw_line_segment(zerozerozero,Xreszerozero,V_object->name_to_Vox_map.at("red_light"));
		V_object->draw_line_segment(zeroYreszero,XresYreszero,V_object->name_to_Vox_map.at("red_light"));
		V_object->draw_line_segment(zerozeroZres,XreszeroZres,V_object->name_to_Vox_map.at("red_light"));
		V_object->draw_line_segment(zeroYresZres,XresYresZres,V_object->name_to_Vox_map.at("red_light"));

		V_object->draw_line_segment(zerozerozero,zeroYreszero,V_object->name_to_Vox_map.at("green_light"));
		V_object->draw_line_segment(Xreszerozero,XresYreszero,V_object->name_to_Vox_map.at("green_light"));
		V_object->draw_line_segment(zerozeroZres,zeroYresZres,V_object->name_to_Vox_map.at("green_light"));
		V_object->draw_line_segment(XreszeroZres,XresYresZres,V_object->name_to_Vox_map.at("green_light"));

		V_object->draw_line_segment(zerozerozero,zerozeroZres,V_object->name_to_Vox_map.at("blue_light"));
		V_object->draw_line_segment(Xreszerozero,XreszeroZres,V_object->name_to_Vox_map.at("blue_light"));
		V_object->draw_line_segment(zeroYreszero,zeroYresZres,V_object->name_to_Vox_map.at("blue_light"));
		V_object->draw_line_segment(XresYreszero,XresYresZres,V_object->name_to_Vox_map.at("blue_light"));


	}

	if(VORALDO_DEBUG)
		cout << "finished drawing platform" << endl;
}

void Car::draw_driveline_and_axles()
{
	if(VORALDO_DEBUG)
		cout << "drawing driveline and axles" << endl;

	V_object->draw_cylinder(center+d_Rdiff,center+d_Fdiff,1,V_object->name_to_Vox_map.at("blue_light"));

	V_object->draw_cylinder(center+d_LRhub,center+d_RRhub,1,V_object->name_to_Vox_map.at("blue_light"));
	V_object->draw_cylinder(center+d_LFhub,center+d_RFhub,1,V_object->name_to_Vox_map.at("blue_light"));

	V_object->mask_all_nonzero();

	if(VORALDO_DEBUG)
		cout << "finished drawing driveline and axles" << endl;
}

void Car::draw_hubs()
{
	if(VORALDO_DEBUG)
		cout << "drawing hubs" << endl;

	V_object->draw_cylinder(center+d_LFhub,center+d_LFinner,2.75,V_object->name_to_Vox_map.at("red_light"));
	V_object->draw_cylinder(center+d_RFhub,center+d_RFinner,2.75,V_object->name_to_Vox_map.at("red_light"));
	V_object->draw_cylinder(center+d_LRhub,center+d_LRinner,2.75,V_object->name_to_Vox_map.at("red_light"));
	V_object->draw_cylinder(center+d_RRhub,center+d_RRinner,2.75,V_object->name_to_Vox_map.at("red_light"));

	V_object->mask_all_nonzero();

	if(VORALDO_DEBUG)
		cout << "finished drawing hubs" << endl;
}

void Car::draw_rear_diff()
{
	if(VORALDO_DEBUG)
		cout << "drawing rear diff" << endl;

	V_object->draw_sphere(center+d_Rdiff,3.8, V_object->name_to_Vox_map.at("diff"));
	V_object->draw_cylinder(center+d_Rdiff,center+d_Rdiff_Roffset,2.3,V_object->name_to_Vox_map.at("diff"));
	V_object->draw_cylinder(center+d_Rdiff,center+d_Rdiff_Loffset,2.3,V_object->name_to_Vox_map.at("diff"));
	V_object->draw_cylinder(center+d_Rdiff,center+d_Rdiff_Foffset,2.3,V_object->name_to_Vox_map.at("diff"));

	V_object->draw_sphere(center+d_Rdiff_Foffset,1.5, V_object->name_to_Vox_map.at("electrical"));

	if(VORALDO_DEBUG)
		cout << "finished drawing rear diff" << endl;
}

void Car::draw_front_diff()
{

	if(VORALDO_DEBUG)
		cout << "drawing front diff" << endl;

	V_object->draw_sphere(center+d_Fdiff,3.8, V_object->name_to_Vox_map.at("diff"));
	V_object->draw_cylinder(center+d_Fdiff,center+d_Fdiff_Roffset,2.3,V_object->name_to_Vox_map.at("diff"));
	V_object->draw_cylinder(center+d_Fdiff,center+d_Fdiff_Loffset,2.3,V_object->name_to_Vox_map.at("diff"));
	V_object->draw_cylinder(center+d_Fdiff,center+d_Fdiff_Boffset,2.3,V_object->name_to_Vox_map.at("diff"));

	if(VORALDO_DEBUG)
		cout << "finished drawing front diff" << endl;
}

void Car::draw_wheels_and_tires()
{

	if(VORALDO_DEBUG)
		cout << "drawing wheels and tires" << endl;

	V_object->draw_cylinder(center+d_LFinner,center+d_LFouter,8,V_object->name_to_Vox_map.at("space_gas_5"));
	V_object->draw_cylinder(center+d_RFinner,center+d_RFouter,8,V_object->name_to_Vox_map.at("space_gas_5"));
	V_object->draw_cylinder(center+d_LRinner,center+d_LRouter,8,V_object->name_to_Vox_map.at("space_gas_5"));
	V_object->draw_cylinder(center+d_RRinner,center+d_RRouter,8,V_object->name_to_Vox_map.at("space_gas_5"));

	V_object->draw_tube(center+d_LFinner,center+d_LFouter,7.5,10,V_object->name_to_Vox_map.at("solid_black"));
	V_object->draw_tube(center+d_RFinner,center+d_RFouter,7.5,10,V_object->name_to_Vox_map.at("solid_black"));
	V_object->draw_tube(center+d_LRinner,center+d_LRouter,7.5,10,V_object->name_to_Vox_map.at("solid_black"));
	V_object->draw_tube(center+d_RRinner,center+d_RRouter,7.5,10,V_object->name_to_Vox_map.at("solid_black"));

	V_object->draw_tube(center+d_LFinner,center+d_LFouter,9.75,10.5,V_object->name_to_Vox_map.at("space_gas_solid"));
	V_object->draw_tube(center+d_RFinner,center+d_RFouter,9.75,10.5,V_object->name_to_Vox_map.at("space_gas_solid"));
	V_object->draw_tube(center+d_LRinner,center+d_LRouter,9.75,10.5,V_object->name_to_Vox_map.at("space_gas_solid"));
	V_object->draw_tube(center+d_RRinner,center+d_RRouter,9.75,10.5,V_object->name_to_Vox_map.at("space_gas_solid"));

	if(VORALDO_DEBUG)
		cout << "finished drawing wheels and tires" << endl;
}

void Car::draw_engine_block()
{

	if(VORALDO_DEBUG)
		cout << "drawing engine block" << endl;

	V_object->unmask_all();

	V_object->draw_quadrilateral_hexahedron(
		center+d_engine_block_a, center+d_engine_block_b, center+d_engine_block_c, center+d_engine_block_d,
		center+d_engine_block_e, center+d_engine_block_f, center+d_engine_block_g, center+d_engine_block_h,
		V_object->name_to_Vox_map.at("engine_block"));

	if(VORALDO_DEBUG)
		cout << "finished drawing engine block" << endl;
}

void Car::draw_body_sills()
{
	if(VORALDO_DEBUG)
		cout << "drawing body sills" << endl;

	V_object->draw_line_segment(center+d_left_back_fender_0,center+d_left_back_fender_1,V_object->name_to_Vox_map.at("body_dark"));
	V_object->draw_line_segment(center+d_left_sill_back,center+d_left_back_fender_0,V_object->name_to_Vox_map.at("body_dark"));
	V_object->draw_line_segment(center+d_left_sill_front,center+d_left_sill_back,V_object->name_to_Vox_map.at("body_dark"));
	V_object->draw_line_segment(center+d_left_sill_front,center+d_left_front_fender_0,V_object->name_to_Vox_map.at("body_dark"));
	V_object->draw_line_segment(center+d_left_front_fender_0,center+d_left_front_fender_1,V_object->name_to_Vox_map.at("body_dark"));

	V_object->draw_line_segment(center+d_right_back_fender_0,center+d_right_back_fender_1,V_object->name_to_Vox_map.at("body_dark"));
	V_object->draw_line_segment(center+d_right_sill_back,center+d_right_back_fender_0,V_object->name_to_Vox_map.at("body_dark"));
	V_object->draw_line_segment(center+d_right_sill_front,center+d_right_sill_back,V_object->name_to_Vox_map.at("body_dark"));
	V_object->draw_line_segment(center+d_right_sill_front,center+d_right_front_fender_0,V_object->name_to_Vox_map.at("body_dark"));
	V_object->draw_line_segment(center+d_right_front_fender_0,center+d_right_front_fender_1,V_object->name_to_Vox_map.at("body_dark"));



	if(VORALDO_DEBUG)
		cout << "finished drawing body sills" << endl;
}
