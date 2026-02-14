CFLAGS?=-O2 -g -Wall -W $(shell pkg-config --cflags librtlsdr)
LDLIBS+=$(shell pkg-config --libs librtlsdr) -lpthread -lm
CC?=gcc
PROGNAME=dump1090

all: dump1090

%.o: %.c
	$(CC) $(CFLAGS) -c $<

dump1090: dump1090.o anet.o
	$(CC) -g -o dump1090 dump1090.o anet.o $(LDFLAGS) $(LDLIBS)

clean:
	rm -f *.o dump1090 dump1090_test

test: dump1090_test
	python3 test_dump1090.py

dump1090_test: dump1090.c anet.c mock_lib/rtl-sdr.c
	$(CC) -O2 -g -Wall -W -I. -Imock_lib -o dump1090_test dump1090.c anet.c mock_lib/rtl-sdr.c -lpthread -lm
