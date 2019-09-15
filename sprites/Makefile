
OS := $(shell uname)

ifeq ($(OS), Linux)
	GIMP=gimp
else
	GIMP=/Applications/GIMP.app/Contents/MacOS/gimp
endif

../dist/sameclip.png ../dist/sameclip.atlas : sameclip.xcf sameclip.list trade.xcf trade-font.list extract-sprites.py pack-sprites
	rm -rf sameclip
	./extract-sprites.py sameclip.list sameclip --gimp='$(GIMP)'
	./extract-sprites.py trade-font.list sameclip --gimp='$(GIMP)'
	./pack-sprites ../dist/sameclip sameclip/*
