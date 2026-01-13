#include <IRremote.h>

#define IR_RECEIVE_PIN A0

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
  Serial.println("Готово. Нажимайте кнопки на пульте.");
}

void loop() {
  if (IrReceiver.decode()) {
    uint32_t code = IrReceiver.decodedIRData.decodedRawData;

    Serial.print("Код: 0x");
    Serial.println(code, HEX);
    Serial.println("-------------------------");

    IrReceiver.resume();
  }
}
