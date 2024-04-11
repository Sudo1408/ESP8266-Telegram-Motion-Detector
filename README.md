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

## Setting up Telegram Bot and Obtaining Chat ID

To integrate your ESP8266 device with Telegram, you'll need to create a Telegram bot using BotFather and obtain the chat ID using IDBot. Follow these steps:

1. **Create a Telegram Bot**:
   - Open the Telegram app and search for "BotFather".
   - Start a chat with BotFather and follow the instructions to create a new bot.
   - Once the bot is created, BotFather will provide you with a token. Copy this token; you'll need it later.

2. **Obtain Chat ID**:
   - Search for "IDBot" in the Telegram app and start a chat with it.
   - Send the command `/start` to IDBot to initiate the conversation.
   - IDBot will reply with your unique chat ID. Copy this chat ID; you'll need it to receive messages from your ESP8266 device.

3. **Configure ESP8266 Telegram Bot**:
   - Access the WiFiManager portal on your ESP8266 device.
   - Enter the Telegram bot token (obtained from BotFather) and chat ID (obtained from IDBot) when prompted.
   - Save the configuration, and your ESP8266 device is now ready to send and receive messages via Telegram.

## Contributing

Contributions are welcome! If you find any issues or have ideas for improvements, feel free to open an issue or submit a pull request.

coding vibes 🧑‍💻

## Contact

For any questions or inquiries, feel free to contact me at:

- **Email**: [My Outlook](mailto:mohamedsayedmohamed88@gmail.com)
- **LinkedIn**: [My Profile](https://www.linkedin.com/in/mohamed-sayed-mohamed-0366b0246/)
