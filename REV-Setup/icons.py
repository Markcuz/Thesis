import pifacedigitalio
import sys


def switch_pressed(event):
    event.chip.output_pins[event.pin_num].turn_on()
    print(event.chip.input_pins[0].value)
    print(event.chip.input_pins[1].value)
    print(event.chip.input_pins[2].value)
    print(event.chip.input_pins[3].value)

    sys.stdout.flush()


def switch_unpressed(event):
    event.chip.output_pins[event.pin_num].turn_off()
    print(event.chip.input_pins[0].value)
    print(event.chip.input_pins[1].value)
    print(event.chip.input_pins[2].value)
    print(event.chip.input_pins[3].value)

    sys.stdout.flush()


if __name__ == "__main__":
    pifacedigital = pifacedigitalio.PiFaceDigital()
    
    listener = pifacedigitalio.InputEventListener(chip=pifacedigital)
    for i in range(4):
        listener.register(i, pifacedigitalio.IODIR_ON, switch_pressed)
        listener.register(i, pifacedigitalio.IODIR_OFF, switch_unpressed)
    listener.activate()