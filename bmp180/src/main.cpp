#include <Wire.h>
#include <Adafruit_BMP085.h>

#define SDA_PIN D2  // GPIO4
#define SCL_PIN D1  // GPIO5

Adafruit_BMP085 bmp;

void setup() {
    Serial.begin(9600);  // Mở Serial Monitor với baud 9600
    Wire.begin(SDA_PIN, SCL_PIN); // Khởi tạo giao tiếp I2C với BMP180

    // Kiểm tra BMP180 có kết nối không
    if (!bmp.begin()) {
        Serial.println("Khong tim thay BMP180. Kiem tra lai ket noi!");
        while (1) {
            delay(1000);
        }
    }
    Serial.println("BMP180 da ket noi thanh cong!");
}

void loop() {
    // Đọc nhiệt độ (đơn vị: °C)
    float temperature = bmp.readTemperature();
    // Đọc áp suất (đơn vị: Pa)
    int32_t pressure = bmp.readPressure();

    Serial.print("Nhiet do: ");
    Serial.print(temperature);
    Serial.println(" *C");

    Serial.print("Ap suat: ");
    Serial.print(pressure);
    Serial.println(" Pa");

    Serial.println("--------------------------");

    delay(2000);  
}
