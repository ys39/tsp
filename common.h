#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>
#include <OPENGL/gl.h>
#include <math.h>
#include <vector>
#include <list>
#include <numeric>
#include <time.h>
#include <functional>
#include <algorithm>
using namespace std;
#ifndef _HEADER_
#define _HEADER_

const int INIT_INDI = 10;//初期個体数
const int VISIT_NUM = 14;//訪問数
const GLfloat WIDTH = 3;//線の大きさ
const GLfloat POINTSIZE = 10;//点の大きさ
const int WAITTIME = 1;//内部クロック
const int DESCENDANT_END = 200;//終了条件の子孫数（200子孫残したら終了）
const int MAXRAND = 13;//初期個体の経路を決定するために用いている（random_init_indi()関数にて）

class opengl {
public:
    static void init(void);
    static void render_string(double, double, const char*);
    static void display(void);
    static void resize(int, int);
    static void timer(int);
    void line(double, double, double, double);
    void line_position(int, int, int, int, int, int, int, int, int, int, int, int, int, int);
    void point(double, double, const char*);
    void point_position();
    
};

class ga {
public:
    void path_decode(int, int, int, int, int, int, int, int, int, int, int, int, int, int, const int);
    void path_encode(int, int, int, int, int, int, int, int, int, int, int, int, int, int, const int);
    void uniform_crossover(int*, int*, int*, int*, int*, int*);
    void mutation(int *,int);
    void random_init_indi();
    void last_init_indi();
    void setting(void);
    double distance(double,double,double,double);
    double distance_2_points(int, int);
    double distance_2_points_all(int, int, int, int, int, int, int, int, int, int, int, int, int, int);
    void procedure(void);
    
    int global_OX_path[INIT_INDI][VISIT_NUM];
    int global_OX_path_copy[INIT_INDI][VISIT_NUM];
    int global_OX_path_copy_2[INIT_INDI][VISIT_NUM];
    int global_OX_path_copy_3[INIT_INDI][VISIT_NUM];
    int global_OX_path_copy_4[INIT_INDI][VISIT_NUM];
    
    int global_PX_path[INIT_INDI][VISIT_NUM];
    
    double global_path_distance;
    int global_result_path_num;
    int global_result_PX_path[INIT_INDI + 1][VISIT_NUM];
    
    double x, y;
    const char* name;
    
};

#endif