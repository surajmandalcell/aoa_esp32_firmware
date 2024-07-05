#ifndef SerialCom_H
#define SerialCom_H

#include <Arduino.h>

/**
 * @brief The SerialCom class provides a simple interface for serial
 * communication.
 */
/**
 * @file serial_com.h
 * @brief Defines the SerialCom class for serial communication.
 */

/**
 * @class SerialCom
 * @brief Represents a serial communication interface.
 */
class SerialCom {
public:
	/**
	 * @brief Constructs a SerialCom object with the specified RX and TX pins and
	 * baud rate.
	 * @param rxPin The RX pin number.
	 * @param txPin The TX pin number.
	 * @param baudRate The baud rate for serial communication. Default is 115200.
	 */
	SerialCom(int rxPin, int txPin, long baudRate = 115200);

	/**
	 * @brief Initializes the serial communication.
	 */
	void begin();

	/**
	 * @brief Sends data over the serial communication.
	 * @param data The data to be sent.
	 */
	void send(String data);

	/**
	 * @brief Receives data from the serial communication.
	 * @return The received data as a String.
	 */
	String receive();

	/**
	 * @brief Checks if there is data available to be read from the serial
	 * communication.
	 * @return The number of bytes available to be read.
	 */
	int available();

private:
	int _rxPin;			/**< The RX pin number. */
	int _txPin;			/**< The TX pin number. */
	long _baudRate; /**< The baud rate for serial communication. */
};

#endif
