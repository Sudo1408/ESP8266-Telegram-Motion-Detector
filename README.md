# ESP8266 Telegram Motion Detector

This project utilizes an ESP8266 microcontroller to create a motion detector system integrated with Telegram messaging service. When motion is detected by the Passive Infrared (PIR) sensor, the system triggers an alert message to a specified Telegram chat ID.

## Features

- **Motion Detection**: The system detects motion using a PIR sensor connected to the ESP8266.
- **Alert System**: Upon detecting motion, the system triggers an alert message to a Telegram chat ID.
- **Customizable Configuration**: The Telegram bot token and chat ID can be configured using WiFiManager for easy setup.

## Components Used

- ESP8266 microcontroller
- Passive Infrared (PIR) sensor
- LED indicator
- Buzzer

## Design

![The Circuit](/images/Design.png)

## Dependencies

- [ESP8266WiFi](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi)
- [DNSServer](https://github.com/esp8266/Arduino/tree/master/libraries/DNSServer)
- [ESP8266WebServer](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer)
- [WiFiManager](https://github.com/tzapu/WiFiManager)
- [UniversalTelegramBot](https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot)

## Usage

1. Connect the components as per the specified pin configuration.
2. Upload the code to your ESP8266 device.
3. Power on the device and connect it to a WiFi network.
4. Access the WiFiManager portal to configure the Telegram bot token and chat ID.
5. Once configured, the system is ready to detect motion and send alerts via Telegram.

## Contributing

Contributions are welcome! If you find any issues or have ideas for improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
