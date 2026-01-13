#include <IRremote.h>

#define IR_RECEIVE_PIN A0

// пины светодиодов
#define GREEN_LED_PIN 8
#define YELLOW_LED_PIN 9
#define RED_LED_PIN 10

// поменять!!
#define BTN_GREEN_CODE  0xAAAAAAAA  
#define BTN_YELLOW_CODE 0xBBBBBBBB  
#define BTN_RED_CODE    0xCCCCCCCC  

void setup() {
  Serial.begin(9600);

  // запускаем ИК‑приёмник
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);

  digitalWrite(GREEN_LED_PIN, LOW);
  digitalWrite(YELLOW_LED_PIN, LOW);
  digitalWrite(RED_LED_PIN, LOW);
}

void loop() {
  if (IrReceiver.decode()) {

    // код нажатой кнопки (сырые данные)
    uint32_t code = IrReceiver.decodedIRData.decodedRawData;

    // смотрим код в Мониторе порта
    Serial.print("Код: 0x");
    Serial.println(code, HEX);


    if (code == BTN_GREEN_CODE) {
      digitalWrite(GREEN_LED_PIN, HIGH);
      digitalWrite(YELLOW_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, LOW);
    }

    else if (code == BTN_YELLOW_CODE) {
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, HIGH);
      digitalWrite(RED_LED_PIN, LOW);
    }

    else if (code == BTN_RED_CODE) {
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(YELLOW_LED_PIN, LOW);
      digitalWrite(RED_LED_PIN, HIGH);
    }


    IrReceiver.resume();  
  }
}