/***********************************************************************************
*This program is a demo of how to display scroll
*This demo was made for LCD modules with 8bit or 16bit data port.
*This program requires the the LCDKIWI library.

* File                : display_scroll.ino
* Hardware Environment: Arduino UNO&Mega2560
* Build Environment   : Arduino

*Set the pins to the correct ones for your development shield or breakout board.
*This demo use the BREAKOUT BOARD only and use these 8bit data lines to the LCD,
*pin usage as follow:
*                  LCD_CS  LCD_CD  LCD_WR  LCD_RD  LCD_RST  SD_SS  SD_DI  SD_DO  SD_SCK 
*     Arduino Uno    A3      A2      A1      A0      A4      10     11     12      13                            
*Arduino Mega2560    A3      A2      A1      A0      A4      10     11     12      13                           

*                  LCD_D0  LCD_D1  LCD_D2  LCD_D3  LCD_D4  LCD_D5  LCD_D6  LCD_D7  
*     Arduino Uno    8       9       2       3       4       5       6       7
*Arduino Mega2560    8       9       2       3       4       5       6       7 

*Remember to set the pins to suit your display module!
*
* @attention
*
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
* TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
* DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
* FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE 
* CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**********************************************************************************/

#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_KBV.h> //Hardware-specific library
#include "font.h"

//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_KBV my_lcd(ILI9341,A3,A2,A1,A0,A4); //model,cs,cd,wr,rd,reset
//if the IC model is not known and the modules is readable,you can use this constructed function
//LCDWIKI_KBV my_lcd(240,320,A3,A2,A1,A0,A4);//width,height,cs,cd,wr,rd,reset

#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

char *aspect_name[] = {"PORTRAIT", "LANDSCAPE", "PORTRAIT_REV", "LANDSCAPE_REV"};
char *color_name[] = { "BLUE", "GREEN", "RED", "WHITE" ,"CYAN","MAGENTA","YELLOW"};
uint16_t color_mask[] = { 0x001F, 0x07E0, 0xF800, 0xFFFF,0x07FF,0xF81F,0xFFE0 };

    
void show_16font(uint16_t x, uint16_t y,uint16_t fc, uint16_t bc,uint8_t *str,uint8_t mode)
{
    uint16_t i,j,k,c_num,color=0;
    boolean first = true;
    c_num = sizeof(tfont16)/sizeof(typFNT_GB16);
    for(k=0;k<c_num;k++)
    {         //pgm_read_byte
         if((pgm_read_byte(&tfont16[k].Index[0])==*str) && (pgm_read_byte(&tfont16[k].Index[1])==*(str+1)))
         {
            my_lcd.Set_Addr_Window(x, y, x+16-1, y+16-1); 
            for(j=0;j<32;j++)
            {
               for(i = 0;i<8;i++)  
               {
                  if(mode) //叠加模式
                  {
                    if(pgm_read_byte(&tfont16[k].Msk[j])&(0x80>>i))
                    {
                        my_lcd.Set_Draw_color(fc);
                        my_lcd.Draw_Pixel(x+((j*8+i)%16),y+((j*8+i)/16));
                     }
                    // x++;
                    // if((x-x0)==16)
                    // {
                   //     x = x0;
                   //     y++;   
                   //  }
     
                  }
                  else   //非叠加模式
                  {
                    if(pgm_read_byte(&tfont16[k].Msk[j])&(0x80>>i))
                    {
                         color = fc;
                     }
                     else
                     {
                        color = bc;
                     }
                     my_lcd.Push_Any_Color(&color, 1, first, 0);
                    first = false;
                  }
               }
            } 
      }
    } 
          
}

void show_24font(uint16_t x, uint16_t y,uint16_t fc, uint16_t bc,uint8_t *str,uint8_t mode)
{
    uint16_t i,j,k,c_num,color;
    boolean first = true;
    c_num = sizeof(tfont24)/sizeof(typFNT_GB24);
    for(k=0;k<c_num;k++)
    {
         if((pgm_read_byte(&tfont24[k].Index[0])==*str) && (pgm_read_byte(&tfont24[k].Index[1])==*(str+1)))
         {
            my_lcd.Set_Addr_Window(x, y, x+24-1, y+24-1); 
            for(j=0;j<72;j++)
            {
               for(i = 0;i<8;i++)  
               {
                  if(mode) //叠加模式
                  {
                    if(pgm_read_byte(&tfont24[k].Msk[j])&(0x80>>i))
                    {
                        my_lcd.Set_Draw_color(fc);
                        my_lcd.Draw_Pixel(x+((j*8+i)%24),y+((j*8+i)/24));
                     }
                  //   x++;
                  //   if((x-x0)==32)
                  //   {
                  //      x = x0;
                  //      y++;   
                  //   }
                  }
                  else   //非叠加模式
                  {
                    if(pgm_read_byte(&tfont24[k].Msk[j])&(0x80>>i))
                    {
                         color = fc;
                     }
                     else
                     {
                        color = bc;
                     }
                     my_lcd.Push_Any_Color(&color, 1, first, 0);
                     first = false;
                  }
               }
            } 
      }
    }
}

void show_32font(uint16_t x, uint16_t y,uint16_t fc, uint16_t bc,uint8_t *str,uint8_t mode)
{
    uint16_t i,j,k,c_num,color;
    boolean first = true;
    c_num = sizeof(tfont32)/sizeof(typFNT_GB32);
    for(k=0;k<c_num;k++)
    {
         if((pgm_read_byte(&tfont32[k].Index[0])==*str) && (pgm_read_byte(&tfont32[k].Index[1])==*(str+1)))
         {
            my_lcd.Set_Addr_Window(x, y, x+32-1, y+32-1); 
            for(j=0;j<128;j++)
            {
               for(i = 0;i<8;i++)  
               {
                  if(mode) //叠加模式
                  {
                    if(pgm_read_byte(&tfont32[k].Msk[j])&(0x80>>i))
                    {
                        my_lcd.Set_Draw_color(fc);
                        my_lcd.Draw_Pixel(x+((j*8+i)%32),y+((j*8+i)/32));
                     }
                   //  x++;
                  //   if((x-x0)==32)
                   //  {
                  //      x = x0;
                  //      y++;   
                   //  }
                  }
                  else   //非叠加模式
                  {
                    if(pgm_read_byte(&tfont32[k].Msk[j])&(0x80>>i))
                    {
                         color = fc;
                     }
                     else
                     {
                        color = bc;
                     }
                    my_lcd.Push_Any_Color(&color, 1, first, 0);
                    first = false;
                  }
               }
            } 
      }
    }
}

void show_chinese(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *str,uint16_t csize,uint8_t mode)
{    
    int i = 0;
    if(x>(my_lcd.Get_Display_Width()-csize)||y>(my_lcd.Get_Display_Height()-csize))
      { 
        return;
      }              
    while(*str!='\0')
    { 
  //      i += 5;
  //      my_lcd.Draw_Fast_VLine(i, 10, 100);
       if(csize==32)
       {
          show_32font(x, y,fc, bc,str,mode);
       }
      else if(csize==24)
      {
          show_24font(x, y,fc, bc,str,mode);
      }
      else
      {
          show_16font(x, y,fc, bc,str,mode);
      } 
      str+=3; 
      x+=csize;              
    }   
}

void show_chinese_test(void)
{
    uint16_t i;
     my_lcd.Set_Rotation(1);
     show_chinese(0, 10,RED,BLACK,"深圳市欢迎您",16,1);
     show_chinese(0, 26,RED,BLACK,"深圳市欢迎您",24,1);
     show_chinese(0, 50,RED,BLACK,"深圳市欢迎您",32,1);
     show_chinese(0, 82,GREEN,BLACK,"深圳市欢迎您",16,1);
     show_chinese(0, 98,GREEN,BLACK,"深圳市欢迎您",24,1);
     show_chinese(0, 122,GREEN,BLACK,"深圳市欢迎您",32,1);
     show_chinese(0, 154,BLUE,BLACK,"深圳市欢迎您",16,1);
     show_chinese(0, 170,BLUE,BLACK,"深圳市欢迎您",24,1);
     show_chinese(0, 194,BLUE,BLACK,"深圳市欢迎您",32,1);
     for (i = 1; i <= my_lcd.Get_Display_Width(); i++) 
     {
         my_lcd.Vert_Scroll(0, my_lcd.Get_Display_Width(), i);
         delay(10);
     }
     delay(2000);
     my_lcd.Fill_Screen(BLACK);
     show_chinese(0, 10,RED,WHITE,"深圳市欢迎您",16,0);
     show_chinese(0, 26,RED,WHITE,"深圳市欢迎您",24,0);
     show_chinese(0, 50,RED,WHITE,"深圳市欢迎您",32,0);
     show_chinese(0, 82,GREEN,WHITE,"深圳市欢迎您",16,0);
     show_chinese(0, 98,GREEN,WHITE,"深圳市欢迎您",24,0);
     show_chinese(0, 122,GREEN,WHITE,"深圳市欢迎您",32,0);
     show_chinese(0, 154,BLUE,WHITE,"深圳市欢迎您",16,0);
     show_chinese(0, 170,BLUE,WHITE,"深圳市欢迎您",24,0);
     show_chinese(0, 194,BLUE,WHITE,"深圳市欢迎您",32,0);
}

void show_pic(void)
{
    int i;
    my_lcd.Set_Addr_Window(my_lcd.Get_Display_Width()-40-40, 20, my_lcd.Get_Display_Width()-40-1, 59); 
    my_lcd.Push_Any_Color(penguin_pic, 1600, 1, 1);
 }

void windowScroll(int16_t x, int16_t y, int16_t wid, int16_t ht, int16_t dx, int16_t dy, uint16_t *buf)
{
    if (dx)
    { 
      for (int16_t row = 0; row < ht; row++) 
      {
            my_lcd.Read_GRAM(x, y + row, buf,wid, 1);
            my_lcd.Set_Addr_Window(x, y + row, x + wid - 1, y + row);
            my_lcd.Push_Any_Color(buf + dx, wid - dx, 1,0);
            my_lcd.Push_Any_Color(buf + 0, dx, 0,0);
        }
    }
    if (dy) 
    {
      for (int16_t col = 0; col < wid; col++) 
      {
            my_lcd.Read_GRAM(x + col, y, buf,1, ht);
            my_lcd.Set_Addr_Window(x + col, y, x + col, y + ht - 1);
            my_lcd.Push_Any_Color(buf + dy, ht - dy, 1,0);
            my_lcd.Push_Any_Color(buf + 0, dy, 0,0);
      }
    }
}

void show_string(uint8_t *str,int16_t x,int16_t y,uint8_t csize,uint16_t fc, uint16_t bc,boolean mode)
{
    my_lcd.Set_Text_Mode(mode);
    my_lcd.Set_Text_Size(csize);
    my_lcd.Set_Text_colour(fc);
    my_lcd.Set_Text_Back_colour(bc);
    my_lcd.Print_String(str,x,y);
}
 
void color_test()
{
  int n,i;
  int cnum = sizeof(color_mask)/sizeof(uint16_t);
  for(i=0;i<cnum;i++)
  {
    for(n=0;n<32;n++)
    {
      my_lcd.Set_Draw_color(n*8, n*8, n*8); 
      my_lcd.Set_Draw_color(my_lcd.Get_Draw_color()&color_mask[i]);
      my_lcd.Fill_Rectangle(n*my_lcd.Get_Display_Width()/32,(my_lcd.Get_Display_Height()/cnum)*i,(n+1)*my_lcd.Get_Display_Width()/32,(my_lcd.Get_Display_Height()/cnum)*(i+1));
     }
     show_string(color_name[i],0,((my_lcd.Get_Display_Height()/cnum)-16)/2+(my_lcd.Get_Display_Height()/cnum)*i,2,color_mask[i], BLACK,1);
  }
  delay(1000);
}

void text_test(void)
{
    show_string("Hello World!",0,0,1,RED, BLACK,0);
    my_lcd.Set_Text_colour(YELLOW);
    my_lcd.Set_Text_Size(2);
    my_lcd.Print_Number_Float(01234.56789, 4, 0, 8, '.', 0, ' '); 
    show_string("ABCDEF123456",0,24,3,BLUE, BLACK,0);
    show_string("Good",0,56,5,GREEN, BLACK,0);
    show_string("By utilizing breath",0,96,2,GREEN, BLACK,0);
    show_string("we soften our experiences.",0,112,1,GREEN, BLACK,0);
    show_string("If we dam them up,",0,120,1,GREEN, BLACK,0);
    show_string("our lives will stagnate,",0,128,1,GREEN, BLACK,0);
    show_string("but we keep them flowing,",0,136,1,GREEN, BLACK,0);
    show_string("we allow more newness",0,144,1,GREEN, BLACK,0);
    show_string("and greater experiences",0,152,1,GREEN, BLACK,0);
    show_string("to blossom.Yes OK",0,160,1,GREEN, BLACK,0);
}

void setup()
{
  Serial.begin(9600);
  my_lcd.Init_LCD();
  Serial.println(my_lcd.Read_ID(), HEX);
  my_lcd.Fill_Screen(BLACK);
 // show_chinese_test();
 // show_pic();
}

void loop() 
{
    uint16_t max_scroll,rotation,i,n;
    my_lcd.Set_Rotation(0);
    uint16_t scrollbuf[my_lcd.Get_Display_Height()]; 
    show_chinese_test();
    delay(500);
    for(rotation = 0;rotation<4;rotation++)
    {
        my_lcd.Set_Rotation(rotation);
        my_lcd.Fill_Screen(BLACK);
        //text
        color_test();
        my_lcd.Fill_Screen(BLACK);
        delay(1000);        
        text_test();    
        delay(1000);
        for(n=0;n<32;n++)
        {
          my_lcd.Set_Draw_color(n*8, n*8, n*8); 
          my_lcd.Set_Draw_color(my_lcd.Get_Draw_color()&color_mask[rotation]);
          my_lcd.Fill_Rectangle(n*my_lcd.Get_Display_Width()/32,48,(n+1)*my_lcd.Get_Display_Width()/32,112);
        }
        show_string("COLOR TESTING",50,72,2,color_mask[rotation+1], BLACK,1);
        show_string(aspect_name[rotation],0,184,2,WHITE, BLACK,0);       
        show_pic();
        show_string("VERTICAL SCROLL UP",0,168,2,YELLOW, BLACK,0);  
        if(my_lcd.Get_Rotation()&1)
        {
            max_scroll = my_lcd.Get_Display_Width();
         }
         else
         {
            max_scroll = my_lcd.Get_Display_Height();
         }
         for(i=1;i<=max_scroll;i++)
         {
            my_lcd.Vert_Scroll(0, max_scroll, i);
            delay(10);
          }
          my_lcd.Vert_Scroll(0, max_scroll, 0);
          show_string("VERTICAL SCROLL DN",0,168,2,GREEN, BLACK,0); 
         for(i=1;i<=max_scroll;i++)
         {
            my_lcd.Vert_Scroll(0, max_scroll, 0-i);
            delay(10);
          }
          delay(1000);
          my_lcd.Vert_Scroll(0, max_scroll, 0);
         if(!(rotation&1))
         {
             show_string("ONLY THE COLOR BAND",0,200,2,BLUE, BLACK,0); 
             for(i=1;i<=64;i++)
            {
              my_lcd.Vert_Scroll(48, 64, i);
              delay(20);
            }
            delay(1000);
            my_lcd.Vert_Scroll(0, max_scroll, 0);
         }
         show_string("SOFTWARE SCROLL",0,216,2,YELLOW, BLACK,0); 
         for (int16_t i = my_lcd.Get_Display_Width(), dx = 4, dy = 0; i > 0; i -= dx)
        {
             windowScroll(0, 216, my_lcd.Get_Display_Width(), 16, dx, dy, scrollbuf);
        }
         delay(3000);
     }
     
    my_lcd.Invert_Display(true);
    delay(3000);
    my_lcd.Invert_Display(false);
    my_lcd.Fill_Screen(BLACK);
}
