#include"common.h"
extern opengl OPENGL;
extern ga GA;
extern ga GA_array[VISIT_NUM];

//順序表現をパス表現に変換する関数
void ga::path_decode(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, const int INDI_NUM) {
    
    int array[VISIT_NUM] = {};
    int point_array[VISIT_NUM] = { a,b,c,d,e,f,g,h,i,j,k,l,m,n};
    list<int> lst;
    
    lst.push_back(0);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    lst.push_back(6);
    lst.push_back(7);
    lst.push_back(8);
    lst.push_back(9);
    lst.push_back(10);
    lst.push_back(11);
    lst.push_back(12);
    lst.push_back(13);
    
    list<int>::iterator it = lst.begin();
    
    int count = 0;
    while (it != lst.end()) {
        array[count] = *it;
        ++it;
        ++count;
    }
    
    for (int k = 0; k<VISIT_NUM; k++) {
        global_PX_path[INDI_NUM][k] = array[point_array[k]];
        lst.remove(array[point_array[k]]);
        
        it = lst.begin();
        count = 0;
        while (it != lst.end()) {
            array[count] = *it;
            ++it;
            ++count;
        }
    }
}

//パス表現を順序表現に変換する関数
void ga::path_encode(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, const int INDI_NUM) {
    
    int count = 0;
    int point_array[VISIT_NUM] = { a,b,c,d,e,f,g,h,i,j,k,l,m,n };
    
    global_OX_path[INDI_NUM][0] = 0;
    
    for (int j = 0; j < VISIT_NUM; j++) {
        for (int i = j; i < VISIT_NUM; i++) {
            if (point_array[j] - point_array[i] > 0) {
                count++;
            }
        }
        global_OX_path[INDI_NUM][j] = count;
        count = 0;
    }
    
}

//一様交差する関数（スワップ関数）
void ga::uniform_crossover(int *a, int *b, int *c, int *x, int *y, int *z) {
    
    int tmp[3];
    
    tmp[0] = *a;
    tmp[1] = *b;
    tmp[2] = *c;
    
    *a = *x;
    *b = *y;
    *c = *z;
    
    *x = tmp[0];
    *y = tmp[1];
    *z = tmp[2];
    
}

//突然変異する関数（スワップ関数）
void ga::mutation(int *a, int temp) {
    int tmp[1];
    
    tmp[0] = rand() % (VISIT_NUM - temp);
    *a = tmp[0];
}

//地点の設定
void ga::setting(){
    
    GA_array[0].x = -4.0;	GA_array[0].y = 4.0;	GA_array[0].name = "A";
    GA_array[1].x = -2.5;	GA_array[1].y = -0.6;	GA_array[1].name = "B";
    GA_array[2].x = -3.0;	GA_array[2].y = 1.2;	GA_array[2].name = "C";
    GA_array[3].x = -6.5;	GA_array[3].y = -1.8;	GA_array[3].name = "D";
    GA_array[4].x =  0.0;	GA_array[4].y = 2.4;	GA_array[4].name = "E";
    GA_array[5].x =  0.5;	GA_array[5].y = 5.8;	GA_array[5].name = "F";
    GA_array[6].x =  1.0;	GA_array[6].y = 2.4;	GA_array[6].name = "G";
    GA_array[7].x =  -4.5;	GA_array[7].y = -5.8;	GA_array[7].name = "H";
    GA_array[8].x =  6.0;	GA_array[8].y = 2.2;	GA_array[8].name = "I";
    GA_array[9].x =  2.5;	GA_array[9].y = 0.6;	GA_array[9].name = "J";
    GA_array[10].x = 4.5;	GA_array[10].y = 0.0;	GA_array[10].name = "K";
    GA_array[11].x =  3.5;	GA_array[11].y = -2.2;	GA_array[11].name = "L";
    GA_array[12].x =  0.0;	GA_array[12].y = -3.8;	GA_array[12].name = "M";
    GA_array[13].x =  -0.5;	GA_array[13].y = -3.2;	GA_array[13].name = "N";
    
}

//二点間の距離を返す関数
double ga::distance(double x_init, double y_init, double x_end, double y_end) {
    double x = fabs(x_init - x_end);
    double y = fabs(y_init - y_end);
    double distance = sqrt((x * x) + (y * y));
    return distance;
}

//二点間の距離を返す関数
double ga::distance_2_points(int key_init, int key_end) {
    double distance_m;
    distance_m = distance(GA_array[key_init].x, GA_array[key_init].y, GA_array[key_end].x, GA_array[key_end].y);
    return distance_m;
}

//各二点間の距離を返す関数（for文でもできるかもしれない）
double ga::distance_2_points_all(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n) {
    double distance_all = 0.00;
    distance_all += distance_2_points(a, b);
    distance_all += distance_2_points(b, c);
    distance_all += distance_2_points(c, d);
    distance_all += distance_2_points(d, e);
    distance_all += distance_2_points(e, f);
    distance_all += distance_2_points(f, g);
    distance_all += distance_2_points(g, h);
    distance_all += distance_2_points(h, i);
    distance_all += distance_2_points(i, j);
    distance_all += distance_2_points(j, k);
    distance_all += distance_2_points(k, l);
    distance_all += distance_2_points(l, m);
    distance_all += distance_2_points(m, n);
    distance_all += distance_2_points(n, a);
    return distance_all;
}

//初期個体を生成する関数
void ga::random_init_indi(){

    for(int j = 0; j < INIT_INDI; j++){
    
    int iaRandarray[MAXRAND];
    int iCounter;
    int iNumRand;
    int iRandKey;
    int iRandVal;
    
    for( iCounter = 0 ; iCounter < MAXRAND ; ++iCounter){
        iaRandarray[ iCounter] = iCounter + 1;
    }
    
    iNumRand = MAXRAND;
    
        for( iCounter = 0 ; iCounter < MAXRAND ; ++iCounter){
        
            iRandKey = rand();
            iRandKey %= iNumRand;
            iRandVal = iaRandarray[ iRandKey ];
            iaRandarray[ iRandKey ] = iaRandarray[ iNumRand - 1 ];
            --iNumRand;

            global_PX_path[j][iCounter] = iRandVal;
        }
        
        global_PX_path[j][MAXRAND] = global_PX_path[j][0];
        global_PX_path[j][0] = 0;
        
    }
    
}

//最も評価の個体を格納するための関数
void ga::last_init_indi(){
    
    for(int j = 0; j<INIT_INDI; j++){
        for(int i = 0; i<VISIT_NUM; i++){
            global_PX_path[j][i] = global_result_PX_path[j][i];
        }
    }
    
}

//GAのプロシージャ
void ga::procedure() {
    
    static int descendant_count = 0;
    
    if (descendant_count < DESCENDANT_END) {
        
        //初期設定
        if (descendant_count == 0) {
            
            random_init_indi();
            global_path_distance = 100;
            
            for(int i = 0; i<VISIT_NUM; i++){
                global_result_PX_path[0][i] = global_PX_path[0][i];
            }
        }
        
        OPENGL.line_position(
                             global_PX_path[0][0],
                             global_PX_path[0][1],
                             global_PX_path[0][2],
                             global_PX_path[0][3],
                             global_PX_path[0][4],
                             global_PX_path[0][5],
                             global_PX_path[0][6],
                             global_PX_path[0][7],
                             global_PX_path[0][8],
                             global_PX_path[0][9],
                             global_PX_path[0][10],
                             global_PX_path[0][11],
                             global_PX_path[0][12],
                             global_PX_path[0][13]
                             );
        
        
        double path_distance[INIT_INDI];
        double path_distance_sum = 0;
        
        for (int i = 0; i < INIT_INDI; i++) {
            path_distance[i] =
            distance_2_points_all(
                                  global_PX_path[i][0],
                                  global_PX_path[i][1],
                                  global_PX_path[i][2],
                                  global_PX_path[i][3],
                                  global_PX_path[i][4],
                                  global_PX_path[i][5],
                                  global_PX_path[i][6],
                                  global_PX_path[i][7],
                                  global_PX_path[i][8],
                                  global_PX_path[i][9],
                                  global_PX_path[i][10],
                                  global_PX_path[i][11],
                                  global_PX_path[i][12],
                                  global_PX_path[i][13]
                                  );
        }
        
        //結果表示のための格納
        if (global_path_distance > path_distance[0]) {
            global_path_distance = path_distance[0];
            
            global_result_path_num = descendant_count;
            
            for(int i = 0; i<VISIT_NUM; i++){
                global_result_PX_path[0][i] = global_PX_path[0][i];
                
            }
        }
        
        //評価のために距離を測定する
        for (int i = 0; i < INIT_INDI; i++) {
            path_distance[i] = (1 / path_distance[i]);
            path_distance_sum += path_distance[i];
        }
        
        for (int i = 0; i < INIT_INDI; i++) {
            path_distance[i] = path_distance[i] / path_distance_sum;
        }
        
        int elite_path_num[INIT_INDI];
        double path_distance_copy[INIT_INDI];
        
        for (int i = 0; i < INIT_INDI; i++) {
            path_distance_copy[i] = path_distance[i];
        }
        cout << endl;
        
        //並び替え
        sort(path_distance_copy, path_distance_copy + INIT_INDI, greater<double>());
        
        //elite選択
        for (int j = 0; j < INIT_INDI; j++) {
            if (path_distance_copy[0] == path_distance[j]) {
                elite_path_num[0] = j;
            }
        }
        
        for (int j = 0; j < INIT_INDI; j++) {
            if (path_distance_copy[1] == path_distance[j] && elite_path_num[0] != j) {
                elite_path_num[1] = j;
            }
        }
        
        for (int j = 0; j < INIT_INDI; j++) {
            if (path_distance_copy[2] == path_distance[j] && elite_path_num[0] != j && elite_path_num[1] != j) {
                elite_path_num[2] = j;
            }
        }
        
        for (int j = 0; j < INIT_INDI; j++) {
            if (path_distance_copy[3] == path_distance[j] && elite_path_num[0] != j && elite_path_num[1] != j && elite_path_num[2] != j) {
                elite_path_num[3] = j;
            }
        }
        
        for (int j = 0; j < INIT_INDI; j++) {
            if (path_distance_copy[4] == path_distance[j] && elite_path_num[0] != j && elite_path_num[1] != j && elite_path_num[2] != j && elite_path_num[3] != j) {
                elite_path_num[4] = j;
            }
        }
        
        for (int j = 0; j < INIT_INDI; j++) {
            if (path_distance_copy[5] == path_distance[j] && elite_path_num[0] != j && elite_path_num[1] != j && elite_path_num[2] != j && elite_path_num[3] != j && elite_path_num[4] != j) {
                elite_path_num[5] = j;
            }
        }
        
        for (int j = 0; j < INIT_INDI; j++) {
            if (path_distance_copy[6] == path_distance[j] && elite_path_num[0] != j && elite_path_num[1] != j && elite_path_num[2] != j && elite_path_num[3] != j && elite_path_num[4] != j && elite_path_num[5] != j) {
                elite_path_num[6] = j;
            }
        }
        
        for (int j = 0; j < INIT_INDI; j++) {
            if (path_distance_copy[7] == path_distance[j] && elite_path_num[0] != j && elite_path_num[1] != j && elite_path_num[2] != j && elite_path_num[3] != j && elite_path_num[4] != j && elite_path_num[5] != j && elite_path_num[6] != j) {
                elite_path_num[7] = j;
            }
        }
        
        for (int j = 0; j < INIT_INDI; j++) {
            if (path_distance_copy[8] == path_distance[j] && elite_path_num[0] != j && elite_path_num[1] != j && elite_path_num[2] != j && elite_path_num[3] != j && elite_path_num[4] != j && elite_path_num[5] != j && elite_path_num[6] != j && elite_path_num[7] != j) {
                elite_path_num[8] = j;
            }
        }
        
        for (int j = 0; j < INIT_INDI; j++) {
            if (path_distance_copy[9] == path_distance[j] && elite_path_num[0] != j && elite_path_num[1] != j && elite_path_num[2] != j && elite_path_num[3] != j && elite_path_num[4] != j && elite_path_num[5] != j && elite_path_num[6] != j && elite_path_num[7] != j && elite_path_num[8] != j) {
                elite_path_num[9] = j;
            }
        }
        
        //上位の個体から子孫を生み出す
        for (int i(0); i < 6; i++) {
            
            path_encode(global_PX_path[elite_path_num[i]][0],
                        global_PX_path[elite_path_num[i]][1],
                        global_PX_path[elite_path_num[i]][2],
                        global_PX_path[elite_path_num[i]][3],
                        global_PX_path[elite_path_num[i]][4],
                        global_PX_path[elite_path_num[i]][5],
                        global_PX_path[elite_path_num[i]][6],
                        global_PX_path[elite_path_num[i]][7],
                        global_PX_path[elite_path_num[i]][8],
                        global_PX_path[elite_path_num[i]][9],
                        global_PX_path[elite_path_num[i]][10],
                        global_PX_path[elite_path_num[i]][11],
                        global_PX_path[elite_path_num[i]][12],
                        global_PX_path[elite_path_num[i]][13],
                        elite_path_num[i]);
            
        }
        
        
        for (int i = 0; i < VISIT_NUM; i++) {
            global_OX_path_copy[elite_path_num[0]][i] = global_OX_path[elite_path_num[0]][i];
            global_OX_path_copy[elite_path_num[1]][i] = global_OX_path[elite_path_num[1]][i];
            
            global_OX_path_copy_2[elite_path_num[0]][i] = global_OX_path[elite_path_num[0]][i];
            global_OX_path_copy_2[elite_path_num[2]][i] = global_OX_path[elite_path_num[2]][i];
            
            global_OX_path_copy_3[elite_path_num[2]][i] = global_OX_path[elite_path_num[2]][i];
            global_OX_path_copy_3[elite_path_num[3]][i] = global_OX_path[elite_path_num[3]][i];
            
            global_OX_path_copy_4[elite_path_num[1]][i] = global_OX_path[elite_path_num[1]][i];
            global_OX_path_copy_4[elite_path_num[3]][i] = global_OX_path[elite_path_num[3]][i];
            
        }
        
        //一様交差を行う（確率80%）
        
        int temp[2];
        temp[1] = rand() % 5 + 1;
        
        int tmp[3];
        tmp[0] = rand() % 11 + 1;
        tmp[1] = tmp[0] + 1;
        tmp[2] = tmp[0] + 2;
        
        //0,1
        if (temp[1] != 1) {
            uniform_crossover(&global_OX_path[elite_path_num[0]][tmp[0]],
                              &global_OX_path[elite_path_num[0]][tmp[1]],
                              &global_OX_path[elite_path_num[0]][tmp[2]],
                              &global_OX_path[elite_path_num[1]][tmp[0]],
                              &global_OX_path[elite_path_num[1]][tmp[1]],
                              &global_OX_path[elite_path_num[1]][tmp[2]]);
        }
        
        tmp[0] = rand() % 11 + 1;
        tmp[1] = tmp[0] + 1;
        tmp[2] = tmp[0] + 2;
        
        //0,1
        if (temp[1] != 2) {
            uniform_crossover(&global_OX_path_copy[elite_path_num[0]][tmp[0]],
                              &global_OX_path_copy[elite_path_num[0]][tmp[1]],
                              &global_OX_path_copy[elite_path_num[0]][tmp[2]],
                              &global_OX_path_copy[elite_path_num[1]][tmp[0]],
                              &global_OX_path_copy[elite_path_num[1]][tmp[1]],
                              &global_OX_path_copy[elite_path_num[1]][tmp[2]]);
        }
        
        tmp[0] = rand() % 11 + 1;
        tmp[1] = tmp[0] + 1;
        tmp[2] = tmp[0] + 2;
        
        //0,2
        if (temp[1] != 3) {
            uniform_crossover(&global_OX_path_copy_2[elite_path_num[0]][tmp[0]],
                              &global_OX_path_copy_2[elite_path_num[0]][tmp[1]],
                              &global_OX_path_copy_2[elite_path_num[0]][tmp[2]],
                              &global_OX_path_copy_2[elite_path_num[2]][tmp[0]],
                              &global_OX_path_copy_2[elite_path_num[2]][tmp[1]],
                              &global_OX_path_copy_2[elite_path_num[2]][tmp[2]]);
        }
        
        tmp[0] = rand() % 11 + 1;
        tmp[1] = tmp[0] + 1;
        tmp[2] = tmp[0] + 2;
        
        //2,3
        if (temp[1] != 4) {
            uniform_crossover(&global_OX_path_copy_4[elite_path_num[2]][tmp[0]],
                              &global_OX_path_copy_3[elite_path_num[2]][tmp[1]],
                              &global_OX_path_copy_3[elite_path_num[2]][tmp[2]],
                              &global_OX_path_copy_3[elite_path_num[3]][tmp[0]],
                              &global_OX_path_copy_3[elite_path_num[3]][tmp[1]],
                              &global_OX_path_copy_3[elite_path_num[3]][tmp[2]]);
        }
        
        tmp[0] = rand() % 11 + 1;
        tmp[1] = tmp[0] + 1;
        tmp[2] = tmp[0] + 2;
        
        //1,3
        if (temp[1] != 5) {
            uniform_crossover(&global_OX_path_copy_4[elite_path_num[1]][tmp[0]],
                              &global_OX_path_copy_4[elite_path_num[1]][tmp[1]],
                              &global_OX_path_copy_4[elite_path_num[1]][tmp[2]],
                              &global_OX_path_copy_4[elite_path_num[3]][tmp[0]],
                              &global_OX_path_copy_4[elite_path_num[3]][tmp[1]],
                              &global_OX_path_copy_4[elite_path_num[3]][tmp[2]]);
        }
        
        
        
        //突然変異を行う（確率80%）
        //0,1
        
        temp[0] = rand() % 13 + 1;
        temp[1] = rand() % 5 + 1;
        
        if (temp[1] != 1) {
            mutation(&global_OX_path[elite_path_num[0]][temp[0]], temp[0]);
        }
        
        
        temp[0] = rand() % 13 + 1;
        
        if (temp[1] != 2) {
            mutation(&global_OX_path[elite_path_num[1]][temp[0]], temp[0]);
        }
        
        //0,1
        
        temp[0] = rand() % 13 + 1;
        
        if (temp[1] != 3) {
            mutation(&global_OX_path_copy[elite_path_num[0]][temp[0]], temp[0]);
        }
        
        
        temp[0] = rand() % 13 + 1;
        
        if (temp[1] != 4) {
            mutation(&global_OX_path_copy[elite_path_num[1]][temp[0]], temp[0]);
        }
        
        //0,2
        
        temp[0] = rand() % 13 + 1;
        
        if (temp[1] != 5) {
            mutation(&global_OX_path_copy_2[elite_path_num[0]][temp[0]], temp[0]);
        }
        
        temp[0] = rand() % 13 + 1;
        
        if (temp[1] != 1) {
            mutation(&global_OX_path_copy_2[elite_path_num[2]][temp[0]], temp[0]);
        }
        
        //2,3
        
        temp[0] = rand() % 13 + 1;
        
        if (temp[1] != 2) {
            mutation(&global_OX_path_copy_3[elite_path_num[2]][temp[0]], temp[0]);
        }
        
        temp[0] = rand() % 13 + 1;
        
        if (temp[1] != 3) {
            mutation(&global_OX_path_copy_3[elite_path_num[3]][temp[0]], temp[0]);
        }
        
        //1,3
        
        temp[0] = rand() % 13 + 1;
        
        if (temp[1] != 4) {
            mutation(&global_OX_path_copy_4[elite_path_num[1]][temp[0]], temp[0]);
        }
        
        
        temp[0] = rand() % 13 + 1;
        
        if (temp[1] != 5) {
            mutation(&global_OX_path_copy_4[elite_path_num[3]][temp[0]], temp[0]);
        }
        
        //順序表現をパス表現に変換（for文使えたかも）
        
        path_decode(global_OX_path[elite_path_num[0]][0],
                    global_OX_path[elite_path_num[0]][1],
                    global_OX_path[elite_path_num[0]][2],
                    global_OX_path[elite_path_num[0]][3],
                    global_OX_path[elite_path_num[0]][4],
                    global_OX_path[elite_path_num[0]][5],
                    global_OX_path[elite_path_num[0]][6],
                    global_OX_path[elite_path_num[0]][7],
                    global_OX_path[elite_path_num[0]][8],
                    global_OX_path[elite_path_num[0]][9],
                    global_OX_path[elite_path_num[0]][10],
                    global_OX_path[elite_path_num[0]][11],
                    global_OX_path[elite_path_num[0]][12],
                    global_OX_path[elite_path_num[0]][13],
                    elite_path_num[0]);
        
        
        path_decode(global_OX_path[elite_path_num[1]][0],
                    global_OX_path[elite_path_num[1]][1],
                    global_OX_path[elite_path_num[1]][2],
                    global_OX_path[elite_path_num[1]][3],
                    global_OX_path[elite_path_num[1]][4],
                    global_OX_path[elite_path_num[1]][5],
                    global_OX_path[elite_path_num[1]][6],
                    global_OX_path[elite_path_num[1]][7],
                    global_OX_path[elite_path_num[1]][8],
                    global_OX_path[elite_path_num[1]][9],
                    global_OX_path[elite_path_num[1]][10],
                    global_OX_path[elite_path_num[1]][11],
                    global_OX_path[elite_path_num[1]][12],
                    global_OX_path[elite_path_num[1]][13],
                    elite_path_num[1]);
        
        
        path_decode(global_OX_path_copy[elite_path_num[0]][0],
                    global_OX_path_copy[elite_path_num[0]][1],
                    global_OX_path_copy[elite_path_num[0]][2],
                    global_OX_path_copy[elite_path_num[0]][3],
                    global_OX_path_copy[elite_path_num[0]][4],
                    global_OX_path_copy[elite_path_num[0]][5],
                    global_OX_path_copy[elite_path_num[0]][6],
                    global_OX_path_copy[elite_path_num[0]][7],
                    global_OX_path_copy[elite_path_num[0]][8],
                    global_OX_path_copy[elite_path_num[0]][9],
                    global_OX_path_copy[elite_path_num[0]][10],
                    global_OX_path_copy[elite_path_num[0]][11],
                    global_OX_path_copy[elite_path_num[0]][12],
                    global_OX_path_copy[elite_path_num[0]][13],
                    elite_path_num[2]);
        
        
        path_decode(global_OX_path_copy[elite_path_num[1]][0],
                    global_OX_path_copy[elite_path_num[1]][1],
                    global_OX_path_copy[elite_path_num[1]][2],
                    global_OX_path_copy[elite_path_num[1]][3],
                    global_OX_path_copy[elite_path_num[1]][4],
                    global_OX_path_copy[elite_path_num[1]][5],
                    global_OX_path_copy[elite_path_num[1]][6],
                    global_OX_path_copy[elite_path_num[1]][7],
                    global_OX_path_copy[elite_path_num[1]][8],
                    global_OX_path_copy[elite_path_num[1]][9],
                    global_OX_path_copy[elite_path_num[1]][10],
                    global_OX_path_copy[elite_path_num[1]][11],
                    global_OX_path_copy[elite_path_num[1]][12],
                    global_OX_path_copy[elite_path_num[1]][13],
                    elite_path_num[3]);
        
        
        path_decode(global_OX_path_copy_2[elite_path_num[0]][0],
                    global_OX_path_copy_2[elite_path_num[0]][1],
                    global_OX_path_copy_2[elite_path_num[0]][2],
                    global_OX_path_copy_2[elite_path_num[0]][3],
                    global_OX_path_copy_2[elite_path_num[0]][4],
                    global_OX_path_copy_2[elite_path_num[0]][5],
                    global_OX_path_copy_2[elite_path_num[0]][6],
                    global_OX_path_copy_2[elite_path_num[0]][7],
                    global_OX_path_copy_2[elite_path_num[0]][8],
                    global_OX_path_copy_2[elite_path_num[0]][9],
                    global_OX_path_copy_2[elite_path_num[0]][10],
                    global_OX_path_copy_2[elite_path_num[0]][11],
                    global_OX_path_copy_2[elite_path_num[0]][12],
                    global_OX_path_copy_2[elite_path_num[0]][13],
                    elite_path_num[4]);
        
        
        path_decode(global_OX_path_copy_2[elite_path_num[2]][0],
                    global_OX_path_copy_2[elite_path_num[2]][1],
                    global_OX_path_copy_2[elite_path_num[2]][2],
                    global_OX_path_copy_2[elite_path_num[2]][3],
                    global_OX_path_copy_2[elite_path_num[2]][4],
                    global_OX_path_copy_2[elite_path_num[2]][5],
                    global_OX_path_copy_2[elite_path_num[2]][6],
                    global_OX_path_copy_2[elite_path_num[2]][7],
                    global_OX_path_copy_2[elite_path_num[2]][8],
                    global_OX_path_copy_2[elite_path_num[2]][9],
                    global_OX_path_copy_2[elite_path_num[2]][10],
                    global_OX_path_copy_2[elite_path_num[2]][11],
                    global_OX_path_copy_2[elite_path_num[2]][12],
                    global_OX_path_copy_2[elite_path_num[2]][13],
                    elite_path_num[5]);
        
        
        path_decode(global_OX_path_copy_3[elite_path_num[2]][0],
                    global_OX_path_copy_3[elite_path_num[2]][1],
                    global_OX_path_copy_3[elite_path_num[2]][2],
                    global_OX_path_copy_3[elite_path_num[2]][3],
                    global_OX_path_copy_3[elite_path_num[2]][4],
                    global_OX_path_copy_3[elite_path_num[2]][5],
                    global_OX_path_copy_3[elite_path_num[2]][6],
                    global_OX_path_copy_3[elite_path_num[2]][7],
                    global_OX_path_copy_3[elite_path_num[2]][8],
                    global_OX_path_copy_3[elite_path_num[2]][9],
                    global_OX_path_copy_3[elite_path_num[2]][10],
                    global_OX_path_copy_3[elite_path_num[2]][11],
                    global_OX_path_copy_3[elite_path_num[2]][12],
                    global_OX_path_copy_3[elite_path_num[2]][13],
                    elite_path_num[6]);
        
        
        path_decode(global_OX_path_copy_3[elite_path_num[3]][0],
                    global_OX_path_copy_3[elite_path_num[3]][1],
                    global_OX_path_copy_3[elite_path_num[3]][2],
                    global_OX_path_copy_3[elite_path_num[3]][3],
                    global_OX_path_copy_3[elite_path_num[3]][4],
                    global_OX_path_copy_3[elite_path_num[3]][5],
                    global_OX_path_copy_3[elite_path_num[3]][6],
                    global_OX_path_copy_3[elite_path_num[3]][7],
                    global_OX_path_copy_3[elite_path_num[3]][8],
                    global_OX_path_copy_3[elite_path_num[3]][9],
                    global_OX_path_copy_3[elite_path_num[3]][10],
                    global_OX_path_copy_3[elite_path_num[3]][11],
                    global_OX_path_copy_3[elite_path_num[3]][12],
                    global_OX_path_copy_3[elite_path_num[3]][13],
                    elite_path_num[7]);
        
        
        path_decode(global_OX_path_copy_4[elite_path_num[1]][0],
                    global_OX_path_copy_4[elite_path_num[1]][1],
                    global_OX_path_copy_4[elite_path_num[1]][2],
                    global_OX_path_copy_4[elite_path_num[1]][3],
                    global_OX_path_copy_4[elite_path_num[1]][4],
                    global_OX_path_copy_4[elite_path_num[1]][5],
                    global_OX_path_copy_4[elite_path_num[1]][6],
                    global_OX_path_copy_4[elite_path_num[1]][7],
                    global_OX_path_copy_4[elite_path_num[1]][8],
                    global_OX_path_copy_4[elite_path_num[1]][9],
                    global_OX_path_copy_4[elite_path_num[1]][10],
                    global_OX_path_copy_4[elite_path_num[1]][11],
                    global_OX_path_copy_4[elite_path_num[1]][12],
                    global_OX_path_copy_4[elite_path_num[1]][13],
                    elite_path_num[8]);
        
        
        path_decode(global_OX_path_copy_4[elite_path_num[3]][0],
                    global_OX_path_copy_4[elite_path_num[3]][1],
                    global_OX_path_copy_4[elite_path_num[3]][2],
                    global_OX_path_copy_4[elite_path_num[3]][3],
                    global_OX_path_copy_4[elite_path_num[3]][4],
                    global_OX_path_copy_4[elite_path_num[3]][5],
                    global_OX_path_copy_4[elite_path_num[3]][6],
                    global_OX_path_copy_4[elite_path_num[3]][7],
                    global_OX_path_copy_4[elite_path_num[3]][8],
                    global_OX_path_copy_4[elite_path_num[3]][9],
                    global_OX_path_copy_4[elite_path_num[3]][10],
                    global_OX_path_copy_4[elite_path_num[3]][11],
                    global_OX_path_copy_4[elite_path_num[3]][12],
                    global_OX_path_copy_4[elite_path_num[3]][13],
                    elite_path_num[9]);
        
        //途中結果出力
        
        for (int j = 0; j < INIT_INDI; j++) {
            for (int i = 0; i < VISIT_NUM; i++) {
                cout << GA_array[global_PX_path[j][i]].name << "=>";
            }
            cout << endl;
        }
        
        descendant_count++;
        cout << "子孫数 = " << descendant_count << endl;
        
    } else {
        
        //最終結果出力
        static int result_count;
        if (result_count == 0) {
            cout << "設定子孫数は" << DESCENDANT_END << endl;
            cout << "最短距離は" << global_path_distance << endl;
            cout << "子孫数は" << global_result_path_num << "の時に最短経路を導いた" << endl;
            result_count++;
            for(int i = 0; i < VISIT_NUM; i++){
                cout << GA_array[global_result_PX_path[0][i]].name << ",";
            }
        }
        
        OPENGL.line_position(
                             global_result_PX_path[0][0],
                             global_result_PX_path[0][1],
                             global_result_PX_path[0][2],
                             global_result_PX_path[0][3],
                             global_result_PX_path[0][4],
                             global_result_PX_path[0][5],
                             global_result_PX_path[0][6],
                             global_result_PX_path[0][7],
                             global_result_PX_path[0][8],
                             global_result_PX_path[0][9],
                             global_result_PX_path[0][10],
                             global_result_PX_path[0][11],
                             global_result_PX_path[0][12],
                             global_result_PX_path[0][13]
                             );
    
    }
}