#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void demo_menu(int id);
void mouse_callback_function(int button, int state, int x, int y); //menu callback
void myinit(void);
void display( void );
void display10000RandomColor(void);
void displayR_3_8(void);


void myinit(void)
{
 
/* attributes */
glEnable(GL_BLEND);
 	  glClearColor(1.0, 1.0, 1.0, 0.0); /* white background */
	   glColor3f(1.0, 0.0, 0.0); /* draw in red */

/* set up viewing */
/* 500 x 500 window with origin lower left */
	

	   glMatrixMode(GL_PROJECTION);
	   glLoadIdentity();
	   gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	   glMatrixMode(GL_MODELVIEW);

	   glutCreateMenu(demo_menu);
	glutAddMenuEntry("8000 σημεία",1);
	glutAddMenuEntry("10000 σημεία, τυχαίο χρώμα",2);
	glutAddMenuEntry("Πεντάγωνο r=3/8",3);
	glutAddMenuEntry("Πεντάγωνο r=1/3",4);
	glutAddMenuEntry("Τερματισμός", 5);

	glutAttachMenu(GLUT_RIGHT_BUTTON
);
	   
}

void demo_menu(int id) //menu callback
{ if(id==5) exit(0);}




void display( void )
{

/* define a point data type */

    typedef GLfloat point2[2];     

    point2 vertices[5]={{250.0,500.0},{488.0,327.0},{397.0,48.0},{103.0,48.0},{12.0,327.0}}; /* A triangle */

    int i, j, k;
    //long rand();       /* standard random number generator */
    point2 p ={250.0,250.0};  /* An srbitrary initial point */

    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */


/* computes and plots 5000 new points */

    for( k=0; k<10000; k++)
    {
	      j=rand()%5; /* pick a vertex at random */	


     /* Compute point halfway between vertex and old point */

	      p[0] = (p[0]-vertices[j][0])/3.0 + vertices [j][0]; 
	      p[1] = (p[1]-vertices[j][1])/3.0 +vertices[j][1];
	
     /* plot new point */

	       glBegin(GL_POINTS);
		         glVertex2fv(p); 
	       glEnd();
	
     }
     glFlush(); /* clear buffers */
 }






void main(int argc, char** argv)
{

/* Standard GLUT initialization */

	    glutInit(&argc,argv);
	    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); /* default, not needed */
	    glutInitWindowSize(500,500); /* 500 x 500 pixel window */
	    glutInitWindowPosition(0,0); /* place window top left on display */
	    glutCreateWindow("Sierpinski Gasket"); /* window title */
	   glutDisplayFunc(displayR_3_8); /* display callback invoked when window opened */

     myinit(); /* set attributes */
	
	    glutMainLoop(); /* enter event loop */
}


void mouse_callback_function(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON){

	}
	

}


void display8000(void){
	
    typedef GLfloat point2[2];     

    point2 vertices[5]={{250.0,500.0},{488.0,327.0},{397.0,48.0},{103.0,48.0},{12.0,327.0}}; /* A triangle */

    int i, j, k;
    //long rand();       /* standard random number generator */
    point2 p ={250.0,250.0};  /* An srbitrary initial point */

    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */


/* computes and plots 5000 new points */

    for( k=0; k<8000; k++)
    {
	      j=rand()%5; /* pick a vertex at random */	


     /* Compute point halfway between vertex and old point */

	      p[0] = (p[0]-vertices[j][0])/3.0 + vertices [j][0]; 
	      p[1] = (p[1]-vertices[j][1])/3.0 +vertices[j][1];
	
     /* plot new point */

	       glBegin(GL_POINTS);
		         glVertex2fv(p); 
	       glEnd();
	
     }
     glFlush(); /* clear buffers */

}


void display10000RandomColor(void){
	 typedef GLfloat point2[2];     

    point2 vertices[5]={{250.0,500.0},{488.0,327.0},{397.0,48.0},{103.0,48.0},{12.0,327.0}}; /* A triangle */

    int i, j, k;
    //long rand();       /* standard random number generator */
    point2 p ={250.0,250.0};  /* An srbitrary initial point */

    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */


/* computes and plots 5000 new points */

    for( k=0; k<10000; k++)
    {
		
		/*pick random color*/
		
		float x = (float)rand()/(float)RAND_MAX;
		float y = (float)rand()/(float)RAND_MAX;
		float z = (float)rand() /(float)RAND_MAX ;
		glColor3f(x,y,z);

		
		





	      j=rand()%5; /* pick a vertex at random */	


     /* Compute point halfway between vertex and old point */

	      p[0] = (p[0]-vertices[j][0])/3.0 + vertices [j][0]; 
	      p[1] = (p[1]-vertices[j][1])/3.0 +vertices[j][1];
	
     /* plot new point */

	       glBegin(GL_POINTS);
		         glVertex2fv(p); 
	       glEnd();
	
     }
     glFlush(); /* clear buffers */
}

void displayR_3_8(void){
	 typedef GLfloat point2[2];     

    point2 vertices[5]={{250.0,500.0},{488.0,327.0},{397.0,48.0},{103.0,48.0},{12.0,327.0}}; /* A triangle */

    int i, j, k;
    //long rand();       /* standard random number generator */
    point2 p ={250.0,250.0};  /* An srbitrary initial point */

    glClear(GL_COLOR_BUFFER_BIT);  /*clear the window */


/* computes and plots 5000 new points */

    for( k=0; k<10000; k++)
    {
	


	      j=rand()%5; /* pick a vertex at random */	


     /* Compute point halfway between vertex and old point */

	      p[0] = (p[0]-vertices[j][0])*3.0/8.0 + vertices [j][0]; 
	      p[1] = (p[1]-vertices[j][1])*3.0/8.0 +vertices[j][1];
	
     /* plot new point */

	       glBegin(GL_POINTS);
		         glVertex2fv(p); 
	       glEnd();
	
     }
     glFlush(); /* clear buffers */
}







