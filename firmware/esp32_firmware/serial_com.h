#ifndef SerialCom_H
#define SerialCom_H

#include <Arduino.h>

/**
 * @file serial_com.h
 * @brief Defines the SerialCom class for serial communication.
 *
 * The SerialCom class provides a simple interface for serial
 * communication using RX and TX pins on an Arduino-compatible device.
 */
class SerialCom {
public:
	/**
	 * @brief Construct a new SerialCom object.
	 *
	 * @param rxPin The RX pin number.
	 * @param txPin The TX pin number.
	 * @param baudRate The baud rate for serial communication (default is 115200).
	 */
	SerialCom(int rxPin, int txPin, long baudRate = 115200);

	/**
	 * @brief Initialize serial communication.
	 */
	void begin();

	/**
	 * @brief Send data over serial.
	 *
	 * @param data The string data to send.
	 */
	void send(String data);

	/**
	 * @brief Receive data from serial.
	 *
	 * @return String The received data.
	 */
	String receive();

	/**
	 * @brief Check the number of bytes available for reading from serial.
	 *
	 * @return int The number of bytes available.
	 */
	int available();

	/**
	 * @brief Flush the serial buffer.
	 *
	 * Clears the serial buffer by reading and discarding all available bytes.
	 */
	void flush();

	/**
	 * @brief Read data from serial.
	 *
	 * @return String The read data.
	 */
	String read();

	/**
	 * @brief Display the file system directory in a menu format.
	 *
	 * @return String The formatted directory listing.
	 */
	String menu_fs_dir();

private:
	int _rxPin;			 // The RX pin number.
	int _txPin;			 // The TX pin number.
	long _baudRate;	 // The baud rate for serial communication.
};

#endif