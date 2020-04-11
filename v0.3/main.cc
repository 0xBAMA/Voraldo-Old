#include <iostream>
#include <string>
#include <chrono>
#include "includes/voraldo/V3.h"

//stream class aliases
using std::cout;
using std::endl;
using std::cin;

//Chrono class aliases 
using Clock=std::chrono::high_resolution_clock;
using milliseconds=std::chrono::milliseconds;

//menu functions
void menu(); //present options and prompt to user
char user(); //get user input

void exit(); //responsible for deallocating memory 

Voraldo *main_block = NULL;

int init_x = 257;
int init_y = 257;
int init_z = 257;

int main(){
	char input = 0; //holds menu response

	auto tick = Clock::now(); //start of the timekeeping

	int num_bytes = init_x * init_y * init_z * sizeof(Vox);

	main_block = new Voraldo;
	main_block->init_block(init_x, init_y, init_z, true);

	auto tock = Clock::now(); //end of timekeeping
	cout<< "-----------------" << endl;
	cout<< "Dynamic memory allocation for " 
		<< init_x * init_y * init_z << " voxels took " 
		<< std::chrono::duration_cast<milliseconds>(tock-tick).count() 
		<< " milliseconds" << endl;

	cout<< "using " << std::setw(4) << float(num_bytes)/(1024.0*1024.0) 
		<< " megabytes" << endl;
	cout<< "-----------------" << endl;

	menu();

	input = user();

	tick = Clock::now();

	//drawing functions

	vec RRhub = vec(78,128,158);
	vec RRinner = vec(78,128,153);
	vec RRouter = vec(78,128,163);

	vec LRhub = vec(78,128,98);
	vec LRinner = vec(78,128,103);
	vec LRouter = vec(78,128,93);

	vec RFhub = vec(178,128,158);
	vec RFinner = vec(178,128,153);
	vec RFouter = vec(178,128,163);

	vec LFhub = vec(178,128,98);
	vec LFinner = vec(178,128,103);
	vec LFouter = vec(178,128,93);

	vec Rdiff = vec(78,128,128);
	vec Rdiff_Roffset = vec(78,128,138);
	vec Rdiff_Loffset = vec(78,128,118);
	vec Rdiff_Foffset = vec(84,128,128);

	vec Fdiff = vec(178,128,128);
	vec Fdiff_Roffset = vec(178,128,138);
	vec Fdiff_Loffset = vec(178,128,118);
	vec Fdiff_Boffset = vec(172,128,128);

	//Draw platform
	main_block->draw_blockoid(vec(0,0,0),vec(257,118,257),main_block->name_to_Vox_map.at("armor_0"));
	main_block->draw_ellipsoid(vec(128,118,128),vec(75,25,50),main_block->name_to_Vox_map.at("empty"));

	main_block->mask_all_nonzero();


	main_block->draw_blockoid(vec(0,112,0),vec(257,118,257),main_block->name_to_Vox_map.at("clear_blue_glass"));
	main_block->draw_blockoid(vec(70,114,0),vec(86,116,257),main_block->name_to_Vox_map.at("space_gas_5"));
	main_block->draw_blockoid(vec(170,114,0),vec(186,116,257),main_block->name_to_Vox_map.at("space_gas_5"));



	main_block->unmask_all();

	//Draw driveline/axles
	main_block->draw_cylinder(Rdiff,Fdiff,1,main_block->name_to_Vox_map.at("blue_light"));

	main_block->draw_cylinder(LRhub,RRhub,1,main_block->name_to_Vox_map.at("blue_light"));
	main_block->draw_cylinder(LFhub,RFhub,1,main_block->name_to_Vox_map.at("blue_light"));

	main_block->mask_all_nonzero();

	//Draw hubs
	main_block->draw_cylinder(LFhub,LFinner,2.75,main_block->name_to_Vox_map.at("red_light"));
	main_block->draw_cylinder(RFhub,RFinner,2.75,main_block->name_to_Vox_map.at("red_light"));
	main_block->draw_cylinder(LRhub,LRinner,2.75,main_block->name_to_Vox_map.at("red_light"));
	main_block->draw_cylinder(RRhub,RRinner,2.75,main_block->name_to_Vox_map.at("red_light"));

	main_block->mask_all_nonzero();

	//Draw rear diff
	main_block->draw_sphere(Rdiff,3.8, main_block->name_to_Vox_map.at("diff"));
	main_block->draw_cylinder(Rdiff,Rdiff_Roffset,2.3,main_block->name_to_Vox_map.at("diff"));
	main_block->draw_cylinder(Rdiff,Rdiff_Loffset,2.3,main_block->name_to_Vox_map.at("diff"));
	main_block->draw_cylinder(Rdiff,Rdiff_Foffset,2.3,main_block->name_to_Vox_map.at("diff"));

	main_block->draw_sphere(Rdiff_Foffset,1.5, main_block->name_to_Vox_map.at("electrical"));

	//Draw front diff
	main_block->draw_sphere(Fdiff,3.8, main_block->name_to_Vox_map.at("diff"));
	main_block->draw_cylinder(Fdiff,Fdiff_Roffset,2.3,main_block->name_to_Vox_map.at("diff"));
	main_block->draw_cylinder(Fdiff,Fdiff_Loffset,2.3,main_block->name_to_Vox_map.at("diff"));
	main_block->draw_cylinder(Fdiff,Fdiff_Boffset,2.3,main_block->name_to_Vox_map.at("diff"));

	//Draw wheels and tires
	main_block->draw_cylinder(LFinner,LFouter,8,main_block->name_to_Vox_map.at("space_gas_5"));
	main_block->draw_cylinder(RFinner,RFouter,8,main_block->name_to_Vox_map.at("space_gas_5"));
	main_block->draw_cylinder(LRinner,LRouter,8,main_block->name_to_Vox_map.at("space_gas_5"));
	main_block->draw_cylinder(RRinner,RRouter,8,main_block->name_to_Vox_map.at("space_gas_5"));

	main_block->draw_tube(LFinner,LFouter,7.5,10,main_block->name_to_Vox_map.at("solid_black"));
	main_block->draw_tube(RFinner,RFouter,7.5,10,main_block->name_to_Vox_map.at("solid_black"));
	main_block->draw_tube(LRinner,LRouter,7.5,10,main_block->name_to_Vox_map.at("solid_black"));
	main_block->draw_tube(RRinner,RRouter,7.5,10,main_block->name_to_Vox_map.at("solid_black"));

	main_block->draw_tube(LFinner,LFouter,9.75,10.5,main_block->name_to_Vox_map.at("space_gas_solid"));
	main_block->draw_tube(RFinner,RFouter,9.75,10.5,main_block->name_to_Vox_map.at("space_gas_solid"));
	main_block->draw_tube(LRinner,LRouter,9.75,10.5,main_block->name_to_Vox_map.at("space_gas_solid"));
	main_block->draw_tube(RRinner,RRouter,9.75,10.5,main_block->name_to_Vox_map.at("space_gas_solid"));

	//end of drawing functions

	tock = Clock::now();

	cout<< "-----------------" << endl;
	cout<< "all drawing took " 
	<< std::chrono::duration_cast<milliseconds>(tock-tick).count() 
	<< " milliseconds" << endl;
	cout<< "-----------------" << endl << endl;



	tick = Clock::now();

	main_block->display();

	tock = Clock::now();

	cout<< "-----------------" << endl;
	cout<< "Displaying the block of  " 
	<< init_x * init_y * init_z << " voxels took " 
	<< std::chrono::duration_cast<milliseconds>(tock-tick).count() 
	<< " milliseconds" << endl;
	cout<< "-----------------" << endl << endl;



	
	exit();

	return 0;

}

void menu(){
	cout << endl << endl
		<< "Hit any letter, followed by enter, to exit." 
		<< endl << endl;

	cout << "Enter a letter." << endl;
	cout << ">";
}

char user(){
	char temp;
	cin >> temp;
	return temp;
}

void exit(){ //this deletes all allocated dynamic memory
	auto tick = Clock::now(); //start of the timekeeping
	delete main_block;
	auto tock = Clock::now(); //end of timekeeping

	int num_bytes = init_x * init_y * init_z * sizeof(Vox);

	cout<< "-----------------" << endl;
	cout<< "Dynamic memory deallocation took " 
		<< std::chrono::duration_cast<milliseconds>(tock-tick).count() 
		<< " milliseconds" << endl;

	cout<< "freeing " << std::setw(4) << float(num_bytes)/(1024.0*1024.0)
		<< " megabytes" << endl;
	cout<< "-----------------" << endl;

}