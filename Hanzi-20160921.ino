//LCD1602显示5*8点阵汉字程序，显示“上午下雨了”5个汉字
#include <Wire.h>  //加载Wire通讯库
#include <LiquidCrystal_I2C.h>  //加载液晶屏库
LiquidCrystal_I2C lcd(0x27, 16, 2); // 设 LCD的地址为0x27，16列2行

//显示字符
#if defined(ARDUINO) && ARDUINO >= 100
#define printByte(args)  write(args);
#else
#define printByte(args)  print(args,BYTE);
#endif

//要显示的汉字编码，定义为一个数组
uint8_t sheng[8] = {0x04, 0x08, 0x1A, 0x0A, 0x1F, 0x0A, 0x0A, 0x0A,}; //升
uint8_t bian[8] = {0x04, 0x1F, 0x04, 0x15, 0x0E, 0x0A, 0x04, 0x0A,}; //变
uint8_t dian[8] = {0x04, 0x1F, 0x15, 0x1F, 0x15, 0x1F, 0x04, 0x07,}; //电
uint8_t suo[8] = {0x05, 0x0A, 0x14, 0x1F, 0x15, 0x1D, 0x15, 0x15,}; //所

void setup() {
  lcd.init();     //初始化LCD
  lcd.backlight(); //打开背光

  //创建新字符，将每个数组映射为一个字符，分别命名为0,1,2,3,4
  lcd.createChar(0, sheng);
  lcd.createChar(1, bian);
  lcd.createChar(2, dian);
  lcd.createChar(3, suo);
  //将字符显示到光标所在位
  lcd.setCursor(7, 2);
  lcd.printByte(0);
  lcd.setCursor(8, 2);
  lcd.printstr("20");
  lcd.printByte(1);
  lcd.printByte(2);
  lcd.printByte(3);
}
void loop() {
}
