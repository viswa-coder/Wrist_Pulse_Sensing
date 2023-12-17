# Wrist Pulse Sensing System with ESP32 and Max30100 Sensors

## Project Overview

The Wrist Pulse Sensing System is a health monitoring project designed to sense and analyze Vatta, Pitha, and Kapha waveforms using an ESP32 microcontroller, a multiplexer (MUX), and three Max30100 pulse oximeter sensors.

## Table of Contents

- [Components Used](#components-used)
- [System Operation](#system-operation)
- [Benefits](#benefits)
- [Future Developments](#future-developments)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Components Used

- **ESP32 Microcontroller:** The brain of the system, responsible for data processing and communication.
- **Max30100 Pulse Oximeter Sensors (x3):** Specialized sensors for measuring heart rate and blood oxygen levels.
- **Multiplexer (MUX):** Enables the ESP32 to interface with multiple Max30100 sensors efficiently.
- **Power Supply:** Provides the necessary power for the ESP32 and sensors.
- **Wristband:** Holds the sensors securely against the wrist for continuous monitoring.

## System Operation

1. **Pulse Waveform Sensing:** The Max30100 sensors are strategically placed on the wrist to capture pulse waveforms associated with Vatta, Pitha, and Kapha.

2. **Data Acquisition:** The ESP32, equipped with the MUX, collects data simultaneously from the three Max30100 sensors. The MUX allows the ESP32 to switch between sensors efficiently.

3. **Signal Processing:** Raw pulse waveform data is processed in real-time to extract key parameters associated with Vatta, Pitha, and Kapha. Signal processing algorithms analyze the waveforms to identify characteristic patterns.

4. **User Interface:** A user-friendly interface, possibly a mobile app, provides a visual representation of Vatta, Pitha, and Kapha waveforms. Users can monitor their pulse patterns and receive insights into their Ayurvedic constitution.

## Benefits

- **Holistic Health Monitoring:** The system provides a holistic approach to health monitoring based on Ayurvedic principles, offering insights into the balance of Vatta, Pitha, and Kapha.

- **Continuous Monitoring:** The wristband design ensures continuous monitoring, allowing for the observation of changes in pulse patterns over time.

## Future Developments

- Integration with Machine Learning: Implementing machine learning algorithms for enhanced pattern recognition and personalized health insights.

- Connectivity Options: Expanding communication capabilities to integrate with cloud platforms for remote monitoring and data storage.

- User Education: Incorporating educational resources within the user interface to help individuals understand and interpret their pulse waveform data.
- Real-time Feedback: Users can receive real-time feedback on their pulse waveforms, enabling them to make lifestyle adjustments in accordance with Ayurvedic recommendations.




