(
// List available ports first if you don't know the device name
SerialPort.devices;
)

(
~port = SerialPort(
    "/dev/tty.usbserial-XXXX", // or /dev/ttyUSB0 on Linux, COMx on Windows
    baudrate: 115200
);

SynthDef(\meterTap, { |bus = 0|
    var sig = In.ar(bus, 2);
    var amp = Amplitude.kr(Mix(sig), 0.01, 0.3);
    SendReply.kr(Impulse.kr(30), '/meterLevel', amp);
}).add;
)

(
OSCFunc({ |msg|
    var level = (msg[3].linlin(0, 1, 0, 255)).asInteger.clip(0, 255);
    ~port.put(level); // single byte out
}, '/meterLevel');

x = Synth(\meterTap, [\bus, 0], addAction: \addToTail);
)

// cleanup
(
x.free;
~port.close;
)