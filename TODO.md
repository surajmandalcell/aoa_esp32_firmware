# TODO LIST

- [ ] Wifi rest api test route (/device)

### 1. **Device Identification:**

- Embed a unique ID in each ESP32 during firmware flashing. Utilize the ESP32's built-in hardware MAC address as a unique identifier. This avoids the need for manual ID assignments.
- On startup, each ESP32 can send its MAC address to the server.

### 2. **Device Discovery:**

- Use mDNS (Multicast DNS) or SSDP (Simple Service Discovery Protocol) for automatic discovery of ESP32 devices on the network.
- Each ESP32 broadcasts its presence, and the server listens for these broadcasts to dynamically discover devices.

### 3. **Server Management:**

- The server maintains a list of discovered devices, storing their IP addresses, MAC addresses (as unique IDs), and any friendly names or additional metadata assigned by the server.
- Implement a REST API or WebSocket on the server for ongoing communication and management.

### 4. **Dynamic IP Handling:**

- Devices use DHCP to obtain an IP address. The server updates its stored IP addresses based on identification broadcasts or keep-alive messages from each ESP32.

### 5. **Device-Specific Actions:**

- Through the server's interface, allow selection of an ESP32 based on its unique ID or assigned friendly name.
- Send commands to the selected ESP32 via the established REST API or WebSocket connection.

### 6. **Firmware Consistency:**

- Use the same firmware on all ESP32 devices. This firmware includes the necessary code for mDNS/SSDP, communicating with the server, and handling commands from the server.

### Implementation Steps:

1. **Firmware:**
   - Add mDNS/SSDP capabilities to each ESP32's firmware.
   - Implement HTTP client functionality to register with the server at boot and periodically send keep-alive messages.
2. **Server:**
   - Develop or deploy a service to listen for mDNS/SSDP broadcasts and HTTP registrations.
   - Create a REST API or WebSocket server to manage ESP32 devices and send/receive commands.
