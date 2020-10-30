#ifndef TRABALHO2_H_INCLUDED
#define TRABALHO2_H_INCLUDED

/*Prototipos de Funcoes-----------------------------*/

/*Funcoes Originais*/
float f(float x, float y, float z);
float g(float x, float y, float z);
float h(float x, float y, float z);

/*Derivadas em relacao a x*/
float fx(float x, float y, float z);
float gx(float x, float y, float z);
float hx(float x, float y, float z);

/*Derivadas em relacao a y*/
float fy(float x, float y, float z);
float gy(float x, float y, float z);
float hy(float x, float y, float z);

/*Derivadas em relacao a z*/
float fz(float x, float y, float z);
float gz(float x, float y, float z);
float hz(float x, float y, float z);

/*Funcoes do Metodo*/
float J(float x, float y, float z);
float formula_x(float x, float y, float z);
float formula_y(float x, float y, float z);
float formula_z(float x, float y, float z);
float novo_x(float x, float y, float z);
float novo_y(float x, float y, float z);
float novo_z(float x, float y, float z);
void Newton(float x, float y, float z);

/*--------------------------------------------------*/

#endif // TRABALHO2_H_INCLUDED
