// GSM požární hlásič
// Arduino nano ATmega168
// D2-RST(sim800l800L); D3-DATA(SRX882); D4-LED1; D5-LED2; D6-LED3; D7-LED4; D8-LED5; D9-Buzzer out; D10-TX(SIM800L); D11-RX(SIM800L); D13+A0-->A7-Volné piny;
// NiceRF 433MHz Přijímač SRX887

// připojení potřebné knihovny
#include <RCSwitch.h>
#include <GSMSim.h>

#define RX 10
#define TX 11
#define RESET 2
#define BAUD 9600                                

//definice připojení pinu k arduinu
RCSwitch prijimac = RCSwitch();                             //Vytvoření objektu přijímače z knihovny
GSMSim gsm(RX, TX);

char* number1 = "+xxxxxxxxxxxx";
char* number2 = "+xxxxxxxxxxxx";
char* number3 = "+xxxxxxxxxxxx";
char* number4 = "+xxxxxxxxxxxx";
char* number5 = "+xxxxxxxxxxxx";
char* number6 = "+xxxxxxxxxxxx";
char* number7 = "+xxxxxxxxxxxx";
char* message = "Pozar v dome!!!";

long ZPRAVA1 = 1511;                                         //Kód přijetí z vysílače č.1
long ZPRAVA2 = 1512;                                         //Kód přijetí z vysílače č.2
long ZPRAVA3 = 1513;                                         //Kód přijetí z vysílače č.3
long ZPRAVA4 = 1514;                                         //Kód přijetí z vysílače č.4
long ZPRAVA5 = 1515;                                         //Kód přijetí z vysílače č.5

//proměnné pro výstupy z arduina
int piezo = 9;                                              //výstupní repro z pinu č.9
int Led1 = 4;                                               //Led čidlo 1
int Led2 = 5;                                               //Led čidlo 2
int Led3 = 6;                                               //Led čidlo 3
int Led4 = 7;                                               //Led čidlo 4
int Led5 = 8;                                               //Led čidlo 5

//čítač počtu příchozích zpráv
int citacCidlo1 = 0;
int citacCidlo2 = 0;
int citacCidlo3 = 0;
int citacCidlo4 = 0;
int citacCidlo5 = 0;

//limit příchodů zpráv 
const int LIMIT_CITAC = 5;

void setup() {
  pinMode(piezo, OUTPUT);                                   //--->Nastavení jako výstupní zařízení
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Led5, OUTPUT);
  digitalWrite(piezo, LOW);                                 //jako výstup na začátku 0 kvůli tichosti
  Serial.begin(9600);                                       // Zahájení komunikace po sériové lince
  delay(1000); 
  gsm.start();                                     //Zahájení komunikace mezi arduinem a SIM800L
  delay(1000); 
  Serial.println("Program nahrán");
  delay(1000);                                              //Prodleva spuštění
  prijimac.enableReceive(1);                                // nastavení přijacího pinu RFmodulu na interrupt pin 1 = pin D3 pro Nano
  delay(1000); 
    digitalWrite(Led1, HIGH);                               //--->Start kontrolek LED 1-->5
  delay(500);
  digitalWrite(Led1, LOW);
    digitalWrite(Led2, HIGH);
  delay(500);
  digitalWrite(Led2, LOW);
    digitalWrite(Led3, HIGH);
  delay(500);
  digitalWrite(Led3, LOW);
   digitalWrite(Led4, HIGH);
  delay(500);
  digitalWrite(Led4, LOW);
    digitalWrite(Led5, HIGH);
  delay(500);
  digitalWrite(Led5, LOW);
  }
  
void(* resetFunc) (void) = 0;                       //Deklarace funkce reset @ address 0

void loop(){
   if (prijimac.available())                        // detekce přichozí komunikace
   {
     Serial.println("dostal jsem zpravu ");
     zpracujZpravu();
   }
   else                                              // v případě úspěšné přijaté zprávy vypíšeme všechny údaje
   {
     //Serial.println("Ted cekam");
   }
   prijimac.resetAvailable();                        // reset modulu pro přijetí nových zpráv
}

void zpracujZpravu(){
  //pripad - Cidlo1
  if (prijimac.getReceivedValue() == ZPRAVA1)         // když bude souhlasit zpráva
  {
    citacCidlo1 = citacCidlo1 + 1;                    // počítání přijatých zpráv
    if (citacCidlo1 >= LIMIT_CITAC)                   // až bude počet přijatých větší nebo rovno
    { 
      digitalWrite(Led1, HIGH);                       // Led1 zapni
      digitalWrite(piezo, HIGH);                      // Spuštění sireny na pinu č.9
      setPDU();                                       // TEXT mode
      sms1();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms2();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms3();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms4();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms5();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms6();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms7();                                          // pokračuj na SMS
      call1();                                        // pokračuj na volání
      call2();                                        // pokračuj na volání
      call3();                                        // pokračuj na volání
      call4();                                        // pokračuj na volání
      call5();                                        // pokračuj na volání
      call6();                                        // pokračuj na volání
      call7();                                        // pokračuj na volání
      resetFunc();                                     // Reset zařízení
    }
  }
  //pripad - Cidlo2
  if (prijimac.getReceivedValue() == ZPRAVA2)
  {
    citacCidlo2 = citacCidlo2 + 1;
    if (citacCidlo2 >= LIMIT_CITAC)
    { 
      digitalWrite(Led2, HIGH);
      digitalWrite(piezo, HIGH);                      // Spuštění sireny na pinu č.9
      setPDU();                                       // TEXT mode
      sms1();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms2();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms3();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms4();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms5();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms6();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms7();                                          // pokračuj na SMS
      call1();                                        // pokračuj na volání
      call2();                                        // pokračuj na volání
      call3();                                        // pokračuj na volání
      call4();                                        // pokračuj na volání
      call5();                                        // pokračuj na volání
      call6();                                        // pokračuj na volání
      call7();                                        // pokračuj na volání
      resetFunc();                                     // Reset zařízení
    }
  }
  //pripad - Cidlo3
  if (prijimac.getReceivedValue() == ZPRAVA3)
  {
    citacCidlo3 = citacCidlo3 + 1;
    if (citacCidlo3 >= LIMIT_CITAC)
    { 
      digitalWrite(Led3, HIGH);
      digitalWrite(piezo, HIGH);                      // Spuštění sireny na pinu č.9
      setPDU();                                       // TEXT mode
      sms1();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms2();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms3();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms4();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms5();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms6();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms7();                                          // pokračuj na SMS
      call1();                                        // pokračuj na volání
      call2();                                        // pokračuj na volání
      call3();                                        // pokračuj na volání
      call4();                                        // pokračuj na volání
      call5();                                        // pokračuj na volání
      call6();                                        // pokračuj na volání
      call7();                                        // pokračuj na volání
      resetFunc();                                     // Reset zařízení
    }
  }
  //pripad - Cidlo4
  if (prijimac.getReceivedValue() == ZPRAVA4)
  {
    citacCidlo4 = citacCidlo4 + 1;
    if (citacCidlo4 >= LIMIT_CITAC)
    { 
      digitalWrite(Led4, HIGH);
      digitalWrite(piezo, HIGH);                      // Spuštění sireny na pinu č.9
      setPDU();                                       // TEXT mode
      sms1();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms2();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms3();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms4();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms5();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms6();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms7();                                          // pokračuj na SMS
      call1();                                        // pokračuj na volání
      call2();                                        // pokračuj na volání
      call3();                                        // pokračuj na volání
      call4();                                        // pokračuj na volání
      call5();                                        // pokračuj na volání
      call6();                                        // pokračuj na volání
      call7();                                        // pokračuj na volání
      resetFunc();                                     // Reset zařízení
    }
  }
  //pripad - Cidlo5
  if (prijimac.getReceivedValue() == ZPRAVA5)
  {
    citacCidlo5 = citacCidlo5 + 1;
    if (citacCidlo5 >= LIMIT_CITAC)
    { 
      digitalWrite(Led5, HIGH);
      digitalWrite(piezo, HIGH);                      // Spuštění sireny na pinu č.9
      setPDU();                                       // TEXT mode
      sms1();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms2();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms3();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms4();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms5();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms6();                                          // pokračuj na SMS
      setPDU();                                       // TEXT mode
      sms7();                                          // pokračuj na SMS
      call1();                                        // pokračuj na volání
      call2();                                        // pokračuj na volání
      call3();                                        // pokračuj na volání
      call4();                                        // pokračuj na volání
      call5();                                        // pokračuj na volání
      call6();                                        // pokračuj na volání
      call7();                                        // pokračuj na volání
      resetFunc();                                     // Reset zařízení
    }
  }
}
void sms1(){
  //funkce poslání SMS
  Serial.println("Odesilam sms...");
  Serial.println(gsm.smsSend(number1, message)); // if success it returns true (1) else false (0)
  delay(10000);
  } 
void sms2(){
  //funkce poslání SMS
  Serial.println("Odesilam sms...");
  Serial.println(gsm.smsSend(number2, message)); // if success it returns true (1) else false (0)
  delay(10000);
  } 
void sms3(){
  //funkce poslání SMS
  Serial.println("Odesilam sms...");
  Serial.println(gsm.smsSend(number3, message)); // if success it returns true (1) else false (0)
  delay(10000);
  } 
void sms4(){
  //funkce poslání SMS
  Serial.println("Odesilam sms...");
  Serial.println(gsm.smsSend(number4, message)); // if success it returns true (1) else false (0)
  delay(10000);
  } 
void sms5(){
  //funkce poslání SMS
  Serial.println("Odesilam sms...");
  Serial.println(gsm.smsSend(number5, message)); // if success it returns true (1) else false (0)
  delay(10000);
  } 
void sms6(){
  //funkce poslání SMS
  Serial.println("Odesilam sms...");
  Serial.println(gsm.smsSend(number6, message)); // if success it returns true (1) else false (0)
  delay(10000);
  } 
void sms7(){
  //funkce poslání SMS
  Serial.println("Odesilam sms...");
  Serial.println(gsm.smsSend(number7, message)); // if success it returns true (1) else false (0)
  delay(10000);
  } 
void call1(){
    Serial.println("Volam...");
  Serial.println(gsm.call(number1));
  delay(40000);
  Serial.println("Zavesuji");
  gsm.callHangoff();
  delay(10000);
  }
void call2(){
    Serial.println("Volam...");
  Serial.println(gsm.call(number2));
  delay(40000);
  Serial.println("Zavesuji");
  gsm.callHangoff();
  delay(10000);
  }
void call3(){
    Serial.println("Volam...");
  Serial.println(gsm.call(number3));
  delay(40000);
  Serial.println("Zavesuji");
  gsm.callHangoff();
  delay(10000);
  }
void call4(){
    Serial.println("Volam...");
  Serial.println(gsm.call(number4));
  delay(40000);
  Serial.println("Zavesuji");
  gsm.callHangoff();
  delay(10000);
  }
void call5(){
    Serial.println("Volam...");
  Serial.println(gsm.call(number5));
  delay(40000);
  Serial.println("Zavesuji");
  gsm.callHangoff();
  delay(10000);
  }
void call6(){
    Serial.println("Volam...");
  Serial.println(gsm.call(number6));
  delay(40000);
  Serial.println("Zavesuji");
  gsm.callHangoff();
  delay(10000);
  }
void call7(){
    Serial.println("Volam...");
  Serial.println(gsm.call(number7));
  delay(40000);
  Serial.println("Zavesuji");
  gsm.callHangoff();
  delay(5000);
  }
void vypisZpravu(){
  Serial.println("Prijata zprava: ");
  Serial.println(prijimac.getReceivedValue());
  }
void setPDU(){
  delay(1000);
  Serial.println("Prepinam na TEXT.");
  gsm.smsTextMode(true); // TEXT or PDU mode. TEXT is readable :)
  delay(1000);
  }

