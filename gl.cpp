#include"common.h"
extern opengl OPENGL;
extern ga GA;
extern ga GA_array[VISIT_NUM];

void opengl::init(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void opengl::resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho(-w / 60.0, w / 60.0, -h / 60.0, h / 60.0, -1.0, 1.0);
}

void opengl::render_string(double x, double y, const char* string) {
    float z = -1.0f;
    glColor3f(0, 0, 0);
    glRasterPos3d(x + 0.1, y - 0.05, z);
    char* p = (char*)string;
    while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
    
}

void opengl::timer(int value) {
    float tick = 0.9;
    static GLboolean isUp = GL_TRUE;
    if (tick > 9) isUp = GL_FALSE;
    else if (tick < -9) isUp = GL_TRUE;
    tick += (isUp == GL_TRUE ? 1 : -1);
    glutPostRedisplay();
    glutTimerFunc(WAITTIME, OPENGL.timer, 0);
}

void opengl::line(double x_init, double y_init, double x_end, double y_end) {
    glColor3d(1.0, 0.5, 0.5);
    glLineWidth(WIDTH);
    glBegin(GL_LINES);
    glVertex2d(x_init, y_init);
    glVertex2d(x_end, y_end);
    glEnd();
}

void opengl::line_position(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n) {
    
    int point_array[VISIT_NUM] = { a,b,c,d,e,f,g,h,i,j,k,l,m,n };
    
    for (int count = 0; count < VISIT_NUM; count++) {
        if (count == VISIT_NUM - 1) {
            line(GA_array[point_array[count]].x, GA_array[point_array[count]].y, GA_array[point_array[0]].x, GA_array[point_array[0]].y);
        }
        else {
            line(GA_array[point_array[count]].x, GA_array[point_array[count]].y, GA_array[point_array[count + 1]].x, GA_array[point_array[count + 1]].y);
        }
    }
}

void opengl::point(double x, double y, const char* name) {
    
    glColor3d(0.5, 0.5, 1.0);
    glPointSize(POINTSIZE);
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
    render_string(x, y, name);
}

void opengl::point_position() {
    for (int count = 0; count < VISIT_NUM; count++) {
        point(GA_array[count].x, GA_array[count].y, GA_array[count].name);
    }
}

void opengl::display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    OPENGL.point_position();
    GA.procedure();
    glFlush();
}