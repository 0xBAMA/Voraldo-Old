// basic libraries
#include <iostream> //terminal I/O
#include <unistd.h> //sleep
#include <cstdlib>  //random number generation
#include <cstdio>
#include <vector>   //container
#include <string>

#include <math.h>   //sqrt, pow




//stream class shit
using std::cout;
using std::endl;
using std::cin;



//  ___________.___   _____  _____________________
//  \__    ___/|   | /     \ \_   _____/\______   \
//    |    |   |   |/  \ /  \ |    __)_  |       _/
//    |    |   |   /    Y    \|        \ |    |   \
//    |____|   |___\____|__  /_______  / |____|_  /
//                         \/        \/         \/

#include <chrono>
//Chrono class aliases

using Clock=std::chrono::high_resolution_clock;
using milliseconds=std::chrono::milliseconds;

Clock Interval_clock;

auto tick = Clock::now(); //variable to hold start of the timekeeping
auto tock = Clock::now(); //variable to hold end of timekeeping




//    ________.____        ________________________ _________________________
//   /  _____/|    |      /   _____/\__    ___/    |   \_   _____/\_   _____/
//  /   \  ___|    |      \_____  \   |    |  |    |   /|    __)   |    __)
//  \    \_\  \    |___   /        \  |    |  |    |  / |     \    |     \
//   \______  /_______ \ /_______  /  |____|  |______/  \___  /    \___  /
//          \/        \/         \/                         \/         \/


// GLEW
#define GLEW_STATIC
#include <GL/glew.h>


// GLUT
#include <GL/freeglut.h>
#include <GL/freeglut_ext.h>


// Shader Compilation
#include "../resources/shaders/Shader.h"


// CImg Image library
#include "../resources/CImg.h"


// Perlin noise - simple-to-use implementation from https://github.com/sol-prog/Perlin_Noise
#include "../resources/perlin.h"


// glsl-style Vector and Matrix Library - separate includes for different functionality
#include "../resources/glm/glm.hpp" //general types
#include "../resources/glm/gtc/matrix_transform.hpp" //orthographic view matrix (glm::ortho( left, right, bottom, top, zNear, zFar ))
#include "../resources/glm/gtc/type_ptr.hpp" //allows the sending of a matrix (weird workaround for glUniform...)


// this namespace contains, for either platform:
//		ortho() matrix variables
//		vector types, vector arrays for points and colors
//    image dimensions
// 		definition of point size
//		definition of rotation and rotation_direction toggles
//
//

namespace jb_OpenGL_Laptop{

	GLfloat left = -1.366f;
	GLfloat right = 1.366f;
	GLfloat top = -0.768f;
	GLfloat bottom = 0.768f;
	GLfloat zNear = -1.0f;
	GLfloat zFar = 1.0f;

	// don't really need this, it's really just for convenience
	typedef glm::vec4  color4;
	typedef glm::vec4  point4;



	// image dimensions, based on laptop screen resolution
	const int image_height = 768;
	const int image_width = 1366;


	// verticies - THINKPAD
	const int NumVertices = 150000;

	point4 points[NumVertices];
	color4 colors[NumVertices];




	// Array of rotation angles (in degrees) for each coordinate axis
	enum { Xaxis = 0, Yaxis = 1, Zaxis = 2, NumAxes = 3 };
	int      Axis = Xaxis;
	GLfloat  Theta[NumAxes] = { 0.0, 0.0, 0.0 };

	GLuint  theta;  // The location of the "theta" shader uniform variable
	GLuint  ortho_matrix;

	glm::mat4 Projection;

	bool rotate = true;
	bool rotation_direction = true;


	//initial value of point size
	GLfloat pointsize = 1.0;

}

namespace jb_OpenGL_Radeon{

	GLfloat left = -1.366f;
	GLfloat right = 1.366f;
	GLfloat top = -0.768f;
	GLfloat bottom = 0.768f;
	GLfloat zNear = -1.0f;
	GLfloat zFar = 1.0f;

	// don't really need this, it's really just for convenience
	typedef glm::vec4  color4;
	typedef glm::vec4  point4;



	// image dimensions, based on laptop screen resolution
	const int image_height = 768;
	const int image_width = 1366;


	// verticies - RADEON
	const int NumVertices = 64000000;

	point4 points[NumVertices];
	color4 colors[NumVertices];




	// Array of rotation angles (in degrees) for each coordinate axis
	enum { Xaxis = 0, Yaxis = 1, Zaxis = 2, NumAxes = 3 };
	int      Axis = Xaxis;
	GLfloat  Theta[NumAxes] = { 0.0, 0.0, 0.0 };

	GLuint  theta;  // The location of the "theta" shader uniform variable
	GLuint  ortho_matrix;

	glm::mat4 Projection;

	bool rotate = true;
	bool rotation_direction = true;


	//initial value of point size
	GLfloat pointsize = 1.0;

}


using namespace jb_OpenGL_Laptop;

//using namespace jb_OpenGL_Radeon;


//----------------------------------------------------------------------------

// // quad generates two triangles for each face and assigns colors
// //    to the vertices

// void
// quad( int a, int b, int c, int d )
// {
//     colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
//     colors[Index] = vertex_colors[b]; points[Index] = vertices[b]; Index++;
//     colors[Index] = vertex_colors[c]; points[Index] = vertices[c]; Index++;
//     colors[Index] = vertex_colors[a]; points[Index] = vertices[a]; Index++;
//     colors[Index] = vertex_colors[c]; points[Index] = vertices[c]; Index++;
//     colors[Index] = vertex_colors[d]; points[Index] = vertices[d]; Index++;
// }
//
// //----------------------------------------------------------------------------
//
// // generate 12 triangles: 36 vertices and 36 colors
// void
// colorcube()
// {
//     quad( 1, 0, 3, 2 );
//     quad( 2, 3, 7, 6 );
//     quad( 3, 0, 4, 7 );
//     quad( 6, 5, 1, 2 );
//     quad( 4, 5, 6, 7 );
//     quad( 5, 4, 0, 1 );
// }


// .___ _______  .______________
// |   |\      \ |   \__    ___/
// |   |/   |   \|   | |    |
// |   /    |    \   | |    |
// |___\____|__  /___| |____|
//             \/

//----------------------------------------------------------------------------

int Index = 0; //tracks the number of points generated

void gencube()
{
	GLfloat num;


	// THINKPAD
 	std::vector<GLfloat> range = {-0.5,-0.48,-0.46,-0.44,-0.42,-0.4,-0.38,-0.36,-0.34,-0.32,-0.3,-0.28,-0.26,-0.24,-0.22,-0.2,-0.18,-0.16,-0.14,-0.12,-0.1,-0.08,-0.06,-0.04,-0.02,0,0.02,0.04,0.06,0.08,0.1,0.12,0.14,0.16,0.18,0.2,0.22,0.24,0.26,0.28,0.3,0.32,0.34,0.36,0.38,0.4,0.42,0.44,0.46,0.48,0.5};



	// RADEON
	// std::vector<GLfloat> range = {-0.5,-0.497468,-0.494937,-0.492405,-0.489873,-0.487342,-0.48481,-0.482278,-0.479747,-0.477215,-0.474684,-0.472152,-0.46962,-0.467089,-0.464557,-0.462025,-0.459494,-0.456962,-0.45443,-0.451899,-0.449367,-0.446835,-0.444304,-0.441772,-0.439241,-0.436709,-0.434177,-0.431646,-0.429114,-0.426582,-0.424051,-0.421519,-0.418987,-0.416456,-0.413924,-0.411392,-0.408861,-0.406329,-0.403797,-0.401266,-0.398734,-0.396203,-0.393671,-0.391139,-0.388608,-0.386076,-0.383544,-0.381013,-0.378481,-0.375949,-0.373418,-0.370886,-0.368354,-0.365823,-0.363291,-0.360759,-0.358228,-0.355696,-0.353165,-0.350633,-0.348101,-0.34557,-0.343038,-0.340506,-0.337975,-0.335443,-0.332911,-0.33038,-0.327848,-0.325316,-0.322785,-0.320253,-0.317722,-0.31519,-0.312658,-0.310127,-0.307595,-0.305063,-0.302532,-0.3,-0.297468,-0.294937,-0.292405,-0.289873,-0.287342,-0.28481,-0.282278,-0.279747,-0.277215,-0.274684,-0.272152,-0.26962,-0.267089,-0.264557,-0.262025,-0.259494,-0.256962,-0.25443,-0.251899,-0.249367,-0.246835,-0.244304,-0.241772,-0.239241,-0.236709,-0.234177,-0.231646,-0.229114,-0.226582,-0.224051,-0.221519,-0.218987,-0.216456,-0.213924,-0.211392,-0.208861,-0.206329,-0.203797,-0.201266,-0.198734,-0.196203,-0.193671,-0.191139,-0.188608,-0.186076,-0.183544,-0.181013,-0.178481,-0.175949,-0.173418,-0.170886,-0.168354,-0.165823,-0.163291,-0.160759,-0.158228,-0.155696,-0.153165,-0.150633,-0.148101,-0.14557,-0.143038,-0.140506,-0.137975,-0.135443,-0.132911,-0.13038,-0.127848,-0.125316,-0.122785,-0.120253,-0.117722,-0.11519,-0.112658,-0.110127,-0.107595,-0.105063,-0.102532,-0.1,-0.0974684,-0.0949367,-0.0924051,-0.0898734,-0.0873418,-0.0848101,-0.0822785,-0.0797468,-0.0772152,-0.0746835,-0.0721519,-0.0696203,-0.0670886,-0.064557,-0.0620253,-0.0594937,-0.056962,-0.0544304,-0.0518987,-0.0493671,-0.0468354,-0.0443038,-0.0417721,-0.0392405,-0.0367089,-0.0341772,-0.0316456,-0.0291139,-0.0265823,-0.0240506,-0.021519,-0.0189873,-0.0164557,-0.013924,-0.0113924,-0.00886076,-0.00632911,-0.00379747,-0.00126582,0,0.00126583,0.00379747,0.00632912,0.00886076,0.0113924,0.0139241,0.0164557,0.0189873,0.021519,0.0240506,0.0265823,0.0291139,0.0316456,0.0341772,0.0367089,0.0392405,0.0417722,0.0443038,0.0468354,0.0493671,0.0518987,0.0544304,0.056962,0.0594937,0.0620253,0.064557,0.0670886,0.0696203,0.0721519,0.0746835,0.0772152,0.0797468,0.0822785,0.0848101,0.0873418,0.0898734,0.0924051,0.0949367,0.0974684,0.1,0.102532,0.105063,0.107595,0.110127,0.112658,0.11519,0.117722,0.120253,0.122785,0.125316,0.127848,0.13038,0.132911,0.135443,0.137975,0.140506,0.143038,0.14557,0.148101,0.150633,0.153165,0.155696,0.158228,0.160759,0.163291,0.165823,0.168354,0.170886,0.173418,0.175949,0.178481,0.181013,0.183544,0.186076,0.188608,0.191139,0.193671,0.196203,0.198734,0.201266,0.203797,0.206329,0.208861,0.211392,0.213924,0.216456,0.218987,0.221519,0.224051,0.226582,0.229114,0.231646,0.234177,0.236709,0.239241,0.241772,0.244304,0.246835,0.249367,0.251899,0.25443,0.256962,0.259494,0.262025,0.264557,0.267089,0.26962,0.272152,0.274684,0.277215,0.279747,0.282278,0.28481,0.287342,0.289873,0.292405,0.294937,0.297468,0.3,0.302532,0.305063,0.307595,0.310127,0.312658,0.31519,0.317722,0.320253,0.322785,0.325316,0.327848,0.33038,0.332911,0.335443,0.337975,0.340506,0.343038,0.34557,0.348101,0.350633,0.353165,0.355696,0.358228,0.360759,0.363291,0.365823,0.368354,0.370886,0.373418,0.375949,0.378481,0.381013,0.383544,0.386076,0.388608,0.391139,0.393671,0.396203,0.398734,0.401266,0.403797,0.406329,0.408861,0.411392,0.413924,0.416456,0.418987,0.421519,0.424051,0.426582,0.429114,0.431646,0.434177,0.436709,0.439241,0.441772,0.444304,0.446835,0.449367,0.451899,0.45443,0.456962,0.459494,0.462025,0.464557,0.467089,0.46962,0.472152,0.474684,0.477215,0.479747,0.482278,0.48481,0.487342,0.489873,0.492405,0.494937,0.497468,0.5};
	PerlinNoise p;

	for(const auto& x : range){
		for(const auto& y : range){
			for(const auto& z : range){
				points[Index] = point4(x,y,z,1.0);

				//num = double(rand())/double(RAND_MAX);

				if ( x==0 || y==0 || z==0 ){
					colors[Index] = color4(0.0,0.0,0.0,1.0);
				}
				else
				{
					// colors[Index] = color4(x+0.5,y+0.5,z+0.5,0.01);
					// colors[Index] = color4(0.0,0.0,0.3,0.1);

					float val = p.noise( 10*x, 10*y, 10*z );
					//float distance_to_zero = sqrt(pow(x2 - x1, 2) +  pow(y2 - y1, 2) +  pow(z2 - z1, 2) * 1.0);

					float distance_to_zero = sqrt( pow(x - 0, 2) +  pow(y - 0, 2) +  pow(z - 0, 2) * 1.0 );


					if( val < 0.3 )
					{
						colors[Index] = color4( p.noise( x, y, z ), 0.0, 1.0, 3.0 );
					}
					else if( val > 0.8 )
					{
						colors[Index] = color4( 1.0, p.noise( x, y, z ), 0.0, 3.0 );
					}
					else
					{
						// colors[Index] = color4( val, val, val, 0.5 - pow( distance_to_zero, 2 ) );
						colors[Index] = color4( val, val, val, 0.5 - distance_to_zero );

					}


				}

				Index++;
			}
		}
	}

	//done
}



// OpenGL initialization
void init( Shader s )
{
    // colorcube();

		gencube();

    // Create a vertex array object
    GLuint vao;
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );

    // Create and initialize a buffer object
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors), NULL, GL_STATIC_DRAW );
    glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(points), points );
    glBufferSubData( GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors );

    // Use the shader program ( input from and compiled in main() )

		s.Use();


    // set up vertex arrays

		// vertex locations
    GLuint vPosition = glGetAttribLocation( s.Program, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid*) (0) );


		// vertex colors
    GLuint vColor = glGetAttribLocation( s.Program, "vColor" );
    glEnableVertexAttribArray( vColor );
    glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid*) (sizeof(points)) );

		cout << sizeof( points );


		// uniform value for rotation
    theta = glGetUniformLocation( s.Program, "theta" );
		ortho_matrix = glGetUniformLocation( s.Program, "view" ); //allows the scaling to the screen dimensions`


		Projection = glm::ortho(left, right, top, bottom, zNear, zFar);

		glUniformMatrix4fv( ortho_matrix, 1, GL_FALSE,  glm::value_ptr( Projection ) );

		// enable z buffer for occlusion
    glEnable( GL_DEPTH_TEST );
		glEnable( GL_TEXTURE_3D );


		// alpha blending
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


		// glBlendFunc(sfactor, dfactor); ?? this is going to require more research

		// The enum values that are available for sfactor are as follows -

		// GL_ZERO,
    // GL_ONE,
    // GL_SRC_COLOR,
    // GL_ONE_MINUS_SRC_COLOR,
    // GL_DST_COLOR,
    // GL_ONE_MINUS_DST_COLOR,
    // GL_SRC_ALPHA,
    // GL_ONE_MINUS_SRC_ALPHA,
    // GL_DST_ALPHA,
    // GL_ONE_MINUS_DST_ALPHA,
    // GL_CONSTANT_COLOR,
    // GL_ONE_MINUS_CONSTANT_COLOR,
    // GL_CONSTANT_ALPHA,
    // GL_ONE_MINUS_CONSTANT_ALPHA,
    // GL_SRC_ALPHA_SATURATE

		// The enum values that are available for dfactor are as follows -

		// GL_ZERO,
    // GL_ONE,
    // GL_SRC_COLOR,
    // GL_ONE_MINUS_SRC_COLOR,
    // GL_DST_COLOR,
    // GL_ONE_MINUS_DST_COLOR,
    // GL_SRC_ALPHA,
    // GL_ONE_MINUS_SRC_ALPHA,
    // GL_DST_ALPHA,
    // GL_ONE_MINUS_DST_ALPHA,
    // GL_CONSTANT_COLOR,
    // GL_ONE_MINUS_CONSTANT_COLOR,
    // GL_CONSTANT_ALPHA,
    // GL_ONE_MINUS_CONSTANT_ALPHA


		// what color background?
    glClearColor( 1.0, 1.0, 1.0, 1.0 );
}



//   ________.____     ____ ______________
//  /  _____/|    |   |    |   \__    ___/
// /   \  ___|    |   |    |   / |    |
// \    \_\  \    |___|    |  /  |    |
//  \______  /_______ \______/   |____|
// 	    	 \/        \/

//----------------------------------------------------------------------------

int frame_timer_index = 0;
bool show_frame_time = false;


const int num_frames_history = 180;
int frame_times[num_frames_history];


void display( void )
{

		tick = Clock::now();



    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		// update the value of theta in the shader
    glUniform3fv( theta, 1, Theta );

		// the draw call
    glDrawArrays( GL_POINTS, 0, NumVertices );


    glutSwapBuffers();



		tock = Clock::now();

		if( frame_timer_index = num_frames_history ){ frame_timer_index = 0; }else{ frame_timer_index++; }

		frame_times[frame_timer_index] = ( int ) std::chrono::duration_cast<milliseconds>( tock - tick ).count( );

		if ( show_frame_time )
			std::cout << frame_times[frame_timer_index] << " milliseconds" << endl;


}

//----------------------------------------------------------------------------

void keyboard( unsigned char key, int x, int y )
{
    switch( key )
		{
			// quit
			case 033: // Escape Key
			case 'q': case 'Q':
			    exit( EXIT_SUCCESS );
			    break;

			// toggle rotation
			case 'r':
					//condition ? result_if_true : result_if_false
					rotate = rotate ? false : true;
					break;

			// change direction of rotation
			case 't':
					rotation_direction = rotation_direction ? false : true;
					break;

			// resize points
			case 'a':
					pointsize += 1;
					glPointSize( pointsize );
					break;
		  case 'z':
					pointsize -= 1;
					glPointSize( pointsize );
					break;


			// toggle frame counter
			case 'f':
			//condition ? result_if_true : result_if_false
			show_frame_time = show_frame_time ? false : true;
			break;

		  case 's':
				 left *= 1.1;
				 right *= 1.1;
				 top *= 1.1;
				 bottom *= 1.1;
				 zNear *= 1.1;
				 zFar *= 1.1;

				 Projection = glm::ortho(left, right, top, bottom, zNear, zFar);

		 			glUniformMatrix4fv( ortho_matrix, 1, GL_FALSE,  glm::value_ptr( Projection ) );
				 break;

		  case 'x':
					left *= 0.9;
					right *= 0.9;
					top *= 0.9;
					bottom *= 0.9;
					zNear *= 0.9;
					zFar *= 0.9;

					Projection = glm::ortho(left, right, top, bottom, zNear, zFar);

				 glUniformMatrix4fv( ortho_matrix, 1, GL_FALSE,  glm::value_ptr( Projection ) );
				break;
    }
}

//----------------------------------------------------------------------------

void mouse( int button, int state, int x, int y )
{
    if ( state == GLUT_DOWN )
		{
			switch( button )
			{
			    case GLUT_LEFT_BUTTON:    Axis = Xaxis;  break;
			    case GLUT_MIDDLE_BUTTON:  Axis = Yaxis;  break;
			    case GLUT_RIGHT_BUTTON:   Axis = Zaxis;  break;
			}
    }
}

//----------------------------------------------------------------------------

void idle( void )
{

		if( rotate ){
			if( rotation_direction ){
				Theta[Axis] += 0.1;

				if ( Theta[Axis] > 360.0 ) {
						Theta[Axis] -= 360.0;
				}
			}else{ //rotate the other way
				Theta[Axis] -= 0.1;

				if ( Theta[Axis] < 0.0 ) {
						Theta[Axis] += 360.0;
				}
			}
		}

    glutPostRedisplay();
}

//----------------------------------------------------------------------------



//    _____      _____  .___ _______
//   /     \    /  _  \ |   |\      \
//  /  \ /  \  /  /_\  \|   |/   |   \
// /    Y    \/    |    \   /    |    \
// \____|__  /\____|__  /___\____|__  /
// 		     \/         \/            \/


int main( int argc, char **argv )
{

	std::cout << "GLUT Initializing...";

	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
	glutInitWindowSize( image_width, image_height );
	glutInitContextVersion( 3, 2 );
	glutInitContextProfile( GLUT_CORE_PROFILE );
	glutCreateWindow( "Color Cube" );
	glutFullScreen();

	std::cout << "\rGLUT Initialization Complete." << std::endl;


	glewExperimental = GL_TRUE;
  glewInit();

	std::cout << "Shader Compilation Starting...";

	Shader theShader( "../resources/shaders/vertex_points.glsl", "../resources/shaders/fragment_points.glsl" );
	std::cout << "\rShader Compilation Complete.  " << std::endl;

	std::cout << "Generating Geometry";

  init( theShader );

	std::cout << "\rInitialization done." << std::endl;
	std::cout << "gencube() produced " << Index << " points" << std::endl;

  glutDisplayFunc( display );
  glutKeyboardFunc( keyboard );
  glutMouseFunc( mouse );
  glutIdleFunc( idle );

  glutMainLoop();

	std::cout << "Exiting" << std::endl;



	return 0;
}
