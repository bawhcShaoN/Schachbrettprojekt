
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
//Deklariere Pins für Display
#define TFT_CS 14
#define TFT_dc 19
#define TFT_mosi 23
#define TFT_sclk 18
#define TFT_rst 22

volatile int interruptCounter;
int totalInterruptCounter;
volatile int k=0;
volatile int g=0;
volatile int m=0;
volatile int s=0;
volatile int m1=0;
volatile int s1=0;
volatile int t=0;
volatile int t1=0;
volatile int Zustand1=0;
volatile int Zustand=0;

hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
 

//
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,TFT_dc,TFT_mosi,TFT_sclk,TFT_rst);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(12, OUTPUT);
  pinMode(15, OUTPUT);
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000000, true);
  timerAlarmEnable(timer);
  tft.initR(INITR_GREENTAB);
}
void IRAM_ATTR onTimer() {
  t1=t;
        t=t+1;
        
        if(t=t1+1){ 
          //Serial.println(Zeit);         
          //Zeit--;
          if(k==0){
          Zustand=digitalRead(2);
          if(Zustand == HIGH){
             g=0;
             k=1;
          }
          else{
              s--;
          }}
          if(k==1){
          Zustand1=digitalRead(3);
          if(Zustand1 == HIGH){
              g=1;
              k=0;
          }
          else{
            s1--;
          }
          }
          
          if(s==0){
            m--;
            s=59;
          }
          if(s1==0){
            m1--;
            s1=59;
          }
          String stringmin=String(m);
          String stringsek=String(s);
          String stringmin1=String(m1);
          String stringsek1=String(s1);
          String stringone=String("   "+stringmin+":"+stringsek);
          String stringtwo=String("   "+stringmin1+":"+stringsek1);
          digitalWrite(12, HIGH);
          digitalWrite(15, LOW);
          
          tft.fillScreen(ST7735_BLACK);
          tft.setTextColor(ST7735_RED);
          tft.setTextSize(2);
          tft.setCursor(0,50);
          tft.println(stringone);
            
          digitalWrite(15, HIGH);
          digitalWrite(12, LOW);
          
          tft.fillScreen(ST7735_BLACK);
          tft.setTextColor(ST7735_RED);
          tft.setTextSize(2);
          tft.setCursor(0,50);
          tft.println(stringone);
}}
void loop() {
  // put your main code here, to run repeatedly
  


}
