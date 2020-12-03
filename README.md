# Arduino LEDs

More information can be found on my blog.

`reverse_rainbow.c` contains a simple arduino program to light up a WS2811 LED
strip with a rainbow. Because I want to bend the strip in half in the middle to
fit the space I need, the rainbow pattern repeats in reverse order halfway
along the strip.

The strip is connected to a 12 power supply. The ground and digital PIN 7 from
the arduino are connected too.

Once the lights have changed do the rainbow colour, you can actually detach the
arduino, and they will stay the same colour until they are switched off.
However, I keep mine attached, as they are on a timer plug and switch off every
night.
