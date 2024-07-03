
#include<GL/glut.h>
#define BLAST_OFF 1
#define ROCKET 0

float ty = 0;
int flag= ROCKET;
float viewer[3] = {0,0,5};

void rocket(){
	glColor3f(1,0,0);
	glPushMatrix();
	glTranslatef(0,1,0);
	glRotatef(-90,1,0,0);
	glutSolidCone(1.1,1.5,5,5);
	glPopMatrix();
	
	glColor3f(1,1,0);
	glutSolidCube(2);
	
}


void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(viewer[0],viewer[1],viewer[2], 0,0,0,0,1,0);
	
	if(flag==BLAST_OFF){
		glPushMatrix();
		glTranslatef(0,ty,0);		
		glPushMatrix(); //translate the whole rocket to base
		glTranslatef(0,-3,0);
		rocket();
		glPopMatrix();
		ty+= 0.01; //keep translating up
		glPopMatrix();
		glutPostRedisplay();
		
	}else if(flag==ROCKET){
		ty=0;
		glPushMatrix(); //translate the whole rocket to base
		glTranslatef(0,-3,0);
		rocket();
		glPopMatrix();
	}
	glutSwapBuffers();
	glFlush();
}

void myinit(){
	glMatrixMode(GL_PROJECTION);
	glOrtho(-5,5,-5,5,2,20);
	glMatrixMode(GL_MODELVIEW);
}

void keys(unsigned char key, int x, int y){
	if(key=='x')viewer[0]+= 0.2;
	else if(key=='X')viewer[0] -= 0.2;
	else if(key=='y')viewer[1] += 0.2;
	else if(key=='Y')viewer[1] -= 0.2;
	else if(key=='z')viewer[2] -= 0.2;
	else if(key=='Z')viewer[2] += 0.2;
	
	//animation
	else if(key=='b') flag=BLAST_OFF;
	else if(key=='r') flag=ROCKET;
	glutPostRedisplay();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Animate 3D object");
	
	myinit();
	glutDisplayFunc(display);
	glutKeyboardFunc(keys);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
