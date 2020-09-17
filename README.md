# LCD16x2_HD44780U_4bits_PIC
Generic Driver for LCD 16x2, 4 bits mode, tested in PIC16f1938 
hardware used: 
PICKIT 3 Programmer 
PIC 28 pin DEMO Board 
PIC16F1938
LCD 16x2, Dupont cables, potentiometer 10k, protoboard 

Software used: 

MPLAB X, compiler XC8, MPLAB Code Configurator tool.


void LCD_init(void); // send comands to initialize the LCD
void Enable(void);   //  pulse on Enable pin
void Init_PORTS(void); //  set up of microcontroler ports
void Comando_LCD(unsigned char x); // 8 bits de tamaño en char  // send data as comands mode
void Dato_LCD(unsigned char x );  // send data as Data mode
void String_LCD(unsigned char *puntero)  // sent Data as Strings of characters 
