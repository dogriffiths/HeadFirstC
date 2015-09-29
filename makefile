.PHONY: page11 page12 page15 page33 page45

PROGDIR=~/Desktop/Chapter\ 3\ -\ small\ tools/testing

geo2json-page3:
	cp $(PROGDIR)/geo2json-page3 .

geo2json-page13:
	cp $(PROGDIR)/geo2json-page13 .

geo2json-page21:
	cp $(PROGDIR)/geo2json-page21 .

categorize_withargs:
	(cd $(PROGDIR) && make categorize_withargs)
	cp $(PROGDIR)/categorize_withargs .

bermuda:
	cp $(PROGDIR)/bermuda .

page11: page9-data.csv geo2json-page3
	./geo2json-page3 < page9-data.csv > output.json

page12: page12-baddata.csv geo2json-page3
	./geo2json-page3 < page12-baddata.csv > output.json

page15: page12-baddata.csv geo2json-page13
	(./geo2json-page13 || :)< page12-baddata.csv > output.json

page33: spooky.csv geo2json-page21 bermuda
	(./bermuda | ./geo2json-page21) < spooky.csv > output.json

page45: gpsdata.data categorize_withargs geo2json-page21
	./categorize_withargs UFO aliens.csv Elvis elvises.csv the_rest.csv
	./geo2json-page21 < elvises.csv > output.json