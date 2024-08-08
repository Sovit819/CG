#include<GL/glut.h>

#define blast 1
#define roc 0

int flag = roc;
float ty=0.0;

void rocket(){
    glColor3f(1,0,0);
    glPushMatrix();
    glTranslatef(0,1,0);
    glRotatef(-90,1,0,0);
    glutSolidCone(1.2,2,5,5);
    glPopMatrix();
    glColor3f(1,1,0);
    glutSolidCube(2);

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,0,5,0,0,0,0,1,0);
    if(flag==blast){
        glPushMatrix();
        glTranslatef(0,ty,0);
        glPushMatrix();
        glTranslatef(0,-3,0);
        rocket();
        glPopMatrix();
        ty+=0.01;
        glPopMatrix();
        glutPostRedisplay();

    }else if(flag == roc){
        ty=0;
        glPushMatrix();
        glTranslatef(0,-3,0);
        rocket();
        glPopMatrix();
    }
    glutSwapBuffers();
    glFlush(); 
}

void init(){
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-5,5,-5,5,-5,5);
    glMatrixMode(GL_MODELVIEW);
}

void keys(unsigned char key, int x, int y){
    switch(key){
        case 'b': flag = blast; break;
        case 'r': flag = roc; break;
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE| GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("3D transformation");
    init();

    glEnable(GL_DEPTH_TEST);
    glutKeyboardFunc(keys);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
