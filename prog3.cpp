using namespace std;
#include<GL/glut.h>
#include<iostream>

float tri[3][3] = {{-100,100,0},{-100,-100,100},{1,1,1,}};
int n=3;
int transform = -1;
#define translate 1
#define rotate 2
#define rotate_pvt 3

float tx=50, ty=50;
float theta = 30, pvx = -100, pvy = -100;

void draw_tri(){
	cout << "Display function called with transform: " << transform << endl;
	glBegin(GL_LINE_LOOP);
	for(int i=0; i<n; i++){
		glVertex2f(tri[0][i], tri[1][i]);
	}
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	draw_tri();
	switch(transform){
		case translate:
			glColor3f(0,1,0);
			glPushMatrix();
			glTranslatef(tx,ty,0);
			draw_tri();
			glPopMatrix();
			break;
		case rotate:
			glColor3f(0,1,0);
			glPushMatrix();
			glRotatef(theta,0,0,1);
			draw_tri();
			glPopMatrix();
			break;
		case rotate_pvt:
			glColor3f(0,1,0);
			glPushMatrix();
			glTranslatef(pvx,pvy,0);
			glRotatef(theta,0,0,1);
			glTranslatef(-pvx,-pvy,0);
			draw_tri();
			glPopMatrix();
			break;
	}
	glFlush();
}


void menu(int id){
	switch(id){
	case 0:
		exit(0);
		break;
	case 1:
		transform = translate;
		break;
	}
	glutPostRedisplay();
}
void rotMenu(int id){
	switch(id){
	case 2:
		transform = rotate;
		break;
	case 3: 
		transform = rotate_pvt;
		break;
	}
	glutPostRedisplay();
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
	glutCreateWindow("2D Transformation");
	init();

	int rot_menu = glutCreateMenu(rotMenu);
	glutAddMenuEntry("Rotate about origin",2);
	glutAddMenuEntry("Rotata about pivot point",3);

	glutDisplayFunc(display);

	glutCreateMenu(menu);
	glutAddMenuEntry("Exit",0);
	glutAddMenuEntry("Translate",1);
	glutAddSubMenu("Rotate",rot_menu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	glutMainLoop();
	return 0;
}



