/* 
 * File:   LCD_4bits.h
 * Author: Ing. Jorge Mercado Ruiz 
 *
 * Created on September 13, 2020, 1:50 PM
 */

#ifndef LCD_4BITS_H
#define LCD_4BITS_H

//************************************
// Libreria para control de LCD 16x2  HD44780U Hitachi
// modo de control a 4 bits 
// Jorge Mercado Ruiz 
//*************************************

//******Definiciones para pines a usar *********
#define      D7      PORTBbits.RB7      // D7
#define Conf_D7      TRISBbits.TRISB7   // configura I/O

#define      D6      PORTBbits.RB6       // D6
#define Conf_D6      TRISBbits.TRISB6   // Configura I/O

#define      D5      PORTBbits.RB5       // D5
#define Conf_D5      TRISBbits.TRISB5    // configura I/O

#define      D4      PORTBbits.RB4       // D4
#define Conf_D4      TRISBbits.TRISB4    // configura I/O

#define LCD_EN       PORTCbits.RC1       // EN
#define Conf_EN      TRISCbits.TRISC1    // configura I/O

#define LCD_RS       PORTCbits.RC0       // RS
#define Conf_RS      TRISCbits.TRISC0   // configura I/O


//comandos disponibles RS =0 para modo de comandos 
#define      LCD_FIRST_ROW           0x80  //128  decimal
#define      LCD_SECOND_ROW          0xC0  //192 decimal 
#define      LCD_THIRD_ROW           0x94   //148 
#define      LCD_FOURTH_ROW          0xD4   //212
#define      LCD_CLEAR               0x01
#define      LCD_RETURN_HOME         0x02
#define      LCD_CURSOR_OFF          0x0C    //12
#define      LCD_UNDERLINE_ON        0x0E    //14
#define      LCD_BLINK_CURSOR_ON     0x0F    //15
#define      LCD_MOVE_CURSOR_LEFT    0x10    //16
#define      LCD_MOVE_CURSOR_RIGHT   0x14    //20
#define      LCD_TURN_OFF            0x00
#define      LCD_TURN_ON             0x08
#define      LCD_SHIFT_LEFT          0x18     //24
#define      LCD_SHIFT_RIGHT         0x1C     //28 

unsigned char mensaje[9]={"Online.."};
//prototipos de funcion ....

void LCD_init(void);
void Enable(void);
void Init_PORTS(void);
void Comando_LCD(unsigned char x); // 8 bits de tamaño en char 
void Dato_LCD(unsigned char x );
void String_LCD(unsigned char *puntero);


// funciones con cuerpo**********************************

void Init_PORTS(void ){

  TRISC = 0x00;  // del RC0 al RC5 como salidas digitales
  //puerto C no tiene capacidad analogica ANSEL C no necesario 
  LATC = 0x00;  // RS = 0 comandos / 1 = datos  TODO EN LOW
  TRISB = 0x00;
  LATB = 0x00;  

}// fin de funcion 

//********************************

void Enable(void){

LCD_EN = 1;
__delay_ms(1);
LCD_EN = 0;

}// fin de funcion 

//**********************************

void LCD_init(void){

unsigned char arreglo[7]={0x33,0x32,0x28,0x0f,0x06,0x01,0x00};
unsigned char i=0;
while(arreglo[i]!=0)
{
Comando_LCD(arreglo[i]);
i++;
}

} // fin de funcion 

//************************************

void Comando_LCD(unsigned char x){

LCD_RS = 0; // RS=0; Para comandos
PORTB = x;  // mandar el 0x30
Enable();
x=x<<=4; // para recorrer cuatro posiciones a la izquierda
PORTB= x;  // mandar el 0x80
Enable();


}// fin de funcion 


//**************************************

void Dato_LCD(unsigned char x ){

LCD_RS = 1; // RS=1; Para datos
PORTB = x;  // mandar el 0x30
Enable();
x=x<<=4; // para recorrer cuatro posiciones a la izquierda
PORTB= x;  // mandar el 0x80
Enable();

}// fin de funcion 

//******************************************

void String_LCD(unsigned char *puntero){


    while(*puntero!=0)
{
Dato_LCD(*puntero);
puntero++;
}
    
    
    
}

//*******************************************



#endif/* LCD_4BITS_H */

