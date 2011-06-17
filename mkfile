CT=/scratch/ct/ct
CFLAGS='--std=c99 -Wall'

PKG_FLAGS=`{pkg-config --cflags glib-2.0}
PKG_LIBS=`{pkg-config --libs glib-2.0}

index.cgi: index.o html.o
	gcc $CFLAGS -o $target $prereq $PKG_LIBS

%.o: %.c
	gcc $CFLAGS $PKG_FLAGS -c -o $target $prereq

%.c: %.ct
	$CT -o $target $prereq 

clean:
	rm -f *.o *.cgi html.c
