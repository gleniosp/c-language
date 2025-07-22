void glenio() {
    int j = 2;

    for (int i = 10; i > 0; i = i - 1) {
        if (i == 5) {
            continue;
        }
        j = j + 1;
    }

    return;
}