using namespace std;
#include<cmath>
#include<GL/glut.h>

float tri[3][3] ={{-100,100,0},{-100,-100,100},{1,1,1}};
float tx = 50, ty=50;
float theta=30;
float thetar = theta*(M_PI/180);
float xr=-100, yr=-100;
float sx=1.5, sy=1.5;
float fx=-100, fy=-100;

void draw_tri(){
	glBegin(GL_LINE_LOOP);
	for(int i=0; i<3; i++)
		glVertex2f(tri[0][i], tri[1][i]);
	glEnd();
}

void translate(float tx, float ty){
	glBegin(GL_LINE_LOOP);
	for(int i=0; i<3; i++){
		int x=tri[0][i];
		int y=tri[1][i];
		glVertex2f(x+tx, y+ty);
	}
	glEnd();
}

void rotate(float thetar, float pvx, float pvy){
	glBegin(GL_LINE_LOOP);
	for(int i=0; i<3; i++){
		int x = tri[0][i];
		int y = tri[1][i];
		//glVertex2f((x*cos(thetar)-y*sin(thetar)), (x*sin(thetar)+y*cos(thetar)));
		glVertex2f((xr+(x-xr)*cos(thetar)-(y-yr)*sin(thetar)),(yr+(x-xr)*sin(thetar)+(y-yr)*cos(thetar))); 
	}
	glEnd();
}

void scale(float sx, float sy, float fx, float fy){
	glBegin(GL_LINE_LOOP);
	for(int i=0; i<3; i++){
		int x = tri[0][i];
		int y = tri[1][i];
		//glVertex2f(x*sx, y*sy);
		glVertex2f((x*sx+fx*(1-sx)), y*sy+fy*(1-sy)); 
	}
	glEnd();
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	draw_tri();

	glColor3f(0,1,0);
	//translate(tx,ty);
	//rotate(thetar,xr,yr);
	scale(sx,sy,fx,fy);
	glFlush();
	
}
	
void init(){
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-250,250,-250,250);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutCreateWindow("2D Basic Operations");
	init();
	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
