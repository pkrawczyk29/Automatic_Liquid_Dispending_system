/*
    Project: BEng Thesis 
    Title: Construction of an automatic liquid dispensing system  
    Author: Przemysław Krawczyk
*/
//Librares
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> // Library for commutnication with Screen using I2C
#include <PinChangeInterrupt.h> // Library for Software Interrupt 
#include <Timers.h> // Library for timers to count engine working time
#include <ShiftRegister74HC595.h> // library to control Shitf Register
#include "HX711.h" // library to control HX711 converter for scale

//PIN Declarations 
#define b_l 7
#define b_ok 6
#define b_r 8
#define b_b 9
#define b_flow 10

#define clc 2
#define latch A3
#define datasr1 A2
#define clc2 5
#define latch2 4
#define datasr2 3

#define calibration_factor -818 //This value is obtained using the SparkFun_HX711_Calibration sketch

#define LOADCELL_DOUT_PIN  A0
#define LOADCELL_SCK_PIN  A1

#define red_led 11
#define green_led 12

//DEKLARACJE PERYFERIÓW
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Configuration connection with screen 
ShiftRegister74HC595<1> sr1(datasr1, clc, latch); 
ShiftRegister74HC595<1> sr2(datasr2, clc2, latch2);

//Variable for flowing rate
float ratio = 725;


char text[16] = "";
bool lcd_flag = false;


//DEKLARACJE OBIEKTÓW
Timer timer_draw_menu;
Timer timer_button;
Timer timer_LED;
HX711 scale;

//Variable declarations 
//Flags
bool flag_subMenu = false;
bool do_once = false;
bool do_once_set = false;
bool flag_menu = false;
bool flag_clean = false;
bool f_glass = false;
bool f_engine = false ;
bool f_engine_start = false;
bool which_mode = false;  
bool f_engine_scale = false;

//Markers
byte marker = 0;
byte marker_sub = 0;
byte marker_rec = 0;
byte which_formula = 0;
byte which_pomp = 0;

float reading;
float offset;

enum choice_t {
  general = 0, recipie = 1, user_choice = 2, clean = 3, settings = 4, settingsEdit = 5
};
enum choice_t menu = general;

//Function proptotype
void clean_test();
void fill_formulas();
void lcd_pass();
void lcd_print();
void draw_menu ();
void draw_general_case();
void recipie_fun();
void user_choice_fun();
void clean_test();
void settings_test();
void setting_edit();
void b_l_fun ();
void b_r_fun ();
void b_ok_fun ();
void b_b_fun ();
void b_flow_fun();
void trigger_engine();
void engine_monitor();
void engine_start();
void engine_stop();
void read_scale();
void resest_scale();
void engine_control_scale();
void blik_LED();
void led_button ();

void setup()
{
  Serial.begin(9600);

  sr1.setAllLow();
  sr2.setAllLow();

  //USTAWIENIA PINÓW
  pinMode (b_l, INPUT_PULLUP);
  pinMode (b_r, INPUT_PULLUP);
  pinMode (b_ok, INPUT_PULLUP);
  pinMode (b_b, INPUT_PULLUP);
  pinMode (b_flow, INPUT_PULLUP);
  pinMode (red_led, OUTPUT);
  pinMode (green_led, OUTPUT);
  pinMode (datasr1, OUTPUT);
  pinMode (datasr2, OUTPUT);
  pinMode (clc, OUTPUT);
  pinMode (clc2, OUTPUT);
  pinMode (latch, OUTPUT);
  pinMode (latch2, OUTPUT);

  //USTAWIENIA PERYFERIÓW
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0

  lcd.begin(16, 2);
  lcd.backlight(); 
  lcd.print("Hello");
  delay(3000);

  //USTAWIANIE TIMERÓW
  timer_draw_menu.begin(50);
  timer_button.begin(25);
  timer_LED.begin(100);

  fill_formulas();

  //PRZERWANIA ZEWNĘTRZNE
  //PRZYCISKI
  attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(b_l), b_l_fun, RISING);
  attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(b_r), b_r_fun, RISING);
  attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(b_ok), b_ok_fun, RISING);
  attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(b_b), b_b_fun, RISING);
  attachPinChangeInterrupt(digitalPinToPinChangeInterrupt(b_flow), b_flow_fun, RISING);
}
