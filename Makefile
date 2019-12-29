ifeq ($(prefix),)
	prefix=/usr/local
endif
ifeq ($(datadir),)
	datadir=$(prefix)/share
endif
ifeq ($(shell which $(CC)),)
	CC=gcc
endif
all:
	$(CC) $(CFLAGS) -o cave2 cave2.c
	strip -S cave2
install:
	if [ ! -d "$(DESTDIR)$(prefix)/games" ]; then mkdir -p $(DESTDIR)$(prefix)/games; fi
	install -m755 cave2 $(DESTDIR)$(prefix)/games
clean:
	rm cave2
