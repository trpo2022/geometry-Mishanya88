CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

geo: main.o libgeo.a
        $(CC) $(CFLAGS) -o $@ $^

main.o: main.c
        $(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

libgeo.a: geo.o
        ar rcs $@ $^

geo.o: geo.c
        $(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

-include main.d geo.d