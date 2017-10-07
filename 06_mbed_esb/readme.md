# Env preparation
* copy esb directory from sdk, as it is still not a git module (under test)

# Encountred issues
* runtime failure
* (+) configured RADIO register are identic
* (-) RADIO_IRQHandler is not triggered, it is declared in Vectors on address 0x1b000 so might not be taken into consideration as sofdevice has the irq

# Solution
* required nRF_Dongle led with mbed-os 5 without softdevices
