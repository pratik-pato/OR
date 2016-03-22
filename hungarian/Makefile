CC = gcc
AR = ar

CFLAGS = -g -Wall -I.
LDFLAGS = -L. -lhungarian

HUNGLIB = libhungarian.a
VERSION = 0.1

all: $(HUNGLIB) test

test: test.c $(HUNGLIB)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

$(HUNGLIB): hungarian.o
	$(AR) cr $@ $<
	
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

dist: clean
	cd .. && rm -f libhungarian-$(VERSION).tar.gz && tar -cvzf libhungarian-$(VERSION).tar.gz hungarian --exclude libhungarian-$(VERSION).tar.gz --exclude CVS 
	mv ../libhungarian-$(VERSION).tar.gz .

clean:
	rm -f *.o *.a test
