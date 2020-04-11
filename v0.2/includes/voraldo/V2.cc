#include "../voraldo/V2.h"


void Block::init(int x, int y, int z)
{

	if(data != NULL)
	{
		delete[] data;
	}

	x_res = x;
	y_res = y;
	z_res = z;

	num_cells = x_res * y_res * z_res;

	data = new Vox[num_cells];

	for(int i = 0; i < num_cells; i++)
	{ //initialize arrays

		data[i].mask = false;


		//this makes nice noise, it's from the first iteration.
		int randcheck = std::rand()%696;
		if(randcheck == 69)
		{
			int s = rand()%256;
			data[i].color = get_RGB_for_state(s%16);
			data[i].size = std::rand()%3 ? 1:2;
				//randomly choose whether it gets alpha - weighted towards not
		}
		else
		{
			data[i].size = 0;
		}
	}
}



void Block::set_data_by_3d_index(int x,int y,int z,Vox set){

	//validate the input - make sure you are in the block
	bool x_valid = x < x_res && x >= 0;
	bool y_valid = y < y_res && y >= 0;
	bool z_valid = z < z_res && z >= 0;

	bool masked = data[get_array_index_by_xyz(x,y,z)].mask;

	//all dimensions valid, do as the user asks
	if(x_valid && y_valid && z_valid && !masked)
	{
		if(set.color.red <= 255&&set.color.green <= 255&&set.color.blue <= 255)
		{
			data[get_array_index_by_xyz(x,y,z)] = set;
		}
		else
		{
			data[get_array_index_by_xyz(x,y,z)].color = get_RGB_for_state(std::rand()%16);
		}
	}
	else
	{
		if(!masked)
		{
			std::cout << std::endl << "Invalid index for set_data_by_index()" << std::endl;

			std::cout << "you used " << std::to_string(x) << " for x which should be between 0 and ";
			std::cout << std::to_string(x_res) << std::endl;

			std::cout << "you used " << std::to_string(y) << " for y which should be between 0 and ";
			std::cout << std::to_string(y_res) << std::endl;

			std::cout << "you used " << std::to_string(z) << " for z which should be between 0 and ";
			std::cout << std::to_string(z_res) << std::endl;
		}
		else
		{
			std::cout << "Cell " 
				<< std::to_string(x) << " " 
				<< std::to_string(y) << " " 
				<< std::to_string(z) << " is masked";
		}
	}

	return;
}

Vox Block::get_data_by_3d_index(int x,int y,int z)
{

	//validate the input
	bool x_valid = x < x_res && x >= 0;
	bool y_valid = y < y_res && y >= 0;
	bool z_valid = z < z_res && z >= 0;

	if(x_valid && y_valid && z_valid)
	{
		return(data[get_array_index_by_xyz(x,y,z)]); //grab the data from the long 1d array
	}
	else
	{
		std::cout << std::endl << "Invalid index for get_data_by_3d_index()" << std::endl;

		Vox temp = {0,false};

		return(temp); //if it is outside, return an empty state 
	}
}


//Implementing this as a separate function keeps the logic more intact, I think
int Block::get_array_index_by_xyz(int x, int y, int z)
{
	return z*(y_res*x_res) + y*(x_res) + x; //this mapping was figured out on paper, but can be 
}	//described pretty succinctly - the z dimension is like pages, each of dimension x * y, then
	//the y dimension is like rows, each of dimension x, and the x dimension is the location 
	//within the row that has been specified by the z and y coordinates.


/*

Conditional Operator (inline if statment)
-----------------------------------------

x ? y : z

works like

if(x) y else z



Just a note, this:
------------------

a = x ? : y;

is the same as:

a = x ? x : y;

*/

Voraldo::Voraldo()
{

}

Voraldo::Voraldo(int x, int y, int z)
{
	Vblock = new Block;
	Vblock->init(x,y,z);
}


Voraldo::~Voraldo()
{
	std::cout << "deleting voraldo object" << std::endl; 
	delete Vblock;
}

void Voraldo::display()
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
	const unsigned char white[3] = {255,255,255};

//vertical dividers
	img.draw_line(1001,0,1001,3004,gold);
	img.draw_line(2003,0,2003,3004,gold);

//horizontal dividers
	img.draw_line(0,1001,3004,1001,gold);
	img.draw_line(0,2003,3004,2003,gold);

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

	for(int x = 0; x < Vblock->get_x_res(); x++)
	{
		for(int y = 0; y < Vblock->get_y_res(); y++)
		{
			for(int z = 0; z < Vblock->get_z_res(); z++)
			{
				color = Vblock->get_data_by_3d_index(x,y,z).color;
				size = Vblock->get_data_by_3d_index(x,y,z).size;
				for(int w = 0; w <= 8; w++)
				{	
					unsigned char color_char[3] = {color.red,color.green,color.blue};

					curr_x = int(floor(centers[w][0]+x*center_x_vecs[w][0]+y*center_y_vecs[w][0]+z*center_z_vecs[w][0]));
					curr_y = int(floor(centers[w][1]+x*center_x_vecs[w][1]+y*center_y_vecs[w][1]+z*center_z_vecs[w][1]));

					switch(size)
					{	
						case 1://point with alpha
							img.draw_point(curr_x,curr_y,color_char,0.3);
							break;
						case 2://point without alpha
							img.draw_point(curr_x,curr_y,color_char,1.0);
							break;
						case 3://size two with alpha
							img.draw_circle(curr_x,curr_y,1,color_char,0.3);
							break;
						case 4://size two without alpha
							img.draw_circle(curr_x,curr_y,1,color_char,1.0);
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

	img.save_bmp("output.bmp");
}



void Voraldo::save_block_to_file()
{
	//produce the JSON file "default.txt"
	nlohmann::json j;
	std::string filename = "save/default.txt"; 

	j["xdim"] = Vblock->get_x_res();
	j["ydim"] = Vblock->get_y_res();
	j["zdim"] = Vblock->get_z_res();

	j["image_filename"] = "save/default.png";

	std::fstream f;

	f.open(filename);

	f << j.dump();

	f.close();

	//produce the PNG image, with a default name
	//this doesn't actually happen right now.

	//eventually we need to figure out how this
	//is going to be structured. 

	using namespace cimg_library;

	int imagex = Vblock->get_x_res();
	int imagey = Vblock->get_y_res()*Vblock->get_z_res();

	CImg<unsigned char> img(imagex,imagey,1,3,0);  
	//declare image with one color per pixel, one channel. 
	//full of 128 values, the dimensions are x = x-res, y = y-res*z-res

	const unsigned char color[] = { 255,128, 64};
	const unsigned char c0[] = {255,128, 64};
	const unsigned char c1[] = { 98, 12, 14};
	const unsigned char c17[] = { 128, 4,168};

	img.draw_point(50,50,color);

	int index = 0;

	for (int y = 0; y < imagey; y++)
	{
		for (int x = 0; x < imagex; x++)
		{

			//can get away with a 2d array, on account of it being a 2d image
			//with a lot of rows. The format is very compatible with the 1d
			//representation of the block, since it is written out in the
			//same general order as you would read text, left to right and
			//top to bottom.

			RGB temp = Vblock->get_data_by_array_index(index).color;

			unsigned char color[3] = {temp.red,temp.blue,temp.green};
			unsigned char black[3] = {0,0,0};

			if(color == black)
			{

			}
			else
			{
				img.draw_point(x,y,color);
			}

			// switch(temp_state)
			// {
			// 	case 0:
			// 		img.draw_point(x,y,c0);
			// 		break;
			// 	case 1:
			// 		img.draw_point(x,y,c1);
			// 		break;
			// 	case 17:
			// 		img.draw_point(x,y,c17);
			// 		break;
			// 	default:
			// 		break;
			// }

			index++;
		}
	}

	img.save_bmp("example.bmp");

}

void Voraldo::load_block_from_file()
{

	//this needs to delete any existing data and make new data from the file





	//load the JSON file, "default.txt"

	//code to load file into block
	//check dimensions first and then load it all in
	int tempx = 0;
	int tempy = 0;  //variables for incoming json values
	int tempz = 0;

	std::string filename = "save/default.txt";

	nlohmann::json j; //declare json object
	std::fstream f;	  //declare fstream object

	f.open(filename); //open the user's file

	f >> j;			  //read in all the content of that file

	tempx = j.value("xdim",0);
	tempy = j.value("ydim",0); //take some specific values from the json input file
	tempz = j.value("zdim",0);	
	//the formatting is j.value("key name", "default value if key not found")



	//load the PNG image, with a name specified by the JSON file
	//this doesn't actually happen right now.

}

void Voraldo::draw_point(int x, int y, int z, Vox state)
{
	Vblock->set_data_by_3d_index(x,y,z,state);
}

void Voraldo::draw_line_segment(vec v1, vec v2, Vox state)
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
		draw_point(current_point[0],current_point[1],current_point[2],state);
	}
}


void Voraldo::draw_triangle(vec v0, vec v1, vec v2, Vox state)
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
		draw_point(v0[0],v0[1],v0[2],state);
		draw_point(v1[0],v1[1],v1[2],state);
		draw_point(v2[0],v2[1],v2[2],state);
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

			draw_line_segment(c1,c2,state);
		}
	}

}

void Voraldo::draw_sphere(int x, int y, int z, int radius, Vox state)
{
	for(int i = 0; i < Vblock->get_x_res(); i++)
	{	
		for(int j = 0; j < Vblock->get_y_res(); j++)
		{
			for(int k = 0; k < Vblock->get_z_res(); k++)
			{
				double testx = (i-x)*(i-x);	//apply offsets and square
				double testy = (j-y)*(j-y);
				double testz = (k-z)*(k-z);

				if((testx + testy + testz) < radius*radius)
				{	//pretty self explainatory, equation of sphere
					Vblock->set_data_by_3d_index(i,j,k,state);
				}
			}
		}
	}
}

void Voraldo::draw_ellipsoid(int x, int y, int z, int xrad, int yrad, int zrad, Vox state)
{
	for(int i = 0; i < Vblock->get_x_res(); i++)
	{	
		for(int j = 0; j < Vblock->get_y_res(); j++)
		{
			for(int k = 0; k < Vblock->get_z_res(); k++)
			{
				double testx = (i-x)*(i-x);	//apply offsets and square
				double testy = (j-y)*(j-y);
				double testz = (k-z)*(k-z);

				double radx = xrad*xrad;
				double rady = yrad*yrad;
				double radz = zrad*zrad;

				double result = testx/radx + testy/rady + testz/radz;

				if(result <= 1){	//point inside ellipsoid - do we want to be able to invert this?
					//(outside, or on the surface, with >= and ==, respectively)
					Vblock->set_data_by_3d_index(i,j,k,state); 
				}
			}
		}
	}
}

void Voraldo::draw_cylinder()
{

}

void Voraldo::draw_blockoid(int xmin, int xmax, int ymin, int ymax, int zmin, int zmax, Vox state)
{
	for(int i = 0; i < Vblock->get_x_res(); i++)
	{	
		for(int j = 0; j < Vblock->get_y_res(); j++)
		{
			for(int k = 0; k < Vblock->get_z_res(); k++)
			{

				bool xtest = i <= xmax && i >= xmin;
				bool ytest = j <= ymax && j >= ymin;
				bool ztest = k <= zmax && k >= zmin;

				if(xtest && ytest && ztest){
					Vblock->set_data_by_3d_index(i,j,k,state);
				}
			}
		}
	}
}

void Voraldo::draw_quadrilateral_hexahedron(vec a, vec b, vec c, vec d, vec e, vec f, vec g, vec h, Vox state)
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

	for(int i = 0; i < Vblock->get_x_res(); i++)
	{	
		for(int j = 0; j < Vblock->get_y_res(); j++)
		{
			for(int k = 0; k < Vblock->get_z_res(); k++)
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
					Vblock->set_data_by_3d_index(i,j,k,state);
				}
			}
		}
	}
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