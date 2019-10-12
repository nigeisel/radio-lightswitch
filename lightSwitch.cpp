#include "433bib/433Utils/rc-switch/RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

RCSwitch rcSwitch;

void switch_a(bool state);
void switch_b(bool state);
void switch_c(bool state);
void switch_d(bool state);

int main(int argc, char *argv[]) {
	int PIN = 0; // siehe wiring Pi Belegung

	if (wiringPiSetup() == -1) return 1;

	rcSwitch = RCSwitch();
	rcSwitch.enableTransmit(PIN);

	if (argc != 3) {
		printf("Specify arguments: lightSwitch [switch = 'a, b, c, d, all' ], [state = 'on, off']\n");
		return 22;
	}

	bool state = strcmp(argv[2], "on") == 0;

	if (strcmp(argv[1], "all") == 0) {
		switch_a(state);
		usleep(10);
                switch_b(state);
		usleep(10);
                switch_c(state);
		usleep(10);
                switch_d(state);
	}

        if (strcmp(argv[1], "light") == 0) {
                switch_a(state);
                usleep(10);
                switch_b(state);
                usleep(10);
                switch_c(state);
        }
        if (strcmp(argv[1], "music") == 0) {
        	switch_d(state);
        }

	if (strcmp(argv[1], "a") == 0) {
		switch_a(state);
	}

        if (strcmp(argv[1], "b") == 0) {
                switch_b(state);
        }

        if (strcmp(argv[1], "c") == 0) {
		switch_c(state);
        }

        if (strcmp(argv[1], "d") == 0) {
                switch_d(state);
        }

	return 0;
}

void switch_a(bool state) {
	int codeSocketDon = 1312081;
	int codeSocketDoff = 1312084;

	if (state) {
		rcSwitch.send(codeSocketDon, 24);
	} else {
		rcSwitch.send(codeSocketDoff, 24);
	}
}

void switch_b(bool state) {
        int codeSocketDon = 1315153;
        int codeSocketDoff = 1315156;

        if (state) {
                rcSwitch.send(codeSocketDon, 24);
        } else {
                rcSwitch.send(codeSocketDoff, 24);
        }
}

void switch_c(bool state) {
        int codeSocketDon = 1315921;
        int codeSocketDoff = 1315924;

        if (state) {
                rcSwitch.send(codeSocketDon, 24);
        } else {
                rcSwitch.send(codeSocketDoff, 24);
        }
}

void switch_d(bool state) {
        int codeSocketDon = 1316113;
        int codeSocketDoff = 1316116;

        if (state) {
                rcSwitch.send(codeSocketDon, 24);
        } else {
                rcSwitch.send(codeSocketDoff, 24);
        }
}

