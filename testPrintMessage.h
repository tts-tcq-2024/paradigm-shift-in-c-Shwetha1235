void printMsgMock(const char *message) {
    printf("%s\n", message);
}

void (*printMessageMock)(const char *message) = printMsgMock;

void testPrintColorMap() {
    char buffer[2048];
    memset(buffer, 0, sizeof(buffer));
    setvbuf(stdout, buffer, _IOFBF, sizeof(buffer));
    printMessageMock("Hello World");
    fflush(stdout);

    const char* expectedOutput = "Hello World";

    assert(strcmp(buffer, expectedOutput) == 0);
}
