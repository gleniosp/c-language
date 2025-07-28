void glenio() {
    int i = 11;

    if (i == 11) {
        goto end;
    }

    i = i + 2;

    end:
        i = i + 21;

    return;
}