using namespace std;
#include<GL/glut.h>
#include<iostream>

float pts[4][3] = {{0,0,1},{0,1,-1},{-1,-1,-1},{1,-1,-1}};
int k;

void draw_tri(float p1[3], float p2[3], float p3[3]){
	glBegin(GL_POLYGON);
	glVertex3fv(p1);
	glVertex3fv(p2);
	glVertex3fv(p3);
	glEnd();
}


void divide_tri(float a[3], float b[3], float c[3], int k){
	if(k>0){
		float m1[3],m2[3],m3[3];
		for(int i=0; i<3; i++){
			m1[i] = (a[i]+b[i])/2;
			m2[i] = (b[i]+c[i])/2;
			m3[i] = (a[i]+c[i])/2;
		}
		divide_tri(a,m1,m3,k-1);
		divide_tri(b,m1,m2,k-1);
		divide_tri(c,m2,m3,k-1);
	}
	else{
		draw_tri(a,b,c);
	}
}

void draw_tetrahedron(){
	glColor3f(0,0,0);
	divide_tri(pts[1],pts[2],pts[3],k);

	glColor3f(1,0,0);
	divide_tri(pts[0],pts[1],pts[2],k);
	
	glColor3f(0,1,0);
	divide_tri(pts[0],pts[2],pts[3],k);
	
	glColor3f(0,0,1);
	divide_tri(pts[0],pts[1],pts[3],k);	
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	draw_tetrahedron();
	glPopMatrix();
	glFlush();
}

void init(){
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2,2,-2,2,-2,2);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
	cout<<"Enter the value of k: ";
	cin >>k;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB |GLUT_SINGLE |GLUT_DEPTH);
	glutInitWindowSize(600,600);
	glutCreateWindow("3D Operations");
	init();
	glEnable(GL_DEPTH_TEST);	

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
