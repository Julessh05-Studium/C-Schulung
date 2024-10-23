//
// Created by Julian Schumacher on 23.10.24.
//

#include <stdio.h>

#include "third.h"


union Test {
    unsigned short word;
    // w/o struct always read from beginning
    unsigned char byteAsChar1;

    struct bytes {
        unsigned char byte1;
        unsigned char byte2;
    } bytes;
};


void unionTest() {
    union Test test1;
    test1.word = 140;
    printf("Word: %d\n", test1.word);
    printf("Byte 1 in struct: %d\n", test1.bytes.byte1);
    printf("Byte 2 in struct: %d\n", test1.bytes.byte2);
    printf("Byte 1 w/o struct: %d\n", test1.byteAsChar1);
}

union Register {
    unsigned short word;

    struct {
        unsigned char buffer1;
        unsigned char buffer2;
        unsigned char checksum;
    };
};

union Register tx;
union Register rx;

void tx_to_rx() {
    const unsigned char temp1 = tx.buffer1;
    const unsigned char temp2 = tx.buffer2;

    printf("Moving 2 value bytes and checksum to receiver");

    // Move checksum
    tx.buffer1 = tx.checksum;
    printf("Checksum in transmitter buffer 1: %#8p with value: %d\n", &tx.buffer1, tx.buffer1);
    rx.buffer1 = tx.buffer1;
    printf("Checksum in receiver buffer 1: %#8p with value: %d\n", &rx.buffer1, rx.buffer1);
    rx.buffer2 = rx.buffer1;
    printf("Checksum in receiver buffer 2: %#8p with value: %d\n", &rx.buffer2, rx.buffer2);
    rx.checksum = rx.buffer2;
    printf("Checksum in receiver checksum: %#8p with value: %d\n", &rx.checksum, rx.checksum);
    printf("\n");

    // Move buffer-2 bits
    tx.buffer1 = temp2;
    printf("Value byte 2 in transmitter buffer 1: %#8p with value: %d\n", &tx.buffer1, tx.buffer1);
    rx.buffer1 = tx.buffer1;
    printf("Value byte 2 in receiver buffer 1: %#8p with value: %d\n", &rx.buffer1, rx.buffer1);
    rx.buffer2 = tx.buffer1;
    printf("Value byte 2 in receiver buffer 2: %#8p with value: %d\n", &rx.buffer2, rx.buffer2);
    printf("\n");

    // Move buffer-1 bits
    tx.buffer1 = temp1;
    printf("Value byte 1 in transmitter buffer 1: %#8p with value: %d\n", &tx.buffer1, tx.buffer1);
    rx.buffer1 = tx.buffer1;
    printf("Value byte 1 in receiver buffer 1: %#8p with value: %d\n", &rx.buffer1, rx.buffer1);
    printf("\n");
}

void simulateTransmission() {
    tx.word = 496;
    tx.checksum = tx.buffer1 ^ tx.buffer2;
    tx_to_rx();
}
