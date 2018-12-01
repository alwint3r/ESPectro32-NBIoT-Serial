#include <Arduino.h>
#include <HardwareSerial.h>

#define NBIOT_RX_PIN    25
#define NBIOT_TX_PIN    26
#define NBIOT_BAUD_RATE 115200
#define NBIOT_PWR_PIN   17
#define NBIOT_DTR_PIN   14
#define NBIOT_RTS_PIN   2

HardwareSerial nbSerial(1);

void setup() {
    Serial.begin(115200);
    pinMode(NBIOT_DTR_PIN, OUTPUT);
    pinMode(NBIOT_RTS_PIN, OUTPUT);
    pinMode(NBIOT_PWR_PIN, OUTPUT);

    digitalWrite(NBIOT_DTR_PIN, LOW);
    digitalWrite(NBIOT_RTS_PIN, LOW);
    
    digitalWrite(NBIOT_PWR_PIN, HIGH);
    delay(500);
    digitalWrite(NBIOT_PWR_PIN, LOW);
    delay(500);
    digitalWrite(NBIOT_PWR_PIN, HIGH);

    nbSerial.begin(NBIOT_BAUD_RATE, SERIAL_8N1, NBIOT_RX_PIN, NBIOT_TX_PIN);
}

void loop() {
    while (Serial.available()) {
        nbSerial.write(Serial.read());
    }

    while (nbSerial.available()) {
        Serial.write(nbSerial.read());
    }
}
