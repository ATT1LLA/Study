//
//  main.cpp
//  Laba №1
//
//  Created by Адиль Тастеков on 12.09.2018.
//  Copyright © 2018 Адиль Тастеков. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

double pressure[4];     // давление в среде
double density[4];      // плотность среды
double speed_d[4];      // скорость фронта разрыва
double speed_c[4];      // скорость звука в газе
double speed_u[4];      // массова скорость
double energy[4];       // удельная внутренняя энергия
double gammaa[4];        // показатель адиабаты
double a[7];

void input_data () {
    gammaa[0] = 1.666;
    density[0] = 7.9;
    speed_u[0] = 0;
    pressure[0] = 3040000000;
    gammaa[3] = 1.666;
    density[3] = 7.9;
    speed_u[3] = 1000000;
    pressure[3] = 3040000000;
    
    speed_c[0] = sqrt(gammaa[0] * pressure[0] / density[0]);
    speed_c[3] = sqrt(gammaa[3] * pressure[3] / density[3]);
}

double max (double *a, int n, int m) {
    double max = -1000000;
    for (int i = n; i <= m; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    return max;
}

double dabs (double a) {
    if (a < 0)
        return -1 * a;
    else
        return a;
}

double dpow (double x, int n) {
    double res = 1;
    for (int i = 0; i < n; i++) {
        res *= x;
    }
    return res;
}

double p (double x) {
    double res = 0;
    for (int i = 0; i <= 6; i++) {
        res += (a[i] * dpow(x, 6 - i));
    }
    return res;
}

double bin_poisk (double bot, double top, double accuracy) {
    double mid = (bot + top) / 2;
    while (top - bot >= accuracy) {
        mid = (bot + top) / 2;
        if (p(mid) == 0) {
            return mid;
        } else {
            if (p(bot) * p(mid) < 0) {
                top = mid;
            } else {
                bot = mid;
            }
        }
    }
    return mid;
}

int main(int argc, const char * argv[]) {
    input_data();
    
    // Рассчет констант для коэффициентов
    double x = pressure[3] / pressure[0];
    double y = pressure[1] / pressure[0];
    double alpha[4] , e[4];
    alpha[0] = (gammaa[0] + 1) / (gammaa[0] - 1);
    alpha[3] = (gammaa[3] + 1) / (gammaa[3] - 1);
    e[0] = (2 * speed_c[0] * speed_c[0]) / (gammaa[0] * (gammaa[0] - 1) * (speed_u[3] - speed_u[0]) * (speed_u[3] - speed_u[0]));
    e[3] = (2 * speed_c[3] * speed_c[3]) / (gammaa[3] * (gammaa[3] - 1) * (speed_u[3] - speed_u[0]) * (speed_u[3] - speed_u[0]));
    for (int i = 0; i < 4; i++) {
        if (i ==0 || i == 3) {
            cout << "gammaa[" << i << "] = " << gammaa[i] << "\t";
            cout << "alpha[" << i << "] = " << alpha[i] << "\t";
            cout << "e[" << i << "] = " << e[i] << "\t";
            cout << "speed_c[" << i << "] = " << speed_c[i] << "\n";
        }
    }
    cout << "x = " << x << "\n";
    
    // Рассчет коэффициентов многочлена
    cout << "Part №1-----------------------------\n";
    a[0] = (alpha[0] * e[3] - alpha[3] * x * e[0]) * (alpha[0] * e[3] - alpha[3] * x * e[0]);
    a[1] = 2 * ((alpha[0] * e[3] - alpha[3] * x * e[0]) * (e[3] * (1 - 2 * alpha[0] * x) - e[0] * x * (x - 2 * alpha[3])) - alpha[0] * alpha[3] * x * (alpha[0] * e[3] + alpha[3] * x * e[0]));
    a[2] = e[3] * e[3] * (6 * alpha[0] * alpha[0] * x * x - 8 * alpha[0] * x + 1) - 2 * e[0] * e[3] * x * (alpha[0] * alpha[3] * (x * x + 4 * x + 1) - 2 * (x + 1) * (alpha[3] + alpha[0] * x) + x) + e[0] * e[0] * x * x * (6 * alpha[3] * alpha[3] - 8 * alpha[3] * x + x * x) + alpha[0] * alpha[0] * alpha[3] * alpha[3] * x * x - 2 * alpha[0] * x * e[3] * (alpha[0] * x - 2 * alpha[0] * alpha[3] * x + 2 * alpha[3]) - 2 * alpha[3] * x * x * e[0] * (alpha[3] + 2 * alpha[0] * x - 2 * alpha[0] * alpha[3]);
    a[3] = - 2 * x * (2 * e[3] * e[3] * (alpha[0] * alpha[0] * x * x - 3 * alpha[0] * x + 1) + e[0] * e[3] * ((alpha[3] + alpha[0] * x) * (x * x + 4 * x + 1) - 2 * alpha[0] * alpha[3] * x * (x + 1) - 2 * x * (x + 1)) + 2 * e[0] * e[0] * x * (x * x - 3 * alpha[3] * x + alpha[3] * alpha[3]) - alpha[0] * alpha[3] * x * (alpha[0] * x + alpha[3]) + e[3] * (alpha[0] * alpha[0] * alpha[3] * x * x - 2 * x * (2 * alpha[0] * alpha[3] + alpha[0] * alpha[0] * x) + (2 * alpha[0] * x + alpha[3])) + e[0] * x * (alpha[0] * alpha[3] * alpha[3] - 2 * alpha[3] * (alpha[3] + 2 * alpha[0] * x) + 2 * alpha[3] * x + alpha[0] * x * x));
    a[4] = x * x * (e[3] * e[3] * (alpha[0] * alpha[0] * x * x - 8 * alpha[0] * x + 6) - 2 * e[0] * e[3] * (alpha[0] * alpha[3] * x - 2 * (x + 1) * (alpha[3] + alpha[0] * x) + x * x + 4 * x + 1) + e[0] * e[0] * (alpha[3] * alpha[3] - 8 * alpha[3] * x + 6 * x * x) + (alpha[3] * alpha[3] + 4 * alpha[0] * alpha[3] * x + alpha[0] * alpha[0] * x * x) - 2 * e[3] * ((alpha[0] * alpha[0] * x + 2 * alpha[0] * alpha[3]) * x - 2 * (2 * alpha[0] * x + alpha[3]) + 1) - 2 * e[0] * (alpha[3] * (2 * alpha[0] * x + alpha[3]) - 2 * x * (2 * alpha[3] + alpha[0] * x) + x * x));
    a[5] = 2 * x * x * x * (e[3] * e[3] * (alpha[0] * x - 2) - e[0] * e[3] * (alpha[0] * x - 2 + alpha[3] - 2 * x) + e[0] * e[0] * (alpha[3] - 2 * x) + (alpha[3] + alpha[0] * x) - e[3] * (2 * alpha[0] * x + alpha[3] - 2) - e[0] * (2 * alpha[3] + alpha[0] * x - 2 * x));
    a[6] = x * x * x * x * ((e[3] - e[0]) * (e[3] - e[0]) + 1 - 2 * (e[3] + e[0]));
    
    cout << "Коэффициенты уравнения:\n";
    for (int i = 0; i < 7; i++) {
        cout << "a[" << i << "] = " << a[i] << "\n";
    }
    
    // Определение области существования корней
    cout << "Part №2-----------------------------\n";
    double q = max(a, 1, 6);
    double w = max(a, 0, 5);
    double bot[7], top[7];
    bot[0] = dabs(a[6]) / (dabs(a[6]) + w);
    top[0] = 1 + q / dabs(a[0]);
    cout << "Область существования корней: [ " << bot[0] << "; " << top[0] << "]\n";
    
    // Локализация корней
    int N = 10000, counter = 0;
    double step = (top[0] - bot[0]) / N;
    double res[2];
    res[0] = p(bot[0]);
    for (int i = 1; i <= N; i++) {
        if (res[0] == 0) {
            counter++;
            bot[counter] = bot[0] + step * (i - 1);
            top[counter] = bot[0] + step * (i - 1);
        }
        res[1] = p(bot[0] + step * i);
        if (res[0] * res[1] < 0) {
            counter++;
            bot[counter] = bot[0] + step * (i - 1);
            top[counter] = bot[0] + step * i;
        }
        res[0] = res[1];
        if (counter == 6)
            break;
    }
    cout << "Отрезки локализации корней: \n";
    for (int i = 1; i <= counter; i++) {
        cout << i << ". [ " << bot[i] << "; " << top[i] << "]\n";
    }
    
    // Определение "точных" значений корней
    cout << "Part №3-----------------------------\n";
    double solution[counter];
    double accuracy = 0.0000000001;
    for (int i = 1; i <= counter; i++) {
        solution[i] = bin_poisk(bot[i], top[i], accuracy);
        
    }
    cout << "Значения корней: \n";
    for (int i = 1; i <= counter; i++) {
        //cout << i << ". y = " << solution[i] << ";\n";
        printf("%d. y = %.5f;\n", i,  solution[i]);
    }
    
    //Подсчет искомых скоростей
    cout << "Part №4-----------------------------\n";
    double d_0[counter], d_3[counter], a_cr[counter], lambda_1[counter], lambda_2[counter];
    for (int i = 1; i <= counter; i++) {
        density[1] = density[0] * ((gammaa[0] - 1) + (gammaa[0] + 1) * solution[i]) / ((gammaa[0] + 1) + (gammaa[0] - 1) * solution[i]);
        pressure[1] = pressure[0] * solution[i];
        
        speed_u[1] = speed_u[0] + speed_c[0] * sqrt(2) * (solution[i] - 1) / sqrtl(gammaa[0] * (gammaa[0] - 1) * (1 + alpha[0] * solution[i]));
        
        d_0[i] = (density[0] * speed_u[0] - density[1] * speed_u[1]) / (density[0] - density[1]);
        d_3[i] = speed_u[3] - (pressure[3] - pressure[1]) / (density[3] * (speed_u[1] - speed_u[3]));
        
        a_cr[i] = sqrt((pressure[1] - pressure[0]) / (density[1] - density[0]));
        lambda_1[i] = (speed_u[0] - d_0[i]) / a_cr[i];
        lambda_2[i] = (speed_u[1] - d_0[i]) / a_cr[i];
    }
    cout << "Итоговые значения: \n";
    for (int i = 1; i <= counter; i++) {
        //cout << i << ". y = " << solution[i] << ";\n";
        cout << i << ". (a_cr)^2 = " << a_cr[i] * a_cr[i] << "\n";
        cout << "   - d_0 = " << d_0[i] << "\n" << "   - d_3 = " << d_3[i] << "\n";
        cout << "   - lambda_1 = " << lambda_1[i] << "\n" << "   - lambda_2 = " << lambda_2[i] << "\n";
            
            /*printf("%d. (a_cr)^2 = %.4f;\n", i,  a_cr[i] * a_cr[i]);
            printf("    d_0 = %.4f      |   ",  d_0[i]);
            printf("    d_3 = %.4f;\n", d_3[i]);
            printf("    lambda_1 = %.4f    |   ",  lambda_1[i]);
            printf("    lambde_2 = %.4f;\n", lambda_2[i]);
            printf("%d. d_0 = %.4f   |   ", i,  d_0[i]);
            printf("%d. d_3 = %.4f;\n", i,  d_3[i]);*/
    }
    cout << speed_u[0];
    cout << "------------------------------------\n";
    
    return 0;
}
