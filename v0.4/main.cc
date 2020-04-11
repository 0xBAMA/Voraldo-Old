#include <iostream>
#include <string>
#include <chrono>
#include "includes/voraldo/V4.h"


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


//for multithreading
int n = 4;

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

	//call Car.draw();
	Car* car1 = new Car();

	car1->init(main_block);
	car1->draw(true,0,3.14/4.0,0);

//	main_block->legacy_display("output.bmp");
	main_block->display("new_output.bmp", 3.14, 3.14/3.0, 3.14/3.0, 0.4, false);





	main_block->init_block(init_x, init_y, init_z, true);


	auto frame_tick = Clock::now();
	auto frame_tock = Clock::now();

	double multithread_limit = n*1.57;
	double multithread_start = 0.14;//multithread_limit-1.57;
	int k;



	//
	//
	// for(double i = multithread_start; i < multithread_limit; i+=0.01)// 0 - 1.57 - 3.14 - 4.71 - 6.28
	// {
	//
	// 	k = int(i*100);
	//
	// 	frame_tick = Clock::now();
	// 	car1->draw(true,0,-i,0);
	// 	if(k < 10)
	// 	{
	// 		main_block->display("frames/output00"+std::to_string(k)+".bmp", 3.14, (3.14/3.0)-i, (3.14/3.0)-i,0.4);
	// 	}
	// 	else if(k < 100)
	// 	{
	// 		main_block->display("frames/output0"+std::to_string(k)+".bmp", 3.14, (3.14/3.0)-i, (3.14/3.0)-i,0.4);
	// 	}
	// 	else
	// 	{
	// 		main_block->display("frames/output"+std::to_string(k)+".bmp", 3.14, (3.14/3.0)-i, (3.14/3.0)-i,0.4);
	// 	}
	//
	// 	main_block->init_block(init_x, init_y, init_z, true);
	//
	// 	frame_tock = Clock::now();
	//
	// 	cout << "frame " << k << " took " << std::chrono::duration_cast<milliseconds>(frame_tock-frame_tick).count() << " ms"<< endl;
	// 	k++;
	// }

	tock = Clock::now();

	cout<< "-----------------" << endl;
	cout<< "Total display for  "
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
