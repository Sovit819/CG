#include<GL/glut.h>
#include<cmath>
int transform = -1;
#define translate 1
#define rotate 2
#define rotatepvt 3
#define scale 4
#define scalefp 5

float tri[3][3] = {{-100,100,0}, {-100,-100,100}, {1,1,1}};
float tx=100, ty=100;
float theta = 30, thetar = (theta*M_PI)/180;
float xr=-100, yr = -100;
float sx=1.5, sy=1.5, fx=-100, fy=-100;

void draw_tri(){
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<3; i++){
        int x = tri[0][i];
        int y = tri[1][i];
        glVertex2f(x,y);
    }
    glEnd();

    switch(transform){
        case translate:
            glBegin(GL_LINE_LOOP);
            for(int i=0; i<3; i++){
                int x = tri[0][i];
                int y = tri[1][i];
                glVertex2f(x+tx, y+ty);
            }
            glEnd();
            break;

        case rotate:
            glBegin(GL_LINE_LOOP);
            for(int i=0; i<3; i++){
                int x = tri[0][i];
                int y = tri[1][i];
                glVertex2f(x*cos(thetar)-y*sin(thetar), x*sin(thetar)+y*cos(thetar));
            }
            glEnd();
            break;

        case rotatepvt:
            glBegin(GL_LINE_LOOP);
            for(int i=0; i<3; i++){
                int x = tri[0][i];
                int y = tri[1][i];
                glVertex2f(xr+(x-xr)*cos(thetar)-(y-yr)*sin(thetar), yr+(x-xr)*sin(thetar)+(y-yr)*cos(thetar));
            }
            glEnd();
            break;

        case scale:
            glBegin(GL_LINE_LOOP);
            for(int i=0; i<3; i++){
                int x = tri[0][i];
                int y = tri[1][i];
                glVertex2f(x*sx, y*sy);
            }
            glEnd();
            break;
  
        case scalefp:
            glBegin(GL_LINE_LOOP);
            for(int i=0; i<3; i++){
                int x = tri[0][i];
                int y = tri[1][i];
                glVertex2f(fx+(x-fx)*sx, fy+(y-fy)*sy);
            }
            glEnd();
            break;
        

    }
}

void menu(int id){
    switch(id){
        case 0:
            ::exit(0);
            break;
        case 1:
            transform = translate;
            break;
    }
    glutPostRedisplay();
}

void rotateMenu(int id){
    switch(id){
        case 2:
            transform = rotate;
            break;
        case 3:
            transform = rotatepvt;
            break;
    }
    glutPostRedisplay();
}

void scaleMenu(int id){
    switch(id){
        case 4:
            transform = scale;
            break;
        case 5:
            transform = scalefp;
            break;
    }
    glutPostRedisplay();
}



void init(){
    glClearColor(1,1,1,1);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(-300,300,-300,300);
    glMatrixMode(GL_PROJECTION);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    draw_tri();

    glFlush();
}

int main(int argc , char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutCreateWindow("2D Operations");

    init();
    int rotate_Menu = glutCreateMenu(rotateMenu);
    glutAddMenuEntry("Rotate(Origin)", 2);
    glutAddMenuEntry("Rotate(Pivot)", 3);

    int scale_Menu = glutCreateMenu(scaleMenu);
    glutAddMenuEntry("Scale(Origin)", 4);
    glutAddMenuEntry("Scale(Fixed Point)", 5);

    glutCreateMenu(menu);
    glutAddMenuEntry("Translate", 1);
    glutAddSubMenu("Rotate", rotate_Menu);
    glutAddSubMenu("Scale", scale_Menu);
    glutAddMenuEntry("Exit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
