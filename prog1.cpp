using namespace std;
#include<iostream>
#include<GL/glut.h>
float xa,ya,xb,yb;

void draw_pixel(int x, int y){
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

void bres(float xa, float xb, float ya, float yb){
	float dx = xb-xa;
	float dy = yb-ya;
	float m = dy/dx;
	
	float inc = 1;
	if(m<0) inc = -1;
	
	dx = abs(dx);
	dy = abs(dy);
	
	if(abs(m)<1){
		int p = 2*dy - dx;
		if(xa>xb){
			swap(xa,xb);
			swap(ya,yb);
		}
		
		while(xa < xb){
			if(p<0)
				p+= 2*dy;
			else{
				ya+= inc;
				p+= 2*dy -2*dx;
			}
			draw_pixel(xa,ya);
			xa++;
		}
	}
	
	else if(abs(m)>=1){
		int p = 2*dx - dy;
		if(ya>yb){
			swap(xa,xb);
			swap(ya,yb);
		}
		while(ya<yb){
			if(p<0)
				p+= 2*dx;
			else{
				p+= 2*dx - 2*dy;
				xa+= inc;
			}
			draw_pixel(xa,ya);
			ya++;
		}
		
	}
	
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	bres(xa,xb,ya,yb);
	// glPointSize(3.0);
	draw_pixel(xa,ya);
	draw_pixel(xb,yb);
	
	glFlush();
}

void init(){
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,499,0,499);
	glMatrixMode(GL_MODELVIEW);
}	

int main(int argc, char** argv){
	cout<<"Enter (xa,ya), (xb,yb)";
	cin >>xa>>ya>>xb>>yb;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(800,800);
	glutCreateWindow("Bresenham's algo");
	init();
	
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}


	
	
	
	
	
	
	
	



