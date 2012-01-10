CT=/scratch/ct/ct
CFLAGS='--std=c99 -Wall'

all:V: index.cgi manual.inc

index.cgi: index.o html.o
	gcc $CFLAGS -o $target $prereq $PKG_LIBS

%.o: %.c html.h
	gcc $CFLAGS $PKG_FLAGS -c -o $target $stem.c

%.c: %.ct
	$CT -o $target $prereq 

manual.inc: ../docs/userguide.ad
	asciidoc -s -a toc -a numbered -b xhtml11 -o- $prereq \
	| awk -f toc.awk > $target

clean:V:
	rm -f *.o *.cgi html.c

push:V:
	user=spenceal
	dest=/home/lug/htdocs/proj/aweather/
	serv=lug.rose-hulman.edu
	rsync -uavz .htaccess \
		$user@$serv:$dest
	rsync -uavz --delete \
		--exclude '*~' \
		--exclude '.*' \
		index.cgi manual.inc images screens data  \
		$user@$serv:$dest
