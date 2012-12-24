CT=/home/andy/src/ct/ct
CFLAGS='--std=c99 -Wall'

all:V: index.cgi manual.inc images/aweather.ico images/logo.png

index.cgi: index.o html.o
	gcc $CFLAGS -o $target $prereq

%.o: %.c html.h
	gcc $CFLAGS -c -o $target $stem.c

%.c: %.ct
	$CT -o $target $prereq 

manual.inc: ../aweather/docs/userguide.ad
	asciidoc -s -a toc -a numbered -b xhtml11 -o- $prereq \
	| awk -f toc.awk > $target

images/aweather.ico: ../aweather/data/icons/16x16/aweather.png
	icotool -c $prereq -o $target

images/logo.png: ../aweather/data/icons/scalable/aweather.svg
	rsvg -w 130 -h 130 $prereq $target

clean:V:
	rm -f *.o *.cgi html.c

push:V:
	user=andy
	dest=/home/pileus/htdocs/aweather/
	serv=pileus.org
	rsync -uavz .htaccess \
		$user@$serv:$dest
	rsync -uavz --delete \
		--exclude '*~' \
		--exclude '.*' \
		index.cgi manual.inc images screens data  \
		$user@$serv:$dest
