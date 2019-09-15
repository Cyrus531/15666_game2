#from https://stackoverflow.com/questions/714100/os-detecting-makefile
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	OPUSENC = ../../nest-libs/linux/opus-tools/bin/opusenc
else
	OPUSENC = ../../nest-libs/macos/opus-tools/bin/opusenc
endif

all: ../dist/cold-dunes.opus ../dist/0.opus ../dist/1.opus ../dist/2.opus \
../dist/3.opus ../dist/4.opus ../dist/5.opus ../dist/6.opus ../dist/7.opus \
../dist/8.opus ../dist/9.opus ../dist/beep.opus

../dist/cold-dunes.opus : cold-dunes.wav
	$(OPUSENC) --vbr --bitrate 128 cold-dunes.wav ../dist/cold-dunes.opus
../dist/0.opus : 0.wav
	$(OPUSENC) --vbr --bitrate 128 0.wav ../dist/0.opus
../dist/1.opus : 1.wav
	$(OPUSENC) --vbr --bitrate 128 1.wav ../dist/1.opus
../dist/2.opus : 2.wav
	$(OPUSENC) --vbr --bitrate 128 2.wav ../dist/2.opus
../dist/3.opus : 3.wav
	$(OPUSENC) --vbr --bitrate 128 3.wav ../dist/3.opus
../dist/4.opus : 4.wav
	$(OPUSENC) --vbr --bitrate 128 4.wav ../dist/4.opus
../dist/5.opus : 5.wav
	$(OPUSENC) --vbr --bitrate 128 5.wav ../dist/5.opus
../dist/6.opus : 6.wav
	$(OPUSENC) --vbr --bitrate 128 6.wav ../dist/6.opus
../dist/7.opus : 7.wav
	$(OPUSENC) --vbr --bitrate 128 7.wav ../dist/7.opus
../dist/8.opus : 8.wav
	$(OPUSENC) --vbr --bitrate 128 8.wav ../dist/8.opus
../dist/9.opus : 9.wav
	$(OPUSENC) --vbr --bitrate 128 9.wav ../dist/9.opus
../dist/beep.opus : beep.wav
	$(OPUSENC) --vbr --bitrate 128 beep.wav ../dist/beep.opus
