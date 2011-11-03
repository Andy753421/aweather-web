CT=/scratch/ct/ct
CFLAGS='--std=c99 -Wall'

PKG_FLAGS=`{pkg-config --cflags glib-2.0}
PKG_LIBS=`{pkg-config --libs glib-2.0}

index.cgi: index.o html.o
	gcc $CFLAGS -o $target $prereq $PKG_LIBS

%.o: %.c html.h
	gcc $CFLAGS $PKG_FLAGS -c -o $target $stem.c

%.c: %.ct
	$CT -o $target $prereq 

clean:V:
	rm -f *.o *.cgi html.c

push:V:
	user=spenceal
	dest=/home/lug/htdocs/proj/aweather/
	rsync -uavz .htaccess \
		$user@lug.rose-hulman.edu:$dest
	rsync -uavz --delete \
		--exclude '*~' \
		--exclude '.*' \
		index.cgi images screens data \
		$user@lug.rose-hulman.edu:$dest
