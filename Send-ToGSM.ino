// Vysílač k GSM požárnímu hlásiči
// ATTINY85 Digispark (Default, 16,5MHz)
// D0-DATA(STX882); D1-->D5-Volné piny
// NiceRF 433MHz Vysílač STX882
// Celkem 5 vysílačů:
// 1.vysílač hodnota: 1511
// 2.vysílač hodnota: 1512
// 3.vysílač hodnota: 1513
// 4.vysílač hodnota: 1514
// 5.vysílač hodnota: 1515

// připojení potřebné knihovny
#include <RCSwitch.h>

RCSwitch vysilac = RCSwitch();                              // Vytvoření objektu vysílače z knihovny
int TXDATA = 0;                                             // Definice pinu DATA připojeného k ATTINY85
int LED = 1;                                                // Definice indikační LED na ATTINY85 - Buildin

const int POCET_ODESILANI = 10;

void setup() {
  vysilac.enableTransmit(TXDATA);                           // Zahájení vysílání na pinu D0
  vysilac.setProtocol(1);                                   // Možnost změnit protokol na č.2
//vysilac.setRepeatTransmit(10);                            // Volba počtu opakování zaslání zprávy
  pinMode(LED, OUTPUT);                                     // Nastavení LED jako výstup

  for (int i = 1; i <= POCET_ODESILANI; i++)
  {
    posliZpravu();
  }
}

void loop() {
}

void posliZpravu()
{
  vysilac.send(1515, 24);                                   // Poslání čísla
  digitalWrite(LED,HIGH);                                   // Zapnutí LED
  delay(1000);                                              // Časová prodleva
  digitalWrite(LED,LOW);                                    // Vypnutí LED
  delay(2000);                                              // Prodleva mezi smyčkou (LOOP)
}
