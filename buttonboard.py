import machine

pressed = ()

buttons = {
  "GH": machine.Pin(5, machine.Pin.IN, machine.Pin.PULL_UP),
  "AB": machine.Pin(6, machine.Pin.IN, machine.Pin.PULL_UP),
  "processor": machine.Pin(7, machine.Pin.IN, machine.Pin.PULL_UP),
  "IJ": machine.Pin(8, machine.Pin.IN, machine.Pin.PULL_UP),
  "KL": machine.Pin(9, machine.Pin.IN, machine.Pin.PULL_UP),
  "BC": machine.Pin(10, machine.Pin.IN, machine.Pin.PULL_UP),
  "left": machine.Pin(11, machine.Pin.IN, machine.Pin.PULL_UP),
  "EF": machine.Pin(12, machine.Pin.IN, machine.Pin.PULL_UP),
  "right": machine.Pin(13, machine.Pin.IN, machine.Pin.PULL_UP)
  }

def button_pressed(pin):
  """Prints the name of the button that was pressed."""
  for name, button in buttons.items():
    if button == pin:
      print(f"Button {name} pressed!")
      break

for name, button in buttons.items():
# Attach the interrupt handler to each button
  button.value(0)
  button.irq(trigger=machine.Pin.IRQ_RISING, handler=button_pressed)

# Keep the code running
while True:
  pass

