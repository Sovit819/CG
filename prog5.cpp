#include <GL/glut.h>

float pts[4][3] = {{0,0,1},{0,1,-1}, {-1,-1,-1},{1,-1,-1}};

float tx = 0.0, ty = 0.0, tz = 0.0; 
float angle = 0.0;
float sx = 1.0, sy = 1.0, sz = 1.0;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 10.0); 
    glMatrixMode(GL_MODELVIEW);
}

void draw_tri(float p1[3], float p2[3], float p3[3]){
    glBegin(GL_POLYGON);
    glVertex3fv(p1); glVertex3fv(p2); glVertex3fv(p3);
    glEnd();
}

void draw_tetrahedron(){
    glColor3f(0,0,0);
    draw_tri(pts[1],pts[2],pts[3]);

    glColor3f(0,1,0);
    draw_tri(pts[0], pts[1], pts[2]);

    glColor3f(0,0,1);
    draw_tri(pts[0],pts[2], pts[3]);

    glColor3f(1,0,0);
    draw_tri(pts[0], pts[1],pts[3]);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 2.0, 0.0,  
              0.0, 0.0, 0.0,  
              0.0, 0.0, 1.0);

    glPushMatrix();
    glTranslatef(tx, ty, tz); 
    glRotatef(angle, 1.0, 1.0, 1.0); 
    glScalef(sx, sy, sz);
    draw_tetrahedron(); 
    glPopMatrix();
    
    glutSwapBuffers();
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'x': tx += 0.1; break; // Translate right
        case 'X': tx -= 0.1; break; // Translate left
        case 'y': ty += 0.1; break; // Translate up
        case 'Y': ty -= 0.1; break; // Translate down
        case 'z': tz += 0.1; break; // Translate forward
        case 'Z': tz -= 0.1; break; // Translate backward
        case 'r': angle += 5.0; break; // Rotate clockwise
        case 'R': angle -= 5.0; break; // Rotate counterclockwise
        case 's': sx += 0.1; sy += 0.1; sz += 0.1; break; // Scale up
        case 'S': sx -= 0.1; sy -= 0.1; sz -= 0.1; break; // Scale down
        case 27: exit(0); // ESC key to exit
        default: break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Basic 3D Transformations with Triangle");
    
    init();
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
}
