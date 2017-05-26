CC = g++
CFLAGS = -Wall -std=c++11
OBJECTS = projectV_driver.o actions.o attacks.o character_class_information.o character_setup.o combat.o Diadal.o Diadal_story.o game.o hostile.o ingame_entity.o primary_character.o primary_stats.o scene.o secondary_stats.o support.o

all: projectV

projectV: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o projectV
	
projectV_driver.o: projectV_driver.cpp
	$(CC) $(CFLAGS) -c projectV_driver.cpp -o projectV_driver.o	
	
actions.o: actions.cpp actions.h
	$(CC) $(CFLAGS) -c actions.cpp -o actions.o
	
attacks.o: attacks.cpp attacks.h
	$(CC) $(CFLAGS) -c attacks.cpp -o attacks.o
	
character_class_information.o: character_class_information.cpp character_class_information.h
	$(CC) $(CFLAGS) -c character_class_information.cpp -o character_class_information.o

character_setup.o: character_setup.cpp character_setup.h
	$(CC) $(CFLAGS) -c character_setup.cpp -o character_setup.o

combat.o: combat.cpp combat.h
	$(CC) $(CFLAGS) -c combat.cpp -o combat.o

Diadal.o: Diadal.cpp Diadal.h
	$(CC) $(CFLAGS) -c Diadal.cpp -o Diadal.o
	
Diadal_story.o: Diadal_story.cpp Diadal_story.h
	$(CC) $(CFLAGS) -c Diadal_story.cpp -o Diadal_story.o
	
game.o: game.cpp game.h
	$(CC) $(CFLAGS) -c game.cpp -o game.o
	
hostile.o: hostile.cpp hostile.h
	$(CC) $(CFLAGS) -c hostile.cpp -o hostile.o

ingame_entity.o: ingame_entity.cpp ingame_entity.h
	$(CC) $(CFLAGS) -c ingame_entity.cpp -o ingame_entity.o

primary_character.o: primary_character.cpp primary_character.h
	$(CC) $(CFLAGS) -c primary_character.cpp -o primary_character.o
	
primary_stats.o: primary_stats.cpp primary_stats.h
	$(CC) $(CFLAGS) -c primary_stats.cpp -o primary_stats.o
	
scene.o: scene.cpp scene.h
	$(CC) $(CFLAGS) -c scene.cpp -o scene.o
	
secondary_stats.o: secondary_stats.cpp secondary_stats.h
	$(CC) $(CFLAGS) -c secondary_stats.cpp -o secondary_stats.o

support.o: support.cpp support.h
	$(CC) $(CFLAGS) -c support.cpp -o support.o

clean:
	rm $(OBJECTS) projectV
	
clean_objects:
	rm $(OBJECTS)