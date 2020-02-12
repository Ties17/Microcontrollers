/*
 * lcd.h
 *
 * Created: 2/12/2020 12:53:46 PM
 *  Author: brand
 */ 

#define F_CPU 8000000

#define LCD_E 	3
#define LCD_RS	2

void init();
void display_text(char *str);
void set_cursor(int position);
void lcd_strobe_lcd_e(void);
void lcd_write_string(char *str);
void lcd_write_data(unsigned char byte);
void lcd_write_command(unsigned char byte);