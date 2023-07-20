#include"common.h"
opengl OPENGL;
ga GA;
ga GA_array[VISIT_NUM];

int main(int argc, char *argv[]) {
    
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    GA.setting();
    srand((unsigned) time(NULL));
    glutDisplayFunc(OPENGL.display);
    glutReshapeFunc(OPENGL.resize);
    glutTimerFunc(WAITTIME, OPENGL.timer, 0);
    OPENGL.init();
    glutMainLoop();
    
    return 0;
    
}